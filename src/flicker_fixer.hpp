#pragma once
#include "main.hpp"

class OuterWorldsMain;

class OuterWorldsFlickerFixer
{
private:
    OuterWorldsMain* m_main{ nullptr };
    SDK::AActor* m_flicker_fixer_actor{ nullptr };
    SDK::USceneCaptureComponent2D* m_scene_capture_component{ nullptr };
    SDK::UTextureRenderTarget2D* m_render_target{ nullptr };

    bool m_is_paused_daytime{ false };
    int m_toggle_native_fix_counter{ -1 };
    
    float m_max_idle_duration{ 10.f }; // [s]
    float m_max_active_duration{ 0.15f }; // [s]
    float m_current_duration{ 6.f };
    bool m_capture_active{ false };

public:
    OuterWorldsFlickerFixer(OuterWorldsMain* main);
    virtual ~OuterWorldsFlickerFixer() {};

    void set_capture(bool active);
    void pause_daytime(bool pause);
    void spawn_flicker_fixer();
    void cycle(int delay);
    bool is_valid();
    void on_tick(float delta);
    void cleanup_pointers();
    static void cleanup_actors();
    void on_load_config(mINI::INIStructure& config);
    void on_save_config(mINI::INIStructure& config);
    void on_draw_imgui();
};
