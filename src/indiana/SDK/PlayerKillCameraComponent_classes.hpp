#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: PlayerKillCameraComponent

#include "Basic.hpp"

#include "Indiana_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass PlayerKillCameraComponent.PlayerKillCameraComponent_C
// 0x0000 (0x0160 - 0x0160)
class UPlayerKillCameraComponent_C final : public UKillCameraComponent
{
public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"PlayerKillCameraComponent_C">();
	}
	static class UPlayerKillCameraComponent_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UPlayerKillCameraComponent_C>();
	}
};
static_assert(alignof(UPlayerKillCameraComponent_C) == 0x000008, "Wrong alignment on UPlayerKillCameraComponent_C");
static_assert(sizeof(UPlayerKillCameraComponent_C) == 0x000160, "Wrong size on UPlayerKillCameraComponent_C");

}

