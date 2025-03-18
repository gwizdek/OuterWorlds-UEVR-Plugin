#pragma once

#include "uevr/API.hpp"
#include "indiana/SDK/Indiana_classes.hpp"
#include "indiana/SDK/UMG_classes.hpp"

using namespace uevr;

class VRHUDAmmoReadout
{
private:
    // widget components
    SDK::UWidgetComponent* m_ammo_readout_widget_component{ nullptr };

public:
    VRHUDAmmoReadout() = default;

    virtual ~VRHUDAmmoReadout() {
        API::get()->log_info("VRHUD AmmoReadout :: Destructor");
    }

    bool attach_ammo_readout(
        SDK::AActor* right_hand_attachments_actor,
        SDK::UHUDWidget* hud
    ) {
        if (right_hand_attachments_actor == nullptr || hud == nullptr) {
            API::get()->log_warn("VRHUD :: Attach Ammo Readout :: Pointers not valid");
            return false;
        }

        if (m_ammo_readout_widget_component != nullptr) {
            API::get()->log_warn("VRHUD :: Attach Ammo Readout :: Already attached");
            return false;
        }

        if (!SDK::UKismetSystemLibrary::IsValid(hud->AmmoReadout)) {
            API::get()->log_warn("VRHUD :: Attach Ammo Readout :: Can't access Minimap");
            return false;
        }

        SDK::FTransform widget_transform{};
        widget_transform.Rotation = SDK::UKismetMathLibrary::Quat_MakeFromEuler({ 0.f, 0.f, 270.0f });
        widget_transform.Translation = { -10.f, -3.f, 4.f };
        widget_transform.Scale3D = { 1.f, 0.04f, 0.04f };

        m_ammo_readout_widget_component = static_cast<SDK::UWidgetComponent*>(
            right_hand_attachments_actor->AddComponentByClass(
                SDK::UWidgetComponent::StaticClass(), false, widget_transform, false
            )
        );

        if (m_ammo_readout_widget_component == nullptr) {
            API::get()->log_warn("VRHUD :: Attach Ammo Readout :: Failed to attach component");
            return false;
        }

        hud->AmmoReadout->RemoveFromViewport();
        m_ammo_readout_widget_component->SetDrawSize({ 300.0f, 150.0f });
        m_ammo_readout_widget_component->SetWidget(hud->AmmoReadout);
        m_ammo_readout_widget_component->SetVisibility(true, true);
        m_ammo_readout_widget_component->SetHiddenInGame(false, false);
        m_ammo_readout_widget_component->SetCollisionEnabled(SDK::ECollisionEnabled::NoCollision);

        auto material = API::get()->find_uobject<SDK::UMaterialInstanceConstant>(
            // L"MaterialInstanceConstant /Engine/EngineMaterials/Widget3DPassThrough_Opaque.Widget3DPassThrough_Opaque"
            L"MaterialInstanceConstant /Engine/EngineMaterials/Widget3DPassThrough_Translucent.Widget3DPassThrough_Translucent"
        );
        SDK::FLinearColor color{ 1.f, 1.f, 1.f, 0.5f };
        m_ammo_readout_widget_component->SetMaterial(0, material);
        m_ammo_readout_widget_component->SetTintColorAndOpacity(color);

        right_hand_attachments_actor->FinishAddComponent(m_ammo_readout_widget_component, false, widget_transform);

        API::get()->log_warn("VRHUD :: Attach Ammo Readout :: Attached Widget");

        return true;
    }
};
