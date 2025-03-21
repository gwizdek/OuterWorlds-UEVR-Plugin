#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: Idle

#include "Basic.hpp"

#include "Indiana_structs.hpp"


namespace SDK::Params
{

// Function Idle.Idle_C.RunDecisionTree
// 0x0040 (0x0040 - 0x0000)
struct Idle_C_RunDecisionTree final
{
public:
	class AIndianaAiCharacter*                    Owner;                                             // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class FName                                   EventType;                                         // 0x0008(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UAIEventInfo*                           EventInfo;                                         // 0x0010(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	EDecisionTreeRequestPriority                  OutPriority;                                       // 0x0018(0x0001)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_19[0x7];                                       // 0x0019(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	TArray<class UDecisionTreeRequestData*>       ReturnValue;                                       // 0x0020(0x0010)(Parm, OutParm, ReturnParm)
	TArray<class UDecisionTreeRequestData*>       K2Node_MakeArray_Array;                            // 0x0030(0x0010)(ReferenceParm)
};
static_assert(alignof(Idle_C_RunDecisionTree) == 0x000008, "Wrong alignment on Idle_C_RunDecisionTree");
static_assert(sizeof(Idle_C_RunDecisionTree) == 0x000040, "Wrong size on Idle_C_RunDecisionTree");
static_assert(offsetof(Idle_C_RunDecisionTree, Owner) == 0x000000, "Member 'Idle_C_RunDecisionTree::Owner' has a wrong offset!");
static_assert(offsetof(Idle_C_RunDecisionTree, EventType) == 0x000008, "Member 'Idle_C_RunDecisionTree::EventType' has a wrong offset!");
static_assert(offsetof(Idle_C_RunDecisionTree, EventInfo) == 0x000010, "Member 'Idle_C_RunDecisionTree::EventInfo' has a wrong offset!");
static_assert(offsetof(Idle_C_RunDecisionTree, OutPriority) == 0x000018, "Member 'Idle_C_RunDecisionTree::OutPriority' has a wrong offset!");
static_assert(offsetof(Idle_C_RunDecisionTree, ReturnValue) == 0x000020, "Member 'Idle_C_RunDecisionTree::ReturnValue' has a wrong offset!");
static_assert(offsetof(Idle_C_RunDecisionTree, K2Node_MakeArray_Array) == 0x000030, "Member 'Idle_C_RunDecisionTree::K2Node_MakeArray_Array' has a wrong offset!");

}

