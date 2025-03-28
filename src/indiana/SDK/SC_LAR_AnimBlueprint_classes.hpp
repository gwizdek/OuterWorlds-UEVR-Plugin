#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: SC_LAR_AnimBlueprint

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "AnimGraphRuntime_structs.hpp"
#include "Indiana_classes.hpp"


namespace SDK
{

// AnimBlueprintGeneratedClass SC_LAR_AnimBlueprint.SC_LAR_AnimBlueprint_C
// 0x0080 (0x0390 - 0x0310)
class USC_LAR_AnimBlueprint_C final : public UWeaponAnimInstance
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0310(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	struct FAnimNode_Root                         AnimGraphNode_Root;                                // 0x0318(0x0030)()
	struct FAnimNode_Slot                         AnimGraphNode_Slot;                                // 0x0348(0x0048)()

public:
	void ExecuteUbergraph_SC_LAR_AnimBlueprint(int32 EntryPoint);
	void AnimGraph(struct FPoseLink* AnimGraph_0);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"SC_LAR_AnimBlueprint_C">();
	}
	static class USC_LAR_AnimBlueprint_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<USC_LAR_AnimBlueprint_C>();
	}
};
static_assert(alignof(USC_LAR_AnimBlueprint_C) == 0x000010, "Wrong alignment on USC_LAR_AnimBlueprint_C");
static_assert(sizeof(USC_LAR_AnimBlueprint_C) == 0x000390, "Wrong size on USC_LAR_AnimBlueprint_C");
static_assert(offsetof(USC_LAR_AnimBlueprint_C, UberGraphFrame) == 0x000310, "Member 'USC_LAR_AnimBlueprint_C::UberGraphFrame' has a wrong offset!");
static_assert(offsetof(USC_LAR_AnimBlueprint_C, AnimGraphNode_Root) == 0x000318, "Member 'USC_LAR_AnimBlueprint_C::AnimGraphNode_Root' has a wrong offset!");
static_assert(offsetof(USC_LAR_AnimBlueprint_C, AnimGraphNode_Slot) == 0x000348, "Member 'USC_LAR_AnimBlueprint_C::AnimGraphNode_Slot' has a wrong offset!");

}

