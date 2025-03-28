#include "plugin.hpp"
#include "vr_common.hpp"

using namespace uevr;

std::unique_ptr<OuterWorldsPlugin> g_plugin = std::make_unique<OuterWorldsPlugin>();

OuterWorldsPlugin::OuterWorldsPlugin() {
}

OuterWorldsPlugin::~OuterWorldsPlugin() {
    m_common->~OuterWorldsCommon();
}

void OuterWorldsPlugin::on_initialize() {
    PLUGIN_LOG_ONCE("Plugin Initializing...");
    m_common = new OuterWorldsCommon();
}

void OuterWorldsPlugin::on_xinput_get_state(uint32_t* retval, uint32_t user_index, XINPUT_STATE* state) {
    PLUGIN_LOG_ONCE("XInput Get State");
}

void OuterWorldsPlugin::on_pre_engine_tick(API::UGameEngine* engine, float delta) {
    PLUGIN_LOG_ONCE("Pre Engine Tick: %f", delta);
    if (m_common != nullptr) {
        m_common->tick();
    }
}
