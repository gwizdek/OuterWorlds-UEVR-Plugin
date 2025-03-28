#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: OnNearbyMeleeAttack

#include "Basic.hpp"

#include "Indiana_structs.hpp"


namespace SDK::Params
{

// Function OnNearbyMeleeAttack.OnNearbyMeleeAttack_C.RunDecisionTree
// 0x0048 (0x0048 - 0x0000)
struct OnNearbyMeleeAttack_C_RunDecisionTree final
{
public:
	class AIndianaAiCharacter*                    Owner;                                             // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class FName                                   EventType;                                         // 0x0008(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UAIEventInfo*                           EventInfo;                                         // 0x0010(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	EDecisionTreeRequestPriority                  OutPriority;                                       // 0x0018(0x0001)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_19[0x7];                                       // 0x0019(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	TArray<class UDecisionTreeRequestData*>       ReturnValue;                                       // 0x0020(0x0010)(Parm, OutParm, ReturnParm)
	EDecisionTreeRequestPriority                  CallFunc_RunMetaDecisionTree_OutPriority;          // 0x0030(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_31[0x7];                                       // 0x0031(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	TArray<class UDecisionTreeRequestData*>       CallFunc_RunMetaDecisionTree_ReturnValue;          // 0x0038(0x0010)(ReferenceParm)
};
static_assert(alignof(OnNearbyMeleeAttack_C_RunDecisionTree) == 0x000008, "Wrong alignment on OnNearbyMeleeAttack_C_RunDecisionTree");
static_assert(sizeof(OnNearbyMeleeAttack_C_RunDecisionTree) == 0x000048, "Wrong size on OnNearbyMeleeAttack_C_RunDecisionTree");
static_assert(offsetof(OnNearbyMeleeAttack_C_RunDecisionTree, Owner) == 0x000000, "Member 'OnNearbyMeleeAttack_C_RunDecisionTree::Owner' has a wrong offset!");
static_assert(offsetof(OnNearbyMeleeAttack_C_RunDecisionTree, EventType) == 0x000008, "Member 'OnNearbyMeleeAttack_C_RunDecisionTree::EventType' has a wrong offset!");
static_assert(offsetof(OnNearbyMeleeAttack_C_RunDecisionTree, EventInfo) == 0x000010, "Member 'OnNearbyMeleeAttack_C_RunDecisionTree::EventInfo' has a wrong offset!");
static_assert(offsetof(OnNearbyMeleeAttack_C_RunDecisionTree, OutPriority) == 0x000018, "Member 'OnNearbyMeleeAttack_C_RunDecisionTree::OutPriority' has a wrong offset!");
static_assert(offsetof(OnNearbyMeleeAttack_C_RunDecisionTree, ReturnValue) == 0x000020, "Member 'OnNearbyMeleeAttack_C_RunDecisionTree::ReturnValue' has a wrong offset!");
static_assert(offsetof(OnNearbyMeleeAttack_C_RunDecisionTree, CallFunc_RunMetaDecisionTree_OutPriority) == 0x000030, "Member 'OnNearbyMeleeAttack_C_RunDecisionTree::CallFunc_RunMetaDecisionTree_OutPriority' has a wrong offset!");
static_assert(offsetof(OnNearbyMeleeAttack_C_RunDecisionTree, CallFunc_RunMetaDecisionTree_ReturnValue) == 0x000038, "Member 'OnNearbyMeleeAttack_C_RunDecisionTree::CallFunc_RunMetaDecisionTree_ReturnValue' has a wrong offset!");

}

