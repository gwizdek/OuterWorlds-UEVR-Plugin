#include "uevr/API.hpp"
#include "imgui/imgui.h"

#include "indiana/SDK/CinematicCamera_classes.hpp"

#include "main.hpp"
#include "weapon.hpp"
#include "hud.hpp"
#include "plugin_config.hpp"
#include "native_fix.hpp"

using namespace uevr;

OuterWorldsMain::OuterWorldsMain() {
    API::get()->log_warn("[main] Constructor");
    m_vr_weapon = new OuterWorldsWeapon(this);
    m_vr_hud = new OuterWorldsHUD(this);
    m_native_fix = new OuterWorldsNativeFix(this);
};

OuterWorldsMain::~OuterWorldsMain() {
    API::get()->log_warn("[main] Destructor");
    m_vr_weapon->~OuterWorldsWeapon();
    m_vr_hud->~OuterWorldsHUD();
}

void OuterWorldsMain::on_xinput(XINPUT_STATE* state) {
    handle_controller_input(state);
}

void OuterWorldsMain::on_tick() {
    //API::get()->log_warn("[Main] Tick");
    if (m_vr_weapon != nullptr) {
        m_vr_weapon->tick();
    }
}

// -------------------------------------------------------------------------------------
// pointers and state
// -------------------------------------------------------------------------------------
void OuterWorldsMain::prepare_pointers() {
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
    }
    catch (...) {
        API::get()->log_error("[main][prepare_pointers] Exception");
        return;
    }
}

// sets state vars, so we can use them later in handlers
bool OuterWorldsMain::prepare_state() {
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
        API::get()->log_error("[main][prepare_state] Exception");
        return false;
    }

    return true;
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
    m_gamepad_left_thumb.set_state(state);
    //m_gamepad_trigger_right.set_state(state);
    //m_gamepad_trigger_left.set_state(state);


    if (m_gamepad_left_thumb.is_long_pressed(2.f)) {
        m_native_fix->cycle_native_fix();
    }
}




void OuterWorldsMain::on_draw_imgui() {
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
            if (OuterWorldsPluginConfig::save_plugin_config()) {
                ImGui::OpenPopup("succesful_save_popup");
            }
        }
        if (ImGui::BeginPopup("succesful_save_popup"))
        {
            ImGui::Text("Configuration Saved!");
            ImGui::EndPopup();
        }

        ImGui::PopItemWidth();

        ImGui::SeparatorText("Debugging");
        // game state section
        ImGui::Checkbox("Show debug", &m_ui_option_show_debug_view);
        if (m_ui_option_show_debug_view) {
            ImGui::BeginGroup();
            ImGui::BeginDisabled();
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
