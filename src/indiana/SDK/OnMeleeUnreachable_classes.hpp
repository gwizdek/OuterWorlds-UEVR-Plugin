#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: OnMeleeUnreachable

#include "Basic.hpp"

#include "Indiana_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass OnMeleeUnreachable.OnMeleeUnreachable_C
// 0x0000 (0x0048 - 0x0048)
class UOnMeleeUnreachable_C final : public UDecisionTree_Combined
{
public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"OnMeleeUnreachable_C">();
	}
	static class UOnMeleeUnreachable_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UOnMeleeUnreachable_C>();
	}
};
static_assert(alignof(UOnMeleeUnreachable_C) == 0x000008, "Wrong alignment on UOnMeleeUnreachable_C");
static_assert(sizeof(UOnMeleeUnreachable_C) == 0x000048, "Wrong size on UOnMeleeUnreachable_C");

}

