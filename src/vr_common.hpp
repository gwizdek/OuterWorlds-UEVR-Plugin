#pragma once
#include "vr_hud.hpp"

#define STATIC_LOAD_ASSET_OFFSET 0x1C67740

class OuterWorldsVRHUD;
class OuterWorldsVRWeapon;

class OuterWorldsCommon
{
private:
    OuterWorldsVRWeapon* m_vr_weapon{ nullptr };
    OuterWorldsVRHUD* m_vr_hud{ nullptr };
    bool m_my_test_value{ true };

public:
    OuterWorldsCommon();
    virtual ~OuterWorldsCommon();

    void tick();
    OuterWorldsVRWeapon* get_weapon() { return m_vr_weapon; };
    OuterWorldsVRHUD* get_hud() { return m_vr_hud; };
    bool get_test_value() { return m_my_test_value; };
};
