#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: CE_StandYourGround

#include "Basic.hpp"

#include "Indiana_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass CE_StandYourGround.CE_StandYourGround_C
// 0x0000 (0x01A8 - 0x01A8)
class UCE_StandYourGround_C final : public UArmorStatusEffect
{
public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"CE_StandYourGround_C">();
	}
	static class UCE_StandYourGround_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UCE_StandYourGround_C>();
	}
};
static_assert(alignof(UCE_StandYourGround_C) == 0x000008, "Wrong alignment on UCE_StandYourGround_C");
static_assert(sizeof(UCE_StandYourGround_C) == 0x0001A8, "Wrong size on UCE_StandYourGround_C");

}

