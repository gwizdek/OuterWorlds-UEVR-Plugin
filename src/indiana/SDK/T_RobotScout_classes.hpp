#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: T_RobotScout

#include "Basic.hpp"

#include "Indiana_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass T_RobotScout.T_RobotScout_C
// 0x0000 (0x0238 - 0x0238)
class UT_RobotScout_C final : public UTeamData
{
public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"T_RobotScout_C">();
	}
	static class UT_RobotScout_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UT_RobotScout_C>();
	}
};
static_assert(alignof(UT_RobotScout_C) == 0x000008, "Wrong alignment on UT_RobotScout_C");
static_assert(sizeof(UT_RobotScout_C) == 0x000238, "Wrong size on UT_RobotScout_C");

}

