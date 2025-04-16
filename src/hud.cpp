#include "uevr/API.hpp"
#include "imgui/imgui.h"

#include "hud.hpp"

using namespace uevr;

OuterWorldsHUD::OuterWorldsHUD(OuterWorldsMain* main) {
    m_main = main;

    m_ammo_readout = new AttachedWidget();
    m_character_overview = new AttachedWidget();
    m_item_degradation = new AttachedWidget();
    m_compass = new AttachedWidget();
}


// --------------------------------------------------------------------
// Attachments
// --------------------------------------------------------------------
void OuterWorldsHUD::initialize() {
    try {
        if (m_main->get_vr_controllers() != nullptr && m_main->get_vr_controllers()->is_valid() && m_main->get_hud() != nullptr) {

            // default transforms
            SDK::FTransform ammo_readout_transform = {
                .Rotation = SDK::UKismetMathLibrary::Quat_MakeFromEuler({ 0.f, 0.f, 270.0f }),
                .Translation = { -6.f, -3.f, 4.f },
                .Scale3D = { 1.f, 0.03f, 0.03f }
            };

            SDK::FTransform character_overview_transform = {
                .Rotation = SDK::UKismetMathLibrary::Quat_MakeFromEuler({ 0.f, 0.f, 90.0f }),
                .Translation = { -5.f, 1.f, 0.f },
                .Scale3D = { 1.f, 0.04f, 0.04f }
            };

            SDK::FTransform item_degradation_transform = {
                .Rotation = SDK::UKismetMathLibrary::Quat_MakeFromEuler({ 0.f, 0.f, 270.0f }),
                .Translation = { 0.f, -3.f, 4.f },
                .Scale3D = { 1.f, 0.03f, 0.03f }
            };

            SDK::FTransform compass_transform = {
                .Rotation = SDK::UKismetMathLibrary::Quat_MakeFromEuler({ 0.f, 180.f, 90.0f }),
                .Translation = { -6.f, -2.f, 0.f },
                .Scale3D = { 1.f, 0.03f, 0.03f }
            };

            m_ammo_readout->attach(
                m_main->get_vr_controllers()->get_right_hand_actor(), m_main->get_hud()->AmmoReadout, ammo_readout_transform, { 300.0f, 100.0f }, "ammo_readout", "Ammo Readout"
            );

            m_character_overview->attach(
                m_main->get_vr_controllers()->get_left_hand_actor(), m_main->get_hud()->CharacterOverview, character_overview_transform, { 400.0f, 120.0f }, "character_overview", "Character Overview"
            );

            m_item_degradation->attach(
                m_main->get_vr_controllers()->get_right_hand_actor(), m_main->get_hud()->ItemDegradation, item_degradation_transform, { 100.0f, 100.0f }, "item_degradation", "Item Degradation"
            );

            m_compass->attach(
                m_main->get_vr_controllers()->get_left_hand_actor(), m_main->get_hud()->Compass, compass_transform, { 620.0f, 80.0f }, "compass", "Compass"
            );
        }
    }
    catch (...) {
        API::get()->log_error("[hud][initialize] Exception");
    }
}

void OuterWorldsHUD::cleanup_pointers() {
    API::get()->log_warn("[weapon][cleanup_pointers] Cleanup");
    m_ammo_readout = nullptr;
    m_character_overview = nullptr;
    m_item_degradation = nullptr;
    m_compass = nullptr;
    m_companion_overview_a = nullptr;
    m_companion_overview_b = nullptr;
}

bool OuterWorldsHUD::is_valid() {
    return (m_ammo_readout != nullptr && m_character_overview != nullptr && m_item_degradation != nullptr && m_compass != nullptr);
}

void OuterWorldsHUD::on_draw_imgui() {
    try {
        if (is_valid()) {
            ImGui::SeparatorText("Attachments");
            m_character_overview->on_draw_imgui();
            m_compass->on_draw_imgui();
            m_ammo_readout->on_draw_imgui();
            m_item_degradation->on_draw_imgui();
        }
    }
    catch (...) {
        API::get()->log_error("[hud][draw_imgui] Exception");
    }
}

void OuterWorldsHUD::on_load_config(mINI::INIStructure& config) {
    if (is_valid()) {
        m_ammo_readout->on_load_config(config);
        m_character_overview->on_load_config(config);
        m_item_degradation->on_load_config(config);
        m_compass->on_load_config(config);
    }
}

void OuterWorldsHUD::on_save_config(mINI::INIStructure& config) {
    if (is_valid()) {
        m_ammo_readout->on_save_config(config);
        m_character_overview->on_save_config(config);
        m_item_degradation->on_save_config(config);
        m_compass->on_save_config(config);
    }
}