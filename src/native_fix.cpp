#include "indiana/SDK/BP_DynamicTOD_classes.hpp"

#include "native_fix.hpp"

void OuterWorldsNativeFix::pause_daytime(bool pause) {
    try {
        if (m_main->get_player_character() != nullptr && m_main->get_player_character()->IsA(SDK::AIndianaPlayerCharacter_BP_C::StaticClass())) {
            API::get()->log_warn("[pause_daytime] Searching for DynamicTOD");

            auto class_ptr = API::get()->find_uobject<API::UClass>(L"BlueprintGeneratedClass /Game/Materials/Lighting/DynamicSystem/BP_DynamicTOD.BP_DynamicTOD_C");
            if (class_ptr != nullptr) {
                API::get()->log_warn("[pause_daytime] BP_DynamicTOD Class found");
                std::vector<SDK::UObject*> matching_objects = class_ptr->get_objects_matching<SDK::UObject>();

                for (size_t i = 0; i < matching_objects.size(); i++) {
                    if (matching_objects[i]->IsA(SDK::ABP_DynamicTOD_C::StaticClass())) {
                        API::get()->log_warn("[pause_daytime] BP_DynamicTOD Object found, changing params");
                        static_cast<SDK::ABP_DynamicTOD_C*>(matching_objects[i])->PrimaryActorTick.TickInterval = pause ? 9999999.f : 0.f;
                    }
                }
            }
        }

        cycle_native_fix();
        m_is_paused_daytime = pause;
    }
    catch (...) {
        API::get()->log_error("[pause_daytime] Exception");
    }
}

// turn native fix off, then wait a few ticks an turn it on
void OuterWorldsNativeFix::cycle_native_fix() {
    API::get()->log_warn("[native_fix][cycle_native_fix] Cycling...");
    if (m_toggle_native_fix_counter == -1) {
        m_toggle_native_fix_counter = 30;
    }
}

void OuterWorldsNativeFix::handle_native_fix() {
    try {
        const UEVR_VRData* vr = API::get()->param()->vr;

        if (m_toggle_native_fix_counter > 0) {
            m_toggle_native_fix_counter--;
        }

        if (m_toggle_native_fix_counter == 9) {
            vr->set_mod_value("VR_NativeStereoFix", "false");
            API::get()->log_warn("[native_fix][handle_native_fix] OFF");
        }

        if (m_toggle_native_fix_counter == 0) {
            vr->set_mod_value("VR_NativeStereoFix", "true");
            API::get()->log_warn("[native_fix][handle_native_fix] ON");
            m_toggle_native_fix_counter = -1;
        }
    }
    catch (...) {
        API::get()->log_error("[native_fix][handle_native_fix] Exception");
    }
}
