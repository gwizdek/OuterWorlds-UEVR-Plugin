#include "plugin.hpp"
#include "plugin_config.hpp"
#include "indiana/SDK/Niagara_classes.hpp"
#include "indiana/SDK/TPV_AnimBP_classes.hpp"
#include "indiana/SDK/FPV_AnimBP2_classes.hpp"
#include "indiana/SDK/TPVLocomotionAnimationSet_classes.hpp"
#include "indiana/SDK/PlayerHighlightComponent_classes.hpp"
#include "indiana/SDK/CinematicCamera_classes.hpp"
#include "indiana/SDK/BP_DynamicTOD_classes.hpp"

using namespace uevr;

// Actually creates the plugin. Very important that this global is created.
// The fact that it's using std::unique_ptr is not important, as long as the constructor is called in some way.
std::unique_ptr<OuterWorldsPlugin> g_plugin = std::make_unique<OuterWorldsPlugin>();

OuterWorldsPlugin::~OuterWorldsPlugin() {
    if (m_vr_hud != nullptr) {
        m_vr_hud->~OuterWorldsVRHUD();
    }
    if (m_config != nullptr) {
        m_config->~OuterWorldsPluginConfig();
    }
}

void OuterWorldsPlugin::on_dllmain() {
}

void OuterWorldsPlugin::on_initialize() {
    // Logs to the appdata UnrealVRMod log.txt file
    API::get()->log_warn("######### UEVR Outer Worlds Plugin Initializing... #########");

    ImGui::CreateContext();

    // plugin configuration
    m_config = new OuterWorldsPluginConfig();
    m_config->load_plugin_config();

    // remove stale VR HUD actors (when re-enabling the plugin)
    OuterWorldsVRHUD::cleanup(SDK::UWorld::GetWorld());
    // VR HUD - will be later initialized by level_change handler
    m_vr_hud = new OuterWorldsVRHUD();
}

void OuterWorldsPlugin::on_xinput_get_state(uint32_t* retval, uint32_t user_index, XINPUT_STATE* state) {
    PLUGIN_LOG_ONCE("XInput Get State");
  
    // start cb timer
    std::chrono::steady_clock::time_point begin_time;
    if (m_ui_option_show_debug_view && m_cb_calls_count == 0) {
        begin_time = std::chrono::steady_clock::now();
    }

    const UEVR_VRData* vr = API::get()->param()->vr;
    if (!vr->is_runtime_ready() || !is_vr_hud_valid())
        return;

    try {
        prepare_pointers();
        prepare_state(vr);
    }
    catch (...) {
        API::get()->log_error("[on_xinput_get_state] Prepare pointers / state");
    }

    try {
        // handlers
        handle_controller_input(state, vr);
    }
    catch (...) {
        API::get()->log_error("[on_xinput_get_state] Handle controller input");
    }

    // set it to true, so we won't process pawn again in pre_engine_tick cb
    m_xinput_cb_processed = true;

    // calculate cb duration
    if (m_ui_option_show_debug_view && m_cb_calls_count == 0) {
        std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
        m_ui_xinput_duration = static_cast<int>(std::chrono::duration_cast<std::chrono::microseconds>(end_time - begin_time).count());
    }
}

void OuterWorldsPlugin::on_pre_engine_tick(API::UGameEngine* engine, float delta) {
    PLUGIN_LOG_ONCE("Pre Engine Tick: %f", delta);

    m_cb_calls_count = m_cb_calls_count < CB_DURATION_SAMPLE_RATE ? ++m_cb_calls_count : 0;
    // start cb timer
    std::chrono::steady_clock::time_point begin_time;
    if (m_ui_option_show_debug_view && m_cb_calls_count == 0) {
        begin_time = std::chrono::steady_clock::now();
    }

    const UEVR_VRData* vr = API::get()->param()->vr;

    try {
        // if the controllers are not active, the xinput cb is not triggered.
        // normally we want the xinput cb to prepare vars as it's the first cb to be called
        // but if it wasn't called, we prepare them here
        if (!m_xinput_cb_processed) {
            if (!vr->is_runtime_ready())
                return;

            prepare_pointers();
            prepare_state(vr);
        }
        else {
            // reset for next cb iteration
            m_xinput_cb_processed = false;
        }
    }
    catch (...) {
        API::get()->log_error("[pre_engine_tick] Prepare pointers / state");
    }

    try {
        handle_level_change(vr);
    }
    catch (...) {
        API::get()->log_error("[pre_engine_tick] Level Change Handler");
    }

    try {
        if (m_vr_hud != nullptr) {
            m_vr_hud->handle_mod_events(&m_mod_events);
            m_vr_hud->process_vr_hud();
        }
    }
    catch (...) {
        API::get()->log_error("[pre_engine_tick] VR HUD Handler");
    }

    handle_mod_events();

    try {
        m_gamepad_left_thumb.add_delta(delta);

        fix_weapon_materials();
        fix_weapon_ironsights_offset();
        handle_native_fix(vr);
        handle_vr_view(vr);
        handle_crouch(vr);

        //is_interactable_in_range();
        //modify_interactables_in_range();
        //get_interactables();
        //fix_player_character_materials();
        //update_character_animation(delta);
        //fix_player_materials();
        //handle_weapon_change();
        //update_wirsts_location(vr);
        //update_arms_wirsts_location(vr);
    }
    catch (...) {
        API::get()->log_error("[pre_engine_tick] Handlers");
    }

    // calculate cb duration
    if (m_ui_option_show_debug_view && m_cb_calls_count == 0) {
        std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
        m_ui_pre_engine_tick_duration = static_cast<int>(std::chrono::duration_cast<std::chrono::microseconds>(end_time - begin_time).count());
    }
}

// -------------------------------------------------------------------------------------
// pointers and state
// -------------------------------------------------------------------------------------
void OuterWorldsPlugin::prepare_pointers() {
    try {
        // world
        m_world = SDK::UWorld::GetWorld();
   
        // character
        m_player_character = SDK::AIndianaPlayerCharacter::GetIndianaPC();
    
        // controller, UI, HUD
        m_player_controller = SDK::AIndianaPlayerController::GetIndianaPlayerController();
    
        if (m_player_controller != nullptr) {
            m_ui = SDK::UIndianaUIFunctionLibrary::GetIndianaUI(&m_reusable_branches, m_player_controller);
            if (m_ui != nullptr) {
                m_hud = m_ui->GetHUD();
            }
        }
        else {
            m_ui = nullptr;
        }

        // these pointers can be null
        if (m_vr_hud != nullptr) {
            m_vr_hud->set_pointers(m_world, m_player_character, m_hud);
        }
    }
    catch (...) {
        API::get()->log_error("[prepare_pointers] Exception");
        return;
    }
}

// sets state vars, so we can use them later in handlers
bool OuterWorldsPlugin::prepare_state(const UEVR_VRData* vr) {
    try {
        // pawn
        m_pawn.set_value(m_world != nullptr ? SDK::UGameplayStatics::GetPlayerPawn(m_world, 0) : nullptr);

        // level
        m_level.set_value(m_world != nullptr ? m_world->PersistentLevel : nullptr);

        // pause
        m_is_game_paused.set_value(m_world != nullptr ? SDK::UGameplayStatics::IsGamePaused(m_world) : true);

        if (m_player_character != nullptr) {
            // equipped weapon
            auto equipment = static_cast<SDK::AIndianaPlayerCharacter_BP_C*>(m_player_character)->Equipment;
            if (equipment != nullptr) {
                SDK::UWeapon* weapon = equipment->GetEquippedWeapon();
                m_equipped_weapon.set_value(weapon);
            }

            // conversation camera
            m_is_conversation_camera_active.set_value(m_player_character->ConversationCameraComponent->CameraComponent->IsActive());

            // is crouched
            m_is_crouched.set_value(m_player_character->bIsCrouched);
        }

        if (m_ui != nullptr) {
            // ledger
            auto ledger_widget = m_ui->GetUserWidget(&m_reusable_branches, m_ui->LedgerWidgetClass);
            m_ui_ledger_open_state.set_value(m_reusable_branches == SDK::ECheckBranches::Valid ? ledger_widget->GetOpenState() : SDK::EWidgetOpenState::Minimized);

            // conversation
            auto conversation_widget = m_ui->GetUserWidget(&m_reusable_branches, m_ui->ConversationWidgetClass);
            m_ui_conversation_open_state.set_value(m_reusable_branches == SDK::ECheckBranches::Valid ? conversation_widget->GetOpenState() : SDK::EWidgetOpenState::Minimized);

            // computer terminal - not used (instead checking conversation camera)
            auto computer_terminal = m_ui->GetUserWidget(&m_reusable_branches, m_ui->ComputerTerminalWidgetClass);
            m_ui_computer_terminal_open_state.set_value(m_reusable_branches == SDK::ECheckBranches::Valid ? computer_terminal->GetOpenState() : SDK::EWidgetOpenState::Minimized);

            // workbench
            auto workbench = m_ui->GetUserWidget(&m_reusable_branches, m_ui->WorkbenchClass);
            m_ui_workbench_open_state.set_value(m_reusable_branches == SDK::ECheckBranches::Valid ? workbench->GetOpenState() : SDK::EWidgetOpenState::Minimized);
        }
    }
    catch (...) {
        API::get()->log_error("[prepare_state] Exception");
        return false;
    }

    return true;
}


// -------------------------------------------------------------------------------------
// handlers
// -------------------------------------------------------------------------------------


void OuterWorldsPlugin::handle_mod_events() {
    try {
        if (m_mod_events.contains(MOD_EVENT_ENABLE_WORLD_RENDERING)) {
            if (m_world != nullptr) {
                API::get()->log_warn("[handle_mod_events] SetEnableWorldRendering");
                SDK::UGameplayStatics::SetEnableWorldRendering(m_world, true);
                m_mod_events.extract(MOD_EVENT_ENABLE_WORLD_RENDERING);
            }
        }
    }
    catch (...) {
        API::get()->log_error("[handle_mod_events] Exception");
    }
}

void OuterWorldsPlugin::handle_crouch(const UEVR_VRData* vr) {
    if (m_is_crouched.has_changed()) {
        reset_height(vr);
    }
}


bool OuterWorldsPlugin::is_interactable_in_range() {
    try {
        if (m_player_character != nullptr) {
            for (auto component : m_player_character->InteractionComponent->InteractablesInRange) {
                if (component->Outer != nullptr) {
                    // take non character components
                    if (!SDK::UKismetMathLibrary::ClassIsChildOf(component->Outer->Class, SDK::AIndianaPlayerCharacter::StaticClass())) {
                        m_is_interactable_in_range.set_value(true);
                        return true;
                    }
                }
            }
            m_is_interactable_in_range.set_value(false);
            //return false;
        }
        m_is_interactable_in_range.set_value(false);
        return false;
    }
    catch (...) {
        API::get()->log_error("[is_interactable_in_range] Exception");
        return false;
    }
}

void OuterWorldsPlugin::fix_cinematic_camera() {
    try {
        if (m_player_character != nullptr) {
            m_player_character->ConversationCameraComponent->ComputerTerminalLocationInterpSpeed = 0.001f;
            m_player_character->ConversationCameraComponent->ComputerTerminalRotationInterpSpeed = 0.001f;
            m_player_character->ConversationCameraComponent->ConversationLocationInterpSpeed = 0.001f;
            m_player_character->ConversationCameraComponent->ConversationRotationInterpSpeed = 0.001f;
        }
        else {
            API::get()->log_error("[fix_cinematic_camera] m_player_character = nullptr");
        }
    }
    catch (...) {
        API::get()->log_error("[fix_cinematic_camera] Exception");
    }
}


bool OuterWorldsPlugin::modify_interactables_in_range() {
    try {
        if (m_player_character != nullptr) {
            for (auto component : m_player_character->InteractionComponent->InteractablesInRange) {
                if (component->Outer != nullptr) {
                    // take non character components
                    //if (!SDK::UKismetMathLibrary::ClassIsChildOf(component->Outer->Class, SDK::AIndianaPlayerCharacter::StaticClass())) {
                    //    if (component->GetAttachParent() != nullptr) {
                    //        component->GetAttachParent()->SetShouldUpdatePhysicsVolume(true);
                    //        for (auto child_component : m_player_character->InteractionComponent->InteractablesInRange) {
                    //    }
                    //    if (compone)
                    //}

                    if (SDK::UKismetMathLibrary::ClassIsChildOf(component->Outer->Class, SDK::APickup::StaticClass())) {
                        //static_cast<SDK::APickup*>(component->Outer)->SetupDropPhysics();
                        static_cast<SDK::APickup*>(component->Outer)->SetActorEnableCollision(true);
                        auto sm_component = static_cast<SDK::APickup*>(component->Outer)->GetComponentByClass(SDK::UStaticMeshComponent::StaticClass());
                        if (sm_component != nullptr) {
                            static_cast<SDK::UStaticMeshComponent*>(sm_component)->SetCollisionEnabled(SDK::ECollisionEnabled::QueryAndPhysics);
                            static_cast<SDK::UStaticMeshComponent*>(sm_component)->SetCollisionObjectType(SDK::ECollisionChannel::ECC_WorldStatic);
                            static_cast<SDK::UStaticMeshComponent*>(sm_component)->SetCollisionResponseToAllChannels(SDK::ECollisionResponse::ECR_Block);
                            /*static_cast<SDK::UStaticMeshComponent*>(sm_component)->SetCollisionResponseToChannel(SDK::ECollisionChannel::ECC_WorldStatic, SDK::ECollisionResponse::ECR_Block);
                            static_cast<SDK::UStaticMeshComponent*>(sm_component)->SetCollisionResponseToChannel(SDK::ECollisionChannel::ECC_WorldDynamic, SDK::ECollisionResponse::ECR_Block);*/
                            static_cast<SDK::UStaticMeshComponent*>(sm_component)->SetAllMassScale(0.4f);
                            static_cast<SDK::UStaticMeshComponent*>(sm_component)->SetSimulatePhysics(true);
                            static_cast<SDK::UStaticMeshComponent*>(sm_component)->SetEnableGravity(true);
                            static_cast<SDK::UStaticMeshComponent*>(sm_component)->AddImpulse(SDK::FVector{ 0.f, 10.f, 10.f }, SDK::FName(), true);

                        }
                    }
                }
            }
            m_is_interactable_in_range.set_value(false);
            //return false;
        }
        m_is_interactable_in_range.set_value(false);
        return false;
    }
    catch (...) {
        API::get()->log_error("[modify_interactables_in_range] Exception");
        return false;
    }
}

void OuterWorldsPlugin::handle_hud() {
    if (m_hud != nullptr) {
        m_hud->AmmoReadout->SetVisibility(SDK::ESlateVisibility::Hidden);
    }
}

void OuterWorldsPlugin::handle_vr_view(const UEVR_VRData* vr) {
    try {
        if (m_pawn.has_changed()) {
            // main menu, character creation
            if (m_pawn.value == nullptr || (m_pawn.value != nullptr && m_pawn.value->IsA(SDK::ADefaultPawn::StaticClass())) ) {
                API::get()->log_warn("[handle_vr_view] Entering Main Menu - NULL Pawn or Default Pawn");
                vr->set_aim_method(0);
                vr->set_mod_value("VR_RoomscaleMovement", "false");
                API::UObjectHook::set_disabled(true);
                vr->recenter_view();
                return;
            }
            else {
                API::get()->log_warn("[handle_vr_view] Leaving Main Menu - PlayerCharacter Pawn");
                vr->set_aim_method(2);
                vr->set_mod_value("VR_RoomscaleMovement", "true");
                API::UObjectHook::set_disabled(false);
                vr->recenter_view();
                return;
            }
        }

        // makes ledger background black
        if (m_ui_ledger_open_state.has_changed()) {
            // opening ledger
            if (m_ui_ledger_open_state.value == SDK::EWidgetOpenState::TransitioningToMaximized) {
                API::get()->log_warn("[handle_vr_view] Opening Ledger");
                SDK::UGameplayStatics::SetEnableWorldRendering(m_world, false);
                return;
            }
            else if (m_ui_ledger_open_state.value == SDK::EWidgetOpenState::Maximized) {
                API::get()->log_warn("[handle_vr_view] Ledger Opened");
                vr->set_mod_value("VR_NativeStereoFix", "false");
                vr->set_aim_method(0);
                vr->set_decoupled_pitch_enabled(true);
                vr->set_mod_value("VR_RoomscaleMovement", "false");
                vr->set_mod_value("UI_Y_Offset", "-0.30000");
                SDK::UGameplayStatics::SetEnableWorldRendering(m_world, true);
                return;
            }
            else {
                API::get()->log_warn("[handle_vr_view] Ledger Closing / Closed");
                SDK::UGameplayStatics::SetEnableWorldRendering(m_world, true);
                vr->set_mod_value("VR_NativeStereoFix", "true");
                vr->set_aim_method(2);
                vr->set_decoupled_pitch_enabled(true);
                vr->set_mod_value("VR_RoomscaleMovement", "true");
                vr->set_mod_value("UI_Y_Offset", "0.00000");
                return;
            }
        }

        // makes workbench background black
        if (m_ui_workbench_open_state.has_changed()) {
            // opening workbench
            if (m_ui_workbench_open_state.value == SDK::EWidgetOpenState::TransitioningToMaximized) {
                API::get()->log_warn("[handle_vr_view] Opening Workbench");
                SDK::UGameplayStatics::SetEnableWorldRendering(m_world, false);
                return;
            }
            else if (m_ui_workbench_open_state.value == SDK::EWidgetOpenState::Maximized) {
                API::get()->log_warn("[handle_vr_view] Workbench Opened");
                SDK::UGameplayStatics::SetEnableWorldRendering(m_world, false);
                vr->set_mod_value("VR_NativeStereoFix", "false");
                vr->set_aim_method(0);
                vr->set_decoupled_pitch_enabled(true);
                vr->set_mod_value("VR_RoomscaleMovement", "false");
                vr->set_mod_value("UI_Y_Offset", "-0.30000");
                m_mod_events.insert(MOD_EVENT_ENABLE_WORLD_RENDERING);
                return;
            }
            else {
                API::get()->log_warn("[handle_vr_view] Workbench Closing / Closed");
                SDK::UGameplayStatics::SetEnableWorldRendering(m_world, true);
                vr->set_mod_value("VR_NativeStereoFix", "true");
                vr->set_aim_method(2);
                vr->set_decoupled_pitch_enabled(true);
                vr->set_mod_value("VR_RoomscaleMovement", "true");
                vr->set_mod_value("UI_Y_Offset", "0.00000");
                return;
            }
        }

        if (m_is_conversation_camera_active.enabled()) {
            API::get()->log_warn("[handle_vr_view] Conversation Camera Enabled");
            vr->set_aim_method(0);
            API::UObjectHook::set_disabled(true);
            vr->recenter_view();
            vr->set_mod_value("UI_Distance", "1.400000");
            vr->set_mod_value("UI_Size", "1.000000");


            // apply offset for computer terminals
            if (m_ui_conversation_open_state.value == SDK::EWidgetOpenState::Minimized) {
                vr->set_mod_value("VR_CameraForwardOffset", "-25.000000");
                vr->set_mod_value("VR_CameraUpOffset", "15.000000");
            }
            return;
        }

        if (m_is_conversation_camera_active.disabled()) {
            API::get()->log_warn("[handle_vr_view] Conversation Camera Disabled");
            vr->set_aim_method(2);
            API::UObjectHook::set_disabled(false);
            vr->set_mod_value("VR_CameraForwardOffset", "0.000000");
            vr->set_mod_value("VR_CameraUpOffset", "0.000000");

            vr->set_mod_value("UI_Distance", "2.000000");
            vr->set_mod_value("UI_Size", "1.200000");
            show_ability_overview(false);
            return;
        }

        // pause menu
        if (m_is_game_paused.enabled()) {
            API::get()->log_warn("[handle_vr_view] Entering Pause Menu");
            vr->set_aim_method(0);
            vr->set_mod_value("VR_RoomscaleMovement", "false");
            vr->set_mod_value("VR_RenderingMethod", "1");
            //API::UObjectHook::set_disabled(true);
            //vr->recenter_view();
        }
        else if (m_is_game_paused.disabled()) {
            API::get()->log_warn("[handle_vr_view] Leaving Pause Menu");
            vr->set_aim_method(2);
            vr->set_mod_value("VR_RoomscaleMovement", "true");
            //vr->set_mod_value("VR_RenderingMethod", "0");
            //API::UObjectHook::set_disabled(false);
        }
        else if (!m_is_game_paused.has_changed() && m_is_game_paused.value) {
            vr->set_mod_value("VR_RenderingMethod", "0");
        }
    }
    catch (...) {
        API::get()->log_error("[handle_vr_view] Exception");
    }
}

void OuterWorldsPlugin::show_ability_overview(bool visible) {
    if (m_hud != nullptr) {
        m_hud->AbilityOverviewGamepad->SetVisibility(visible ? SDK::ESlateVisibility::Visible : SDK::ESlateVisibility::Hidden);
        m_hud->AbilityOverview->SetVisibility(visible ? SDK::ESlateVisibility::Visible : SDK::ESlateVisibility::Hidden);
    }
}

// not used
void OuterWorldsPlugin::handle_weapon_change() {
    if (m_equipped_weapon.has_changed() && m_equipped_weapon.value) {
        API::get()->log_warn("Equipped Weapon: %s", m_equipped_weapon.value->GetFullName().c_str());

    }
}

void OuterWorldsPlugin::handle_level_change(const UEVR_VRData* vr) {
    try {
        if (m_level.has_changed()) {

            if (m_level.value == nullptr) {
                return;
            }

            m_foreground_priority_fname = SDK::UKismetStringLibrary::Conv_StringToName(L"ForegroundPriorityEnabled");

            const UEVR_SDKData* sdk = API::get()->sdk();
            auto level_name = m_level.value->GetFullName();

            API::get()->log_warn("New Level: %s", level_name.c_str());

            API::get()->log_warn("Fixing Materials");
            fix_player_character_materials();
            API::get()->log_warn("Setting Camera IDLE time");
            set_idle_camera_time(1000);
            fix_player_highlighter();
            fix_cinematic_camera();
            //// check if it's the main menu
            //if (level_name.ends_with(".00_Menu.PersistentLevel")) {
            //}
            //else {
            //    // initialize hud
            //    m_mod_events.insert(MOD_EVENT_VR_HUD_INITIALIZE);

            //    vr->set_aim_method(2);
            //    vr->set_snap_turn_enabled(true);
            //    vr->set_decoupled_pitch_enabled(true);
            //    vr->set_mod_value("VR_RoomscaleMovement", "true");
            //    API::UObjectHook::set_disabled(false);
            //}

            // schedule vr hud init as level change has destroyed our custom actors
            API::get()->log_warn("Inserting Event: MOD_EVENT_VR_HUD_INITIALIZE");
            m_mod_events.insert(MOD_EVENT_VR_HUD_INITIALIZE);

            vr->set_aim_method(2);
            vr->set_decoupled_pitch_enabled(true);
            vr->set_mod_value("VR_RoomscaleMovement", "true");
            vr->set_mod_value("UI_Distance", "2.000000");
            vr->set_mod_value("UI_Size", "1.200000");
            API::UObjectHook::set_disabled(false);
            reset_height(vr);

            if (m_pawn.value != nullptr && !m_pawn.value->IsA(SDK::ADefaultPawn::StaticClass())) {
                if (m_config->m_cfg_option_auto_pause_daytime) {
                    pause_daytime(true);
                }
            }

        }
    }
    catch (...) {
        API::get()->log_error("[handle_level_change] Exception");
    }
}

// handles controller state based on game context
void OuterWorldsPlugin::handle_controller_input(XINPUT_STATE* state, const UEVR_VRData* vr) {
    m_gamepad_btn_a.set_state(state);
    //m_gamepad_btn_x.set_state(state);
    //m_gamepad_btn_b.set_state(state);
    //m_gamepad_btn_y.set_state(state);
    //m_gamepad_right_shoulder.set_state(state);
    //m_gamepad_left_shoulder.set_state(state);
    //m_gamepad_right_thumb.set_state(state);
    m_gamepad_left_thumb.set_state(state);
    //m_gamepad_trigger_right.set_state(state);
    //m_gamepad_trigger_left.set_state(state);


    if (m_gamepad_left_thumb.is_long_pressed(2.f)) {
        cycle_native_fix();
    }
}

// -------------------------------------------------------------------------------------
// Utils
// -------------------------------------------------------------------------------------

void OuterWorldsPlugin::pause_daytime(bool pause) {
    try {
        if (m_player_character != nullptr && m_player_character->IsA(SDK::AIndianaPlayerCharacter_BP_C::StaticClass())) {
            API::get()->log_warn("[pause_daytime] Searching for DynamicTOD");

            auto class_ptr = API::get()->find_uobject<API::UClass>(L"BlueprintGeneratedClass /Game/Materials/Lighting/DynamicSystem/BP_DynamicTOD.BP_DynamicTOD_C");
            if (class_ptr != nullptr) {
                API::get()->log_warn("[pause_daytime] BP_DynamicTOD Class found");
                std::vector<SDK::UObject*> matching_objects = class_ptr->get_objects_matching<SDK::UObject>();

                for (size_t i = 0; i < matching_objects.size(); i++) {
                    if (matching_objects[i]->IsA(SDK::ABP_DynamicTOD_C::StaticClass())) {
                        API::get()->log_warn("[pause_daytime] BP_DynamicTOD Object found, changing params");
                        static_cast<SDK::ABP_DynamicTOD_C*>(matching_objects[i])->PrimaryActorTick.TickInterval = pause ? 9999999.f : 0.f;
                    }
                }
            }
        }

        cycle_native_fix();
        m_is_paused_daytime = pause;
    }
    catch (...) {
        API::get()->log_error("[pause_daytime] Exception");
    }
}

// turn native fix off, then wait a few ticks an turn it on
void OuterWorldsPlugin::cycle_native_fix() {
    API::get()->log_warn("[cycle_native_fix] Cycling...");
    if (m_toggle_native_fix_counter == -1) {
        m_toggle_native_fix_counter = 30;
    }
}

void OuterWorldsPlugin::handle_native_fix(const UEVR_VRData* vr) {
    try {
        if (m_toggle_native_fix_counter > 0) {
            m_toggle_native_fix_counter--;
        }

        if (m_toggle_native_fix_counter == 9) {
            vr->set_mod_value("VR_NativeStereoFix", "false");
            API::get()->log_warn("[toggle_native_fix] OFF");
        }

        if (m_toggle_native_fix_counter == 0) {
            vr->set_mod_value("VR_NativeStereoFix", "true");
            API::get()->log_warn("[toggle_native_fix] ON");
            m_toggle_native_fix_counter = -1;
        }
    }
    catch (...) {
        API::get()->log_error("[toggle_native_fix] Exception");
    }
}

void OuterWorldsPlugin::set_player_mesh_visibility(bool value) {
    if (m_player_character != nullptr) {
        m_player_character->Mesh->SetVisibility(false, false);

        for (auto child : m_player_character->Mesh->AttachChildren) {
            if (child->IsA(SDK::USkeletalMeshComponent::StaticClass())) {
                static_cast<SDK::USkeletalMeshComponent*>(child)->SetVisibility(value, value);
            }
        }
    }
}

void OuterWorldsPlugin::set_arms_mesh_visibility(bool value) {
    if (m_player_character != nullptr) {
        m_player_character->FPVMesh->SetVisibility(value, value);
    }
}

void OuterWorldsPlugin::fix_weapon_materials() {
    try {
        if (m_equipped_weapon.value != nullptr && m_equipped_weapon.value->SkeletalMeshComponent != nullptr) {
            // main weapon components
            for (auto material : m_equipped_weapon.value->SkeletalMeshComponent->OverrideMaterials) {
                if (material->IsA(SDK::UMaterialInstanceDynamic::StaticClass())) {
                    static_cast<SDK::UMaterialInstanceDynamic*>(material)->SetScalarParameterValue(m_foreground_priority_fname, 0.f);
                    //static_cast<SDK::UMaterialInstanceDynamic*>(material)->GetBaseMaterial()->BlendMode = SDK::EBlendMode::BLEND_Additive;
                }
            }

            for (auto child : m_equipped_weapon.value->SkeletalMeshComponent->AttachChildren) {
                // weapon modifications
                if (child->IsA(SDK::UStaticMeshComponent::StaticClass())) {
                    for (auto material : static_cast<SDK::UStaticMeshComponent*>(child)->OverrideMaterials) {
                        if (material->IsA(SDK::UMaterialInstanceDynamic::StaticClass())) {
                            static_cast<SDK::UMaterialInstanceDynamic*>(material)->SetScalarParameterValue(m_foreground_priority_fname, 0.f);
                            //static_cast<SDK::UMaterialInstanceDynamic*>(material)->GetBaseMaterial()->BlendMode = SDK::EBlendMode::BLEND_Additive;
                        }
                    }
                }

                // niagara effects
                if (child->IsA(SDK::UNiagaraComponent::StaticClass())) {
                    static_cast<SDK::UNiagaraComponent*>(child)->SetNiagaraVariableFloat(L"ForegroundPriorityEnabled", 0.f);
                }
            }
            //m_equipped_weapon.value->SkeletalMeshComponent->SetCollisionEnabled(SDK::ECollisionEnabled::QueryAndPhysics);
            //m_equipped_weapon.value->SkeletalMeshComponent->SetCollisionResponseToAllChannels(SDK::ECollisionResponse::ECR_Block);
        }
    }
    catch (...) {
        API::get()->log_error("[PRE_ENGINE_TICK][fix_weapon_materials] Exception");
    }
}

void OuterWorldsPlugin::fix_weapon_ironsights_offset() {
    try {
        if (m_equipped_weapon.value != nullptr && m_equipped_weapon.value->SkeletalMeshComponent != nullptr && is_vr_hud_valid()) {
            // get barrel transform
            auto offset_transform = m_equipped_weapon.value->SkeletalMeshComponent->GetSocketTransform(
                SDK::UKismetStringLibrary::Conv_StringToName(L"MuzzleFlashSocket"), SDK::ERelativeTransformSpace::RTS_Component
            );
            const UEVR_Vector3f offset{ 0.f, -offset_transform.Translation.Z, 0.f };
            m_vr_hud->set_particle_pointer_offset({ 0.f, 0.f, offset_transform.Translation.Z });

            API::UObjectHook::get_or_add_motion_controller_state((API::UObject*)m_player_character->FPVCamera)->set_location_offset(&offset);
        }
    }
    catch (...) {
        API::get()->log_error("[fix_weapon_ironsights_offset] Exception");
    }
}

void OuterWorldsPlugin::fix_player_highlighter() {
    try {
        if (m_player_character != nullptr && m_player_character->IsA(SDK::AIndianaPlayerCharacter_BP_C::StaticClass())) {
            API::get()->log_warn("[fix_highlighter] Searching for PlayerHightlightComponent");

            auto class_ptr = API::get()->find_uobject<API::UClass>(L"BlueprintGeneratedClass /Game/Blueprints/Player/PlayerHighlightComponent.PlayerHighlightComponent_C");
            if (class_ptr != nullptr) {
                API::get()->log_warn("[fix_highlighter] PlayerHighlightComponent Class found");
                std::vector<SDK::UObject*> matching_objects = class_ptr->get_objects_matching<SDK::UObject>();

                for (size_t i = 0; i < matching_objects.size(); i++) {
                    if (matching_objects[i]->IsA(SDK::UPlayerHighlightComponent_C::StaticClass())) {
                        API::get()->log_warn("[fix_highlighter] PlayerHighlightComponent Object found, changing params");
                        static_cast<SDK::UPlayerHighlightComponent_C*>(matching_objects[i])->PostProcessDynamicMaterial->SetScalarParameterValue(
                            SDK::UKismetStringLibrary::Conv_StringToName(L"OutlineThickness"), 0.5f
                        );
                        static_cast<SDK::UPlayerHighlightComponent_C*>(matching_objects[i])->PostProcessDynamicMaterial->SetScalarParameterValue(
                            SDK::UKismetStringLibrary::Conv_StringToName(L"OutlineBrightness"), 1.0f
                        );
                    }
                }
            }
        }
    }
    catch (...) {
        API::get()->log_error("[fix_highlighter] Exception");
    }
}

void OuterWorldsPlugin::fix_player_character_materials() {
    if (m_player_character != nullptr) {
        auto foreground_priority_uevr = API::FName(L"ForegroundPriorityEnabled", API::FName::EFindName::Find);
        m_foreground_priority_fname.ComparisonIndex = foreground_priority_uevr.comparison_index;
        m_foreground_priority_fname.Number = foreground_priority_uevr.number;

        //auto foreground_priority = SDK::FName("ForegroundPriorityEnabled", API::FName::EFindName::Find);

        if (m_foreground_priority_fname.ComparisonIndex == 0) {
            return;
        }

        // arms mesh fix
        for (auto material : m_player_character->FPVMesh->OverrideMaterials) {
            if (material->IsA(SDK::UMaterialInstanceDynamic::StaticClass())) {
                static_cast<SDK::UMaterialInstanceDynamic*>(material)->SetScalarParameterValue(m_foreground_priority_fname, 0.f);
            }
        }

        // main components
        for (auto material : m_player_character->Mesh->OverrideMaterials) {
            if (material->IsA(SDK::UMaterialInstanceDynamic::StaticClass())) {
                static_cast<SDK::UMaterialInstanceDynamic*>(material)->SetScalarParameterValue(m_foreground_priority_fname, 0.f);
            }
        }

        // child components
        for (auto child : m_player_character->Mesh->AttachChildren) {
            if (child->IsA(SDK::USkeletalMeshComponent::StaticClass())) {
                for (auto material : static_cast<SDK::USkeletalMeshComponent*>(child)->OverrideMaterials) {
                    if (material->IsA(SDK::UMaterialInstanceDynamic::StaticClass())) {
                        static_cast<SDK::UMaterialInstanceDynamic*>(material)->SetScalarParameterValue(m_foreground_priority_fname, 0.f);
                    }
                }
            }
        }
    }
}

void OuterWorldsPlugin::update_camera(const UEVR_VRData* vr) {
    if (vr->is_using_controllers()) {
        if (m_player_character != nullptr) {
            auto camera = m_player_character->FPVCamera;
            if (camera != nullptr && is_vr_hud_valid()) {
                SDK::FHitResult h_res;
                auto rh_location = m_vr_hud->get_rh_controller()->K2_GetComponentLocation();
                auto rh_rotation = m_vr_hud->get_rh_controller()->K2_GetComponentRotation();

                camera->K2_SetWorldLocationAndRotation(rh_location, rh_rotation, false, &h_res, false);
            }
        }
    }
}


/*
Mesh->AnimScriptInstance->AnimGraphNode_TwoBoneIK (r_wirst_JNT) :
- AlphaScaleBias.Bias = 1.0f
- EffectorLocation (Vector)
- EffectorLocationSpace  (SDK::EBoneControlSpace::BCS_WorldSpace)

AnimGraphNode_TwoBoneIK_1 (l_wirst_JNT) :
*/

void OuterWorldsPlugin::attach_animation() {
    if (m_player_character != nullptr) {
        m_player_character->Mesh->SetVisibility(true, true);
        m_player_character->Mesh->SetAnimationMode(SDK::EAnimationMode::AnimationBlueprint);
        m_player_character->Mesh->SetAnimClass(SDK::UTPV_AnimBP_C::StaticClass());
        //m_player_character->Mesh->SetAnimClass(SDK::UFPV_AnimBP2_C::StaticClass());

        //m_player_character->Mesh->SetVisibility(true, false);
        /*auto anim_inst = m_player_character->Mesh->GetAnimInstance();
        anim_inst->BlueprintInitializeAnimation();*/
        //anim_inst->BlueprintBeginPlay();
        //m_player_character->Mesh->SetPlayRate(1.f);
    }
}

void OuterWorldsPlugin::update_character_animation(float delta) {
    if (m_player_character != nullptr) {
        auto anim_inst = m_player_character->Mesh->GetAnimInstance();
        if (anim_inst != nullptr) {
            anim_inst->BlueprintUpdateAnimation(delta);

        }
    }
}


void OuterWorldsPlugin::manipulate_animation() {
    if (m_player_character != nullptr) {
        m_player_character->Mesh->SetAnimationMode(SDK::EAnimationMode::AnimationBlueprint);

        auto anim_inst = m_player_character->Mesh->GetAnimInstance();
        anim_inst->BlueprintInitializeAnimation();
        anim_inst->BlueprintBeginPlay();
        m_player_character->Mesh->SetPlayRate(10.f);
    }
}


// error
void OuterWorldsPlugin::set_personality() {
    if (m_player_character != nullptr) {
        SDK::UTPV_AnimBP_C* anim_inst = (SDK::UTPV_AnimBP_C*)m_player_character->Mesh->GetAnimInstance();
        if (anim_inst != nullptr && anim_inst->IsA(SDK::UTPV_AnimBP_C::StaticClass())) {
            //anim_inst->ResetEmotionToDefault();
            /*anim_inst->AnimNotify_ResetLocomotionState();
            anim_inst->ClearCurrentEmotion();
            anim_inst->SetPersonality(anim_inst->DefaultPersonality->GetDefaultObj());
            anim_inst->UpdatePersonalityAnims();*/
            
            auto class_ptr = API::get()->find_uobject<API::UClass>(L"BlueprintGeneratedClass /Game/Blueprints/CHAR/TPVLocomotionAnimationSet.TPVLocomotionAnimationSet_C");
            if (class_ptr != nullptr) {
                std::vector<SDK::UTPVLocomotionAnimationSet_C*> objects_matching = class_ptr->get_objects_matching<SDK::UTPVLocomotionAnimationSet_C>();
                for (size_t i = 0; i < objects_matching.size(); i++) {
                    std::string obj_name = objects_matching[i]->GetFullName();
                    API::get()->log_warn("Found Animation Set: %s", obj_name.c_str());
                    if (obj_name.ends_with(".Default_LngGn_Personality")) {
                    //if (obj_name.ends_with(".Default_unarmed_Personality")){
                        API::get()->log_warn("Setting Personality: %s", obj_name.c_str());
                        //anim_inst->SetPersonality(objects_matching[i]->GetDefaultObj());
                        anim_inst->LocomotionAnimationSet=objects_matching[i];
                        anim_inst->DefaultPersonality = objects_matching[i];
                        anim_inst->CurrentPersonality = objects_matching[i];

                        anim_inst->UpdateAnimationParams();
                        anim_inst->UpdateRunAnims();
                    }
                }
            }


            /*auto anim_set = SDK::UTPVLocomotionAnimationSet_C::GetDefaultObj();
            if (anim_set != nullptr) {
                static_cast<SDK::UTPV_AnimBP_C*>(anim_inst)->SetPersonality(SDK::UTPVLocomotionAnimationSet_C::GetDefaultObj());
            }
            else {
                API::get()->log_warn("set_personality : no DCO");
            }*/

        }
    }
}


void OuterWorldsPlugin::attach_controllers_to_wirsts() {
    if (m_player_character != nullptr) {
        //auto anim_inst = m_player_character->Mesh->GetAnimInstance();
        //if (anim_inst != nullptr && anim_inst->IsA(SDK::UTPV_AnimBP_C::StaticClass())) {
        //    static_cast<SDK::UTPV_AnimBP_C*>(anim_inst)->AnimGraphNode_TwoBoneIK.AlphaScaleBias.Bias = 1.0f;
        //    static_cast<SDK::UTPV_AnimBP_C*>(anim_inst)->AnimGraphNode_TwoBoneIK.EffectorLocationSpace = SDK::EBoneControlSpace::BCS_WorldSpace;

        //    static_cast<SDK::UTPV_AnimBP_C*>(anim_inst)->AnimGraphNode_TwoBoneIK_1.AlphaScaleBias.Bias = 1.0f;
        //    static_cast<SDK::UTPV_AnimBP_C*>(anim_inst)->AnimGraphNode_TwoBoneIK_1.EffectorLocationSpace = SDK::EBoneControlSpace::BCS_WorldSpace;

        //    auto socket_fname = API::FName(L"LngGn_Equip_Socket", API::FName::EFindName::Find);
        //    SDK::FName sdk_socket_fname{
        //        .ComparisonIndex = socket_fname.comparison_index,
        //        .Number = socket_fname.number
        //    };

        //    //static_cast<SDK::UTPV_AnimBP_C*>(anim_inst)->AnimGraphNode_TwoBoneIK.EffectorTarget.SocketReference = SDK::FSocketReference()

        //    //m_player_character->Mesh->K2_AttachToComponent(wandMeshParent, wandMeshAttachSocketName, 0, 0, 0, false)
        //    m_wirsts_attached = true;
        //}
    }
}

void OuterWorldsPlugin::update_wirsts_location(const UEVR_VRData* vr) {
    if (m_wirsts_attached) {
        if (m_player_character != nullptr) {
            auto anim_inst = m_player_character->Mesh->GetAnimInstance();
            if (anim_inst != nullptr && anim_inst->IsA(SDK::UTPV_AnimBP_C::StaticClass())) {
                if (vr->is_using_controllers()) {
                    auto rh_location = m_vr_hud->get_rh_controller()->K2_GetComponentLocation();
                    auto lh_location = m_vr_hud->get_lh_controller()->K2_GetComponentLocation();
                    /*UEVR_Vector3f right_hand_position{};
                    UEVR_Quaternionf right_hand_rotation{};
                    vr->get_grip_pose(vr->get_right_controller_index(), (UEVR_Vector3f*)&right_hand_position, (UEVR_Quaternionf*)&right_hand_rotation);*/

                    //m_player_character->Mesh->BodyInstance
                    //static_cast<SDK::UTPV_AnimBP_C*>(anim_inst)->AnimGraphNode_TwoBoneIK.EffectorTarget.SocketReference
                    //static_cast<SDK::UTPV_AnimBP_C*>(anim_inst)->AnimGraphNode_TwoBoneIK.

                    //static_cast<SDK::UTPV_AnimBP_C*>(anim_inst)->CurrentSkeleton-

                    static_cast<SDK::UTPV_AnimBP_C*>(anim_inst)->AnimGraphNode_TwoBoneIK.EffectorLocation = SDK::FVector{ rh_location.X, rh_location.Y, rh_location.Z };
                    static_cast<SDK::UTPV_AnimBP_C*>(anim_inst)->AnimGraphNode_TwoBoneIK_1.EffectorLocation = SDK::FVector{ lh_location.X, lh_location.Y, lh_location.Z };
                }
            }

            //FRotator rotPelvis = Mesh->MeshGetInstance(this))->GetBoneRotation(FName(TEXT("pelvis")));

        }
    }
}


void OuterWorldsPlugin::attach_controllers_to_arms_wirsts() {
    if (m_player_character != nullptr) {
        auto anim_inst = m_player_character->FPVMesh->GetAnimInstance();
        if (anim_inst != nullptr && anim_inst->IsA(SDK::UFPV_AnimBP2_C::StaticClass())) {
            static_cast<SDK::UFPV_AnimBP2_C*>(anim_inst)->AnimGraphNode_TwoBoneIK.AlphaScaleBias.Bias = 1.0f;
            static_cast<SDK::UFPV_AnimBP2_C*>(anim_inst)->AnimGraphNode_TwoBoneIK.EffectorLocationSpace = SDK::EBoneControlSpace::BCS_WorldSpace;

            static_cast<SDK::UFPV_AnimBP2_C*>(anim_inst)->AnimGraphNode_TwoBoneIK_1.AlphaScaleBias.Bias = 1.0f;
            static_cast<SDK::UFPV_AnimBP2_C*>(anim_inst)->AnimGraphNode_TwoBoneIK_1.EffectorLocationSpace = SDK::EBoneControlSpace::BCS_WorldSpace;

            m_arms_wirsts_attached = true;
        }
    }
}

void OuterWorldsPlugin::update_arms_wirsts_location(const UEVR_VRData* vr) {
    if (m_arms_wirsts_attached) {
        if (m_player_character != nullptr) {
            auto anim_inst = m_player_character->FPVMesh->GetAnimInstance();
            if (anim_inst != nullptr && anim_inst->IsA(SDK::UFPV_AnimBP2_C::StaticClass())) {
                if (vr->is_using_controllers()) {
                    auto rh_location = m_vr_hud->get_rh_controller()->K2_GetComponentLocation();
                    auto lh_location = m_vr_hud->get_lh_controller()->K2_GetComponentLocation();

                    static_cast<SDK::UFPV_AnimBP2_C*>(anim_inst)->AnimGraphNode_TwoBoneIK.EffectorLocation = SDK::FVector{ rh_location.X, rh_location.Y, rh_location.Z };
                    static_cast<SDK::UFPV_AnimBP2_C*>(anim_inst)->AnimGraphNode_TwoBoneIK_1.EffectorLocation = SDK::FVector{ lh_location.X, lh_location.Y, lh_location.Z };
                }
            }
        }
    }
}

void OuterWorldsPlugin::set_mouse_cursor() {
    SDK::UUserWidget* widget = API::get()->find_uobject<SDK::UUserWidget>(
        L"GenericCrosshair_BP_C /Game/UI/HUD/Reticle/Reticle_BP.Reticle_BP_C.WidgetTree.Crosshair"
    );
    if (widget != nullptr) {
        m_player_controller->SetMouseCursorWidget(SDK::EMouseCursor::Hand, widget);
    }
    else {
        API::get()->log_warn("set_mouse_cursor : Widget not found");
    }

    m_player_controller->DefaultMouseCursor = SDK::EMouseCursor::Hand;
    m_player_controller->CurrentMouseCursor = SDK::EMouseCursor::Hand;
}

void OuterWorldsPlugin::set_idle_camera_time(float seconds_to_wait) {
    if (m_player_character != nullptr && m_player_character->IsA(SDK::AIndianaPlayerCharacter_BP_C::StaticClass())) {
        static_cast<SDK::AIndianaPlayerCharacter_BP_C*>(m_player_character)->IdleCamera->SecondsToWait = seconds_to_wait;
    }
}

bool OuterWorldsPlugin::is_vr_hud_valid() {
    return (m_vr_hud != nullptr) && (m_vr_hud->get_hud_state() == OuterWorldsVRHUDState::VR_HUD_SUCCESS);
}

void OuterWorldsPlugin::reset_height(const UEVR_VRData* vr, float offset_y) {
    UEVR_Vector3f origin{};
    vr->get_standing_origin(&origin);

    UEVR_Vector3f hmd_pos{};
    UEVR_Quaternionf hmd_rot{};
    vr->get_pose(vr->get_hmd_index(), &hmd_pos, &hmd_rot);

    origin.y = (hmd_pos.y) + offset_y;

    vr->set_standing_origin(&origin);
}


void OuterWorldsPlugin::test_func() {
}

void OuterWorldsPlugin::test_func2() {
}


// -------------------------------------------------------------------------------------
// ImGui
// -------------------------------------------------------------------------------------
void OuterWorldsPlugin::internal_frame() {
    if (!API::get()->param()->functions->is_drawing_ui()) {
        return;
    }

    static const auto UEVR_NAME = std::format("Outer Worlds UEVR plugin [rev. {}]", MOD_VERSION);
    static const auto NO_CHARACTER = std::format("No Player Character detected! Is it Main Menu?");
    static const auto NO_PAWN = std::format("No Pawn detected!");

    constexpr auto window_w = 500.0f;
    constexpr auto window_h = 500.0f;

    ImGui::SetNextWindowSize(ImVec2(window_w, window_h), ImGuiCond_::ImGuiCond_Once);

    if (ImGui::Begin(UEVR_NAME.c_str())) {
        ImGui::PushItemWidth(200);
        if (ImGui::Button("Save Configuration")) {
            if (m_config->save_plugin_config()) {
                ImGui::OpenPopup("succesful_save_popup");
            };
        };

        if (ImGui::BeginPopup("succesful_save_popup"))
        {
            ImGui::Text("Configuration Saved!");
            ImGui::EndPopup();
        }

        ImGui::SeparatorText("General options");
        if (m_config != nullptr) {
            if (ImGui::Button("Pause Daytime")) {
                pause_daytime(true);
            };

            ImGui::Checkbox("Auto Pause Daytime on Level Load", &(m_config->m_cfg_option_auto_pause_daytime));

            //ImGui::SeparatorText("Attachments");
            //ImGui::Checkbox("Ammo Readout", &(m_config->m_cfg_option_attach_ammo_readout));
            //ImGui::Checkbox("Character Overview", &(m_config->m_cfg_option_attach_character_overview));
            //ImGui::Checkbox("Compass", &(m_config->m_cfg_option_attach_compass));
            //ImGui::Checkbox("Item Degradation", &(m_config->m_cfg_option_attach_compass));
        }

        ImGui::PopItemWidth();

        ImGui::SeparatorText("Debugging");
        // game state section
        ImGui::Checkbox("Show debug", &m_ui_option_show_debug_view);

        if (m_ui_option_show_debug_view) {
            ImGui::BeginGroup();

            if (ImGui::Button("Test Function")) {
                test_func();
            }

            if (ImGui::Button("Test Function 2")) {
                test_func2();
            }

            //if (ImGui::Button("Attach Character Mesh Wirsts")) {
            //    attach_controllers_to_wirsts();
            //}

            //if (ImGui::Button("Attach Arms Mesh Wirsts")) {
            //    attach_controllers_to_arms_wirsts();
            //}

            //if (ImGui::Button("Attach Anim Class")) {
            //    attach_animation();
            //};

            //if (ImGui::Button("Manipulate Anim")) {
            //    //attach_animation();
            //    manipulate_animation();
            //};

            //if (ImGui::Button("Set Personality set")) {
            //    set_personality();
            //};

            //static bool arms_visible{ false };
            //if (ImGui::Button("Toggle Arms")) {
            //    arms_visible = !arms_visible;
            //    set_arms_mesh_visibility(arms_visible);
            //}

            //static bool mesh_visible{ false };
            //if (ImGui::Button("Toggle Player Mesh")) {
            //    mesh_visible = !mesh_visible;
            //    set_player_mesh_visibility(mesh_visible);
            //}

            //if (ImGui::Button("Apply Idle Camera Time: 1000")) {
            //    set_idle_camera_time(1000);
            //};

            ImGui::BeginDisabled();

            //ImGui::InputText("Full Level Name", m_level.value != nullptr ? (char*)m_level.value->GetFullName().c_str() : (char*)"NONE", 30);
            ImGui::InputText("Level Name", m_world != nullptr ? (char*)SDK::UGameplayStatics::GetCurrentLevelName(m_world, true).ToString().c_str() : (char*)"NONE", 30);
            ImGui::InputText("Pawn Name", m_pawn.value != nullptr ? (char*)m_pawn.value->GetName().c_str() : (char*)"NONE", 30);
            //ImGui::InputText("Character Name", m_player_character != nullptr ? (char*)m_player_character->GetName().c_str() : (char*)"NONE", 30);
            //ImGui::InputText("Controller Name", m_player_controller != nullptr ? (char*)m_player_controller->GetName().c_str() : (char*)"NONE", 30);
            //ImGui::InputText("UI", m_ui != nullptr ? (char*)m_ui->GetName().c_str() : (char*)"NONE", 30);

            if (m_vr_hud != nullptr) {
                ImGui::InputText("VR HUD Status", (char*)VRHackerHUDStateNames[m_vr_hud->get_hud_state()], 20);
                ImGui::InputText("VR HUD Last Error", (char*)m_vr_hud->get_hud_error().c_str(), 20);
            }

            ImGui::Checkbox("IsPaused", &m_is_game_paused.value);
            ImGui::Checkbox("IsInteractableInRange", &(m_is_interactable_in_range.value));

            //int comp_overlap_count = is_vr_hud_valid() ? m_vr_hud->get_overlapping_components_count() : 0;
            //ImGui::InputInt("Overlapping Components", &comp_overlap_count);

            //int actor_overlap_count = is_vr_hud_valid() ? m_vr_hud->get_overlapping_actors_count() : 0;
            //ImGui::InputInt("Overlapping Actors", &actor_overlap_count);

            int hit_distance = is_vr_hud_valid() ? m_vr_hud->get_line_trace_distance() : 0;
            ImGui::InputInt("Hit Distance", &hit_distance);


            //if (m_player_character != nullptr) {
            //    m_player_character->Mesh->GetAnimInstance();
            //    auto is_playing = m_player_character->Mesh->IsPlaying();
            //    ImGui::Checkbox("IsPlaying", &is_playing);
            //    ImGui::Checkbox("Is Mesh wirsts attached", &m_wirsts_attached);
            //    ImGui::Checkbox("ArmsMesh wirsts attached", &m_arms_wirsts_attached);
            //}

            ImGui::PushItemWidth(50);
            ImGui::InputInt("XInput cb duration [microseconds]", &m_ui_xinput_duration, 0, 0);
            ImGui::InputInt("Pre Engine Tick cb duration [microseconds]", &m_ui_pre_engine_tick_duration, 0, 0);
            ImGui::PopItemWidth();
            ImGui::EndDisabled();
            ImGui::EndGroup();
        }
    }
    ImGui::End();
}

bool OuterWorldsPlugin::on_message(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) {
    ImGui_ImplWin32_WndProcHandler(hwnd, msg, wparam, lparam);

    return !ImGui::GetIO().WantCaptureMouse && !ImGui::GetIO().WantCaptureKeyboard;
}

void OuterWorldsPlugin::on_device_reset() {
    PLUGIN_LOG_ONCE("Device Reset");

    //std::scoped_lock _{ m_imgui_mutex };

    const auto renderer_data = API::get()->param()->renderer;

    if (renderer_data->renderer_type == UEVR_RENDERER_D3D11) {
        ImGui_ImplDX11_Shutdown();
        g_d3d11 = {};
    }

    if (renderer_data->renderer_type == UEVR_RENDERER_D3D12) {
        ImGui_ImplDX12_Shutdown();
        g_d3d12 = {};
    }

    m_imgui_initialized = false;
}

void OuterWorldsPlugin::on_post_render_vr_framework_dx11(ID3D11DeviceContext* context, ID3D11Texture2D* texture, ID3D11RenderTargetView* rtv) {
    PLUGIN_LOG_ONCE("Post Render VR Framework DX11");

    const auto vr_active = API::get()->param()->vr->is_hmd_active();

    if (!m_imgui_initialized || !vr_active) {
        return;
    }

    if (m_was_rendering_desktop) {
        m_was_rendering_desktop = false;
        on_device_reset();
        return;
    }

    //std::scoped_lock _{ m_imgui_mutex };

    ImGui_ImplDX11_NewFrame();
    g_d3d11.render_imgui_vr(context, rtv);
}

void OuterWorldsPlugin::on_post_render_vr_framework_dx12(ID3D12GraphicsCommandList* command_list, ID3D12Resource* rt, D3D12_CPU_DESCRIPTOR_HANDLE* rtv) {
    PLUGIN_LOG_ONCE("Post Render VR Framework DX12");

    const auto vr_active = API::get()->param()->vr->is_hmd_active();

    if (!m_imgui_initialized || !vr_active) {
        return;
    }

    if (m_was_rendering_desktop) {
        m_was_rendering_desktop = false;
        on_device_reset();
        return;
    }

    //std::scoped_lock _{ m_imgui_mutex };

    ImGui_ImplDX12_NewFrame();
    g_d3d12.render_imgui_vr(command_list, rtv);
}

bool OuterWorldsPlugin::initialize_imgui() {
    if (m_imgui_initialized) {
        return true;
    }

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();

    static const auto imgui_ini = API::get()->get_persistent_dir(L"outer_worlds_vr_imgui.ini").string();
    ImGui::GetIO().IniFilename = imgui_ini.c_str();
    ImGui::GetIO().ConfigFlags |= ImGuiConfigFlags_NoMouseCursorChange;

    const auto renderer_data = API::get()->param()->renderer;

    DXGI_SWAP_CHAIN_DESC swap_desc{};
    auto swapchain = (IDXGISwapChain*)renderer_data->swapchain;
    swapchain->GetDesc(&swap_desc);

    m_wnd = swap_desc.OutputWindow;

    if (!ImGui_ImplWin32_Init(m_wnd)) {
        return false;
    }

    if (renderer_data->renderer_type == UEVR_RENDERER_D3D11) {
        if (!g_d3d11.initialize()) {
            return false;
        }
    }
    else if (renderer_data->renderer_type == UEVR_RENDERER_D3D12) {
        if (!g_d3d12.initialize()) {
            return false;
        }
    }

    m_imgui_initialized = true;
    return true;
}

void OuterWorldsPlugin::on_present() {
    //std::scoped_lock _{ m_imgui_mutex };

    if (!m_imgui_initialized) {
        API::get()->log_info("imgui not initialized");
        if (!initialize_imgui()) {
            API::get()->log_info("Failed to initialize imgui");
            return;
        }
        else {
            API::get()->log_info("Initialized imgui");
        }
    }

    const auto renderer_data = API::get()->param()->renderer;

    if (renderer_data->renderer_type == UEVR_RENDERER_D3D11) {
        ImGui_ImplDX11_NewFrame();
        ImGui_ImplWin32_NewFrame();
        ImGui::NewFrame();

        internal_frame();

        ImGui::EndFrame();
        ImGui::Render();

        g_d3d11.render_imgui();
    }
    else if (renderer_data->renderer_type == UEVR_RENDERER_D3D12) {
        auto command_queue = (ID3D12CommandQueue*)renderer_data->command_queue;

        if (command_queue == nullptr) {
            return;
        }

        ImGui_ImplDX12_NewFrame();
        ImGui_ImplWin32_NewFrame();
        ImGui::NewFrame();

        internal_frame();

        ImGui::EndFrame();
        ImGui::Render();

        g_d3d12.render_imgui();
    }
}
