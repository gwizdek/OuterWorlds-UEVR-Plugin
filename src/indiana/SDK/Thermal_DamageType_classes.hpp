#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: Thermal_DamageType

#include "Basic.hpp"

#include "Base_DamageType_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass Thermal_DamageType.Thermal_DamageType_C
// 0x0000 (0x01B8 - 0x01B8)
class UThermal_DamageType_C final : public UBase_DamageType_C
{
public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"Thermal_DamageType_C">();
	}
	static class UThermal_DamageType_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UThermal_DamageType_C>();
	}
};
static_assert(alignof(UThermal_DamageType_C) == 0x000008, "Wrong alignment on UThermal_DamageType_C");
static_assert(sizeof(UThermal_DamageType_C) == 0x0001B8, "Wrong size on UThermal_DamageType_C");

}

