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
    bool is_valid();
    void cleanup_pointers();
    void on_draw_imgui();
    void on_load_config(mINI::INIStructure& config);
    void on_save_config(mINI::INIStructure& config);
};
