#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: CompanionCommandMoveTo

#include "Basic.hpp"

#include "Indiana_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass CompanionCommandMoveTo.CompanionCommandMoveTo_C
// 0x0000 (0x0048 - 0x0048)
class UCompanionCommandMoveTo_C final : public UDecisionTree_CombinedRequests
{
public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"CompanionCommandMoveTo_C">();
	}
	static class UCompanionCommandMoveTo_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UCompanionCommandMoveTo_C>();
	}
};
static_assert(alignof(UCompanionCommandMoveTo_C) == 0x000008, "Wrong alignment on UCompanionCommandMoveTo_C");
static_assert(sizeof(UCompanionCommandMoveTo_C) == 0x000048, "Wrong size on UCompanionCommandMoveTo_C");

}

