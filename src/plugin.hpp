#pragma once

#include <windows.h>
#include <memory>
#include <unordered_set>

//#include <stdio.h>
//#include <string.h>
//#include <mutex>
//#include <iostream>
//#include <codecvt>
//#include <chrono>
//#include <map>
//#include <set>


#include "imgui/imgui.h"
#include "imgui/imgui_impl_dx11.h"
#include "imgui/imgui_impl_dx12.h"
#include "imgui/imgui_impl_win32.h"

#include "rendering/d3d11.hpp"
#include "rendering/d3d12.hpp"

#include "indiana/SDK/Engine_classes.hpp"
#include "indiana/SDK/UMG_classes.hpp"
#include "indiana/SDK/Indiana_classes.hpp"
#include "indiana/SDK/IndianaPlayerCharacter_BP_classes.hpp"
#include "indiana/SDK/GenericCrosshair_BP_classes.hpp"

#include "uevr/API.hpp"
#include "uevr/Plugin.hpp"
#include "plugin_shared.hpp"
#include "plugin_vr_hud.hpp"
#include "plugin_config.hpp"
//#include "pch.h"

#define  _CRT_SECURE_NO_WARNINGS 1
#define  _SILENCE_CXX17_CODECVT_HEADER_DEPRECATION_WARNING 1
#define _DEBUG_DURATIONS 0

#define PLUGIN_LOG_ONCE(...) { \
    static bool _logged_ = false; \
    if (!_logged_) { \
        _logged_ = true; \
        API::get()->log_info(__VA_ARGS__); \
    } }

#define PLUGIN_LOG_ONCE_WARN(...) { \
    static bool _logged_ = false; \
    if (!_logged_) { \
        _logged_ = true; \
        API::get()->log_warn(__VA_ARGS__); \
    } }

#define PLUGIN_LOG_ONCE_ERROR(...) { \
    static bool _logged_ = false; \
    if (!_logged_) { \
        _logged_ = true; \
        API::get()->log_error(__VA_ARGS__); \
    } }

#define INPUT_DEADZONE_LO  ( 0.01f * FLOAT(0x7FFF) )  // Default to 01% of the +/- 32767 range.
#define INPUT_DEADZONE_MED ( 0.45f * FLOAT(0x7FFF) )  // Default to 45% of the +/- 32767 range.
#define INPUT_DEADZONE_HI  ( 0.80f * FLOAT(0x7FFF) )  // Default to 80% of the +/- 32767 range.

extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

// Global accessor for our plugin.
class OuterWorldsPlugin;
extern std::unique_ptr<OuterWorldsPlugin> g_plugin;

//class OuterWorldsPluginConfig;

class OuterWorldsPlugin : public uevr::Plugin {
public:
    OuterWorldsPlugin() = default;
    virtual ~OuterWorldsPlugin();

    // Main plugin callbacks
    void on_dllmain() override;
    void on_initialize() override;
    void on_present() override;
    void on_device_reset() override;
    bool on_message(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) override;
    void on_xinput_get_state(uint32_t* retval, uint32_t user_index, XINPUT_STATE* state) override;

    // Game/Engine callbacks
    void on_pre_engine_tick(uevr::API::UGameEngine* engine, float delta) override;

    // ImGui
    bool initialize_imgui();
    void internal_frame();
    void on_post_render_vr_framework_dx11(ID3D11DeviceContext* context, ID3D11Texture2D* texture, ID3D11RenderTargetView* rtv) override;
    void on_post_render_vr_framework_dx12(ID3D12GraphicsCommandList* command_list, ID3D12Resource* rt, D3D12_CPU_DESCRIPTOR_HANDLE* rtv) override;

    // -------------------------------------------------------------------------------------------------------
    const char* MOD_VERSION = "0.1.0";

    // VR HUD
    OuterWorldsVRHUD* m_vr_hud{ nullptr };
    OuterWorldsPluginConfig* m_config{ nullptr };

    // convenience pointers
    SDK::UWorld* m_world{ nullptr };
    SDK::AIndianaUI* m_ui{ nullptr };
    SDK::UHUDWidget* m_hud{ nullptr };
    SDK::AIndianaPlayerCharacter* m_player_character{ nullptr };
    SDK::AIndianaPlayerController* m_player_controller{ nullptr };

    // utils
    //std::recursive_mutex m_imgui_mutex{};
    std::unordered_set<ModEvent> m_mod_events{};
    SDK::FName m_foreground_priority_fname{
        .ComparisonIndex = 0,
        .Number = 0
    };
    SDK::ECheckBranches m_reusable_branches{};
    bool m_xinput_cb_processed{ false };
    int m_toggle_native_fix_counter{ -1 };

    // state
    MemoProperty<SDK::APawn*> m_pawn{ nullptr, nullptr };
    MemoProperty<SDK::ULevel*> m_level{ nullptr, nullptr };
    MemoProperty<SDK::UWeapon*> m_equipped_weapon{ nullptr, nullptr };
    MemoBoolean m_is_weapon_equipped{ false };
    MemoBoolean m_is_game_paused{ false };
    MemoBoolean m_is_interactable_in_range{ false };
    MemoBoolean m_is_conversation_camera_active{ false };
    MemoBoolean m_is_crouched{ false };
    bool m_is_paused_daytime{ false };

    bool m_wirsts_attached{ false };
    bool m_arms_wirsts_attached{ false };
    MemoProperty<SDK::EWidgetOpenState> m_ui_ledger_open_state{ SDK::EWidgetOpenState::Minimized, SDK::EWidgetOpenState::Minimized };
    MemoProperty<SDK::EWidgetOpenState> m_ui_conversation_open_state{ SDK::EWidgetOpenState::Minimized, SDK::EWidgetOpenState::Minimized };
    MemoProperty<SDK::EWidgetOpenState> m_ui_computer_terminal_open_state{ SDK::EWidgetOpenState::Minimized, SDK::EWidgetOpenState::Minimized };
    MemoProperty<SDK::EWidgetOpenState> m_ui_workbench_open_state{ SDK::EWidgetOpenState::Minimized, SDK::EWidgetOpenState::Minimized };

    // controls
    MemoInput m_gamepad_btn_a{ XINPUT_GAMEPAD_A, "BTN_A" };
    MemoDualInput m_gamepad_left_thumb{ XINPUT_GAMEPAD_LEFT_THUMB, "LEFT_THUMB" };

    // ImGui
    HWND m_wnd{};
    bool m_imgui_initialized{ false };
    bool m_was_rendering_desktop{ false };
    bool m_ui_option_show_debug_view{ false };

    // debug
    const int CB_DURATION_SAMPLE_RATE = 100;
    int m_cb_calls_count{ 0 };
    int m_ui_xinput_duration{ 0 }; // [microseconds]
    int m_ui_pre_engine_tick_duration{ 0 }; // [microseconds]

    SDK::UParticleSystemComponent* m_emitter{ nullptr };

    void prepare_pointers();
    bool prepare_state(const UEVR_VRData* vr);
    void handle_hud();
    void handle_weapon_change();
    void handle_level_change(const UEVR_VRData* vr);
    void handle_controller_input(XINPUT_STATE* state, const UEVR_VRData* vr);
    void handle_crouch(const UEVR_VRData* vr);
    void handle_mod_events();
    void pause_daytime(bool pause);
    void cycle_native_fix();
    void handle_native_fix(const UEVR_VRData* vr);
    void fix_weapon_materials();
    void fix_player_character_materials();
    void fix_player_highlighter();
    void fix_cinematic_camera();
    void fix_weapon_ironsights_offset();
    void show_ability_overview(bool visible);
    void set_mouse_cursor();
    void set_idle_camera_time(float seconds_to_wait);
    void attach_animation();
    void manipulate_animation();
    void attach_controllers_to_wirsts();
    void update_wirsts_location(const UEVR_VRData* vr);
    void attach_controllers_to_arms_wirsts();
    void update_arms_wirsts_location(const UEVR_VRData* vr);
    void set_player_mesh_visibility(bool value);
    void set_arms_mesh_visibility(bool value);
    void set_personality();
    void reset_height(const UEVR_VRData* vr, float offset_y = 0.0f);
    void update_character_animation(float delta);
    void handle_vr_view(const UEVR_VRData* vr);
    void update_camera(const UEVR_VRData* vr);
    bool is_interactable_in_range();
    bool modify_interactables_in_range();
    bool is_vr_hud_valid();
    void test_func();
    void test_func2();
    //void load_asset(uintptr_t fn_address);
};
