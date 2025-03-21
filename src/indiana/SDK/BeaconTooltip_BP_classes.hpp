#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: BeaconTooltip_BP

#include "Basic.hpp"

#include "Indiana_classes.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass BeaconTooltip_BP.BeaconTooltip_BP_C
// 0x0018 (0x0318 - 0x0300)
class UBeaconTooltip_BP_C final : public UMapBeaconEntryTooltipWidget
{
public:
	class UTextBlockBase*                         FastTravelTextBlock;                               // 0x0300(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UBorder*                                FrameBorder;                                       // 0x0308(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UTextBlockBase*                         RestrictionTextBlock;                              // 0x0310(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"BeaconTooltip_BP_C">();
	}
	static class UBeaconTooltip_BP_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UBeaconTooltip_BP_C>();
	}
};
static_assert(alignof(UBeaconTooltip_BP_C) == 0x000008, "Wrong alignment on UBeaconTooltip_BP_C");
static_assert(sizeof(UBeaconTooltip_BP_C) == 0x000318, "Wrong size on UBeaconTooltip_BP_C");
static_assert(offsetof(UBeaconTooltip_BP_C, FastTravelTextBlock) == 0x000300, "Member 'UBeaconTooltip_BP_C::FastTravelTextBlock' has a wrong offset!");
static_assert(offsetof(UBeaconTooltip_BP_C, FrameBorder) == 0x000308, "Member 'UBeaconTooltip_BP_C::FrameBorder' has a wrong offset!");
static_assert(offsetof(UBeaconTooltip_BP_C, RestrictionTextBlock) == 0x000310, "Member 'UBeaconTooltip_BP_C::RestrictionTextBlock' has a wrong offset!");

}

