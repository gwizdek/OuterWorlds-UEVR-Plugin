#include "vr_attached_widget.hpp"

using namespace uevr;

VRAttachedWidget::~VRAttachedWidget() {
    API::get()->log_warn("[VRAttachedWidget] :: Destructor");
}

SDK::FTransform VRAttachedWidget::get_transform() {
    return m_widget_transform;
}

SDK::UWidgetComponent* VRAttachedWidget::get_widget_component() {
    return m_widget_component;
}

void VRAttachedWidget::set_transform(SDK::FVector euler_rotation, SDK::FVector translation, float scale) {
    m_widget_transform.Rotation = SDK::UKismetMathLibrary::Quat_MakeFromEuler(euler_rotation);
    m_widget_transform.Translation = translation;
    m_widget_transform.Scale3D = { 1.f, scale, scale };

    SDK::FHitResult hit_result{};
    m_widget_component->K2_SetRelativeTransform(m_widget_transform, false, &hit_result, false);
}

float VRAttachedWidget::get_opacity() {
    return m_widget_opacity;
}

void VRAttachedWidget::set_opacity(float opacity) {
    m_widget_opacity = opacity;
    SDK::FLinearColor color{ 1.f, 1.f, 1.f, m_widget_opacity };
    m_widget_component->SetTintColorAndOpacity(color);
}

void VRAttachedWidget::set_local_offset(float offset) {
    static bool computed_visibility = offset > 20.f && offset < 300.f;
    m_widget_component->SetVisibility(computed_visibility, computed_visibility);
    m_widget_component->SetHiddenInGame(!computed_visibility, !computed_visibility);
    
    static SDK::FHitResult hit_result{};
    m_widget_component->K2_SetRelativeLocation(SDK::FVector{ offset, 0.f, 0.f }, false, &hit_result, false);
}

bool VRAttachedWidget::attach(SDK::AActor* hand_actor, SDK::UUserWidget* widget, SDK::FTransform transform, SDK::FVector2D draw_size, const char* widget_name) {
    API::get()->log_warn("[VRAttachedWidget] :: Attaching [%s]", widget_name);
    if (hand_actor == nullptr || widget == nullptr) {
        API::get()->log_warn("[VRAttachedWidget] :: [%s] Pointers not valid", widget_name);
        return false;
    }

    if (m_widget_component != nullptr) {
        API::get()->log_warn("[VRAttachedWidget] :: [%s] Already attached", widget_name);
        return false;
    }

    if (!SDK::UKismetSystemLibrary::IsValid(widget)) {
        API::get()->log_warn("[VRAttachedWidget] :: [%s] Invalid widget", widget_name);
        return false;
    }

    m_widget_transform = transform;

    m_widget_component = static_cast<SDK::UWidgetComponent*>(
        hand_actor->AddComponentByClass(SDK::UWidgetComponent::StaticClass(), false, m_widget_transform, false)
        );

    if (m_widget_component == nullptr) {
        API::get()->log_warn("[VRAttachedWidget] :: [%s] Failed to attach component", widget_name);
        return false;
    }

    widget->RemoveFromViewport();
    m_widget_component->SetDrawSize(draw_size);
    m_widget_component->SetWidget(widget);
    m_widget_component->SetVisibility(true, true);
    m_widget_component->SetHiddenInGame(false, false);
    m_widget_component->SetCollisionEnabled(SDK::ECollisionEnabled::NoCollision);

    auto material = API::get()->find_uobject<SDK::UMaterialInstanceConstant>(
        // L"MaterialInstanceConstant /Engine/EngineMaterials/Widget3DPassThrough_Opaque.Widget3DPassThrough_Opaque"
        L"MaterialInstanceConstant /Engine/EngineMaterials/Widget3DPassThrough_Translucent.Widget3DPassThrough_Translucent"
    );

    m_widget_component->SetMaterial(0, material);
    set_opacity(0.6f);
    m_widget_component->BlendMode = SDK::EWidgetBlendMode::Transparent;

    hand_actor->FinishAddComponent(m_widget_component, false, m_widget_transform);

    API::get()->log_warn("[VRAttachedWidget] :: [%s] Successfully Attached", widget_name);

    return true;
}
