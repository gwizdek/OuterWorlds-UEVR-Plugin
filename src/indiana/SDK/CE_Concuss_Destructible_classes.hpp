#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: CE_Concuss_Destructible

#include "Basic.hpp"

#include "Indiana_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass CE_Concuss_Destructible.CE_Concuss_Destructible_C
// 0x0000 (0x0198 - 0x0198)
class UCE_Concuss_Destructible_C final : public UCastSpellStatusEffect
{
public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"CE_Concuss_Destructible_C">();
	}
	static class UCE_Concuss_Destructible_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UCE_Concuss_Destructible_C>();
	}
};
static_assert(alignof(UCE_Concuss_Destructible_C) == 0x000008, "Wrong alignment on UCE_Concuss_Destructible_C");
static_assert(sizeof(UCE_Concuss_Destructible_C) == 0x000198, "Wrong size on UCE_Concuss_Destructible_C");

}

