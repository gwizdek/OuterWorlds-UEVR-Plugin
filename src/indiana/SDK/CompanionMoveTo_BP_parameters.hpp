#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: CompanionMoveTo_BP

#include "Basic.hpp"

#include "SlateCore_structs.hpp"
#include "CoreUObject_structs.hpp"


namespace SDK::Params
{

// Function CompanionMoveTo_BP.CompanionMoveTo_BP_C.ExecuteUbergraph_CompanionMoveTo_BP
// 0x0080 (0x0080 - 0x0000)
struct CompanionMoveTo_BP_C_ExecuteUbergraph_CompanionMoveTo_BP final
{
public:
	int32                                         EntryPoint;                                        // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	TDelegate<void()>                             K2Node_CreateDelegate_OutputDelegate;              // 0x0004(0x0010)(ZeroConstructor, NoDestructor)
	uint8                                         Pad_14[0x4];                                       // 0x0014(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class UUMGSequencePlayer*                     CallFunc_PlayAnimation_ReturnValue;                // 0x0018(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UUMGSequencePlayer*                     CallFunc_PlayAnimation_ReturnValue_1;              // 0x0020(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FGeometry                              K2Node_Event_MyGeometry;                           // 0x0028(0x0038)(IsPlainOldData, NoDestructor)
	float                                         K2Node_Event_InDeltaTime;                          // 0x0060(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_64[0x4];                                       // 0x0064(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class UUMGSequencePlayer*                     CallFunc_PlayAnimation_ReturnValue_2;              // 0x0068(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FLinearColor                           CallFunc_GetColorByType_ReturnValue;               // 0x0070(0x0010)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(CompanionMoveTo_BP_C_ExecuteUbergraph_CompanionMoveTo_BP) == 0x000008, "Wrong alignment on CompanionMoveTo_BP_C_ExecuteUbergraph_CompanionMoveTo_BP");
static_assert(sizeof(CompanionMoveTo_BP_C_ExecuteUbergraph_CompanionMoveTo_BP) == 0x000080, "Wrong size on CompanionMoveTo_BP_C_ExecuteUbergraph_CompanionMoveTo_BP");
static_assert(offsetof(CompanionMoveTo_BP_C_ExecuteUbergraph_CompanionMoveTo_BP, EntryPoint) == 0x000000, "Member 'CompanionMoveTo_BP_C_ExecuteUbergraph_CompanionMoveTo_BP::EntryPoint' has a wrong offset!");
static_assert(offsetof(CompanionMoveTo_BP_C_ExecuteUbergraph_CompanionMoveTo_BP, K2Node_CreateDelegate_OutputDelegate) == 0x000004, "Member 'CompanionMoveTo_BP_C_ExecuteUbergraph_CompanionMoveTo_BP::K2Node_CreateDelegate_OutputDelegate' has a wrong offset!");
static_assert(offsetof(CompanionMoveTo_BP_C_ExecuteUbergraph_CompanionMoveTo_BP, CallFunc_PlayAnimation_ReturnValue) == 0x000018, "Member 'CompanionMoveTo_BP_C_ExecuteUbergraph_CompanionMoveTo_BP::CallFunc_PlayAnimation_ReturnValue' has a wrong offset!");
static_assert(offsetof(CompanionMoveTo_BP_C_ExecuteUbergraph_CompanionMoveTo_BP, CallFunc_PlayAnimation_ReturnValue_1) == 0x000020, "Member 'CompanionMoveTo_BP_C_ExecuteUbergraph_CompanionMoveTo_BP::CallFunc_PlayAnimation_ReturnValue_1' has a wrong offset!");
static_assert(offsetof(CompanionMoveTo_BP_C_ExecuteUbergraph_CompanionMoveTo_BP, K2Node_Event_MyGeometry) == 0x000028, "Member 'CompanionMoveTo_BP_C_ExecuteUbergraph_CompanionMoveTo_BP::K2Node_Event_MyGeometry' has a wrong offset!");
static_assert(offsetof(CompanionMoveTo_BP_C_ExecuteUbergraph_CompanionMoveTo_BP, K2Node_Event_InDeltaTime) == 0x000060, "Member 'CompanionMoveTo_BP_C_ExecuteUbergraph_CompanionMoveTo_BP::K2Node_Event_InDeltaTime' has a wrong offset!");
static_assert(offsetof(CompanionMoveTo_BP_C_ExecuteUbergraph_CompanionMoveTo_BP, CallFunc_PlayAnimation_ReturnValue_2) == 0x000068, "Member 'CompanionMoveTo_BP_C_ExecuteUbergraph_CompanionMoveTo_BP::CallFunc_PlayAnimation_ReturnValue_2' has a wrong offset!");
static_assert(offsetof(CompanionMoveTo_BP_C_ExecuteUbergraph_CompanionMoveTo_BP, CallFunc_GetColorByType_ReturnValue) == 0x000070, "Member 'CompanionMoveTo_BP_C_ExecuteUbergraph_CompanionMoveTo_BP::CallFunc_GetColorByType_ReturnValue' has a wrong offset!");

// Function CompanionMoveTo_BP.CompanionMoveTo_BP_C.Tick
// 0x003C (0x003C - 0x0000)
struct CompanionMoveTo_BP_C_Tick final
{
public:
	struct FGeometry                              MyGeometry;                                        // 0x0000(0x0038)(BlueprintVisible, BlueprintReadOnly, Parm, IsPlainOldData, NoDestructor)
	float                                         InDeltaTime;                                       // 0x0038(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(CompanionMoveTo_BP_C_Tick) == 0x000004, "Wrong alignment on CompanionMoveTo_BP_C_Tick");
static_assert(sizeof(CompanionMoveTo_BP_C_Tick) == 0x00003C, "Wrong size on CompanionMoveTo_BP_C_Tick");
static_assert(offsetof(CompanionMoveTo_BP_C_Tick, MyGeometry) == 0x000000, "Member 'CompanionMoveTo_BP_C_Tick::MyGeometry' has a wrong offset!");
static_assert(offsetof(CompanionMoveTo_BP_C_Tick, InDeltaTime) == 0x000038, "Member 'CompanionMoveTo_BP_C_Tick::InDeltaTime' has a wrong offset!");

}

