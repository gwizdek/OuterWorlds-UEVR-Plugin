#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: CE_Scramble

#include "Basic.hpp"

#include "Indiana_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass CE_Scramble.CE_Scramble_C
// 0x0000 (0x01B8 - 0x01B8)
class UCE_Scramble_C final : public UMultiStatusEffect
{
public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"CE_Scramble_C">();
	}
	static class UCE_Scramble_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UCE_Scramble_C>();
	}
};
static_assert(alignof(UCE_Scramble_C) == 0x000008, "Wrong alignment on UCE_Scramble_C");
static_assert(sizeof(UCE_Scramble_C) == 0x0001B8, "Wrong size on UCE_Scramble_C");

}

