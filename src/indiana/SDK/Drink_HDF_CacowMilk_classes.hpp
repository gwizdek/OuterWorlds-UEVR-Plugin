#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: Drink_HDF_CacowMilk

#include "Basic.hpp"

#include "Indiana_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass Drink_HDF_CacowMilk.Drink_HDF_CacowMilk_C
// 0x0000 (0x0230 - 0x0230)
class UDrink_HDF_CacowMilk_C final : public UConsumableItem
{
public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"Drink_HDF_CacowMilk_C">();
	}
	static class UDrink_HDF_CacowMilk_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UDrink_HDF_CacowMilk_C>();
	}
};
static_assert(alignof(UDrink_HDF_CacowMilk_C) == 0x000008, "Wrong alignment on UDrink_HDF_CacowMilk_C");
static_assert(sizeof(UDrink_HDF_CacowMilk_C) == 0x000230, "Wrong size on UDrink_HDF_CacowMilk_C");

}

