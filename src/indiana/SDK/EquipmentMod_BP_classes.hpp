#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: EquipmentMod_BP

#include "Basic.hpp"

#include "Indiana_classes.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass EquipmentMod_BP.EquipmentMod_BP_C
// 0x0000 (0x02A8 - 0x02A8)
class UEquipmentMod_BP_C final : public UEquipmentModWidget
{
public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"EquipmentMod_BP_C">();
	}
	static class UEquipmentMod_BP_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UEquipmentMod_BP_C>();
	}
};
static_assert(alignof(UEquipmentMod_BP_C) == 0x000008, "Wrong alignment on UEquipmentMod_BP_C");
static_assert(sizeof(UEquipmentMod_BP_C) == 0x0002A8, "Wrong size on UEquipmentMod_BP_C");

}

