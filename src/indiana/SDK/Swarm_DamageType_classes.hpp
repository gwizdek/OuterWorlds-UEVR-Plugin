#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: Swarm_DamageType

#include "Basic.hpp"

#include "Base_DamageType_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass Swarm_DamageType.Swarm_DamageType_C
// 0x0000 (0x01B8 - 0x01B8)
class USwarm_DamageType_C final : public UBase_DamageType_C
{
public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"Swarm_DamageType_C">();
	}
	static class USwarm_DamageType_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<USwarm_DamageType_C>();
	}
};
static_assert(alignof(USwarm_DamageType_C) == 0x000008, "Wrong alignment on USwarm_DamageType_C");
static_assert(sizeof(USwarm_DamageType_C) == 0x0001B8, "Wrong size on USwarm_DamageType_C");

}

