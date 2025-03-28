#include "uevr/API.hpp"
#include "vr_common.hpp"
#include "vr_weapon.hpp"
#include "vr_hud.hpp"

using namespace uevr;

OuterWorldsCommon::OuterWorldsCommon() {
    API::get()->log_warn("[VR Common] Constructor");
    m_vr_weapon = new OuterWorldsVRWeapon(this);
    m_vr_hud = new OuterWorldsVRHUD(this);
};

OuterWorldsCommon::~OuterWorldsCommon() {
    API::get()->log_warn("[VR Common] Destructor");
    m_vr_weapon->~OuterWorldsVRWeapon();
    m_vr_hud->~OuterWorldsVRHUD();
}

void OuterWorldsCommon::tick() {
    API::get()->log_warn("[VR Common] Tick");
    m_vr_weapon->tick();
}
