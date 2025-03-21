#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: Idle

#include "Basic.hpp"

#include "Indiana_structs.hpp"
#include "Indiana_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass Idle.Idle_C
// 0x0000 (0x0030 - 0x0030)
class UIdle_C final : public UDecisionTree
{
public:
	TArray<class UDecisionTreeRequestData*> RunDecisionTree(class AIndianaAiCharacter* Owner, class FName EventType, class UAIEventInfo* EventInfo, EDecisionTreeRequestPriority* OutPriority);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"Idle_C">();
	}
	static class UIdle_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UIdle_C>();
	}
};
static_assert(alignof(UIdle_C) == 0x000008, "Wrong alignment on UIdle_C");
static_assert(sizeof(UIdle_C) == 0x000030, "Wrong size on UIdle_C");

}

