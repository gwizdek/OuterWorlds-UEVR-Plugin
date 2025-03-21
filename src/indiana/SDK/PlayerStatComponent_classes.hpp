#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: PlayerStatComponent

#include "Basic.hpp"

#include "StatComponentBase_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass PlayerStatComponent.PlayerStatComponent_C
// 0x0000 (0x01C0 - 0x01C0)
class UPlayerStatComponent_C final : public UStatComponentBase_C
{
public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"PlayerStatComponent_C">();
	}
	static class UPlayerStatComponent_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UPlayerStatComponent_C>();
	}
};
static_assert(alignof(UPlayerStatComponent_C) == 0x000008, "Wrong alignment on UPlayerStatComponent_C");
static_assert(sizeof(UPlayerStatComponent_C) == 0x0001C0, "Wrong size on UPlayerStatComponent_C");

}

