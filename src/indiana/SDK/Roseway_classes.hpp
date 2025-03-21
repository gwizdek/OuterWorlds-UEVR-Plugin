#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: Roseway

#include "Basic.hpp"

#include "Indiana_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass Roseway.Roseway_C
// 0x0000 (0x0200 - 0x0200)
class URoseway_C final : public UFactionData
{
public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"Roseway_C">();
	}
	static class URoseway_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<URoseway_C>();
	}
};
static_assert(alignof(URoseway_C) == 0x000008, "Wrong alignment on URoseway_C");
static_assert(sizeof(URoseway_C) == 0x000200, "Wrong size on URoseway_C");

}

