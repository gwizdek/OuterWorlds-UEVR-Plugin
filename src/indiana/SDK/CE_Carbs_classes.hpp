#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: CE_Carbs

#include "Basic.hpp"

#include "Indiana_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass CE_Carbs.CE_Carbs_C
// 0x0000 (0x0240 - 0x0240)
class UCE_Carbs_C final : public UStatModifierStatusEffect
{
public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"CE_Carbs_C">();
	}
	static class UCE_Carbs_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UCE_Carbs_C>();
	}
};
static_assert(alignof(UCE_Carbs_C) == 0x000008, "Wrong alignment on UCE_Carbs_C");
static_assert(sizeof(UCE_Carbs_C) == 0x000240, "Wrong size on UCE_Carbs_C");

}

