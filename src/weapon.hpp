#pragma once
#include "main.hpp"

typedef enum VRWeaponType {
    WEAPON_TYPE_UNARMED,
    WEAPON_TYPE_RANGED,
    WEAPON_TYPE_MELEE,
    WEAPON_TYPE_UNDEFINED
} VRWeaponType;

class OuterWorldsWeapon
{
private:
    SDK::UWeapon* m_equipped_weapon{ nullptr };
    VRControllers* m_vr_controllers{ nullptr };
    OuterWorldsMain* m_main{ nullptr };
    HandPreference m_hand_preference{ RIGHT_HANDED };

    // interaction components
    SDK::UParticleSystemComponent* m_particle_pointer_component{ nullptr };
    SDK::USceneComponent* m_particle_pointer_offset_component{ nullptr };
    SDK::USceneCaptureComponent2D* m_scope_view_capture_component{ nullptr };
    SDK::UStaticMeshComponent* m_scope_component{ nullptr };

    VRWeaponType m_weapon_type{ WEAPON_TYPE_UNDEFINED };
    bool is_scoped_weapon{ false };

public:
    OuterWorldsWeapon(OuterWorldsMain* main, VRControllers* controllers, HandPreference hand_preference);
    virtual ~OuterWorldsWeapon() {};

    // setters
    void set_equipped_weapon(SDK::UWeapon* weapon);
    void set_weapon_type();

    void initialize();
    bool is_valid();
    void tick();
    void fix_materials();
    void set_offset_component();
    void destroy();

};
