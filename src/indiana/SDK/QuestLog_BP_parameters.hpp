#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: QuestLog_BP

#include "Basic.hpp"


namespace SDK::Params
{

// Function QuestLog_BP.QuestLog_BP_C.ExecuteUbergraph_QuestLog_BP
// 0x0020 (0x0020 - 0x0000)
struct QuestLog_BP_C_ExecuteUbergraph_QuestLog_BP final
{
public:
	int32                                         EntryPoint;                                        // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_IsAnimationPlaying_ReturnValue;           // 0x0004(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_IsAnimationPlaying_ReturnValue_1;         // 0x0005(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_6[0x2];                                        // 0x0006(0x0002)(Fixing Size After Last Property [ Dumper-7 ])
	class UUMGSequencePlayer*                     CallFunc_PlayAnimation_ReturnValue;                // 0x0008(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UUMGSequencePlayer*                     CallFunc_PlayAnimation_ReturnValue_1;              // 0x0010(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_EqualEqual_FloatFloat_ReturnValue;        // 0x0018(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(QuestLog_BP_C_ExecuteUbergraph_QuestLog_BP) == 0x000008, "Wrong alignment on QuestLog_BP_C_ExecuteUbergraph_QuestLog_BP");
static_assert(sizeof(QuestLog_BP_C_ExecuteUbergraph_QuestLog_BP) == 0x000020, "Wrong size on QuestLog_BP_C_ExecuteUbergraph_QuestLog_BP");
static_assert(offsetof(QuestLog_BP_C_ExecuteUbergraph_QuestLog_BP, EntryPoint) == 0x000000, "Member 'QuestLog_BP_C_ExecuteUbergraph_QuestLog_BP::EntryPoint' has a wrong offset!");
static_assert(offsetof(QuestLog_BP_C_ExecuteUbergraph_QuestLog_BP, CallFunc_IsAnimationPlaying_ReturnValue) == 0x000004, "Member 'QuestLog_BP_C_ExecuteUbergraph_QuestLog_BP::CallFunc_IsAnimationPlaying_ReturnValue' has a wrong offset!");
static_assert(offsetof(QuestLog_BP_C_ExecuteUbergraph_QuestLog_BP, CallFunc_IsAnimationPlaying_ReturnValue_1) == 0x000005, "Member 'QuestLog_BP_C_ExecuteUbergraph_QuestLog_BP::CallFunc_IsAnimationPlaying_ReturnValue_1' has a wrong offset!");
static_assert(offsetof(QuestLog_BP_C_ExecuteUbergraph_QuestLog_BP, CallFunc_PlayAnimation_ReturnValue) == 0x000008, "Member 'QuestLog_BP_C_ExecuteUbergraph_QuestLog_BP::CallFunc_PlayAnimation_ReturnValue' has a wrong offset!");
static_assert(offsetof(QuestLog_BP_C_ExecuteUbergraph_QuestLog_BP, CallFunc_PlayAnimation_ReturnValue_1) == 0x000010, "Member 'QuestLog_BP_C_ExecuteUbergraph_QuestLog_BP::CallFunc_PlayAnimation_ReturnValue_1' has a wrong offset!");
static_assert(offsetof(QuestLog_BP_C_ExecuteUbergraph_QuestLog_BP, CallFunc_EqualEqual_FloatFloat_ReturnValue) == 0x000018, "Member 'QuestLog_BP_C_ExecuteUbergraph_QuestLog_BP::CallFunc_EqualEqual_FloatFloat_ReturnValue' has a wrong offset!");

}

