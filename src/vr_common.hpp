#pragma once
#include <windows.h>
#include <Xinput.h>

#include "vr_hud.hpp"

#define STATIC_LOAD_ASSET_OFFSET 0x1C67740

using namespace uevr;

class OuterWorldsVRHUD;
class OuterWorldsVRWeapon;

class OuterWorldsCommon
{
private:
    OuterWorldsVRWeapon* m_vr_weapon{ nullptr };
    OuterWorldsVRHUD* m_vr_hud{ nullptr };
    bool m_my_test_value{ true };

    bool m_ui_option_show_debug_view{ false };
    int m_ui_xinput_duration{ 0 };              // [microseconds]
    int m_ui_pre_engine_tick_duration{ 0 };     // [microseconds]

    const char* MOD_VERSION = "0.1.0";
public:
    OuterWorldsCommon();
    virtual ~OuterWorldsCommon();

    void on_tick();
    void on_xinput(XINPUT_STATE* state);
    void on_draw_imgui();
    
    bool get_test_value() { return m_my_test_value; };
    bool get_ui_option_show_debug_view() { return m_ui_option_show_debug_view; };
    void set_ui_xinput_duration(int value) { m_ui_xinput_duration = value; };
    void set_ui_pre_engine_tick_duration(int value) { m_ui_pre_engine_tick_duration = value; };

    OuterWorldsVRWeapon* get_weapon() { return m_vr_weapon; };
    OuterWorldsVRHUD* get_hud() { return m_vr_hud; };
};
