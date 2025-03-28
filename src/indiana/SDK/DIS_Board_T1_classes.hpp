#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: DIS_Board_T1

#include "Basic.hpp"

#include "Indiana_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass DIS_Board_T1.DIS_Board_T1_C
// 0x0000 (0x01D0 - 0x01D0)
class UDIS_Board_T1_C final : public UDisguiseItem
{
public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"DIS_Board_T1_C">();
	}
	static class UDIS_Board_T1_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UDIS_Board_T1_C>();
	}
};
static_assert(alignof(UDIS_Board_T1_C) == 0x000008, "Wrong alignment on UDIS_Board_T1_C");
static_assert(sizeof(UDIS_Board_T1_C) == 0x0001D0, "Wrong size on UDIS_Board_T1_C");

}

