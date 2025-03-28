#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: CompanionEquipmentBarWidget

#include "Basic.hpp"

#include "Indiana_classes.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass CompanionEquipmentBarWidget.CompanionEquipmentBarWidget_C
// 0x0020 (0x0490 - 0x0470)
class UCompanionEquipmentBarWidget_C final : public UCompanionEquipmentBarWidget
{
public:
	class UInventoryItem_BP_C*                    Item0;                                             // 0x0470(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UInventoryItem_BP_C*                    Item1;                                             // 0x0478(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UInventoryItem_BP_C*                    Item2;                                             // 0x0480(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UInventoryItem_BP_C*                    Item3;                                             // 0x0488(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"CompanionEquipmentBarWidget_C">();
	}
	static class UCompanionEquipmentBarWidget_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UCompanionEquipmentBarWidget_C>();
	}
};
static_assert(alignof(UCompanionEquipmentBarWidget_C) == 0x000008, "Wrong alignment on UCompanionEquipmentBarWidget_C");
static_assert(sizeof(UCompanionEquipmentBarWidget_C) == 0x000490, "Wrong size on UCompanionEquipmentBarWidget_C");
static_assert(offsetof(UCompanionEquipmentBarWidget_C, Item0) == 0x000470, "Member 'UCompanionEquipmentBarWidget_C::Item0' has a wrong offset!");
static_assert(offsetof(UCompanionEquipmentBarWidget_C, Item1) == 0x000478, "Member 'UCompanionEquipmentBarWidget_C::Item1' has a wrong offset!");
static_assert(offsetof(UCompanionEquipmentBarWidget_C, Item2) == 0x000480, "Member 'UCompanionEquipmentBarWidget_C::Item2' has a wrong offset!");
static_assert(offsetof(UCompanionEquipmentBarWidget_C, Item3) == 0x000488, "Member 'UCompanionEquipmentBarWidget_C::Item3' has a wrong offset!");

}

