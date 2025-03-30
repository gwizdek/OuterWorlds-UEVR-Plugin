#pragma once

class OuterWorldsPluginConfig {
public:
    OuterWorldsPluginConfig() = default;
    virtual ~OuterWorldsPluginConfig();

    // mod persisted configuration
    static bool m_cfg_option_auto_pause_daytime;
    static bool m_cfg_option_attach_ammo_readout;
    static bool m_cfg_option_attach_character_overview;
    static bool m_cfg_option_attach_compass;
    static bool m_cfg_option_attach_item_degradation;

    static void load_plugin_config();
    static bool save_plugin_config();
};
