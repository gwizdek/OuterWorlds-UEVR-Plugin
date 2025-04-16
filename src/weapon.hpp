#pragma once
#include "main.hpp"

typedef enum VRWeaponType {
    WEAPON_TYPE_UNARMED,
    WEAPON_TYPE_RANGED,
    WEAPON_TYPE_MELEE,
    WEAPON_TYPE_UNKNOWN
} VRWeaponType;

static std::map<VRWeaponType, const char*> VRWeaponTypeName = {
    { WEAPON_TYPE_UNARMED, "Unarmed" },
    { WEAPON_TYPE_RANGED, "Ranged" },
    { WEAPON_TYPE_MELEE, "Melee" },
    { WEAPON_TYPE_UNKNOWN, "Unknown" }
};

class OuterWorldsWeapon
{
private:
    OuterWorldsMain* m_main{ nullptr };
    SDK::UWeapon* m_equipped_weapon{ nullptr };
    HandPreference m_hand_preference{ RIGHT_HANDED };

    // interaction components
    SDK::UParticleSystemComponent* m_particle_pointer_component{ nullptr };
    SDK::USceneComponent* m_particle_pointer_offset_component{ nullptr };
    SDK::USceneCaptureComponent2D* m_scope_view_capture_component{ nullptr };
    SDK::UStaticMeshComponent* m_scope_component{ nullptr };

    VRWeaponType m_weapon_type{ WEAPON_TYPE_UNKNOWN };
    bool m_has_scope{ false };

public:
    OuterWorldsWeapon(OuterWorldsMain* main);
    virtual ~OuterWorldsWeapon() {};

    // setters
    void set_equipped_weapon(SDK::UWeapon* weapon);
    void set_weapon_type();
    void set_materials();
    void set_offset_component_relative_location();
    void set_particle_pointer_visibility(bool visible);

    void initialize(HandPreference hand_preference);
    void cleanup_pointers();
    bool is_valid();
    void on_tick();
    void on_draw_imgui();
    void spawn_particle_pointer();
    void update_particle_pointer();
};
