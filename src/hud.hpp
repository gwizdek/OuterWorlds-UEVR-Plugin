#pragma once
#include "main.hpp"
#include "attached_widget.hpp"

//typedef enum OuterWorldsHUDState
//{
//    VR_HUD_PENDING_INIT,
//    VR_HUD_INITIALIZING,
//    VR_HUD_SUCCESS,
//    VR_HUD_ERROR
//} OuterWorldsHUDState;

class OuterWorldsHUD
{
private:
    OuterWorldsMain* m_main{ nullptr };

    SDK::FTransform m_ammo_readout_transform{};
    SDK::FTransform m_character_overview_transform{};
    SDK::FTransform m_item_degradation_transform{};
    SDK::FTransform m_compass_transform{};

    // widget components
    AttachedWidget* m_ammo_readout{ nullptr };
    AttachedWidget* m_character_overview{ nullptr };
    AttachedWidget* m_item_degradation{ nullptr };
    AttachedWidget* m_compass{ nullptr };
    AttachedWidget* m_companion_overview_a{ nullptr };
    AttachedWidget* m_companion_overview_b{ nullptr };

public:
    OuterWorldsHUD(OuterWorldsMain* main);
    virtual ~OuterWorldsHUD() {};

    void initialize();
    void cleanup_pointers();
    void draw_imgui();
};
