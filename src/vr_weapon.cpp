#include "uevr/API.hpp"
#include "vr_weapon.hpp"

using namespace uevr;

void OuterWorldsVRWeapon::tick() {
    try {
        if (m_common != nullptr) {
            API::get()->log_warn("[VR Weapon][tick] Crouched: %s", m_common->get_test_value() ? "YES" : "NO");
        }
    }
    catch (...) {
        API::get()->log_error("[VR Weapon][tick] Exception");
    }
}
