#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: Arm_MMod_None

#include "Basic.hpp"

#include "Indiana_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass Arm_MMod_None.Arm_MMod_None_C
// 0x0000 (0x0040 - 0x0040)
class UArm_MMod_None_C final : public UMicroMod
{
public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"Arm_MMod_None_C">();
	}
	static class UArm_MMod_None_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UArm_MMod_None_C>();
	}
};
static_assert(alignof(UArm_MMod_None_C) == 0x000008, "Wrong alignment on UArm_MMod_None_C");
static_assert(sizeof(UArm_MMod_None_C) == 0x000040, "Wrong size on UArm_MMod_None_C");

}

