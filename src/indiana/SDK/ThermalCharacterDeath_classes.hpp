#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: ThermalCharacterDeath

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "BaseCharacterDeath_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass ThermalCharacterDeath.ThermalCharacterDeath_C
// 0x0008 (0x0160 - 0x0158)
class UThermalCharacterDeath_C final : public UBaseCharacterDeath_C
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0158(0x0008)(ZeroConstructor, Transient, DuplicateTransient)

public:
	void ExecuteUbergraph_ThermalCharacterDeath(int32 EntryPoint);
	void ExecuteOnReload(class UCharacterDeathComponent* InDeathComponent);
	void Tick(float Delta);
	void Execute(class UCharacterDeathComponent* InDeathComponent);
	void TriggerParticleEffects();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"ThermalCharacterDeath_C">();
	}
	static class UThermalCharacterDeath_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UThermalCharacterDeath_C>();
	}
};
static_assert(alignof(UThermalCharacterDeath_C) == 0x000008, "Wrong alignment on UThermalCharacterDeath_C");
static_assert(sizeof(UThermalCharacterDeath_C) == 0x000160, "Wrong size on UThermalCharacterDeath_C");
static_assert(offsetof(UThermalCharacterDeath_C, UberGraphFrame) == 0x000158, "Member 'UThermalCharacterDeath_C::UberGraphFrame' has a wrong offset!");

}

