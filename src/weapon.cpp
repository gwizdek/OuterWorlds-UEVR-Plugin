#include "uevr/API.hpp"

#include "indiana/SDK/Niagara_classes.hpp"

#include "weapon.hpp"
#include "imgui/imgui.h"

using namespace uevr;

OuterWorldsWeapon::OuterWorldsWeapon(OuterWorldsMain* main, HandPreference hand_preference) {
    m_main = main;
    m_hand_preference = hand_preference;
}

bool OuterWorldsWeapon::is_valid() {
    if (
        m_equipped_weapon != nullptr &&
        m_particle_pointer_component != nullptr &&
        m_particle_pointer_offset_component != nullptr
        ) {
        return true;
    }
    return false;
}

void OuterWorldsWeapon::initialize() {
    try {
        if (m_main->get_vr_controllers() != nullptr && m_main->get_vr_controllers()->is_valid()) {
            SDK::FTransform zero_transform{
                .Rotation = { 0.f, 0.f, 0.f, 1.f },
                .Translation = { 0.f, 0.f, 0.f },
                .Scale3D = { 1.f, 1.f, 1.f }
            };
            // particle pointer offset component
            m_particle_pointer_offset_component = static_cast<SDK::USceneComponent*>(
                m_main->get_vr_controllers()->get_right_hand_actor()->AddComponentByClass(SDK::USceneComponent::StaticClass(), false, zero_transform, true)
                );
            if (m_particle_pointer_offset_component == nullptr) {
                API::get()->log_error("[weapon][initialize] Failed to add Particle Pointer Offset component");
                return;
            }
            m_main->get_vr_controllers()->get_right_hand_actor()->FinishAddComponent(m_particle_pointer_offset_component, false, zero_transform);
            API::get()->log_warn("[weapon][initialize] Added Particle Pointer Offset component");

            if (!m_particle_pointer_offset_component->K2_AttachTo(
                m_main->get_vr_controllers()->get_rh_controller_component(),
                SDK::UKismetStringLibrary::Conv_StringToName(L"None"),
                SDK::EAttachLocation::KeepRelativeOffset,
                false
            )) {
                API::get()->log_error("[weapon][initialize] Failed to Attach Particle Pointer Offset Component");
            }
            API::get()->log_warn("[weapon][initialize] Attached Particle Pointer Offset component to RH controller");

            spawn_particle_pointer();
        }
    }
    catch (...) {
        API::get()->log_error("[weapon][initialize] Exception");
    }
}

void OuterWorldsWeapon::cleanup_pointers() {
    API::get()->log_warn("[weapon][cleanup_pointers] Cleanup");

    m_particle_pointer_component = nullptr;
    m_particle_pointer_offset_component = nullptr;
    m_equipped_weapon = nullptr;
    m_weapon_type = WEAPON_TYPE_UNKNOWN;
    m_has_scope = false;
}

void OuterWorldsWeapon::tick() {
    try {
        if (m_main != nullptr) {

            // when loading a save uevr has problem rendering a frame and trigering these setters in set_equipped weapon
            if (m_weapon_type == WEAPON_TYPE_UNKNOWN) {
                set_materials();
                set_weapon_type();
            }

            update_particle_pointer();
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
        set_materials();
        set_weapon_type();
    }
}

void OuterWorldsWeapon::set_materials() {
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
        API::get()->log_error("[weapon][set_materials] Exception");
    }
}

void OuterWorldsWeapon::set_weapon_type() {
    try {
        if (m_equipped_weapon != nullptr && m_equipped_weapon->SkeletalMeshComponent != nullptr) {
            auto weapon_mode = m_equipped_weapon->GetCurrentMode();
            if (
                weapon_mode->IsA(SDK::URangedMode::StaticClass()) ||
                SDK::UKismetMathLibrary::ClassIsChildOf(weapon_mode->StaticClass(), SDK::URangedMode::StaticClass())
                ) {
                m_weapon_type = WEAPON_TYPE_RANGED;

                // remove extra fov adjustment for fine aim
                static_cast<SDK::URangedMode*>(weapon_mode)->FineAimFovAdjustment = 0.f;
                static_cast<SDK::URangedMode*>(weapon_mode)->FineAimLookStickRateMultiplier = 0.00001f;

                m_has_scope = static_cast<SDK::URangedMode*>(weapon_mode)->HasScope();

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
                m_has_scope = false;
            }
            else {
                m_weapon_type = WEAPON_TYPE_UNARMED;
                m_has_scope = false;
            }
        }
        else {
            m_weapon_type = WEAPON_TYPE_UNKNOWN;
            m_has_scope = false;
        }

        API::get()->log_warn("[weapon][set_weapon_type] Weapon Type: %s", VRWeaponTypeName[m_weapon_type]);
    }
    catch (...) {
        API::get()->log_error("[weapon][set_weapon_type] Exception");
    }
}

void OuterWorldsWeapon::set_offset_component_relative_location() {
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

void OuterWorldsWeapon::set_particle_pointer_visibility(bool visible) {
    if (m_particle_pointer_component != nullptr) {
        m_particle_pointer_component->SetVisibility(visible, false);
    }
}

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


void OuterWorldsWeapon::spawn_particle_pointer() {

    try {
        API::get()->log_warn("[weapon][spawn_particle_pointer] Spawning Particle Pointer - Begin");

        //if (m_particle_pointer_component != nullptr) {
        //    API::get()->log_warn("[weapon][spawn_particle_pointer] ParticleSystemComponent already attached");
        //    return;
        //}

        SDK::UParticleSystem* ps{ nullptr };

        auto asset_class = API::get()->find_uobject<API::UClass>(L"Class /Script/Engine.ParticleSystem");
        if (asset_class == nullptr) {
            API::get()->log_error("[weapon][spawn_particle_pointer] Failed to find ParticleSystem class");
            return;
        }

        std::vector<API::UObject*> matching_objects = asset_class->get_objects_matching<API::UObject>();

        for (size_t i = 0; i < matching_objects.size(); i++) {
            auto obj = (SDK::UObject*)matching_objects[i];

            if (obj->IsA(SDK::UParticleSystem::StaticClass())) {
                if (obj->GetFullName().ends_with("PS_Plasma_Ball.PS_Plasma_Ball")) {
                    API::get()->log_warn("[weapon][spawn_particle_pointer] ParticleSystem found: %s", obj->GetFullName().c_str());
                    ps = static_cast<SDK::UParticleSystem*>(obj);
                }
            }
        }

        if (ps == nullptr || m_particle_pointer_offset_component == nullptr) {
            API::get()->log_error("[weapon][spawn_particle_pointer] ParticleSystem not found or RH controller not set up");
            return;
        }

        API::get()->log_warn("[weapon][spawn_particle_pointer] Spawning ParticleSystemComponent");
        m_particle_pointer_component = SDK::UGameplayStatics::SpawnEmitterAttached(
            ps, m_particle_pointer_offset_component, SDK::FName(), { 200.f, 0.f, 0.f }, { 0.f, 0.f, 0.f }, { 0.04f, 0.04f, 0.04f },
            SDK::EAttachLocation::KeepRelativeOffset, true, SDK::EPSCPoolMethod::None, true
        );

        if (m_particle_pointer_component != nullptr) {
            m_particle_pointer_component->SetAutoActivate(true);
            m_particle_pointer_component->SecondsBeforeInactive = 0.0f;
            m_particle_pointer_component->SetCollisionEnabled(SDK::ECollisionEnabled::QueryAndPhysics);
            m_particle_pointer_component->SetCollisionResponseToAllChannels(SDK::ECollisionResponse::ECR_Block);
            m_particle_pointer_component->SetRenderInMainPass(true);
            m_particle_pointer_component->bRenderInDepthPass = true;
            API::get()->log_warn("[weapon][spawn_particle_pointer] Successfully spawn ParticleSystemComponent");
        }
        else {
            API::get()->log_error("[weapon][spawn_particle_pointer] Could not spawn ParticleSystemComponent");
        }

        API::get()->log_warn("[weapon][spawn_particle_pointer] Spawning Particle Pointer - End");
        return;
    }
    catch (...) {
        API::get()->log_error("[weapon][spawn_particle_pointer] Exception");
        return;
    }
}

void OuterWorldsWeapon::update_particle_pointer() {
    try {
        static SDK::FHitResult h_result{};
        static SDK::FHitResult lt_result{};
        if (m_particle_pointer_offset_component != nullptr) {
            set_offset_component_relative_location();

            //m_particle_pointer_offset_component->K2_SetRelativeLocation(m_particle_pointer_offset, false, &h_result, false);
            auto start = m_particle_pointer_offset_component->K2_GetComponentLocation();
            auto rot = m_particle_pointer_offset_component->K2_GetComponentRotation();
            auto end = start + (SDK::UKismetMathLibrary::Conv_RotatorToVector(rot) * 400.f);
            SDK::FLinearColor color{ 1.0f, 1.0f, 1.0f, 1.0f };

            // adding player character to be ignored in line trace
            SDK::TArray<SDK::AActor*> actors_to_ignore{};
            actors_to_ignore.Data = (SDK::AActor**)API::FMalloc::get()->malloc(1 * sizeof(SDK::AActor*));
            actors_to_ignore.NumElements = 1;
            actors_to_ignore.MaxElements = 1;
            actors_to_ignore.Data[0] = (SDK::AActor*)m_main->get_player_character();

            SDK::UKismetSystemLibrary::LineTraceSingle(
                SDK::UWorld::GetWorld(),
                start,
                end,
                SDK::ETraceTypeQuery::TraceTypeQuery6,
                //SDK::ETraceTypeQuery::TraceTypeQuery1,
                true,
                actors_to_ignore,
                SDK::EDrawDebugTrace::None,
                &lt_result,
                true, color, color, 0.0f);

            //if (m_reusable_result.Actor.Get() != nullptr) {
            //    auto traced_actor = m_reusable_result.Actor.Get();

            //    // take character components
            //    if (SDK::UKismetMathLibrary::ClassIsChildOf(traced_actor->Class, SDK::AIndianaCharacter::StaticClass())) {
            //        API::get()->log_warn("[VR HUD][update_particle_pointer] Found Character");

            //        static_cast<SDK::AIndianaCharacter*>(traced_actor)->Mesh->SetAllBodiesBelowSimulatePhysics(SDK::UKismetStringLibrary::Conv_StringToName(L"pelvis"), true, true);
            //        //static_cast<SDK::AIndianaCharacter*>(traced_actor)->Mesh->SetAllBodiesBelowPhysicsBlendWeight(SDK::UKismetStringLibrary::Conv_StringToName(L"pelvis"), 0.5f, false, false);
            //        static_cast<SDK::AIndianaCharacter*>(traced_actor)->Mesh->SetCollisionEnabled(SDK::ECollisionEnabled::QueryAndPhysics);
            //        //static_cast<SDK::AIndianaCharacter*>(traced_actor)->Mesh->SetCollisionObjectType(SDK::ECollisionChannel::ECC_WorldStatic);
            //        //static_cast<SDK::AIndianaCharacter*>(traced_actor)->Mesh->SetCollisionResponseToChannel(SDK::ECollisionChannel::ECC_PhysicsBody, SDK::ECollisionResponse::ECR_Block);
            //        //static_cast<SDK::AIndianaCharacter*>(traced_actor)->Mesh->SetCollisionResponseToAllChannels(SDK::ECollisionResponse::ECR_Block);

            //        for (auto child : static_cast<SDK::AIndianaCharacter*>(traced_actor)->Mesh->AttachChildren) {
            //            if (child->IsA(SDK::USkeletalMeshComponent::StaticClass())) {

            //                static_cast<SDK::USkeletalMeshComponent*>(child)->SetSimulatePhysics(true);
            //                //static_cast<SDK::USkeletalMeshComponent*>(child)->SetAllBodiesBelowSimulatePhysics(SDK::UKismetStringLibrary::Conv_StringToName(L"pelvis"), true, true);
            //                //static_cast<SDK::USkeletalMeshComponent*>(child)->SetAllBodiesBelowPhysicsBlendWeight(SDK::UKismetStringLibrary::Conv_StringToName(L"pelvis"), 0.5f, false, false);
            //                static_cast<SDK::USkeletalMeshComponent*>(child)->SetCollisionEnabled(SDK::ECollisionEnabled::QueryAndPhysics);
            //                //static_cast<SDK::USkeletalMeshComponent*>(child)->SetCollisionObjectType(SDK::ECollisionChannel::ECC_WorldStatic);
            //                //static_cast<SDK::USkeletalMeshComponent*>(child)->SetCollisionResponseToChannel(SDK::ECollisionChannel::ECC_PhysicsBody, SDK::ECollisionResponse::ECR_Block);
            //                static_cast<SDK::USkeletalMeshComponent*>(child)->SetCollisionResponseToAllChannels(SDK::ECollisionResponse::ECR_Block);
            //            }
            //        }
            //    }

            //    //API::get()->log_warn("[VR HUD][update_particle_pointer] Object: %s", m_reusable_result.Component.Get()->Name.ToString().c_str());
            //    //m_reusable_result.Component.Get()->SetSimulatePhysics(true);
            //}

            if (m_particle_pointer_component != nullptr) {
                if (lt_result.Distance <= 1.f) {
                    m_particle_pointer_component->SetVisibility(false, false);
                }

                m_particle_pointer_component->K2_SetRelativeLocation({ lt_result.Distance - 0.5f, 0.f, 0.f }, false, &h_result, false);

                if (lt_result.Distance > 1.f) {
                    m_particle_pointer_component->SetVisibility(true, false);
                }
            }
        }
    }
    catch (...) {
        API::get()->log_error("[weapon][update_particle_pointer] Exception");
    }
}

void OuterWorldsWeapon::draw_imgui() {
    ImGui::SeparatorText("Equipped Weapon");
    // game state section
    
    ImGui::BeginGroup();
    ImGui::BeginDisabled();

    ImGui::InputText("Name", (m_equipped_weapon != nullptr) ? (char*)m_equipped_weapon->GetName().c_str() : (char*)"Unknown", 20);
    ImGui::InputText("Type", (char*)VRWeaponTypeName[m_weapon_type], 20);
    ImGui::Checkbox("Has Scope", &m_has_scope);

    ImGui::EndDisabled();
    ImGui::EndGroup();
}
