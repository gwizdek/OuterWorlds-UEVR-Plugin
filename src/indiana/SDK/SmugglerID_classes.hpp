#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: SmugglerID

#include "Basic.hpp"

#include "Indiana_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass SmugglerID.SmugglerID_C
// 0x0000 (0x01D0 - 0x01D0)
class USmugglerID_C final : public UQuestItem
{
public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"SmugglerID_C">();
	}
	static class USmugglerID_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<USmugglerID_C>();
	}
};
static_assert(alignof(USmugglerID_C) == 0x000008, "Wrong alignment on USmugglerID_C");
static_assert(sizeof(USmugglerID_C) == 0x0001D0, "Wrong size on USmugglerID_C");

}

