#include "imgui/imgui.h"

#include "attached_widget.hpp"

using namespace uevr;

AttachedWidget::~AttachedWidget() {
    API::get()->log_warn("[attached_widget][%s] Destructor", m_widget_name);
}

bool AttachedWidget::is_valid() {
    return SDK::UKismetSystemLibrary::IsValid(m_widget_component);
}

SDK::FTransform AttachedWidget::get_transform() {
    return m_widget_transform;
}

SDK::UWidgetComponent* AttachedWidget::get_widget_component() {
    return m_widget_component;
}

void AttachedWidget::set_transform(SDK::FVector euler_rotation, SDK::FVector translation, float scale) {
    m_widget_transform.Rotation = SDK::UKismetMathLibrary::Quat_MakeFromEuler(euler_rotation);
    m_widget_transform.Translation = translation;
    m_widget_transform.Scale3D = { 1.f, scale, scale };

    SDK::FHitResult hit_result{};
    m_widget_component->K2_SetRelativeTransform(m_widget_transform, false, &hit_result, false);
}

float AttachedWidget::get_opacity() {
    return m_widget_opacity;
}

void AttachedWidget::set_opacity(float opacity) {
    m_widget_opacity = opacity;
    SDK::FLinearColor color{ 1.f, 1.f, 1.f, m_widget_opacity };
    m_widget_component->SetTintColorAndOpacity(color);
}

bool AttachedWidget::attach(SDK::AActor* hand_actor, SDK::UUserWidget* widget, SDK::FTransform transform, SDK::FVector2D draw_size, const char* widget_name, const char* widget_ui_name) {
    try {
        //API::get()->log_warn("[attached_widget][attach][%s] Attaching", widget_name);
        if (hand_actor == nullptr || widget == nullptr) {
            API::get()->log_warn("[attached_widget][attach][%s] Pointers not valid", widget_name);
            return false;
        }

        //if (m_widget_component != nullptr) {
        //    API::get()->log_warn("[attached_widget][attach] [%s] Already attached", widget_name);
        //    return false;
        //}

        if (!SDK::UKismetSystemLibrary::IsValid(widget)) {
            API::get()->log_warn("[attached_widget][attach][%s] Invalid widget", widget_name);
            return false;
        }

        m_widget_transform = transform;

        m_widget_component = static_cast<SDK::UWidgetComponent*>(
            hand_actor->AddComponentByClass(SDK::UWidgetComponent::StaticClass(), false, m_widget_transform, false)
            );

        if (m_widget_component == nullptr) {
            API::get()->log_warn("[attached_widget][attach][%s] Failed to attach component", widget_name);
            return false;
        }

        widget->RemoveFromViewport();
        m_widget_component->SetDrawSize(draw_size);
        m_widget_component->SetWidget(widget);
        m_widget_component->SetVisibility(true, true);
        m_widget_component->SetHiddenInGame(false, false);
        m_widget_component->SetCollisionEnabled(SDK::ECollisionEnabled::NoCollision);

        auto material = API::get()->find_uobject<SDK::UMaterialInstanceConstant>(
            // L"MaterialInstanceConstant /Engine/EngineMaterials/Widget3DPassThrough_Opaque.Widget3DPassThrough_Opaque"
            L"MaterialInstanceConstant /Engine/EngineMaterials/Widget3DPassThrough_Translucent.Widget3DPassThrough_Translucent"
        );

        m_widget_component->SetMaterial(0, material);
        set_opacity(0.6f);
        m_widget_component->BlendMode = SDK::EWidgetBlendMode::Transparent;

        hand_actor->FinishAddComponent(m_widget_component, false, m_widget_transform);

        m_widget_name = widget_name;
        m_widget_ui_name = widget_ui_name;

        API::get()->log_warn("[attached_widget][attach][%s] Successfully Attached", widget_name);
        return true;
    }
    catch (...) {
        API::get()->log_error("[attached_widget][attach][%s] Exception", widget_name);
    }
}

void AttachedWidget::on_draw_imgui() {
    try {
        if (is_valid()) {
            if (ImGui::CollapsingHeader(m_widget_ui_name.c_str(), ImGuiTreeNodeFlags_None)) {
                ImGui::BeginGroup();
                ImGui::PushID(m_widget_name.c_str());
                if (ImGui::Button("Restore Defaults")) {
                    SDK::FHitResult hit_result{};
                    m_widget_component->K2_SetRelativeTransform(m_widget_transform, false, &hit_result, false);
                }

                ImGui::SliderFloat("X", &m_widget_component->RelativeLocation.X, -15.f, 15.f, "%.1f");
                ImGui::SliderFloat("Y", &m_widget_component->RelativeLocation.Y, -15.f, 15.f, "%.1f");
                ImGui::SliderFloat("Z", &m_widget_component->RelativeLocation.Z, -15.f, 15.f, "%.1f");

                ImGui::SliderFloat("Pitch", &m_widget_component->RelativeRotation.Pitch, -180.f, 180.f, "%1.f");
                ImGui::SliderFloat("Roll", &m_widget_component->RelativeRotation.Roll, -180.f, 180.f, "%1.f");
                ImGui::SliderFloat("Yaw", &m_widget_component->RelativeRotation.Yaw, -180.f, 180.f, "%1.f");

                ImGui::SliderFloat("Scale X", &m_widget_component->RelativeScale3D.Y, 0.0f, 0.1f, "%.3f");
                ImGui::SliderFloat("Scale Y", &m_widget_component->RelativeScale3D.Z, 0.0f, 0.1f, "%.3f");

                ImGui::PopID();
                ImGui::EndGroup();
            }
        }
    }
    catch (...) {
        API::get()->log_error("[attached_widget][on_draw_imgui][%s] Exception", m_widget_name.c_str());
    }
}

void AttachedWidget::on_save_config(mINI::INIStructure& config) {
    try {
        API::get()->log_warn("[attached_widget][on_save_config][%s] Saving", m_widget_name.c_str());

        if (!is_valid()) {
            API::get()->log_error("[attached_widget][on_save_config][%s] Invalid component", m_widget_name.c_str());
            return;
        }

        config[m_widget_name.c_str()]["pos_x"] = std::to_string(m_widget_component->RelativeLocation.X).c_str();
        config[m_widget_name.c_str()]["pos_y"] = std::to_string(m_widget_component->RelativeLocation.Y).c_str();
        config[m_widget_name.c_str()]["pos_z"] = std::to_string(m_widget_component->RelativeLocation.Z).c_str();
        config[m_widget_name.c_str()]["pitch"] = std::to_string(m_widget_component->RelativeRotation.Pitch).c_str();
        config[m_widget_name.c_str()]["roll"] = std::to_string(m_widget_component->RelativeRotation.Roll).c_str();
        config[m_widget_name.c_str()]["yaw"] = std::to_string(m_widget_component->RelativeRotation.Yaw).c_str();
        config[m_widget_name.c_str()]["scale_y"] = std::to_string(m_widget_component->RelativeScale3D.Y).c_str();
        config[m_widget_name.c_str()]["scale_z"] = std::to_string(m_widget_component->RelativeScale3D.Z).c_str();
    }
    catch (...) {
        API::get()->log_error("[attached_widget][on_save_config][%s] Exception", m_widget_name.c_str());
    }
}

void AttachedWidget::on_load_config(mINI::INIStructure& config) {
    try {
        if (!is_valid()) {
            API::get()->log_error("[attached_widget][on_load_config][%s] Invalid component", m_widget_name.c_str());
            return;
        }

        if (config.has(m_widget_name.c_str())) {
            try {
                m_widget_component->RelativeLocation.X = std::stof(config[m_widget_name.c_str()]["pos_x"]);
                m_widget_component->RelativeLocation.Y = std::stof(config[m_widget_name.c_str()]["pos_y"]);
                m_widget_component->RelativeLocation.Z = std::stof(config[m_widget_name.c_str()]["pos_z"]);
                m_widget_component->RelativeRotation.Pitch = std::stof(config[m_widget_name.c_str()]["pitch"]);
                m_widget_component->RelativeRotation.Roll = std::stof(config[m_widget_name.c_str()]["roll"]);
                m_widget_component->RelativeRotation.Yaw = std::stof(config[m_widget_name.c_str()]["yaw"]);
                m_widget_component->RelativeScale3D.Y = std::stof(config[m_widget_name.c_str()]["scale_y"]);
                m_widget_component->RelativeScale3D.Z = std::stof(config[m_widget_name.c_str()]["scale_z"]);
            }
            catch (...) {
                API::get()->log_error("[attached_widget][on_load_config][%s] Failed to load config value", m_widget_name.c_str());
            }
        }
    }
    catch (...) {
        API::get()->log_error("[attached_widget][on_load_config][%s] Exception", m_widget_name.c_str());
    }
}
