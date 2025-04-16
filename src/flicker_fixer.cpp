#include "imgui/imgui.h"

#include "indiana/SDK/BP_DynamicTOD_classes.hpp"

#include "flicker_fixer.hpp"
#include "plugin_utils.hpp"



OuterWorldsFlickerFixer::OuterWorldsFlickerFixer(OuterWorldsMain* main) {
    m_main = main;
};

void OuterWorldsFlickerFixer::pause_daytime(bool pause) {
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

        cycle(50.f);
        m_is_paused_daytime = pause;
    }
    catch (...) {
        API::get()->log_error("[pause_daytime] Exception");
    }
}

// turn native fix off, then wait a few ticks an turn it on
void OuterWorldsFlickerFixer::cycle(int delay) {
    API::get()->log_warn("[flicker_fixer][cycle] Cycling...");
    m_toggle_native_fix_counter = delay;
}

bool OuterWorldsFlickerFixer::is_valid() {
    if (
        SDK::UKismetSystemLibrary::IsValid(m_flicker_fixer_actor) &&
        SDK::UKismetSystemLibrary::IsValid(m_scene_capture_component) &&
        SDK::UKismetSystemLibrary::IsValid(m_render_target)
        ) {
        return true;
    }
    return false;
}

void OuterWorldsFlickerFixer::on_tick(float delta) {
    //API::get()->log_warn("[flicker_fixer][on_tick] Tick %f", m_current_duration);
    try {
        m_current_duration += delta;
        if (!m_capture_active && (m_current_duration > m_max_idle_duration)) {
            m_capture_active = true;
            set_capture(m_capture_active);
            m_current_duration = 0.f;
        }
        if (m_capture_active && (m_current_duration > m_max_active_duration)) {
            m_capture_active = false;
            set_capture(m_capture_active);
            m_current_duration = 0.f;
            //API::get()->log_warn("[flicker_fixer][on_tick] Deactivate");
        }

        const UEVR_VRData* vr = API::get()->param()->vr;

        if (m_toggle_native_fix_counter > 0) {
            m_toggle_native_fix_counter--;
        }

        if (m_toggle_native_fix_counter == 9) {
            vr->set_mod_value("VR_NativeStereoFix", "false");
            API::get()->log_warn("[flicker_fixer][on_tick] OFF");
        }

        if (m_toggle_native_fix_counter == 0) {
            vr->set_mod_value("VR_NativeStereoFix", "true");
            API::get()->log_warn("[flicker_fixer][on_tick] ON");
            m_toggle_native_fix_counter = -1;
        }
    }
    catch (...) {
        API::get()->log_error("[flicker_fixer][on_tick] Exception");
    }
}

void OuterWorldsFlickerFixer::set_capture(bool active) {
    if (SDK::UKismetSystemLibrary::IsValid(m_scene_capture_component)) {
        m_scene_capture_component->SetVisibility(active, false);
    }
}

void OuterWorldsFlickerFixer::spawn_flicker_fixer() {
    try {
        auto world = SDK::UWorld::GetWorld();
        if (!SDK::UKismetSystemLibrary::IsValid(world)) {
            API::get()->log_error("[flicker_fixer][spawn_fixer] World not valid");
            return;
        }

        SDK::FTransform zero_transform{
            .Rotation = {1.f, 0.f, 0.f, 1.f},
            .Translation = {0.f, 0.f, 0.f},
            .Scale3D = {1.f, 1.f, 1.f}
        };

        m_flicker_fixer_actor = PluginUtils::spawn_actor(world, zero_transform, L"VRFlickerFixerActor");
        if (m_flicker_fixer_actor == nullptr) {
            API::get()->log_error("[flicker_fixer][spawn_fixer] Error spawning Flicker Fixer Actor");
            return;
        }

        m_scene_capture_component = static_cast<SDK::USceneCaptureComponent2D*>(
            m_flicker_fixer_actor->AddComponentByClass(SDK::USceneCaptureComponent2D::StaticClass(), false, zero_transform, true)
            );

        if (m_scene_capture_component == nullptr) {
            API::get()->log_error("[flicker_fixer][spawn_fixer] Failed to add Flicker Fixer Capture Component");
            return;
        }

        SDK::FLinearColor zero_color{ 0.f ,0.f, 0.f, 0.f };
        m_render_target = SDK::UKismetRenderingLibrary::CreateRenderTarget2D(SDK::UWorld::GetWorld(), 16, 16, SDK::ETextureRenderTargetFormat::RTF_RGBA16f, zero_color, false);

        if (m_render_target == nullptr) {
            API::get()->log_error("[flicker_fixer][spawn_fixer] Failed to create Render Target");
            return;
        }

        m_scene_capture_component->TextureTarget = m_render_target;
        m_scene_capture_component->FOVAngle = -1.f;
        m_scene_capture_component->SetVisibility(true, true);

        m_flicker_fixer_actor->FinishAddComponent(m_scene_capture_component, false, zero_transform);
        API::get()->log_warn("[flicker_fixer][spawn_fixer] Added Flicker Fixer");

        //API::get()->log_warn("[flicker_fixer][spawn_fixer] Searching for SceneCaptureComponent2D");

        //auto class_ptr = API::get()->find_uobject<API::UClass>(L"Class /Script/Engine.SceneCaptureComponent2D");
        //if (class_ptr != nullptr) {
        //    API::get()->log_warn("[flicker_fixer][spawn_fixer] SceneCaptureComponent2D Class found");
        //    std::vector<SDK::UObject*> matching_objects = class_ptr->get_objects_matching<SDK::UObject>();

        //    for (size_t i = 0; i < matching_objects.size(); i++) {
        //        if (matching_objects[i]->IsA(SDK::USceneCaptureComponent2D::StaticClass())) {
        //            if (matching_objects[i]->GetFullName().ends_with(".PhineasCapture_ShipAI.NewSceneCaptureComponent2D")) {
        //                API::get()->log_warn("[flicker_fixer][spawn_fixer] PhineasCapture_ShipAI found: %s", matching_objects[i]->GetFullName().c_str());
        //                SDK::TArray<struct SDK::FEngineShowFlagsSetting> sf_settings = static_cast<SDK::USceneCaptureComponent2D*>(matching_objects[i])->ShowFlagSettings;
        //                for (auto setting : sf_settings) {
        //                    API::get()->log_warn("[flicker_fixer][spawn_fixer] SF Setting %s = %s", setting.ShowFlagName.ToString().c_str(), setting.Enabled ? "True" : "False");
        //                }
        //            }
        //        }
        //    }
        //}

        //SDK::TArray<SDK::FEngineShowFlagsSetting> show_flags{};
        //show_flags.Data = (SDK::FEngineShowFlagsSetting*)API::FMalloc::get()->malloc(32 * sizeof(SDK::FEngineShowFlagsSetting));
        //show_flags.NumElements = 23;
        //show_flags.MaxElements = 23;
        //show_flags.Data[0] = { .ShowFlagName = SDK::FString(L"AntiAliasing"), .Enabled = false };
        //show_flags.Data[1] = { .ShowFlagName = SDK::FString(L"AntiAliasing"), .Enabled = false };
        //show_flags.Data[2] = { .ShowFlagName = SDK::FString(L"Fog"), .Enabled = false };
        //show_flags.Data[3] = { .ShowFlagName = SDK::FString(L"Landscape"), .Enabled = false };
        //show_flags.Data[4] = { .ShowFlagName = SDK::FString(L"Particles"), .Enabled = false };
        //show_flags.Data[5] = { .ShowFlagName = SDK::FString(L"AtmosphericFog"), .Enabled = false };
        //show_flags.Data[6] = { .ShowFlagName = SDK::FString(L"Cloud"), .Enabled = false };
        //show_flags.Data[7] = { .ShowFlagName = SDK::FString(L"InstancedFoliage"), .Enabled = false };
        //show_flags.Data[8] = { .ShowFlagName = SDK::FString(L"InstancedGrass"), .Enabled = false };
        //show_flags.Data[9] = { .ShowFlagName = SDK::FString(L"TextRender"), .Enabled = false };
        //show_flags.Data[10] = { .ShowFlagName = SDK::FString(L"Paper2DSprites"), .Enabled = false };
        //show_flags.Data[11] = { .ShowFlagName = SDK::FString(L"Bloom"), .Enabled = false };
        //show_flags.Data[12] = { .ShowFlagName = SDK::FString(L"EyeAdaptation"), .Enabled = false };
        //show_flags.Data[13] = { .ShowFlagName = SDK::FString(L"DirectionalLights"), .Enabled = false };
        //show_flags.Data[14] = { .ShowFlagName = SDK::FString(L"AmbientOcclusion"), .Enabled = false };
        //show_flags.Data[15] = { .ShowFlagName = SDK::FString(L"DistanceFieldAO"), .Enabled = false };
        //show_flags.Data[16] = { .ShowFlagName = SDK::FString(L"LightShafts"), .Enabled = false };
        //show_flags.Data[17] = { .ShowFlagName = SDK::FString(L"ReflectionEnvironment"), .Enabled = false };
        //show_flags.Data[18] = { .ShowFlagName = SDK::FString(L"CustomDepth"), .Enabled = false };
        //show_flags.Data[19] = { .ShowFlagName = SDK::FString(L"ScreenSpaceReflections"), .Enabled = false };
        //show_flags.Data[20] = { .ShowFlagName = SDK::FString(L"SubsurfaceScattering"), .Enabled = false };
        //show_flags.Data[21] = { .ShowFlagName = SDK::FString(L"VolumetricFog"), .Enabled = false };
        //show_flags.Data[22] = { .ShowFlagName = SDK::FString(L"PostProcessing"), .Enabled = false };

        ///*m_scene_capture_component->bEnableClipPlane = true;
        //m_scene_capture_component->CustomNearClippingPlane = 1.f;*/
        //m_scene_capture_component->PrimitiveRenderMode = SDK::ESceneCapturePrimitiveRenderMode::PRM_UseShowOnlyList;
        //m_scene_capture_component->bUseRayTracingIfEnabled = false;
        ////m_scene_capture_component->MaxViewDistanceOverride = 10.f;
        ////m_scene_capture_component->bDisableFlipCopyGLES = true;
        //m_scene_capture_component->ShowFlagSettings = show_flags;
        //m_scene_capture_component->SetAutoActivate(true);
        //m_scene_capture_component->bCaptureEveryFrame = true;
        //m_scene_capture_component->ShowOnlyActorComponents(m_flicker_fixer_actor, false);
    }
    catch (...) {
        API::get()->log_error("[flicker_fixer][spawn_fixer] Exception");
    }
}

void OuterWorldsFlickerFixer::cleanup_pointers() {
    m_flicker_fixer_actor = nullptr;
    m_scene_capture_component = nullptr;
    m_render_target = nullptr;
}

void OuterWorldsFlickerFixer::cleanup_actors() {
    try {
        auto world = SDK::UWorld::GetWorld();
        if (!SDK::UKismetSystemLibrary::IsValid(world)) {
            API::get()->log_error("[flicker_fixer][cleanup_actors] World invalid");
            return;
        }

        PluginUtils::destroy_actors_by_tag(world, L"VRFlickerFixerActor");
    }
    catch (...) {
        API::get()->log_error("[flicker_fixer][cleanup_actors] Exception");
    }
}

void OuterWorldsFlickerFixer::on_save_config(mINI::INIStructure& config) {
    try {
        API::get()->log_warn("[flicker_fixer][on_save_config] Saving");

        if (!is_valid()) {
            API::get()->log_error("[flicker_fixer][on_save_config] Invalid state");
            return;
        }

        config["flicker_fixer"]["max_idle_duration"] = std::to_string(m_max_idle_duration).c_str();
        config["flicker_fixer"]["max_active_duration"] = std::to_string(m_max_active_duration).c_str();
    }
    catch (...) {
        API::get()->log_error("[flicker_fixer][on_save_config] Exception");
    }
}

void OuterWorldsFlickerFixer::on_load_config(mINI::INIStructure& config) {
    try {
        API::get()->log_warn("[flicker_fixer][on_load_config] Saving");
        if (!is_valid()) {
            API::get()->log_error("[flicker_fixer][on_load_config] Invalid state");
            return;
        }

        if (config.has("flicker_fixer")) {
            try {
                m_max_idle_duration = std::stof(config["flicker_fixer"]["max_idle_duration"]);
                m_max_active_duration = std::stof(config["flicker_fixer"]["max_active_duration"]);
            }
            catch (...) {
                API::get()->log_error("[flicker_fixer][on_load_config] Failed to load config value");
            }
        }
    }
    catch (...) {
        API::get()->log_error("[flicker_fixer][on_load_config] Exception");
    }
}

void OuterWorldsFlickerFixer::on_draw_imgui() {
    try {
        if (is_valid()) {
            ImGui::BeginGroup();
            ImGui::SeparatorText("Flicker Fixer");
            ImGui::PushID("flicker_fixer");
            ImGui::SliderFloat("Idle Duration", &m_max_idle_duration, 1.f, 10.f, "%1.0f");
            ImGui::SliderFloat("Active Duration", &m_max_active_duration, 0.01f, 1.f, "%.2f");
            ImGui::PopID();
            ImGui::EndGroup();
        }
    }
    catch (...) {
        API::get()->log_error("[flicker_fixer][on_draw_imgui] Exception");
    }
}
