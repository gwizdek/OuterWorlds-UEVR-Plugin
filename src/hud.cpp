#include "uevr/API.hpp"
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
            SDK::FTransform m_ammo_readout_transform = {
                .Rotation = SDK::UKismetMathLibrary::Quat_MakeFromEuler({ 0.f, 0.f, 270.0f }),
                .Translation = { -6.f, -3.f, 4.f },
                .Scale3D = { 1.f, 0.03f, 0.03f }
            };

            SDK::FTransform m_character_overview_transform = {
                .Rotation = SDK::UKismetMathLibrary::Quat_MakeFromEuler({ 0.f, 0.f, 90.0f }),
                .Translation = { -5.f, 1.f, 0.f },
                .Scale3D = { 1.f, 0.04f, 0.04f }
            };

            SDK::FTransform m_item_degradation_transform = {
                .Rotation = SDK::UKismetMathLibrary::Quat_MakeFromEuler({ 0.f, 0.f, 270.0f }),
                .Translation = { 0.f, -3.f, 4.f },
                .Scale3D = { 1.f, 0.03f, 0.03f }
            };

            SDK::FTransform m_compass_transform = {
                .Rotation = SDK::UKismetMathLibrary::Quat_MakeFromEuler({ 0.f, 180.f, 90.0f }),
                .Translation = { -6.f, -2.f, 0.f },
                .Scale3D = { 1.f, 0.03f, 0.03f }
            };


            m_ammo_readout->attach(
                m_main->get_vr_controllers()->get_right_hand_actor(), m_main->get_hud()->AmmoReadout, m_ammo_readout_transform, { 300.0f, 100.0f }, "Ammo Readout"
            );

            m_character_overview->attach(
                m_main->get_vr_controllers()->get_left_hand_actor(), m_main->get_hud()->CharacterOverview, m_character_overview_transform, { 400.0f, 120.0f }, "Character Overview"
            );

            m_item_degradation->attach(
                m_main->get_vr_controllers()->get_right_hand_actor(), m_main->get_hud()->ItemDegradation, m_item_degradation_transform, { 100.0f, 100.0f }, "Item Degradation"
            );

            m_compass->attach(
                m_main->get_vr_controllers()->get_left_hand_actor(), m_main->get_hud()->Compass, m_compass_transform, { 620.0f, 80.0f }, "Compass"
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

void OuterWorldsHUD::draw_imgui() {
    try {
    }
    catch (...) {
        API::get()->log_error("[hud][draw_imgui] Exception");
    }
}