#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: StatsPerkListEntry_BP

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "Indiana_classes.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass StatsPerkListEntry_BP.StatsPerkListEntry_BP_C
// 0x0020 (0x0388 - 0x0368)
class UStatsPerkListEntry_BP_C final : public UPerksListEntry
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0368(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	class UWidgetAnimation*                       Pip3Flashing;                                      // 0x0370(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, RepSkip, NoDestructor, HasGetValueTypeHash)
	class UWidgetAnimation*                       Pip2Flashing;                                      // 0x0378(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, RepSkip, NoDestructor, HasGetValueTypeHash)
	class UWidgetAnimation*                       Pip1Flashing;                                      // 0x0380(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, RepSkip, NoDestructor, HasGetValueTypeHash)

public:
	void ExecuteUbergraph_StatsPerkListEntry_BP(int32 EntryPoint);
	void UpdateButtonBrush(bool bPendingPurchase, bool bActuallyPurchased, bool bSuppressed);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"StatsPerkListEntry_BP_C">();
	}
	static class UStatsPerkListEntry_BP_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UStatsPerkListEntry_BP_C>();
	}
};
static_assert(alignof(UStatsPerkListEntry_BP_C) == 0x000008, "Wrong alignment on UStatsPerkListEntry_BP_C");
static_assert(sizeof(UStatsPerkListEntry_BP_C) == 0x000388, "Wrong size on UStatsPerkListEntry_BP_C");
static_assert(offsetof(UStatsPerkListEntry_BP_C, UberGraphFrame) == 0x000368, "Member 'UStatsPerkListEntry_BP_C::UberGraphFrame' has a wrong offset!");
static_assert(offsetof(UStatsPerkListEntry_BP_C, Pip3Flashing) == 0x000370, "Member 'UStatsPerkListEntry_BP_C::Pip3Flashing' has a wrong offset!");
static_assert(offsetof(UStatsPerkListEntry_BP_C, Pip2Flashing) == 0x000378, "Member 'UStatsPerkListEntry_BP_C::Pip2Flashing' has a wrong offset!");
static_assert(offsetof(UStatsPerkListEntry_BP_C, Pip1Flashing) == 0x000380, "Member 'UStatsPerkListEntry_BP_C::Pip1Flashing' has a wrong offset!");

}

