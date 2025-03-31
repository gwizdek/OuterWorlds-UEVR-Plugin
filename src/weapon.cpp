#include "uevr/API.hpp"

#include "indiana/SDK/Niagara_classes.hpp"

#include "weapon.hpp"

using namespace uevr;

OuterWorldsWeapon::OuterWorldsWeapon(OuterWorldsMain* main, VRControllers* controllers, HandPreference hand_preference) {
    m_main = main;
    m_vr_controllers = controllers;
    m_hand_preference = hand_preference;
}

bool OuterWorldsWeapon::is_valid() {
    return true;
}

void OuterWorldsWeapon::initialize() {
    try {
        if (m_vr_controllers != nullptr && m_vr_controllers->is_valid()) {
            SDK::FTransform zero_transform{
                .Rotation = { 0.f, 0.f, 0.f, 1.f },
                .Translation = { 0.f, 0.f, 0.f },
                .Scale3D = { 1.f, 1.f, 1.f }
            };
            // particle pointer offset component
            m_particle_pointer_offset_component = static_cast<SDK::USceneComponent*>(
                m_vr_controllers->get_right_hand_actor()->AddComponentByClass(SDK::USceneComponent::StaticClass(), false, zero_transform, true)
                );
            if (m_particle_pointer_offset_component == nullptr) {
                API::get()->log_error("[weapon][initialize] Failed to add Particle Pointer Offset component");
                return;
            }
            m_vr_controllers->get_right_hand_actor()->FinishAddComponent(m_particle_pointer_offset_component, false, zero_transform);
            API::get()->log_warn("[weapon][initialize] Added Particle Pointer Offset component");

            if (!m_particle_pointer_offset_component->K2_AttachTo(
                m_vr_controllers->get_rh_controller_component(),
                SDK::UKismetStringLibrary::Conv_StringToName(L"None"),
                SDK::EAttachLocation::KeepRelativeOffset,
                false
            )) {
                API::get()->log_error("[weapon][initialize] Failed to Attach Particle Pointer Offset Component");
            }
        }
    }
    catch (...) {
        API::get()->log_error("[weapon][initialize] Exception");
    }
}

void OuterWorldsWeapon::tick() {
    try {
        if (m_main != nullptr) {

            //API::get()->log_warn("[Weapon][tick] Crouched: %s", m_common->get_test_value() ? "YES" : "NO");
        }
    }
    catch (...) {
        API::get()->log_error("[weapon][tick] Exception");
    }
}

void OuterWorldsWeapon::set_equipped_weapon(SDK::UWeapon* weapon) {
    if (m_equipped_weapon != weapon) {
        m_equipped_weapon = weapon;
        API::get()->log_warn("[weapon][set_equipped_weapon] New Weapon: %s", weapon->GetFullName().c_str());
        fix_materials();
        set_weapon_type();
        set_offset_component();
    }
}

void OuterWorldsWeapon::fix_materials() {
    // fixing weapon materials
    try {
        if (SDK::UKismetSystemLibrary::IsValid(m_equipped_weapon) && m_equipped_weapon->SkeletalMeshComponent != nullptr) {
            // main weapon components
            for (auto material : m_equipped_weapon->SkeletalMeshComponent->OverrideMaterials) {
                if (material->IsA(SDK::UMaterialInstanceDynamic::StaticClass())) {
                    static_cast<SDK::UMaterialInstanceDynamic*>(material)->SetScalarParameterValue(
                        SDK::UKismetStringLibrary::Conv_StringToName(L"ForegroundPriorityEnabled"), 0.f
                    );
                    //static_cast<SDK::UMaterialInstanceDynamic*>(material)->GetBaseMaterial()->BlendMode = SDK::EBlendMode::BLEND_Additive;
                }
            }

            for (auto child : m_equipped_weapon->SkeletalMeshComponent->AttachChildren) {
                // weapon modifications
                if (child->IsA(SDK::UStaticMeshComponent::StaticClass())) {
                    for (auto material : static_cast<SDK::UStaticMeshComponent*>(child)->OverrideMaterials) {
                        if (material->IsA(SDK::UMaterialInstanceDynamic::StaticClass())) {
                            static_cast<SDK::UMaterialInstanceDynamic*>(material)->SetScalarParameterValue(
                                SDK::UKismetStringLibrary::Conv_StringToName(L"ForegroundPriorityEnabled"), 0.f
                            );
                            //static_cast<SDK::UMaterialInstanceDynamic*>(material)->GetBaseMaterial()->BlendMode = SDK::EBlendMode::BLEND_Additive;
                        }
                    }
                }

                // niagara effects
                if (child->IsA(SDK::UNiagaraComponent::StaticClass())) {
                    static_cast<SDK::UNiagaraComponent*>(child)->SetNiagaraVariableFloat(L"ForegroundPriorityEnabled", 0.f);
                }
            }
            //m_equipped_weapon->SkeletalMeshComponent->SetCollisionEnabled(SDK::ECollisionEnabled::QueryAndPhysics);
            //m_equipped_weapon->SkeletalMeshComponent->SetCollisionResponseToAllChannels(SDK::ECollisionResponse::ECR_Block);
            //m_equipped_weapon->SkeletalMeshComponent->SetCollisionObjectType(SDK::ECollisionChannel::ECC_PhysicsBody);
            //m_equipped_weapon->SkeletalMeshComponent->SetSimulatePhysics(true);
            //m_equipped_weapon->SkeletalMeshComponent->SetEnableGravity(false);
            //m_equipped_weapon->SkeletalMeshComponent->AddImpulse(SDK::FVector{ 0.f, 10.f, 10.f }, SDK::FName(), true);

        }
    }
    catch (...) {
        API::get()->log_error("[weapon][fix_materials] Exception");
    }
}

void OuterWorldsWeapon::set_weapon_type() {
    try {
        if (m_equipped_weapon != nullptr && m_equipped_weapon->SkeletalMeshComponent != nullptr) {
            auto weapon_mode = m_equipped_weapon->GetCurrentMode();
            if (
                weapon_mode->IsA(SDK::URangedMode::StaticClass()) ||
                SDK::UKismetMathLibrary::ClassIsChildOf(weapon_mode->Class, SDK::URangedMode::StaticClass())
                ) {
                m_weapon_type = WEAPON_TYPE_RANGED;
                static_cast<SDK::URangedMode*>(weapon_mode)->FineAimFovAdjustment = 0.f;
                static_cast<SDK::URangedMode*>(weapon_mode)->FineAimLookStickRateMultiplier = 0.00001f;

                is_scoped_weapon = static_cast<SDK::URangedMode*>(weapon_mode)->HasScope();

                //if (m_equipped_weapon->SkeletalMeshComponent->DoesSocketExist(SDK::UKismetStringLibrary::Conv_StringToName(L"Sight_Socket"))) {
                //    // get scope transform
                //    offset_transform = m_equipped_weapon->SkeletalMeshComponent->GetSocketTransform(
                //        SDK::UKismetStringLibrary::Conv_StringToName(L"Sight_Socket"), SDK::ERelativeTransformSpace::RTS_Component
                //    );
                //    m_vr_hud->set_scope_offset({ 0.f, 0.f, offset_transform.Translation.Z });
                //}
                //else {
                //}
            } else if (
                weapon_mode->IsA(SDK::UMeleeMode::StaticClass()) ||
                weapon_mode->IsA(SDK::UMeleeMultiDamageTypeMode::StaticClass())
                ) {
                m_weapon_type = WEAPON_TYPE_MELEE;
                is_scoped_weapon = false;
            }
            else {
                m_weapon_type = WEAPON_TYPE_UNARMED;
                is_scoped_weapon = false;
            }
        }
        else {
            m_weapon_type = WEAPON_TYPE_UNDEFINED;
            is_scoped_weapon = false;
        }
    }
    catch (...) {
        API::get()->log_error("[weapon][set_weapon_type] Exception");
    }
}

void OuterWorldsWeapon::set_offset_component() {
    static SDK::FHitResult h_result{};
    // offset FPVCamera to match weapon barrel
    try {
        if (m_equipped_weapon != nullptr && m_equipped_weapon->SkeletalMeshComponent != nullptr) {
            // get barrel transform
            auto offset_transform = m_equipped_weapon->SkeletalMeshComponent->GetSocketTransform(
                SDK::UKismetStringLibrary::Conv_StringToName(L"MuzzleFlashSocket"), SDK::ERelativeTransformSpace::RTS_Component
            );
            const UEVR_Vector3f offset{ 0.f, -offset_transform.Translation.Z, 0.f };
            m_particle_pointer_offset_component->K2_SetRelativeLocation({ 0.f, 0.f, offset_transform.Translation.Z }, false, &h_result, false);

            API::UObjectHook::get_or_add_motion_controller_state((API::UObject*)m_main->get_player_character()->FPVCamera)->set_location_offset(&offset);
        }
    }
    catch (...) {
        API::get()->log_error("[weapon][set_offset_component] Exception");
    }
}

//void set_particle_pointer_visibility(bool visible) {
//    if (m_particle_pointer_component != nullptr) {
//        m_particle_pointer_component->SetVisibility(visible, false);
//    }
//}
//
//float get_line_trace_distance() {
//    return m_reusable_result.Distance;
//}
//
//void set_particle_pointer_offset(SDK::FVector offset) {
//    m_particle_pointer_offset = offset;
//}
//
//void set_scope_offset(SDK::FVector offset) {
//    static SDK::FHitResult h_result{};
//    if (m_scope_component != nullptr) {
//        m_scope_component->K2_SetRelativeLocation(offset, false, &h_result, false);
//    }
//}
//
//void set_scope_visibility(bool visible) {
//    if (m_scope_component != nullptr) {
//        m_scope_component->SetVisibility(visible, true);
//        m_scope_component->SetHiddenInGame(!visible, true);
//    }
//}


void OuterWorldsWeapon::destroy() {
    //API::get()->log_warn("[VR HUD] :: Destroying actors");

    //if (SDK::UKismetSystemLibrary::IsValid(m_hmd_actor) && m_weapon_scope_actor->IsA(SDK::AActor::StaticClass())) {
    //    m_weapon_scope_actor->K2_DestroyActor();
    //    API::get()->log_warn("[VR HUD] :: Weapon Scope Actor destroyed");
    //}
}