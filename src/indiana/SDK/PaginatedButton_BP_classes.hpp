#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: PaginatedButton_BP

#include "Basic.hpp"

#include "Indiana_classes.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass PaginatedButton_BP.PaginatedButton_BP_C
// 0x0000 (0x0288 - 0x0288)
class UPaginatedButton_BP_C final : public UPaginatedButtonWidget
{
public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"PaginatedButton_BP_C">();
	}
	static class UPaginatedButton_BP_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UPaginatedButton_BP_C>();
	}
};
static_assert(alignof(UPaginatedButton_BP_C) == 0x000008, "Wrong alignment on UPaginatedButton_BP_C");
static_assert(sizeof(UPaginatedButton_BP_C) == 0x000288, "Wrong size on UPaginatedButton_BP_C");

}

