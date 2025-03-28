#pragma once

typedef enum OuterWorldsVRHUDState
{
    VR_HUD_PENDING_INIT,
    VR_HUD_INITIALIZING,
    VR_HUD_SUCCESS,
    VR_HUD_ERROR
} OuterWorldsVRHUDState;

class OuterWorldsCommon;

class OuterWorldsVRHUD
{
private:
    const char* VRHackerHUDStateNames[4] = { "VR_HUD_PENDING_INIT", "VR_HUD_INITIALIZING", "VR_HUD_SUCCESS", "VR_HUD_ERROR" };
    OuterWorldsCommon* m_common{ nullptr };
    OuterWorldsVRHUDState m_hud_state{ VR_HUD_PENDING_INIT };

public:
    OuterWorldsVRHUD(OuterWorldsCommon* common) { m_common = common; };
    virtual ~OuterWorldsVRHUD() {};
};
