#include "uevr/API.hpp"
#include "imgui/imgui.h"

#include "indiana/SDK/CinematicCamera_classes.hpp"
#include "indiana/SDK/PlayerHighlightComponent_classes.hpp"

#include "main.hpp"
#include "weapon.hpp"
#include "hud.hpp"
#include "flicker_fixer.hpp"
#include "plugin_utils.hpp"

using namespace uevr;

OuterWorldsMain::OuterWorldsMain() {
    try {
        API::get()->log_warn("[main] Constructor");
        m_vr_controllers = new VRControllers();
        m_vr_weapon = new OuterWorldsWeapon(this);
        m_vr_hud = new OuterWorldsHUD(this);
        m_flicker_fixer = new OuterWorldsFlickerFixer(this);
    }
    catch (...) {
        API::get()->log_error("[main][constructor] Exception");
        return;
    }
};

OuterWorldsMain::~OuterWorldsMain() {
    API::get()->log_warn("[main] Destructor");
    //m_vr_hud->~OuterWorldsHUD();
    //m_vr_weapon->~OuterWorldsWeapon();
    //m_vr_controllers->~VRControllers();
    //m_flicker_fixer->~OuterWorldsFlickerFixer();
}

void OuterWorldsMain::on_xinput(XINPUT_STATE* state) {
    handle_controller_input(state);
}

void OuterWorldsMain::on_tick(float delta) {
    handle_level_change();
    handle_game_state();
    handle_mod_events();
    fix_ledger();
    fix_workbench();
    handle_crouch();
    handle_weapon();

    if (m_flicker_fixer->is_valid()) {
        m_flicker_fixer->on_tick(delta);
    }

    if (m_vr_weapon->is_valid()) {
        m_vr_weapon->on_tick();
    }

    // add delta time to dual state inputs
    m_gamepad_left_thumb.add_delta(delta);
}

void OuterWorldsMain::cleanup_pointers() {
    try {
        API::get()->log_warn("[main][cleanup] Starting Pointers Cleanup");

        if (m_vr_weapon != nullptr) {
            m_vr_weapon->cleanup_pointers();
        }
        if (m_vr_hud != nullptr) {
            m_vr_hud->cleanup_pointers();
        }
        if (m_vr_controllers != nullptr) {
            m_vr_controllers->cleanup_pointers();
        }
        if (m_flicker_fixer != nullptr) {
            m_flicker_fixer->cleanup_pointers();
        }
    }
    catch (...) {
        API::get()->log_error("[main][cleanup_pointers] Exception");
    }
}

void OuterWorldsMain::cleanup_actors() {
    API::get()->log_warn("[main][cleanup] Starting Actors Cleanup");
    VRControllers::cleanup_actors();
    OuterWorldsFlickerFixer::cleanup_actors();
}

// -------------------------------------------------------------------------------------
// pointers and state
// -------------------------------------------------------------------------------------
void OuterWorldsMain::prepare_pointers() {
    try {
        // world
        m_world = SDK::UWorld::GetWorld();
        // pawn
        m_pawn = m_world != nullptr ? SDK::UGameplayStatics::GetPlayerPawn(m_world, 0) : nullptr;
        // character
        m_player_character = SDK::AIndianaPlayerCharacter::GetIndianaPC();
        // controller
        m_player_controller = SDK::AIndianaPlayerController::GetIndianaPlayerController();
        if (m_player_controller != nullptr) {
            // UI
            m_ui = SDK::UIndianaUIFunctionLibrary::GetIndianaUI(&m_reusable_branches, m_player_controller);
            if (m_reusable_branches == SDK::ECheckBranches::Valid && m_ui != nullptr) {
                // HUD
                m_hud = m_ui->GetHUD();
            }
            else {
                m_hud = nullptr;
            }
        }
        else {
            m_ui = nullptr;
        }
    }
    catch (...) {
        API::get()->log_error("[main][prepare_pointers] Exception");
    }
}

// sets state vars, so we can use them later in handlers
void OuterWorldsMain::prepare_state() {
    try {
        // level
        m_level.set_value(m_world != nullptr ? m_world->PersistentLevel : nullptr);

        // pause
        m_is_game_paused.set_value(m_world != nullptr ? SDK::UGameplayStatics::IsGamePaused(m_world) : true);

        if (m_player_character != nullptr) {
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
        API::get()->log_error("[main][prepare_state] Exception");
    }
}

void OuterWorldsMain::prepare_game_state() {
    try {
        if (!SDK::UKismetSystemLibrary::IsValid(m_pawn)) {
            m_game_state.set_value(GAME_STATE_UNDEFINED);
            return;
        }

        if (SDK::UKismetSystemLibrary::IsValid(m_pawn) && m_pawn->IsA(SDK::ADefaultPawn::StaticClass())) {
            m_game_state.set_value(GAME_STATE_MAIN_MENU);
            return;
        }

        if (
            m_ui_ledger_open_state.value == SDK::EWidgetOpenState::Maximized ||
            m_ui_ledger_open_state.value == SDK::EWidgetOpenState::TransitioningToMaximized
            ) {
            m_game_state.set_value(GAME_STATE_LEDGER);
            return;
        }

        if (
            m_ui_workbench_open_state.value == SDK::EWidgetOpenState::Maximized ||
            m_ui_workbench_open_state.value == SDK::EWidgetOpenState::TransitioningToMaximized
            ) {
            m_game_state.set_value(GAME_STATE_WORKBENCH);
            return;
        }

        if (m_is_game_paused.value) {
            m_game_state.set_value(GAME_STATE_PAUSE_MENU);
            return;
        }

        if (m_player_character->ConversationCameraComponent->CameraComponent->IsActive()) {
            if (m_ui_conversation_open_state.value == SDK::EWidgetOpenState::Minimized) {
                m_game_state.set_value(GAME_STATE_COMPUTER_TERMINAL);
                return;
            }

            m_game_state.set_value(GAME_STATE_CONVERSATION);
            return;
        }

        m_game_state.set_value(GAME_STATE_PLAYING);
    }
    catch (...) {
        API::get()->log_error("[main][prepare_game_state] Exception");
    }
}

// -------------------------------------------------------------------------------------
// controller input
// -------------------------------------------------------------------------------------
void OuterWorldsMain::handle_controller_input(XINPUT_STATE* state) {
    m_gamepad_btn_a.set_state(state);
    //m_gamepad_btn_x.set_state(state);
    //m_gamepad_btn_b.set_state(state);
    //m_gamepad_btn_y.set_state(state);
    //m_gamepad_right_shoulder.set_state(state);
    //m_gamepad_left_shoulder.set_state(state);
    //m_gamepad_right_thumb.set_state(state);
    //m_gamepad_left_thumb.set_state(state);
    //m_gamepad_trigger_right.set_state(state);
    //m_gamepad_trigger_left.set_state(state);


    //if (m_gamepad_left_thumb.is_long_pressed(2.f)) {
    //    if (m_flicker_fixer->is_valid()) {
    //        m_flicker_fixer->cycle(50);
    //    }
    //}
}

// -------------------------------------------------------------------------------------
// handlers
// -------------------------------------------------------------------------------------
void OuterWorldsMain::handle_game_state() {
    try {
        if (m_game_state.has_changed()) {
            API::get()->log_warn("[main][handle_game_state] New Game State: %s", GameStateName[m_game_state.value]);
            const UEVR_VRData* vr = API::get()->param()->vr;

            switch (m_game_state.value) {
                case GAME_STATE_MAIN_MENU:
                    vr->set_aim_method(0);
                    vr->set_decoupled_pitch_enabled(false);
                    vr->set_mod_value("VR_CameraForwardOffset", "0.000000");
                    vr->set_mod_value("VR_CameraUpOffset", "0.000000");
                    vr->set_mod_value("UI_Distance", "2.000000");
                    vr->set_mod_value("UI_Size", "1.400000");
                    vr->set_mod_value("UI_Y_Offset", "0.00000");
                    vr->set_mod_value("VR_RoomscaleMovement", "false");
                    vr->set_mod_value("VR_DecoupledPitchUIAdjust", "false");
                    PluginUtils::reset_height(0.f);
                    vr->recenter_view();
                    API::UObjectHook::set_disabled(true);
                    vr->set_mod_value("VR_NativeStereoFix", "false");
                    //OuterWorldsNativeFix::cycle(50);
                    break;

                case GAME_STATE_PAUSE_MENU:
                    API::UObjectHook::set_disabled(false);
                    vr->set_aim_method(0);
                    vr->set_decoupled_pitch_enabled(true);
                    vr->set_mod_value("VR_CameraForwardOffset", "0.000000");
                    vr->set_mod_value("VR_CameraUpOffset", "0.000000");
                    vr->set_mod_value("UI_Distance", "2.000000");
                    vr->set_mod_value("UI_Size", "1.400000");
                    vr->set_mod_value("UI_Y_Offset", "-0.30000");
                    vr->set_mod_value("VR_RoomscaleMovement", "false");
                    vr->set_mod_value("VR_DecoupledPitchUIAdjust", "false");
                    PluginUtils::reset_height(0.f);
                    vr->recenter_view();
                    break;

                case GAME_STATE_PLAYING:
                    API::UObjectHook::set_disabled(false);
                    vr->set_aim_method(2);
                    vr->set_decoupled_pitch_enabled(true);
                    vr->set_mod_value("VR_CameraForwardOffset", "0.000000");
                    vr->set_mod_value("VR_CameraUpOffset", "0.000000");
                    vr->set_mod_value("UI_Distance", "2.000000");
                    vr->set_mod_value("UI_Size", "1.200000");
                    vr->set_mod_value("UI_Y_Offset", "0.00000");
                    vr->set_mod_value("VR_RoomscaleMovement", "true");
                    vr->set_mod_value("VR_DecoupledPitchUIAdjust", "true");
                    vr->set_mod_value("VR_NativeStereoFix", "true");
                    PluginUtils::reset_height(0.f);
                    vr->recenter_view();
                    if (m_vr_weapon != nullptr) {
                        m_vr_weapon->set_particle_pointer_visibility(true);
                    }
                    set_ability_overview_visibility(false);
                    break;

                case GAME_STATE_CONVERSATION:
                    API::UObjectHook::set_disabled(false);
                    vr->set_aim_method(0);
                    vr->set_mod_value("VR_CameraForwardOffset", "0.000000");
                    vr->set_mod_value("VR_CameraUpOffset", "0.000000");
                    vr->set_mod_value("UI_Distance", "1.400000");
                    vr->set_mod_value("UI_Size", "1.000000");
                    vr->set_mod_value("UI_Y_Offset", "0.00000");
                    vr->set_mod_value("VR_RoomscaleMovement", "false");
                    vr->set_mod_value("VR_DecoupledPitchUIAdjust", "true");
                    vr->recenter_view();
                    if (m_vr_weapon != nullptr) {
                        m_vr_weapon->set_particle_pointer_visibility(false);
                    }
                    break;

                case GAME_STATE_COMPUTER_TERMINAL:
                    API::UObjectHook::set_disabled(true);
                    vr->set_aim_method(0);
                    vr->set_mod_value("VR_CameraForwardOffset", "-25.000000");
                    vr->set_mod_value("VR_CameraUpOffset", "15.000000");
                    vr->set_mod_value("UI_Distance", "1.400000");
                    vr->set_mod_value("UI_Size", "1.000000");
                    vr->set_mod_value("UI_Y_Offset", "0.00000");
                    vr->set_mod_value("VR_RoomscaleMovement", "false");
                    vr->set_mod_value("VR_DecoupledPitchUIAdjust", "false");
                    vr->recenter_view();
                    break;

                case GAME_STATE_LEDGER:
                case GAME_STATE_WORKBENCH:
                    API::UObjectHook::set_disabled(true);
                    vr->set_aim_method(0);
                    vr->set_mod_value("VR_CameraForwardOffset", "0.000000");
                    vr->set_mod_value("VR_CameraUpOffset", "0.000000");
                    vr->set_mod_value("UI_Distance", "2.000000");
                    vr->set_mod_value("UI_Size", "1.400000");
                    vr->set_mod_value("UI_Y_Offset", "-0.30000");
                    vr->set_mod_value("VR_RoomscaleMovement", "false");
                    vr->set_mod_value("VR_DecoupledPitchUIAdjust", "false");
                    vr->recenter_view();
                    break;
            }
        }
    }
    catch (...) {
        API::get()->log_error("[handle_game_state] Exception");
    }
}


void OuterWorldsMain::handle_level_change() {
    try {
        if (m_level.has_changed() && m_level.value != nullptr) {
            const UEVR_VRData* vr = API::get()->param()->vr;

            //const UEVR_SDKData* sdk = API::get()->sdk();
            auto level_name = m_level.value->GetFullName();
            API::get()->log_warn("[main][handle_level_change] New Level: %s", level_name.c_str());

            if (m_game_state.value != GAME_STATE_MAIN_MENU) {
                API::get()->log_warn("[main][handle_level_change] Initialize components");

                m_vr_controllers->initialize();
                m_vr_weapon->initialize(RIGHT_HANDED);
                m_vr_hud->initialize();
                m_flicker_fixer->spawn_flicker_fixer();

                load_mod_config();

                set_idle_camera_time(1000);
                fix_player_highlighter();
                fix_cinematic_camera();
                set_ability_overview_visibility(false);
            }
            else {
                API::get()->log_warn("[main][handle_level_change] Components cleanup");
                cleanup_pointers();
            }
        }
    }
    catch (...) {
        API::get()->log_error("[main][handle_level_change] Exception");
    }
}

void OuterWorldsMain::handle_mod_events() {
    try {
        if (m_mod_events.contains(MOD_EVENT_ENABLE_WORLD_RENDERING)) {
            if (m_world != nullptr) {
                API::get()->log_warn("[main][handle_mod_events] SetEnableWorldRendering");
                SDK::UGameplayStatics::SetEnableWorldRendering(m_world, true);
                m_mod_events.extract(MOD_EVENT_ENABLE_WORLD_RENDERING);
            }
        }
    }
    catch (...) {
        API::get()->log_error("[main][handle_mod_events] Exception");
    }
}

void OuterWorldsMain::handle_crouch() {
    if (m_is_crouched.has_changed()) {
        PluginUtils::reset_height(0.f);
    }
}

void OuterWorldsMain::handle_weapon() {
    try {
        // equipped weapon
        if (SDK::UKismetSystemLibrary::IsValid(m_player_character)) {
            auto equipment = static_cast<SDK::AIndianaPlayerCharacter_BP_C*>(m_player_character)->Equipment;
            if (equipment != nullptr) {
                m_vr_weapon->set_equipped_weapon(equipment->GetEquippedWeapon());
            }
        }
    }
    catch (...) {
        API::get()->log_error("[main][handle_weapon] Exception");
    }
}


// -------------------------------------------------------------------------------------
// fixes
// -------------------------------------------------------------------------------------
void OuterWorldsMain::fix_player_highlighter() {
    try {
        if (m_player_character != nullptr && m_player_character->IsA(SDK::AIndianaPlayerCharacter_BP_C::StaticClass())) {
            API::get()->log_warn("[main][fix_highlighter] Searching for PlayerHightlightComponent");

            auto class_ptr = API::get()->find_uobject<API::UClass>(L"BlueprintGeneratedClass /Game/Blueprints/Player/PlayerHighlightComponent.PlayerHighlightComponent_C");
            if (class_ptr != nullptr) {
                API::get()->log_warn("[main][fix_highlighter] PlayerHighlightComponent Class found");
                std::vector<SDK::UObject*> matching_objects = class_ptr->get_objects_matching<SDK::UObject>();

                for (size_t i = 0; i < matching_objects.size(); i++) {
                    if (matching_objects[i]->IsA(SDK::UPlayerHighlightComponent_C::StaticClass())) {
                        API::get()->log_warn("[main][fix_highlighter] PlayerHighlightComponent Object found, changing params");
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
        API::get()->log_error("[main][fix_player_highlighter] Exception");
    }
}

void OuterWorldsMain::fix_cinematic_camera() {
    try {
        API::get()->log_warn("[main][fix_cinematic_camera] Fixing Cinematic Camera");
        if (SDK::UKismetSystemLibrary::IsValid(m_player_character)) {
            m_player_character->ConversationCameraComponent->ComputerTerminalLocationInterpSpeed = 0.001f;
            m_player_character->ConversationCameraComponent->ComputerTerminalRotationInterpSpeed = 0.001f;
            m_player_character->ConversationCameraComponent->ConversationLocationInterpSpeed = 0.001f;
            m_player_character->ConversationCameraComponent->ConversationRotationInterpSpeed = 0.001f;
        }
        else {
            API::get()->log_error("[main][fix_cinematic_camera] Player Character is not valid");
        }
    }
    catch (...) {
        API::get()->log_error("[main][fix_cinematic_camera] Exception");
    }
}

void OuterWorldsMain::fix_ledger() {
    try {
        // makes ledger background black
        if (m_ui_ledger_open_state.has_changed()) {
            const UEVR_VRData* vr = API::get()->param()->vr;
            if (m_ui_ledger_open_state.value == SDK::EWidgetOpenState::TransitioningToMaximized) {
                API::get()->log_warn("[main][fix_ledger] Opening Ledger");
                SDK::UGameplayStatics::SetEnableWorldRendering(m_world, false);
                return;
            }
            else if (m_ui_ledger_open_state.value == SDK::EWidgetOpenState::Maximized) {
                API::get()->log_warn("[main][fix_ledger] Ledger Opened");
                vr->set_mod_value("VR_NativeStereoFix", "false");
                SDK::UGameplayStatics::SetEnableWorldRendering(m_world, true);
                return;
            }
            else {
                API::get()->log_warn("[main][fix_ledger] Ledger Closing / Closed");
                SDK::UGameplayStatics::SetEnableWorldRendering(m_world, true);
                vr->set_mod_value("VR_NativeStereoFix", "true");
                return;
            }
        }
    }
    catch (...) {
        API::get()->log_error("[main][fix_ledger] Exception");
    }
}

void OuterWorldsMain::fix_workbench() {
    try {
        // makes workbench background black
        if (m_ui_workbench_open_state.has_changed()) {
            const UEVR_VRData* vr = API::get()->param()->vr;
            if (m_ui_workbench_open_state.value == SDK::EWidgetOpenState::TransitioningToMaximized) {
                API::get()->log_warn("[main][fix_workbench] Opening Workbench");
                SDK::UGameplayStatics::SetEnableWorldRendering(m_world, false);
                return;
            }
            else if (m_ui_workbench_open_state.value == SDK::EWidgetOpenState::Maximized) {
                API::get()->log_warn("[main][fix_workbench] Workbench Opened");
                SDK::UGameplayStatics::SetEnableWorldRendering(m_world, false);
                vr->set_mod_value("VR_NativeStereoFix", "false");
                m_mod_events.insert(MOD_EVENT_ENABLE_WORLD_RENDERING);
                return;
            }
            else {
                API::get()->log_warn("[main][fix_workbench] Workbench Closing / Closed");
                SDK::UGameplayStatics::SetEnableWorldRendering(m_world, true);
                vr->set_mod_value("VR_NativeStereoFix", "true");
                return;
            }
        }
    }
    catch (...) {
        API::get()->log_error("[main][fix_ledger] Exception");
    }
}

void OuterWorldsMain::set_ability_overview_visibility(bool visible) {
    try {
        if (m_hud != nullptr) {
            m_hud->AbilityOverviewGamepad->SetVisibility(visible ? SDK::ESlateVisibility::Visible : SDK::ESlateVisibility::Hidden);
            m_hud->AbilityOverview->SetVisibility(visible ? SDK::ESlateVisibility::Visible : SDK::ESlateVisibility::Hidden);
        }
    }
    catch (...) {
        API::get()->log_error("[main][set_ability_overview_visibility] Exception");
    }
}

// -------------------------------------------------------------------------------------
// setters
// -------------------------------------------------------------------------------------
void OuterWorldsMain::set_idle_camera_time(float seconds_to_wait) {
    try {
        API::get()->log_warn("[main][set_idle_camera_time] Setting idle time %f", seconds_to_wait);
        if (m_player_character != nullptr && m_player_character->IsA(SDK::AIndianaPlayerCharacter_BP_C::StaticClass())) {
            static_cast<SDK::AIndianaPlayerCharacter_BP_C*>(m_player_character)->IdleCamera->SecondsToWait = seconds_to_wait;
        }
    }
    catch (...) {
        API::get()->log_error("[main][set_idle_camera_time] Exception");
    }
}


void OuterWorldsMain::set_mouse_cursor() {
    try {
        SDK::UUserWidget* widget = API::get()->find_uobject<SDK::UUserWidget>(
            L"GenericCrosshair_BP_C /Game/UI/HUD/Reticle/Reticle_BP.Reticle_BP_C.WidgetTree.Crosshair"
        );
        if (widget != nullptr) {
            m_player_controller->SetMouseCursorWidget(SDK::EMouseCursor::Hand, widget);
        }
        else {
            API::get()->log_warn("[main][set_mouse_cursor] Widget not found");
        }

        m_player_controller->DefaultMouseCursor = SDK::EMouseCursor::Hand;
        m_player_controller->CurrentMouseCursor = SDK::EMouseCursor::Hand;
    }
    catch (...) {
        API::get()->log_error("[main][set_mouse_cursor] Exception");
    }
}

// -------------------------------------------------------------------------------------
// hooks
// -------------------------------------------------------------------------------------
//Weapon trace hook
//void OuterWorldsMain::hook_onfire_fn() {
//    m_onfire_hook_id = hook_vtable_fn(L"Class /Script/GunfireRuntime.RangedWeapon", L"OnFire", on_get_onfire, (void**)&m_onfire_hook_fn);
//}


// -------------------------------------------------------------------------------------
// ImGui
// -------------------------------------------------------------------------------------
void OuterWorldsMain::on_draw_imgui() {
    try {
        if (!API::get()->param()->functions->is_drawing_ui()) {
            return;
        }

        static const auto UEVR_NAME = std::format("Outer Worlds UEVR plugin [rev. {}]", MOD_VERSION);
        static const auto NO_CHARACTER = std::format("No Player Character detected! Is it Main Menu?");
        static const auto NO_PAWN = std::format("No Pawn detected!");

        static constexpr auto window_w = 500.0f;
        static constexpr auto window_h = 500.0f;

        ImGui::SetNextWindowSize(ImVec2(window_w, window_h), ImGuiCond_::ImGuiCond_Once);

        if (ImGui::Begin(UEVR_NAME.c_str())) {
            ImGui::PushItemWidth(200);
            if (ImGui::Button("Save Configuration")) {
                if (save_mod_config()) {
                    ImGui::OpenPopup("succesful_save_popup");
                }
            }
            if (ImGui::BeginPopup("succesful_save_popup"))
            {
                ImGui::Text("Configuration Saved!");
                ImGui::EndPopup();
            }

            ImGui::PopItemWidth();

            if (m_flicker_fixer != nullptr) {
                m_flicker_fixer->on_draw_imgui();
            }
            
            if (m_vr_hud != nullptr) {
                m_vr_hud->on_draw_imgui();
            }

            ImGui::SeparatorText("Debugging");
            // game state section
            ImGui::Checkbox("Show debug", &m_ui_option_show_debug_view);
            if (m_ui_option_show_debug_view) {
                ImGui::BeginGroup();
                ImGui::BeginDisabled();
                ImGui::InputText("Game State", (char*)GameStateName[m_game_state.value], 20);
                ImGui::Checkbox("IsPaused", &m_is_game_paused.value);
                ImGui::EndDisabled();
                ImGui::EndGroup();

                if (m_vr_weapon != nullptr) {
                    m_vr_weapon->on_draw_imgui();
                }

                ImGui::SeparatorText("Timers [microseconds]");
                ImGui::BeginGroup();
                ImGui::BeginDisabled();
                ImGui::PushItemWidth(50);
                ImGui::InputInt("XInput duration", &m_ui_xinput_duration, 0, 0);
                ImGui::InputInt("PreEngineTick duration", &m_ui_pre_engine_tick_duration, 0, 0);
                ImGui::PopItemWidth();
                ImGui::EndDisabled();
                ImGui::EndGroup();
            }
        }
        ImGui::End();
    }
    catch (...) {
        API::get()->log_error("[main][on_draw_imgui] Exception");
    }
}

// -------------------------------------------------------------------------------------
// mod config
// -------------------------------------------------------------------------------------
bool OuterWorldsMain::load_mod_config() {
    try {
        API::get()->log_warn("[main][load_mod_config] Loading...");
        static const auto config_filename = API::get()->get_persistent_dir(L"outer_worlds_vr_config.ini").string();
        mINI::INIFile mod_config_file(config_filename);
        mINI::INIStructure mod_config;

        if (!mod_config_file.read(mod_config)) {
            API::get()->log_error("[main][load_mod_config] Missing config file. Creating config with default values");
            return save_mod_config();
        }

        m_vr_hud->on_load_config(mod_config);
        m_flicker_fixer->on_load_config(mod_config);
        return true;
    }
    catch (...) {
        API::get()->log_error("[plugin_config][load_mod_config] Exception");
        return false;
    }
}

bool OuterWorldsMain::save_mod_config() {
    try {
        API::get()->log_warn("[main][save_mod_config] Saving...");
        static const auto config_filename = API::get()->get_persistent_dir(L"outer_worlds_vr_config.ini").string();
        mINI::INIFile mod_config_file(config_filename);
        mINI::INIStructure mod_config;

        m_vr_hud->on_save_config(mod_config);
        m_flicker_fixer->on_save_config(mod_config);

        return mod_config_file.write(mod_config, true);
    }
    catch (...) {
        API::get()->log_error("[main][save_mod_config] Exception");
        return false;
    }
}