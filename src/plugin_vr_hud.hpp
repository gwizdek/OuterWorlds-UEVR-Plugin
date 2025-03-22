#pragma once

#include <unordered_set>

#include "uevr/API.hpp"
#include "utility/Module.hpp"
#include "plugin_shared.hpp"

#include "indiana/SDK/Engine_classes.hpp"
#include "indiana/SDK/Indiana_classes.hpp"
#include "indiana/SDK/IndianaPlayerCharacter_BP_classes.hpp"
#include "indiana/SDK/HeadMountedDisplay_classes.hpp"
#include "indiana/SDK/UMG_classes.hpp"
#include "indiana/SDK/GameplayTags_classes.hpp"
#include "vr_attached_widget.hpp"

#define STATIC_LOAD_ASSET_OFFSET 0x1C67740

using namespace SDK;

typedef enum OuterWorldsVRHUDState
{
    VR_HUD_PENDING_INIT,
    VR_HUD_INITIALIZING,
    VR_HUD_SUCCESS,
    VR_HUD_ERROR
} OuterWorldsVRHUDState;

const char* VRHackerHUDStateNames[4] = { "VR_HUD_PENDING_INIT", "VR_HUD_INITIALIZING", "VR_HUD_SUCCESS", "VR_HUD_ERROR" };
const ECollisionChannel item_selector_collision_channel{ SDK::ECollisionChannel::ECC_EngineTraceChannel1 };

typedef SDK::UObject* (*StaticLoadObject_t)(uevr::API::UClass* ObjectClass, uevr::API::UObject* InOuter, const wchar_t* inName, const wchar_t* Filename, int32_t LoadFlags, struct UPackageMap* Sandbox, bool bAllowObjectReconciliation, const struct FLinkerInstancingContext* InstancingContext);

class OuterWorldsVRHUD
{
private:
    OuterWorldsVRHUDState m_hud_state{ VR_HUD_PENDING_INIT };
    std::string m_hud_error_msg{};
    SDK::FHitResult m_reusable_result{};

    // options

    // transforms
    SDK::FVector m_particle_pointer_offset{ 0.f, 0.f, 0.f };

    // convinience pointers
    SDK::UWorld* m_world{ nullptr };
    SDK::AIndianaPlayerCharacter* m_player_character{ nullptr };
    SDK::UHUDWidget* m_hud{ nullptr };

    // actors
    SDK::AActor* m_hmd_actor{ nullptr };
    SDK::AActor* m_right_hand_attachments_actor{ nullptr };
    SDK::AActor* m_left_hand_attachments_actor{ nullptr };
    SDK::TArray<SDK::AActor*> m_actors_to_ignore{};

    // motion controllers
    SDK::UMotionControllerComponent* m_rh_controller_component{ nullptr };
    SDK::UMotionControllerComponent* m_lh_controller_component{ nullptr };

    // interaction components
    SDK::UParticleSystemComponent* m_particle_pointer_component{ nullptr };

    // scene components
    SDK::USceneComponent* m_hmd_component{ nullptr };
    SDK::USceneComponent* m_weapon_offset_component{ nullptr };

    // widget components
    VRAttachedWidget* m_ammo_readout{ nullptr };
    VRAttachedWidget* m_character_overview{ nullptr };
    VRAttachedWidget* m_companion_overview_a{ nullptr };
    VRAttachedWidget* m_companion_overview_b{ nullptr };
    VRAttachedWidget* m_item_degradation{ nullptr };
    VRAttachedWidget* m_compass{ nullptr };

public:
    OuterWorldsVRHUD() {
        API::get()->log_warn("[VR HUD] :: Constructor");
    };

    virtual ~OuterWorldsVRHUD() {
        API::get()->log_warn("[VR HUD] :: Destructor");
    }

    SDK::UMotionControllerComponent* get_rh_controller() {
        return m_rh_controller_component;
    }

    SDK::UMotionControllerComponent* get_lh_controller() {
        return m_lh_controller_component;
    }

    void process_vr_hud() {
        if (m_hud_state == OuterWorldsVRHUDState::VR_HUD_SUCCESS) {
            //check_overlapping_components();
            update_particle_pointer();
        }
    }

    // call it each tick (or reference pointers maybe?)
    void set_pointers(SDK::UWorld* world, SDK::AIndianaPlayerCharacter* player_character, SDK::UHUDWidget* hud) {
        m_world = world;
        m_player_character = player_character;
        m_hud = hud;
    }

    bool initialize_hud() {
        if (m_player_character == nullptr || m_hud == nullptr || m_hud_state != VR_HUD_PENDING_INIT) {
            return false;
        }

        API::get()->log_warn("[VR HUD] :: Initializing");
        clear_pointers();

        m_hud_error_msg = "NONE";
        m_hud_state = VR_HUD_INITIALIZING;

        if (!prepare_attachment_points()) {
            //destroy_actors();
            m_hud_state = VR_HUD_ERROR;
            return false;
        }

        m_ammo_readout = new VRAttachedWidget();
        m_character_overview = new VRAttachedWidget();
        m_item_degradation = new VRAttachedWidget();
        m_compass = new VRAttachedWidget();
        //m_companion_overview_a = new VRAttachedWidget();
        //m_companion_overview_b = new VRAttachedWidget();

        if (
            !attach_ammo_readout() ||
            !attach_character_overview() ||
            !attach_item_degradation() ||
            !attach_compass() ||
            !spawn_particle_pointer()
            ) {
            //destroy_actors();
            m_hud_state = VR_HUD_ERROR;
            return false;
        }

        // hide AbilityOverviewGamepad
        m_hud->AbilityOverviewGamepad->SetVisibility(SDK::ESlateVisibility::Hidden);
        m_hud->AbilityOverview->SetVisibility(SDK::ESlateVisibility::Hidden);
        //update_laser_pointer_length(2000.f);
        //update_overlapper_length(250.f);

        m_hud_state = VR_HUD_SUCCESS;
        return true;
    }

    void handle_mod_events(std::unordered_set<ModEvent>* mod_events) {
        if (mod_events == nullptr) {
            return;
        }

        if (mod_events->contains(MOD_EVENT_VR_HUD_INITIALIZE)) {
            m_hud_state = OuterWorldsVRHUDState::VR_HUD_PENDING_INIT;

            if (initialize_hud()) {
                mod_events->extract(MOD_EVENT_VR_HUD_INITIALIZE);
            };
        }
    }

    OuterWorldsVRHUDState get_hud_state() {
        return m_hud_state;
    }

    void set_hud_state(OuterWorldsVRHUDState state) {
        m_hud_state = state;
    }

    std::string get_hud_error() {
        return m_hud_error_msg;
    }

    void log_error(std::string error_msg) {
        m_hud_error_msg = error_msg;
        API::get()->log_warn(error_msg.c_str());
    }

    void clear_pointers() {
        // actors
        m_right_hand_attachments_actor = nullptr;
        m_left_hand_attachments_actor = nullptr;
        m_hmd_actor = nullptr;

        // components
        m_rh_controller_component = nullptr;
        m_lh_controller_component = nullptr;
        m_hmd_component = nullptr;
        m_weapon_offset_component = nullptr;
        m_particle_pointer_component = nullptr;

        // widgets
        m_ammo_readout = nullptr;
        m_character_overview = nullptr;
        m_item_degradation = nullptr;
        m_compass = nullptr;
    }

    void destroy_actors(bool _clear_pointers = true) {
        API::get()->log_warn("[VR HUD] :: Destroying actors");

        if (SDK::UKismetSystemLibrary::IsValid(m_right_hand_attachments_actor) && m_right_hand_attachments_actor->IsA(SDK::AActor::StaticClass())) {
            m_right_hand_attachments_actor->K2_DestroyActor();
            API::get()->log_warn("[VR HUD] :: RH Actor destroyed");
        }

        if (SDK::UKismetSystemLibrary::IsValid(m_left_hand_attachments_actor) && m_left_hand_attachments_actor->IsA(SDK::AActor::StaticClass())) {
            m_left_hand_attachments_actor->K2_DestroyActor();
            API::get()->log_warn("[VR HUD] :: LH Actor destroyed");
        }

        if (SDK::UKismetSystemLibrary::IsValid(m_hmd_actor) && m_hmd_actor->IsA(SDK::AActor::StaticClass())) {
            m_hmd_actor->K2_DestroyActor();
            API::get()->log_warn("[VR HUD] :: HMD Actor destroyed");
        }

        if (_clear_pointers) {
            clear_pointers();
            m_hud_state = VR_HUD_PENDING_INIT;
        }
    }

    SDK::AActor* spawn_actor(SDK::FTransform transform) {
        try {
            if (m_world == nullptr || m_player_character == nullptr) {
                log_error("[VR HUD][spawn_actor] Invalid pointers");
                return nullptr;
            }

            SDK::AActor* actor = SDK::UGameplayStatics::BeginDeferredActorSpawnFromClass(
                m_world, SDK::AActor::StaticClass(), transform, SDK::ESpawnActorCollisionHandlingMethod::AlwaysSpawn, nullptr
            );
            if (actor == nullptr) {
                log_error("[VR HUD][spawn_actor] Error spawning actor");
                return nullptr;
            }

            SDK::UGameplayStatics::FinishSpawningActor(actor, transform);

            SDK::TArray<SDK::FName> actor_tags{};
            actor_tags.Data = (SDK::FName*)API::FMalloc::get()->malloc(1 * sizeof(SDK::FName));
            actor_tags.NumElements = 1;
            actor_tags.MaxElements = 1;
            actor_tags.Data[0] = SDK::UKismetStringLibrary::Conv_StringToName(L"CustomVRActor");

            actor->Tags = actor_tags;

            API::get()->log_warn("[VR HUD][spawn_actor] Spawned actor");
            return actor;
        }
        catch (...) {
            API::get()->log_error("[VR HUD][spawn_actor] Exception");
            return nullptr;
        }
    }

    bool prepare_attachment_points() {
        if (
            m_player_character == nullptr ||
            m_right_hand_attachments_actor != nullptr ||
            m_left_hand_attachments_actor != nullptr ||
            m_hmd_actor != nullptr
            ) {
            log_error("Can't prepare attachment points. Pointers");
            return false;
        }

        const SDK::FVector pawn_location = m_player_character->K2_GetActorLocation();
        SDK::FTransform transform{};
        transform.Rotation = { 0.f, 0.f, 0.f, 1.f };
        transform.Translation = { pawn_location.X, pawn_location.Y, pawn_location.Z };
        transform.Scale3D = { 1.f, 1.f, 1.f };


        // --------------------------------------------------------------------
        // Right Hand
        // - Actor
        // - Motion Controller
        // - Paricle Pointer
        // --------------------------------------------------------------------

        // actor
        m_right_hand_attachments_actor = spawn_actor(transform);
        if (m_right_hand_attachments_actor == nullptr) {
            log_error("Error spawning right hand actor");
            return false;
        }

        // motion controller component
        m_rh_controller_component = static_cast<SDK::UMotionControllerComponent*>(
            m_right_hand_attachments_actor->AddComponentByClass(
                SDK::UMotionControllerComponent::StaticClass(), false, transform, false
            )
            );
        if (m_rh_controller_component == nullptr) {
            log_error("Failed to add right hand motion controller component");
            return false;
        }
        API::get()->log_warn("[VR HUD] Added RH component");

        m_rh_controller_component->MotionSource = SDK::UKismetStringLibrary::Conv_StringToName(L"Right");
        m_rh_controller_component->Hand = SDK::EControllerHand::Right;
        m_right_hand_attachments_actor->FinishAddComponent(m_rh_controller_component, false, transform);
        API::get()->log_warn("[VR HUD] Finished adding RH component");

        // weapon offset component
        m_weapon_offset_component = static_cast<SDK::USceneComponent*>(
            m_right_hand_attachments_actor->AddComponentByClass(SDK::USceneComponent::StaticClass(), false, transform, true)
            );
        if (m_weapon_offset_component == nullptr) {
            log_error("Failed to add Weapon Offset component");
            return false;
        }
        m_right_hand_attachments_actor->FinishAddComponent(m_weapon_offset_component, false, transform);
        API::get()->log_warn("[VR HUD] Added Weapon Offset component");

        if (!m_weapon_offset_component->K2_AttachTo(m_rh_controller_component, SDK::UKismetStringLibrary::Conv_StringToName(L"None"), SDK::EAttachLocation::KeepRelativeOffset, false)) {
            API::get()->log_error("[VR HUD] Failed to Attach Weapon Offset Component");
        }

        // --------------------------------------------------------------------
        // Left Hand
        // - Actor
        // - Motion Controller
        // --------------------------------------------------------------------

        // actor
        m_left_hand_attachments_actor = spawn_actor(transform);
        if (m_left_hand_attachments_actor == nullptr) {
            log_error("Error spawning left hand actor");
            return false;
        }

        // motion controller component
        m_lh_controller_component = static_cast<SDK::UMotionControllerComponent*>(
            m_left_hand_attachments_actor->AddComponentByClass(
                SDK::UMotionControllerComponent::StaticClass(), false, transform, false
            )
            );
        if (m_lh_controller_component == nullptr) {
            log_error("Failed to add left hand motion controller component");
            return false;
        }
        API::get()->log_warn("[VR HUD] :: Added LH component");

        m_lh_controller_component->MotionSource = SDK::UKismetStringLibrary::Conv_StringToName(L"Left");
        m_lh_controller_component->Hand = SDK::EControllerHand::Left;
        m_left_hand_attachments_actor->FinishAddComponent(m_lh_controller_component, false, transform);
        API::get()->log_warn("[VR HUD] :: Finished adding LH component");

        return true;
    }

    // --------------------------------------------------------------------
    // Attachments
    // --------------------------------------------------------------------
    bool attach_ammo_readout() {
        SDK::FTransform widget_transform{};
        widget_transform.Rotation = SDK::UKismetMathLibrary::Quat_MakeFromEuler({ 0.f, 0.f, 270.0f });
        widget_transform.Translation = { -6.f, -3.f, 4.f };
        widget_transform.Scale3D = { 1.f, 0.03f, 0.03f };

        return m_ammo_readout->attach(m_right_hand_attachments_actor, m_hud->AmmoReadout, widget_transform, { 300.0f, 100.0f }, "Ammo Readout");
    }

    bool attach_character_overview() {
        SDK::FTransform widget_transform{};
        widget_transform.Rotation = SDK::UKismetMathLibrary::Quat_MakeFromEuler({ 0.f, 0.f, 90.0f });
        widget_transform.Translation = { -5.f, 1.f, 0.f };
        widget_transform.Scale3D = { 1.f, 0.04f, 0.04f };

        return m_character_overview->attach(m_left_hand_attachments_actor, m_hud->CharacterOverview, widget_transform, { 400.0f, 120.0f }, "Character Overview");
    }

    bool attach_item_degradation() {
        SDK::FTransform widget_transform{};
        widget_transform.Rotation = SDK::UKismetMathLibrary::Quat_MakeFromEuler({ 0.f, 0.f, 270.0f });
        widget_transform.Translation = { 0.f, -3.f, 4.f };
        widget_transform.Scale3D = { 1.f, 0.03f, 0.03f };

        return m_item_degradation->attach(m_right_hand_attachments_actor, m_hud->ItemDegradation, widget_transform, { 100.0f, 100.0f }, "Item Degradation");
    }

    bool attach_compass() {
        SDK::FTransform widget_transform{};
        widget_transform.Rotation = SDK::UKismetMathLibrary::Quat_MakeFromEuler({ 0.f, 180.f, 90.0f });
        widget_transform.Translation = { -6.f, -2.f, 0.f };
        widget_transform.Scale3D = { 1.f, 0.03f, 0.03f };

        return m_compass->attach(m_left_hand_attachments_actor, m_hud->Compass, widget_transform, { 620.0f, 80.0f }, "Compass");
    }

    //bool attach_m_companion_a() {
    //    SDK::FTransform widget_transform{};
    //    widget_transform.Rotation = SDK::UKismetMathLibrary::Quat_MakeFromEuler({ 180.f, 0.f, 90.0f });
    //    widget_transform.Translation = { -10.f, -3.f, 0.f };
    //    widget_transform.Scale3D = { 1.f, 0.03f, 0.03f };

    //    m_companion_overview_a->attach(m_left_hand_attachments_actor, m_hud->CompanionOverview_0, widget_transform, { 800.0f, 800.0f }, "CompanionOverview A");
    //    return true;
    //}

    //bool attach_m_companion_b() {
    //    SDK::FTransform widget_transform{};
    //    widget_transform.Rotation = SDK::UKismetMathLibrary::Quat_MakeFromEuler({ 180.f, 0.f, 90.0f });
    //    widget_transform.Translation = { -5.f, -3.f, 0.f };
    //    widget_transform.Scale3D = { 1.f, 0.03f, 0.03f };

    //    //return m_companion_overview_b->attach(m_left_hand_attachments_actor, m_hud->CompanionOverview_1, widget_transform, { 200.0f, 200.0f }, "CompanionOverview B");
    //    return true;
    //}

    void set_particle_pointer_visibility(bool visible) {
        if (m_particle_pointer_component != nullptr) {
            m_particle_pointer_component->SetVisibility(visible, false);
        }
    }

    float get_line_trace_distance() {
        return m_reusable_result.Distance;
    }

    void set_particle_pointer_offset(SDK::FVector offset) {
        m_particle_pointer_offset = offset;
    }

    void update_particle_pointer() {
        try {
            static SDK::FHitResult h_result{};
            if (m_world != nullptr && m_rh_controller_component != nullptr && m_player_character != nullptr && get_hud_state() == OuterWorldsVRHUDState::VR_HUD_SUCCESS) {

                m_weapon_offset_component->K2_SetRelativeLocation(m_particle_pointer_offset, false, &h_result, false);
                auto start = m_weapon_offset_component->K2_GetComponentLocation();
                auto rot = m_weapon_offset_component->K2_GetComponentRotation();
                auto end = start + (SDK::UKismetMathLibrary::Conv_RotatorToVector(rot) * 400.f);
                SDK::FLinearColor color{ 1.0f, 1.0f, 1.0f, 1.0f };

                //SDK::ECollisionChannel::ECC_WorldDynamic
                //SDK::ECollisionResponse::ECR_Ignore
                //SDK::ECollisionEnabled::NoCollision

                // adding player character to be ignored in line trace
                SDK::TArray<SDK::AActor*> actors_to_ignore{};
                actors_to_ignore.Data = (SDK::AActor**)API::FMalloc::get()->malloc(1 * sizeof(SDK::AActor*));
                actors_to_ignore.NumElements = 1;
                actors_to_ignore.MaxElements = 1;
                actors_to_ignore.Data[0] = (SDK::AActor*)m_player_character;

                SDK::UKismetSystemLibrary::LineTraceSingle(
                    m_world,
                    start,
                    end,
                    SDK::ETraceTypeQuery::TraceTypeQuery6,
                    true,
                    actors_to_ignore,
                    SDK::EDrawDebugTrace::None,
                    &m_reusable_result,
                    true, color, color, 0.0f);

                if (m_particle_pointer_component != nullptr) {
                    if (m_reusable_result.Distance <= 1.f) {
                        m_particle_pointer_component->SetVisibility(false, false);
                    }

                    auto hit = start + (SDK::UKismetMathLibrary::Conv_RotatorToVector(rot) * (m_reusable_result.Distance - 1.f));
                    m_particle_pointer_component->K2_SetWorldLocation(hit, false, &h_result, false);

                    if (m_reusable_result.Distance > 1.f) {
                        m_particle_pointer_component->SetVisibility(true, false);
                    }
                }
            }
        }
        catch (...) {
            API::get()->log_error("[VR HUD][update_particle_pointer] Exception");
        }
    }

    bool spawn_particle_pointer() {
        try {
            API::get()->log_warn("[VR HUD] Spawning Particle Pointer - Begin");

            if (m_particle_pointer_component != nullptr) {
                API::get()->log_warn("[VR HUD] ParticleSystemComponent already attached");
                return false;
            }

            // load particle system asset
            auto asset_class = API::get()->find_uobject<API::UClass>(L"Class /Script/Engine.ParticleSystem");
            std::wstring resource_name{ L"/Game/Art/VFX/ParticleSystems/Weapons/Projectiles/Plasma/PS_Plasma_Ball.PS_Plasma_Ball" };

            if (!asset_class) {
                API::get()->log_error("[VR HUD] Failed to find ParticleSystem class");
                return false;
            }

            auto mod = utility::get_executable();
            auto static_load_asset_func_addr = (uintptr_t)mod + STATIC_LOAD_ASSET_OFFSET;
            auto func = (StaticLoadObject_t)static_load_asset_func_addr;

            SDK::UObject* asset = func(asset_class, nullptr, resource_name.c_str(), nullptr, 0, nullptr, true, nullptr);
            if (!asset) {
                API::get()->log_warn("[VR HUD] Failed to load Plasma Ball");
                return false;
            }
            API::get()->log_warn("[VR HUD] Loaded Plasma Ball!");

            SDK::UParticleSystem* ps{ nullptr };

            API::get()->log_warn("[VR HUD] Searching for ParticleSystem");
            auto class_ptr = API::get()->find_uobject<API::UClass>(L"Class /Script/Engine.ParticleSystem");
            if (class_ptr != nullptr) {
                API::get()->log_warn("[VR HUD] ParticleSystem Class found");
                std::vector<API::UObject*> matching_objects = class_ptr->get_objects_matching<API::UObject>();

                for (size_t i = 0; i < matching_objects.size(); i++) {
                    auto obj = (SDK::UObject*)matching_objects[i];

                    if (obj->IsA(SDK::UParticleSystem::StaticClass())) {
                        if (obj->GetFullName().ends_with("PS_Plasma_Ball.PS_Plasma_Ball")) {
                            API::get()->log_warn("[VR HUD] ParticleSystem found: %s", obj->GetFullName().c_str());
                            ps = static_cast<SDK::UParticleSystem*>(obj);
                        }
                    }
                }
            }

            if (ps == nullptr || m_rh_controller_component == nullptr) {
                API::get()->log_error("[VR HUD] ParticleSystem not found or RH controller not set up");
                return false;
            }

            API::get()->log_warn("[VR HUD] Spawning ParticleSystemComponent");
            m_particle_pointer_component = SDK::UGameplayStatics::SpawnEmitterAttached(
                ps, m_rh_controller_component, SDK::FName(), { 200.f, 0.f, 0.f }, { 0.f, 0.f, 0.f }, { 0.04f, 0.04f, 0.04f }, SDK::EAttachLocation::KeepRelativeOffset, true, SDK::EPSCPoolMethod::None, true
            );

            if (m_particle_pointer_component != nullptr) {
                m_particle_pointer_component->SetAutoActivate(true);
                m_particle_pointer_component->SecondsBeforeInactive = 0.0f;
                m_particle_pointer_component->SetCollisionEnabled(SDK::ECollisionEnabled::QueryAndPhysics);
                m_particle_pointer_component->SetCollisionResponseToAllChannels(SDK::ECollisionResponse::ECR_Block);
                m_particle_pointer_component->SetRenderInMainPass(true);
                m_particle_pointer_component->bRenderInDepthPass = true;
                API::get()->log_warn("[VR HUD] Successfully spawn ParticleSystemComponent");
            }
            else {
                API::get()->log_error("[VR HUD] Could not spawn ParticleSystemComponent");
            }

            API::get()->log_warn("[VR HUD] Spawning Particle Pointer - End");
            return true;
        }
        catch (...) {
            API::get()->log_error("[VR HUD][spawn_particle_pointer] Exception");
            return false;
        }
    }

    // -------------------------------------------------------------------------------------
    // attachments cleanup
    // -------------------------------------------------------------------------------------

    // this function tries to find and destroy actors we created for attachments, even when we no longer have pointers to them
    static void cleanup(SDK::UWorld* world) {
        try {
            API::get()->log_warn("[VR HUD][cleanup] Cleaning up stale Actors");

            if (world == nullptr || !SDK::UKismetSystemLibrary::IsValid(world)) {
                API::get()->log_warn("[VR HUD][cleanup] Invalid World object");
                return;
            }
        
            SDK::TArray<SDK::AActor*> actors_to_destroy{};
            actors_to_destroy.Data = (SDK::AActor**)API::FMalloc::get()->malloc(16 * sizeof(SDK::AActor*));
            actors_to_destroy.NumElements = 0;
            actors_to_destroy.MaxElements = 16;

            SDK::UGameplayStatics::GetAllActorsOfClassWithTag(world, SDK::AActor::StaticClass(), SDK::UKismetStringLibrary::Conv_StringToName(L"CustomVRActor"), &actors_to_destroy);

            API::get()->log_warn("[VR HUD][cleanup] Found %d Actors to Destroy", actors_to_destroy.Num());

            // destroying actors
            for (size_t i = 0; i < actors_to_destroy.Num(); i++) {
                if (actors_to_destroy[i] != nullptr && SDK::UKismetSystemLibrary::IsValid(actors_to_destroy[i]) && actors_to_destroy[i]->IsA(SDK::AActor::StaticClass())) {
                    static_cast<SDK::AActor*>(actors_to_destroy[i])->K2_DestroyActor();
                    API::get()->log_warn("[VR HUD][cleanup] Destroyed an Actor");
                }
            }

            return;
        }
        catch (...) {
            API::get()->log_error("[VR HUD][cleanup] Exception");
            return;
        }
    }
};
