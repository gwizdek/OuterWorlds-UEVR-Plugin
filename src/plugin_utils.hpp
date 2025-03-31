#pragma once
#include "uevr/API.hpp"
#include "indiana/SDK/Engine_classes.hpp"

class PluginUtils
{
private:

public:
    PluginUtils() = default;
    virtual ~PluginUtils() {};

    static void reset_height(float offset_y);
    static SDK::AActor* spawn_actor(SDK::UWorld* world, SDK::FTransform transform, std::wstring actor_tag);
    static void destroy_actors_by_tag(SDK::UWorld* world, std::wstring actor_tag);

};
