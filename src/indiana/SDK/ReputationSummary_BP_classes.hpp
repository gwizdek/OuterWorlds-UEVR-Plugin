#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: ReputationSummary_BP

#include "Basic.hpp"

#include "Indiana_classes.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass ReputationSummary_BP.ReputationSummary_BP_C
// 0x0000 (0x0340 - 0x0340)
class UReputationSummary_BP_C final : public UReputationSummaryWidget
{
public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"ReputationSummary_BP_C">();
	}
	static class UReputationSummary_BP_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UReputationSummary_BP_C>();
	}
};
static_assert(alignof(UReputationSummary_BP_C) == 0x000008, "Wrong alignment on UReputationSummary_BP_C");
static_assert(sizeof(UReputationSummary_BP_C) == 0x000340, "Wrong size on UReputationSummary_BP_C");

}

