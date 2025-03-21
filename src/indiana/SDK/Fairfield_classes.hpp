#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: Fairfield

#include "Basic.hpp"

#include "Indiana_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass Fairfield.Fairfield_C
// 0x0000 (0x0200 - 0x0200)
class UFairfield_C final : public UFactionData
{
public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"Fairfield_C">();
	}
	static class UFairfield_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UFairfield_C>();
	}
};
static_assert(alignof(UFairfield_C) == 0x000008, "Wrong alignment on UFairfield_C");
static_assert(sizeof(UFairfield_C) == 0x000200, "Wrong size on UFairfield_C");

}

