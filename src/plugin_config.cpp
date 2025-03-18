#include "uevr/API.hpp"
#include "plugin_config.hpp"
#include "mINI/ini.h"

using namespace uevr;

OuterWorldsPluginConfig::~OuterWorldsPluginConfig() {
}

void OuterWorldsPluginConfig::load_plugin_config() {
    API::get()->log_warn("[Plugin Config] Loading Config...");
    static const auto config_filename = API::get()->get_persistent_dir(L"outer_worlds_vr_config.ini").string();
    mINI::INIFile mod_config_file(config_filename);
    mINI::INIStructure mod_config;

    if (!mod_config_file.read(mod_config)) {
        API::get()->log_error("[Plugin Config] Missing config file. Creating config with default values");
        save_plugin_config();
        return;
    }

    if (mod_config.has("general")) {
        // use_laser_pointer
        if (mod_config["general"].has("use_laser_pointer")) {
            try {
                std::string& use_laser_pointer = mod_config["general"]["use_laser_pointer"];
                m_cfg_option_use_laser_pointer = std::stoi(use_laser_pointer) == 1;
            }
            catch (...) {
                API::get()->log_error("[Plugin Config] Invalid Value: [general][use_laser_pointer]");
            }
        }
    }
    else {
        API::get()->log_error("[Plugin Config] Missing [general] config section");
    }

    if (mod_config.has("attachments")) {
        // ammo_readout
        if (mod_config["attachments"].has("ammo_readout")) {
            try {
                std::string& ammo_readout = mod_config["attachments"]["ammo_readout"];
                m_cfg_option_attach_ammo_readout = std::stoi(ammo_readout) == 1;
            }
            catch (...) {
                API::get()->log_error("[Plugin Config] Invalid Value: [attachments][ammo_readout]");
            }
        }

        // character_overview
        if (mod_config["attachments"].has("character_overview")) {
            try {
                std::string& character_overview = mod_config["attachments"]["character_overview"];
                m_cfg_option_attach_character_overview = std::stoi(character_overview) == 1;
            }
            catch (...) {
                API::get()->log_error("[Plugin Config] Invalid Value: [attachments][character_overview]");
            }
        }

        // compass
        if (mod_config["attachments"].has("compass")) {
            try {
                std::string& compass = mod_config["attachments"]["compass"];
                m_cfg_option_attach_compass = std::stoi(compass) == 1;
            }
            catch (...) {
                API::get()->log_error("[Plugin Config] Invalid Value: [attachments][compass]");
            }
        }
    }
    else {
        API::get()->log_error("[Plugin Config] Missing [attachments] config section");
    }
}

bool OuterWorldsPluginConfig::save_plugin_config() {
    API::get()->log_warn("[Plugin Config] Saving Config...");
    static const auto config_filename = API::get()->get_persistent_dir(L"outer_worlds_vr_config.ini").string();
    mINI::INIFile mod_config_file(config_filename);
    mINI::INIStructure mod_config;

    mod_config["general"]["use_laser_pointer"] = std::to_string(m_cfg_option_use_laser_pointer).c_str();

    mod_config["attachments"]["ammo_readout"] = std::to_string(m_cfg_option_attach_ammo_readout).c_str();
    mod_config["attachments"]["character_overview"] = std::to_string(m_cfg_option_attach_character_overview).c_str();
    mod_config["attachments"]["compass"] = std::to_string(m_cfg_option_attach_compass).c_str();

    return mod_config_file.generate(mod_config, true);
}
