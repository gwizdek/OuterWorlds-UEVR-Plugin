#pragma once
#include <windows.h>
#include <Xinput.h>
#include <unordered_set>
#include <map>

#include "mINI/ini.h"

#include "indiana/SDK/Engine_classes.hpp"
#include "indiana/SDK/UMG_classes.hpp"
#include "indiana/SDK/Indiana_classes.hpp"
#include "indiana/SDK/IndianaPlayerCharacter_BP_classes.hpp"
#include "indiana/SDK/GenericCrosshair_BP_classes.hpp"

#include "memo_structs.hpp"
#include "vr_controllers.hpp"

typedef enum HandPreference {
    RIGHT_HANDED,
    LEFT_HANDED
} HandPreference;

typedef enum ModEvent {
    MOD_EVENT_VR_HUD_INITIALIZE,
    MOD_EVENT_ENABLE_WORLD_RENDERING
} ModEvent;

typedef enum GameState {
    GAME_STATE_PLAYING,
    GAME_STATE_MAIN_MENU,
    GAME_STATE_PAUSE_MENU,
    GAME_STATE_LEDGER,
    GAME_STATE_WORKBENCH,
    GAME_STATE_CONVERSATION,
    GAME_STATE_CINEMATIC,
    GAME_STATE_COMPUTER_TERMINAL,
    GAME_STATE_UNDEFINED
} GameState;

static std::map<GameState, const char*> GameStateName = {
    { GAME_STATE_PLAYING, "Playing" },
    { GAME_STATE_MAIN_MENU, "Main Menu" },
    { GAME_STATE_PAUSE_MENU, "Pause Menu" },
    { GAME_STATE_LEDGER, "Ledger" },
    { GAME_STATE_WORKBENCH, "Workbench" },
    { GAME_STATE_CONVERSATION, "Conversation" },
    { GAME_STATE_CINEMATIC, "Cinematic" },
    { GAME_STATE_COMPUTER_TERMINAL, "Computer Terminal" },
    { GAME_STATE_UNDEFINED, "Undefined" }
};

using namespace uevr;

class OuterWorldsHUD;
class OuterWorldsWeapon;
class OuterWorldsFlickerFixer;

class OuterWorldsMain
{
private:
    const char* MOD_VERSION = "6DOF Guns v0.2.0";

    VRControllers* m_vr_controllers{ nullptr };
    OuterWorldsWeapon* m_vr_weapon{ nullptr };
    OuterWorldsHUD* m_vr_hud{ nullptr };
    OuterWorldsFlickerFixer* m_flicker_fixer{ nullptr };

    bool m_ui_option_show_debug_view{ false };
    int m_ui_xinput_duration{ 0 };              // [microseconds]
    int m_ui_pre_engine_tick_duration{ 0 };     // [microseconds]

    // convenience pointers
    SDK::UWorld* m_world{ nullptr };
    SDK::AIndianaUI* m_ui{ nullptr };
    SDK::UHUDWidget* m_hud{ nullptr };
    SDK::APawn* m_pawn{ nullptr };
    SDK::AIndianaPlayerCharacter* m_player_character{ nullptr };
    SDK::AIndianaPlayerController* m_player_controller{ nullptr };

    // utils
    std::unordered_set<ModEvent> m_mod_events{};
    SDK::ECheckBranches m_reusable_branches{};
    int m_toggle_native_fix_counter{ -1 };

    // watched state
    MemoProperty<GameState> m_game_state{ GAME_STATE_UNDEFINED, GAME_STATE_UNDEFINED };
    MemoProperty<SDK::ULevel*> m_level{ nullptr, nullptr };
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

    void on_tick(float delta);
    void on_xinput(XINPUT_STATE* state);
    void on_draw_imgui();
    bool load_mod_config();
    bool save_mod_config();
    void cleanup_pointers();
    static void cleanup_actors();

    void prepare_pointers();
    void prepare_state();
    void prepare_game_state();
    
    // getters
    bool get_test_value() { return m_my_test_value; };
    bool get_ui_option_show_debug_view() { return m_ui_option_show_debug_view; };
    VRControllers* get_vr_controllers() { return m_vr_controllers; };
    OuterWorldsWeapon* get_weapon() { return m_vr_weapon; };
    SDK::UHUDWidget* get_hud() { return m_hud; };
    SDK::AIndianaPlayerCharacter* get_player_character() { return m_player_character; };
    
    // setters
    void set_ui_xinput_duration(int value) { m_ui_xinput_duration = value; };
    void set_ui_pre_engine_tick_duration(int value) { m_ui_pre_engine_tick_duration = value; };
    void set_idle_camera_time(float seconds_to_wait);
    void set_mouse_cursor();
    void set_ability_overview_visibility(bool visible);

    // handlers
    void handle_controller_input(XINPUT_STATE* state);
    void handle_level_change();
    void handle_game_state();
    void handle_mod_events();
    void handle_crouch();
    void handle_weapon();

    // fixes
    void fix_player_highlighter();
    void fix_cinematic_camera();
    void fix_ledger();
    void fix_workbench();
};
