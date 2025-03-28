//#include "uevr/API.hpp"
//#include "vr_weapon.hpp"
#include "plugin.hpp"

//using namespace uevr;

//OuterWorldsVRWeapon::OuterWorldsVRWeapon(OuterWorldsPlugin* plugin) {
//    API::get()->log_warn("[VR Weapon] Constructor");
//    m_plugin = plugin;
//};
class OuterWorldsPlugin;

extern std::unique_ptr<OuterWorldsPlugin> g_plugin;


OuterWorldsVRWeapon::~OuterWorldsVRWeapon() {
    API::get()->log_warn("[VR Weapon] Destructor");
};

void OuterWorldsVRWeapon::tick() {
    try {
        if (g_plugin != nullptr) {
            API::get()->log_warn("[VR Weapon][tick] Crouched: %s", g_plugin->m_is_crouched.value ? "YES" : "NO");
        }
    }
    catch (...) {
        API::get()->log_error("[VR Weapon][tick] Exception");
    }
}
