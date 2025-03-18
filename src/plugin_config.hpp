#pragma once

class OuterWorldsPluginConfig {
public:
    OuterWorldsPluginConfig() = default;
    virtual ~OuterWorldsPluginConfig();

    // mod persisted configuration
    bool m_cfg_option_use_laser_pointer{ true };
    bool m_cfg_option_attach_ammo_readout{ true };
    bool m_cfg_option_attach_character_overview{ true };
    bool m_cfg_option_attach_compass{ true };

    void load_plugin_config();
    bool save_plugin_config();
};
