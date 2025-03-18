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

#define STATIC_LOAD_ASSET_OFFSET_STEAM 0x1C03560
#define STATIC_LOAD_ASSET_OFFSET_EPIC 0x1C67740

using namespace uevr;

typedef enum OuterWorldsVRHUDState
{
    VR_HUD_PENDING_INIT,
    VR_HUD_INITIALIZING,
    VR_HUD_SUCCESS,
    VR_HUD_ERROR
} OuterWorldsVRHUDState;

const char* VRHackerHUDStateNames[4] = { "VR_HUD_PENDING_INIT", "VR_HUD_INITIALIZING", "VR_HUD_SUCCESS", "VR_HUD_ERROR" };
const SDK::ECollisionChannel item_selector_collision_channel{ SDK::ECollisionChannel::ECC_EngineTraceChannel1 };

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

    SDK::TArray<SDK::AActor*> m_overlapping_actors{};
    SDK::TArray<SDK::UPrimitiveComponent*> m_overlapping_components{};

    // motion controllers
    SDK::UMotionControllerComponent* m_rh_controller_component{ nullptr };
    SDK::UMotionControllerComponent* m_lh_controller_component{ nullptr };

    // interaction components (unused)
    SDK::UWidgetInteractionComponent* m_rh_interaction_component{ nullptr };
    SDK::UCapsuleComponent* m_laser_pointer_component{ nullptr };
    SDK::UParticleSystemComponent* m_particle_pointer_component{ nullptr };
    //SDK::UCapsuleComponent* m_overlapper_component{ nullptr };

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


    uint8_t m_trace_type_query{ 1 };

public:
    OuterWorldsVRHUD() {
        API::get()->log_warn("[VR HUD] :: Constructor");

    };

    virtual ~OuterWorldsVRHUD() {
        API::get()->log_warn("[VR HUD] :: Destructor");
        //if (m_ammo_readout != nullptr) {
        //    delete m_ammo_readout;
        //}

        //if (m_character_overview != nullptr) {
        //    delete m_character_overview;
        //}

        //if (m_companion_overview_a != nullptr) {
        //    delete m_companion_overview_a;
        //}

        //if (m_companion_overview_b != nullptr) {
        //    delete m_companion_overview_b;
        //}

        //m_ammo_readout = nullptr;
        //m_character_overview = nullptr;
        //m_companion_overview_a = nullptr;
        //m_companion_overview_b = nullptr;

        //if (m_emitter != nullptr) {
        //    m_emitter->SetActive(false, true, SDK::FName(0));
        //    m_emitter->DetachFromParent(false, false);
        //}
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

    void set_trace_type_query(uint8_t trace_type_query) {
        m_trace_type_query = trace_type_query;
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
        m_rh_interaction_component = nullptr;
        m_hmd_component = nullptr;
        m_weapon_offset_component = nullptr;
        m_laser_pointer_component = nullptr;
        //m_overlapper_component = nullptr;
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
        if (m_world == nullptr || m_player_character == nullptr) {
            log_error("[VR HUD] :: spawn_actor :: invalid pointers");
            return nullptr;
        }

        SDK::AActor* actor = SDK::UGameplayStatics::BeginDeferredActorSpawnFromClass(
            m_world, SDK::AActor::StaticClass(), transform, SDK::ESpawnActorCollisionHandlingMethod::AlwaysSpawn, nullptr
        );
        if (actor == nullptr) {
            log_error("[VR HUD] :: spawn_actor :: error spawning actor");
            return nullptr;
        }

        SDK::UGameplayStatics::FinishSpawningActor(actor, transform);

        API::get()->log_warn("[VR HUD] :: Spawned actor");
        return actor;
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
        // - Widget Interaction Component
        // - Laser Pointer for Item Selector and MFD
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
        API::get()->log_warn("[VR HUD] :: Added RH component");

        m_rh_controller_component->MotionSource = SDK::UKismetStringLibrary::Conv_StringToName(L"Right");
        m_rh_controller_component->Hand = SDK::EControllerHand::Right;
        m_right_hand_attachments_actor->FinishAddComponent(m_rh_controller_component, false, transform);
        API::get()->log_warn("[VR HUD] :: Finished adding RH component");

        // weapon offset component
        m_weapon_offset_component = static_cast<SDK::USceneComponent*>(
            m_right_hand_attachments_actor->AddComponentByClass(SDK::USceneComponent::StaticClass(), false, transform, true)
            );
        if (m_weapon_offset_component == nullptr) {
            log_error("Failed to add Weapon Offset component");
            return false;
        }
        m_right_hand_attachments_actor->FinishAddComponent(m_weapon_offset_component, false, transform);
        API::get()->log_warn("[VR HUD] :: Added Weapon Offset component");

        if (!m_weapon_offset_component->K2_AttachTo(m_rh_controller_component, SDK::UKismetStringLibrary::Conv_StringToName(L"None"), SDK::EAttachLocation::KeepRelativeOffset, false)) {
            API::get()->log_warn("[VR HUD] :: Failed to Attach Weapon Offset Component");
        }

        // laser pointer
        //SDK::FTransform laser_pointer_transform{};
        //laser_pointer_transform.Rotation = { 0.f, 1.f, 0.f, 1.f };
        //laser_pointer_transform.Translation = { 0.f, 0.f, 0.f };
        //laser_pointer_transform.Scale3D = { 1.f, 1.f, 1.f };

        //m_laser_pointer_component = static_cast<SDK::UCapsuleComponent*>(
        //    m_right_hand_attachments_actor->AddComponentByClass(
        //        SDK::UCapsuleComponent::StaticClass(), false, laser_pointer_transform, false
        //    )
        //    );
        //API::get()->log_warn("[VR HUD] :: Added laser pointer component");

        //if (m_laser_pointer_component == nullptr) {
        //    API::get()->log_warn("[VR HUD] :: Failed to add capsule component");
        //    return false;
        //}
        //m_laser_pointer_component->SetCapsuleSize(0.01f, 1.f, false);
        //m_laser_pointer_component->SetCapsuleHalfHeight(1.f, false);
        //m_laser_pointer_component->SetVisibility(true, true);
        //m_laser_pointer_component->SetHiddenInGame(false, false);
        //m_laser_pointer_component->bAutoActivate = true;
        //m_laser_pointer_component->SetGenerateOverlapEvents(false);
        //m_laser_pointer_component->SetCollisionEnabled(SDK::ECollisionEnabled::NoCollision);
        //m_laser_pointer_component->SetCollisionResponseToAllChannels(SDK::ECollisionResponse::ECR_Ignore);
        //m_laser_pointer_component->SetRenderInMainPass(true);
        //m_laser_pointer_component->bRenderInDepthPass = true;
        //m_laser_pointer_component->ShapeColor = SDK::FColor{ 0, 0, 255, 255 };

        //m_laser_pointer_component->SetRenderCustomDepth(true);
        //m_laser_pointer_component->SetCustomDepthStencilValue(100);
        //m_laser_pointer_component->SetCustomDepthStencilWriteMask(SDK::ERendererStencilMask::ERSM_255);

        //m_right_hand_attachments_actor->FinishAddComponent(m_laser_pointer_component, false, laser_pointer_transform);
        //API::get()->log_warn("[VR HUD] :: Finished adding laser pointer component");

        // overlapper
        //SDK::FTransform pointer_transform{};
        //pointer_transform.Rotation = { 0.f, 1.f, 0.f, 1.f };
        //pointer_transform.Translation = { 0.f, 0.f, 0.f };
        //pointer_transform.Scale3D = { 1.f, 1.f, 1.f };

        //m_pointer_component = static_cast<SDK::USphereComponent*>(
        //    m_right_hand_attachments_actor->AddComponentByClass(
        //        SDK::USphereComponent::StaticClass(), false, pointer_transform, false
        //    ));

        //m_pointer_component->SetSphereRadius(25.f, false);
        //m_pointer_component->SetVisibility(true, true);
        //m_pointer_component->SetHiddenInGame(false, false);
        //m_pointer_component->SetRenderInMainPass(true);
        //m_pointer_component->bRenderInDepthPass = true;
        //m_pointer_component->ShapeColor = SDK::FColor{ 255, 255, 255, 55 };
        //m_pointer_component->SetGenerateOverlapEvents(false);
        //m_pointer_component->SetCollisionResponseToAllChannels(SDK::ECollisionResponse::ECR_Ignore);
        //m_pointer_component->CachedMaxDrawDistance = 1000.f;
        //m_pointer_component->LDMaxDrawDistance = 1000.f;
        ////m_pointer_component->bAllowCullDistanceVolume = false;
        //m_pointer_component->SetCullDistance(1000.f);
        //m_pointer_component->SetBoundsScale(1.2f);
        ////m_pointer_component->DetailMode = SDK::EDetailMode::DM_High;
        //m_pointer_component->SetRenderCustomDepth(true);
        //m_pointer_component->SetCustomDepthStencilValue(1000);
        //m_pointer_component->SetCustomDepthStencilWriteMask(SDK::ERendererStencilMask::ERSM_255);

        //m_right_hand_attachments_actor->FinishAddComponent(m_pointer_component, false, pointer_transform);
        //API::get()->log_warn("[VR HUD] :: Finished adding pointer component");



        // overlapper
        //SDK::FTransform overlapper_transform{};
        //overlapper_transform.Rotation = { 0.f, 1.f, 0.f, 1.f };
        //overlapper_transform.Translation = { 0.f, 0.f, 0.f };
        //overlapper_transform.Scale3D = { 1.f, 1.f, 1.f };

        //m_overlapper_component = static_cast<SDK::UCapsuleComponent*>(
        //    m_right_hand_attachments_actor->AddComponentByClass(
        //        SDK::UCapsuleComponent::StaticClass(), false, overlapper_transform, false
        //    )
        //    );
        //API::get()->log_warn("[VR HUD] :: Added overlapper component");

        //if (m_overlapper_component == nullptr) {
        //    API::get()->log_warn("[VR HUD] :: Failed to add capsule component");
        //    return false;
        //}
        //m_overlapper_component->SetCapsuleSize(2.0f, 2.f, true);
        //m_overlapper_component->SetVisibility(false, false);
        //m_overlapper_component->SetHiddenInGame(true, true);
        //m_overlapper_component->bAutoActivate = true;
        //m_overlapper_component->SetGenerateOverlapEvents(false);
        //m_overlapper_component->SetCollisionEnabled(SDK::ECollisionEnabled::NoCollision);
        ////m_overlapper_component->SetCollisionEnabled(SDK::ECollisionEnabled::QueryAndPhysics);
        //m_overlapper_component->SetRenderInMainPass(true);
        //m_overlapper_component->bRenderInDepthPass = true;
        //m_overlapper_component->ShapeColor = SDK::FColor{ 255, 255, 255, 55 };
        //m_overlapper_component->SetCollisionResponseToAllChannels(SDK::ECollisionResponse::ECR_Ignore);
        ////m_overlapper_component->SetCollisionResponseToChannel(SDK::ECollisionChannel::ECC_Pawn, SDK::ECollisionResponse::ECR_Overlap);
        ////m_overlapper_component->SetCollisionResponseToChannel(SDK::ECollisionChannel::ECC_Visibility, SDK::ECollisionResponse::ECR_Overlap);
        ////m_overlapper_component->SetCollisionResponseToChannel(SDK::ECollisionChannel::ECC_WorldStatic, SDK::ECollisionResponse::ECR_Block);
        ////m_overlapper_component->SetCollisionResponseToChannel(SDK::ECollisionChannel::ECC_WorldDynamic, SDK::ECollisionResponse::ECR_Block);
        ////m_overlapper_component->SetCollisionResponseToChannel(SDK::ECollisionChannel::ECC_GameTraceChannel11, SDK::ECollisionResponse::ECR_Overlap);
        ////m_overlapper_component->SetCollisionResponseToChannel(SDK::ECollisionChannel::ECC_EngineTraceChannel2, SDK::ECollisionResponse::ECR_Overlap);
        ////m_rh_interaction_component->TraceChannel = item_selector_collision_channel;
        ////SDK::ECollisionChannel::ECC_EngineTraceChannel1


        //m_overlapper_component->SetRenderCustomDepth(true);
        //m_overlapper_component->SetCustomDepthStencilValue(100);
        //m_overlapper_component->SetCustomDepthStencilWriteMask(SDK::ERendererStencilMask::ERSM_255);

        //m_right_hand_attachments_actor->FinishAddComponent(m_overlapper_component, false, laser_pointer_transform);
        //API::get()->log_warn("[VR HUD] :: Finished adding overlapper component");

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




    void set_laser_pointer_visibility(bool visible) {
        if (m_laser_pointer_component != nullptr) {
            m_laser_pointer_component->SetHiddenInGame(!visible, true);
        }
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

    void update_laser_pointer_length(float no_hit_length) {
        if (m_laser_pointer_component == nullptr) {
            return;
        }
        float hit_distance = no_hit_length;

        m_laser_pointer_component->SetCapsuleHalfHeight(hit_distance / 2, false);
        m_laser_pointer_component->K2_SetRelativeLocation({ (hit_distance / 2) + 30.f, 0.f, 0.f }, false, &m_reusable_result, false);
    }

    void update_laser_pointer_dot(float range) {
        if (m_laser_pointer_component == nullptr) {
            return;
        }
        if (range > 50.f) {
            //m_laser_pointer_component->SetCapsuleHalfHeight(0.1f, false);
            m_laser_pointer_component->K2_SetRelativeLocation({ range - 50.f, 0.f, 0.f }, false, &m_reusable_result, false);
        }
    }

    //void update_overlapper_length(float no_hit_length) {
    //    float hit_distance = no_hit_length;

    //    m_overlapper_component->SetCapsuleHalfHeight(hit_distance / 2, false);
    //    m_overlapper_component->K2_SetRelativeLocation({ (hit_distance / 2) + 100.f, 0.f, 0.f }, false, &m_reusable_result, false);
    //}


    //void check_overlapping_components() {
    //    if (m_overlapper_component == nullptr) {
    //        return;
    //    }
    //    m_overlapper_component->GetOverlappingActors(&m_overlapping_actors, SDK::AActor::StaticClass());
    //    m_overlapper_component->GetOverlappingComponents(&m_overlapping_components);
    //}

    int get_overlapping_actors_count() {
        return m_overlapping_actors.Num();
    }
    int get_overlapping_components_count() {
        return m_overlapping_components.Num();
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

                SDK::TArray<SDK::AActor*> ignore_actors{};
                ignore_actors.Add(m_right_hand_attachments_actor);
                ignore_actors.Add(m_left_hand_attachments_actor);
                ignore_actors.Add(m_hmd_actor);
                ignore_actors.Add(m_player_character);

                //SDK::ECollisionChannel::ECC_WorldDynamic
                //SDK::ECollisionResponse::ECR_Ignore
                //SDK::ECollisionEnabled::NoCollision

                SDK::UKismetSystemLibrary::LineTraceSingle(
                    m_world,
                    start,
                    end,
                    SDK::ETraceTypeQuery::TraceTypeQuery4,
                    true,
                    ignore_actors,
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
            API::get()->log_error("[VR HUD][update_particle_pointer]");
        }
    }

    bool spawn_particle_pointer() {
        try {
            API::get()->log_warn("[VR HUD] :: Spawning Particle Pointer - Begin");

            if (m_particle_pointer_component != nullptr) {
                API::get()->log_warn("[VR HUD] :: ParticleSystemComponent already attached");
                return false;
            }

            // load particle system asset
            auto asset_class = API::get()->find_uobject<API::UClass>(L"Class /Script/Engine.ParticleSystem");
            std::wstring resource_name{ L"/Game/Art/VFX/ParticleSystems/Weapons/Projectiles/Plasma/PS_Plasma_Ball.PS_Plasma_Ball" };

            if (!asset_class) {
                API::get()->log_warn("[VR HUD] :: Failed to find ParticleSystem class");
                return false;
            }

            auto mod = utility::get_executable();
            //auto static_load_asset_func_addr = (uintptr_t)mod + 0x1C67740; // Epic
            //auto static_load_asset_func_addr = (uintptr_t)mod + 0x1C03560; // Steam

            auto static_load_asset_func_addr = (uintptr_t)mod + STATIC_LOAD_ASSET_OFFSET_EPIC;
            auto func = (StaticLoadObject_t)static_load_asset_func_addr;

            SDK::UObject* asset = func(asset_class, nullptr, resource_name.c_str(), nullptr, 0, nullptr, true, nullptr);
            if (!asset) {
                API::get()->log_warn("[VR HUD] :: Failed to load Plasma Ball");
                return false;
            }
            API::get()->log_warn("[VR HUD] :: Loaded Plasma Ball!");

            SDK::UParticleSystem* ps{ nullptr };

            API::get()->log_warn("[VR HUD] :: Searching for ParticleSystem");
            auto class_ptr = API::get()->find_uobject<API::UClass>(L"Class /Script/Engine.ParticleSystem");
            if (class_ptr != nullptr) {
                API::get()->log_warn("[VR HUD] :: ParticleSystem Class found");
                std::vector<API::UObject*> matching_objects = class_ptr->get_objects_matching<API::UObject>();

                for (size_t i = 0; i < matching_objects.size(); i++) {
                    auto obj = (SDK::UObject*)matching_objects[i];

                    if (obj->IsA(SDK::UParticleSystem::StaticClass())) {
                        if (obj->GetFullName().ends_with("PS_Plasma_Ball.PS_Plasma_Ball")) {
                            API::get()->log_info("[VR HUD] :: ParticleSystem found: %s", obj->GetFullName().c_str());
                            ps = static_cast<SDK::UParticleSystem*>(obj);
                        }
                    }
                }
            }

            if (ps == nullptr || m_rh_controller_component == nullptr) {
                API::get()->log_warn("[VR HUD] :: ParticleSystem not found or RH controller not set up");
                return false;
            }

            API::get()->log_warn("[VR HUD] :: Spawning ParticleSystemComponent");
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
                API::get()->log_warn("[VR HUD] :: Successfully spawn ParticleSystemComponent");
            }
            else {
                API::get()->log_warn("[VR HUD] :: Could not spawn ParticleSystemComponent");
            }

            API::get()->log_warn("[VR HUD] :: Spawning Particle Pointer - End");
            return true;
        }
        catch (...) {
            API::get()->log_error("[VR HUD][spawn_particle_pointer]");
            return false;
        }
    }
};
