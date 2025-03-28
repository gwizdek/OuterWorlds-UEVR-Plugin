#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: SC_LightPistol_Weapon_Base

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "Indiana_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass SC_LightPistol_Weapon_Base.SC_LightPistol_Weapon_Base_C
// 0x0008 (0x05D8 - 0x05D0)
class USC_LightPistol_Weapon_Base_C : public UWeapon
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x05D0(0x0008)(ZeroConstructor, Transient, DuplicateTransient)

public:
	void ExecuteUbergraph_SC_LightPistol_Weapon_Base(int32 EntryPoint);
	void ReceiveTick(float DeltaSeconds);
	void ReceiveActorBeginOverlap(class AActor* OtherActor);
	void ReceiveBeginPlay();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"SC_LightPistol_Weapon_Base_C">();
	}
	static class USC_LightPistol_Weapon_Base_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<USC_LightPistol_Weapon_Base_C>();
	}
};
static_assert(alignof(USC_LightPistol_Weapon_Base_C) == 0x000008, "Wrong alignment on USC_LightPistol_Weapon_Base_C");
static_assert(sizeof(USC_LightPistol_Weapon_Base_C) == 0x0005D8, "Wrong size on USC_LightPistol_Weapon_Base_C");
static_assert(offsetof(USC_LightPistol_Weapon_Base_C, UberGraphFrame) == 0x0005D0, "Member 'USC_LightPistol_Weapon_Base_C::UberGraphFrame' has a wrong offset!");

}

