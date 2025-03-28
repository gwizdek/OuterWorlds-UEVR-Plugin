#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: DIS_Hope_T1

#include "Basic.hpp"

#include "Indiana_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass DIS_Hope_T1.DIS_Hope_T1_C
// 0x0000 (0x01D0 - 0x01D0)
class UDIS_Hope_T1_C final : public UDisguiseItem
{
public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"DIS_Hope_T1_C">();
	}
	static class UDIS_Hope_T1_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UDIS_Hope_T1_C>();
	}
};
static_assert(alignof(UDIS_Hope_T1_C) == 0x000008, "Wrong alignment on UDIS_Hope_T1_C");
static_assert(sizeof(UDIS_Hope_T1_C) == 0x0001D0, "Wrong size on UDIS_Hope_T1_C");

}

