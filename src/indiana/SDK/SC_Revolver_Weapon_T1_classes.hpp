#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: SC_Revolver_Weapon_T1

#include "Basic.hpp"

#include "SC_Revolver_Weapon_Base_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass SC_Revolver_Weapon_T1.SC_Revolver_Weapon_T1_C
// 0x0000 (0x05D0 - 0x05D0)
class USC_Revolver_Weapon_T1_C final : public USC_Revolver_Weapon_Base_C
{
public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"SC_Revolver_Weapon_T1_C">();
	}
	static class USC_Revolver_Weapon_T1_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<USC_Revolver_Weapon_T1_C>();
	}
};
static_assert(alignof(USC_Revolver_Weapon_T1_C) == 0x000008, "Wrong alignment on USC_Revolver_Weapon_T1_C");
static_assert(sizeof(USC_Revolver_Weapon_T1_C) == 0x0005D0, "Wrong size on USC_Revolver_Weapon_T1_C");

}

