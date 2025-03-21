#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: PlayerPerkList_BP

#include "Basic.hpp"

#include "Indiana_classes.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass PlayerPerkList_BP.PlayerPerkList_BP_C
// 0x0018 (0x0378 - 0x0360)
class UPlayerPerkList_BP_C final : public UPerksListWidget
{
public:
	class UImage*                                 PerkRowLineBreakOne;                               // 0x0360(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UImage*                                 PerkRowLineBreakTwo;                               // 0x0368(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UVerticalBox*                           PerkVerticalBox;                                   // 0x0370(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"PlayerPerkList_BP_C">();
	}
	static class UPlayerPerkList_BP_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UPlayerPerkList_BP_C>();
	}
};
static_assert(alignof(UPlayerPerkList_BP_C) == 0x000008, "Wrong alignment on UPlayerPerkList_BP_C");
static_assert(sizeof(UPlayerPerkList_BP_C) == 0x000378, "Wrong size on UPlayerPerkList_BP_C");
static_assert(offsetof(UPlayerPerkList_BP_C, PerkRowLineBreakOne) == 0x000360, "Member 'UPlayerPerkList_BP_C::PerkRowLineBreakOne' has a wrong offset!");
static_assert(offsetof(UPlayerPerkList_BP_C, PerkRowLineBreakTwo) == 0x000368, "Member 'UPlayerPerkList_BP_C::PerkRowLineBreakTwo' has a wrong offset!");
static_assert(offsetof(UPlayerPerkList_BP_C, PerkVerticalBox) == 0x000370, "Member 'UPlayerPerkList_BP_C::PerkVerticalBox' has a wrong offset!");

}

