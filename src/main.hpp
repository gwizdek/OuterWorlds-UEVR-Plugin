#pragma once
#include <windows.h>
#include <Xinput.h>
#include <unordered_set>

#include "indiana/SDK/Engine_classes.hpp"
#include "indiana/SDK/UMG_classes.hpp"
#include "indiana/SDK/Indiana_classes.hpp"
#include "indiana/SDK/IndianaPlayerCharacter_BP_classes.hpp"
#include "indiana/SDK/GenericCrosshair_BP_classes.hpp"

#include "hud.hpp"
#include "memo_structs.hpp"

#define STATIC_LOAD_ASSET_OFFSET 0x1C67740

typedef enum ModEvent {
    MOD_EVENT_VR_HUD_INITIALIZE,
    MOD_EVENT_ENABLE_WORLD_RENDERING
} ModEvent;

using namespace uevr;

class OuterWorldsHUD;
class OuterWorldsWeapon;
class OuterWorldsNativeFix;

class OuterWorldsMain
{
private:
    const char* MOD_VERSION = "0.1.0";

    OuterWorldsWeapon* m_vr_weapon{ nullptr };
    OuterWorldsHUD* m_vr_hud{ nullptr };
    OuterWorldsNativeFix* m_native_fix{ nullptr };

    bool m_ui_option_show_debug_view{ false };
    int m_ui_xinput_duration{ 0 };              // [microseconds]
    int m_ui_pre_engine_tick_duration{ 0 };     // [microseconds]

    // convenience pointers
    SDK::UWorld* m_world{ nullptr };
    SDK::AIndianaUI* m_ui{ nullptr };
    SDK::UHUDWidget* m_hud{ nullptr };
    SDK::AIndianaPlayerCharacter* m_player_character{ nullptr };
    SDK::AIndianaPlayerController* m_player_controller{ nullptr };

    // utils
    std::unordered_set<ModEvent> m_mod_events{};
    SDK::ECheckBranches m_reusable_branches{};
    int m_toggle_native_fix_counter{ -1 };

    // watched state
    MemoProperty<SDK::APawn*> m_pawn{ nullptr, nullptr };
    MemoProperty<SDK::ULevel*> m_level{ nullptr, nullptr };
    MemoProperty<SDK::UWeapon*> m_equipped_weapon{ nullptr, nullptr };
    MemoBoolean m_is_weapon_equipped{ false };
    MemoBoolean m_is_game_paused{ false };
    MemoBoolean m_is_interactable_in_range{ false };
    MemoBoolean m_is_conversation_camera_active{ false };
    MemoBoolean m_is_crouched{ false };
    MemoProperty<SDK::EWidgetOpenState> m_ui_ledger_open_state{ SDK::EWidgetOpenState::Minimized, SDK::EWidgetOpenState::Minimized };
    MemoProperty<SDK::EWidgetOpenState> m_ui_conversation_open_state{ SDK::EWidgetOpenState::Minimized, SDK::EWidgetOpenState::Minimized };
    MemoProperty<SDK::EWidgetOpenState> m_ui_computer_terminal_open_state{ SDK::EWidgetOpenState::Minimized, SDK::EWidgetOpenState::Minimized };
    MemoProperty<SDK::EWidgetOpenState> m_ui_workbench_open_state{ SDK::EWidgetOpenState::Minimized, SDK::EWidgetOpenState::Minimized };

    // controls
    MemoInput m_gamepad_btn_a{ XINPUT_GAMEPAD_A, "BTN_A" };
    MemoDualInput m_gamepad_left_thumb{ XINPUT_GAMEPAD_LEFT_THUMB, "LEFT_THUMB" };

    bool m_my_test_value{ true };
public:
    OuterWorldsMain();
    virtual ~OuterWorldsMain();

    void on_tick();
    void on_xinput(XINPUT_STATE* state);
    void on_draw_imgui();

    void prepare_pointers();
    bool prepare_state();
    
    // getters
    bool get_test_value() { return m_my_test_value; };
    bool get_ui_option_show_debug_view() { return m_ui_option_show_debug_view; };
    OuterWorldsWeapon* get_weapon() { return m_vr_weapon; };
    OuterWorldsHUD* get_hud() { return m_vr_hud; };
    SDK::AIndianaPlayerCharacter* get_player_character() { return m_player_character; };
    
    // setters
    void set_ui_xinput_duration(int value) { m_ui_xinput_duration = value; };
    void set_ui_pre_engine_tick_duration(int value) { m_ui_pre_engine_tick_duration = value; };

    // handlers
    void handle_controller_input(XINPUT_STATE* state);
};
