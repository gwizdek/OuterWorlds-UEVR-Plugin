#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: PlayerTTDComponent

#include "Basic.hpp"

#include "Indiana_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass PlayerTTDComponent.PlayerTTDComponent_C
// 0x0000 (0x0260 - 0x0260)
class UPlayerTTDComponent_C final : public UTacticalTimeDilationComponent
{
public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"PlayerTTDComponent_C">();
	}
	static class UPlayerTTDComponent_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UPlayerTTDComponent_C>();
	}
};
static_assert(alignof(UPlayerTTDComponent_C) == 0x000008, "Wrong alignment on UPlayerTTDComponent_C");
static_assert(sizeof(UPlayerTTDComponent_C) == 0x000260, "Wrong size on UPlayerTTDComponent_C");

}

