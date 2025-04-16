#pragma once
#include "uevr/API.hpp"
#include "indiana/SDK/UMG_classes.hpp"
#include "mINI/ini.h"

class AttachedWidget
{
    SDK::UWidgetComponent* m_widget_component{ nullptr };

    SDK::FTransform m_widget_transform{
        .Rotation = { SDK::UKismetMathLibrary::Quat_MakeFromEuler({ 0.f, 0.f, 270.0f }) },
        .Translation = { 0.f, 0.f, 0.f },
        .Scale3D = { 1.f, 0.04f, 0.04f }
    };
    float m_widget_opacity{ 0.5f };
    std::string m_widget_name{"##attached_widget"};
    std::string m_widget_ui_name{ "Attached Widget" };

public:
    AttachedWidget() = default;
    virtual ~AttachedWidget();

    SDK::UWidgetComponent* get_widget_component();
    SDK::FTransform get_transform();
    float get_opacity();

    void set_transform(SDK::FVector euler_rotation, SDK::FVector translation, float scale);
    void set_opacity(float opacity);

    bool attach(SDK::AActor* hand_actor, SDK::UUserWidget* widget, SDK::FTransform transform, SDK::FVector2D draw_size, const char* widget_name, const char* widget_ui_name);
    bool is_valid();
    void on_draw_imgui();
    void on_load_config(mINI::INIStructure& config);
    void on_save_config(mINI::INIStructure& config);
};
