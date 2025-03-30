#include "uevr/API.hpp"
#include "weapon.hpp"

using namespace uevr;

void OuterWorldsWeapon::tick() {
    try {
        if (m_main != nullptr) {
            //API::get()->log_warn("[Weapon][tick] Crouched: %s", m_common->get_test_value() ? "YES" : "NO");
        }
    }
    catch (...) {
        API::get()->log_error("[Weapon][tick] Exception");
    }
}
