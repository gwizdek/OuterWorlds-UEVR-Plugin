#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: PlayerDefaultHitReaction

#include "Basic.hpp"

#include "GameplayCameras_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass PlayerDefaultHitReaction.PlayerDefaultHitReaction_C
// 0x0000 (0x01B0 - 0x01B0)
class UPlayerDefaultHitReaction_C final : public UMatineeCameraShake
{
public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"PlayerDefaultHitReaction_C">();
	}
	static class UPlayerDefaultHitReaction_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UPlayerDefaultHitReaction_C>();
	}
};
static_assert(alignof(UPlayerDefaultHitReaction_C) == 0x000010, "Wrong alignment on UPlayerDefaultHitReaction_C");
static_assert(sizeof(UPlayerDefaultHitReaction_C) == 0x0001B0, "Wrong size on UPlayerDefaultHitReaction_C");

}

