#ifndef VR_PLUGIN_WRAPPER_H
#define VR_PLUGIN_WRAPPER_H

#include "uevr/Plugin.hpp"

#define PLUGIN_LOG_ONCE(...) { \
    static bool _logged_ = false; \
    if (!_logged_) { \
        _logged_ = true; \
        API::get()->log_info(__VA_ARGS__); \
    } }

class OuterWorldsPlugin;
extern std::unique_ptr<OuterWorldsPlugin> g_plugin;

class OuterWorldsCommon;

class OuterWorldsPlugin : public uevr::Plugin {
public:
    OuterWorldsPlugin();
    virtual ~OuterWorldsPlugin();

    void on_initialize() override;
    void on_xinput_get_state(uint32_t* retval, uint32_t user_index, XINPUT_STATE* state) override;
    void on_pre_engine_tick(uevr::API::UGameEngine* engine, float delta) override;

    OuterWorldsCommon* m_common{ nullptr };
};

#endif // !VR_PLUGIN_WRAPPER_H
