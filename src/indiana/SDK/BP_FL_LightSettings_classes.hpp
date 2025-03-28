#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: BP_FL_LightSettings

#include "Basic.hpp"

#include "Engine_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass BP_FL_LightSettings.BP_FL_LightSettings_C
// 0x0000 (0x0030 - 0x0030)
class UBP_FL_LightSettings_C final : public UBlueprintFunctionLibrary
{
public:
	static void LightSettings(class UPointLightComponent* PointLight_Actor, class USpotLightComponent* SpotLight_Actor, float LightIntensity, float AttenuationRadius, float LightTemperature, const struct FLinearColor& LightColor, float InnerConeAngle, float OuterConeAngle, bool LightOn, class UObject* __WorldContext);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"BP_FL_LightSettings_C">();
	}
	static class UBP_FL_LightSettings_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UBP_FL_LightSettings_C>();
	}
};
static_assert(alignof(UBP_FL_LightSettings_C) == 0x000008, "Wrong alignment on UBP_FL_LightSettings_C");
static_assert(sizeof(UBP_FL_LightSettings_C) == 0x000030, "Wrong size on UBP_FL_LightSettings_C");

}

