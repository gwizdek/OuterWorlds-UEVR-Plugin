#include "uevr/API.hpp"
#include "vr_common.hpp"
#include "vr_weapon.hpp"
#include "vr_hud.hpp"
#include "imgui/imgui.h"

using namespace uevr;

OuterWorldsCommon::OuterWorldsCommon() {
    API::get()->log_warn("[VR Common] Constructor");
    m_vr_weapon = new OuterWorldsVRWeapon(this);
    m_vr_hud = new OuterWorldsVRHUD(this);
};

OuterWorldsCommon::~OuterWorldsCommon() {
    API::get()->log_warn("[VR Common] Destructor");
    m_vr_weapon->~OuterWorldsVRWeapon();
    m_vr_hud->~OuterWorldsVRHUD();
}

void OuterWorldsCommon::on_tick() {
    //API::get()->log_warn("[VR Common] Tick");
    m_vr_weapon->tick();
}

void OuterWorldsCommon::on_xinput(XINPUT_STATE* state) {

}

void OuterWorldsCommon::on_draw_imgui() {
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
            ImGui::OpenPopup("succesful_save_popup");
        };
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
