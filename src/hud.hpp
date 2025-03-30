#pragma once

typedef enum OuterWorldsHUDState
{
    VR_HUD_PENDING_INIT,
    VR_HUD_INITIALIZING,
    VR_HUD_SUCCESS,
    VR_HUD_ERROR
} OuterWorldsHUDState;

class OuterWorldsMain;

class OuterWorldsHUD
{
private:
    const char* VRHackerHUDStateNames[4] = { "VR_HUD_PENDING_INIT", "VR_HUD_INITIALIZING", "VR_HUD_SUCCESS", "VR_HUD_ERROR" };
    OuterWorldsMain* m_main{ nullptr };
    OuterWorldsHUDState m_hud_state{ VR_HUD_PENDING_INIT };

public:
    OuterWorldsHUD(OuterWorldsMain* main) { m_main = main; };
    virtual ~OuterWorldsHUD() {};
};
