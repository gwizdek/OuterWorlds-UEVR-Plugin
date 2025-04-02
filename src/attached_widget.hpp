#pragma once
#include "uevr/API.hpp"
#include "indiana/SDK/UMG_classes.hpp"

class AttachedWidget
{
    SDK::UWidgetComponent* m_widget_component{ nullptr };

    SDK::FTransform m_widget_transform{
        .Rotation = { SDK::UKismetMathLibrary::Quat_MakeFromEuler({ 0.f, 0.f, 270.0f }) },
        .Translation = { 0.f, 0.f, 0.f },
        .Scale3D = { 1.f, 0.04f, 0.04f }
    };
    float m_widget_opacity{ 0.5f };

public:
    AttachedWidget() = default;
    virtual ~AttachedWidget();

    SDK::FTransform get_transform();
    float get_opacity();

    void set_transform(SDK::FVector euler_rotation, SDK::FVector translation, float scale);
    void set_local_offset(float offset);
    void set_opacity(float opacity);

    bool attach(SDK::AActor* hand_actor, SDK::UUserWidget* widget, SDK::FTransform transform, SDK::FVector2D draw_size, const char* widget_name);
    SDK::UWidgetComponent* get_widget_component();
};
