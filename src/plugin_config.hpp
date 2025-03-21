#pragma once

class OuterWorldsPluginConfig {
public:
    OuterWorldsPluginConfig() = default;
    virtual ~OuterWorldsPluginConfig();

    // mod persisted configuration
    bool m_cfg_option_auto_pause_daytime{ false };
    bool m_cfg_option_attach_ammo_readout{ true };
    bool m_cfg_option_attach_character_overview{ true };
    bool m_cfg_option_attach_compass{ true };
    bool m_cfg_option_attach_item_degradation{ true };

    void load_plugin_config();
    bool save_plugin_config();
};
