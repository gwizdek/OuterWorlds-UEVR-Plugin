#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: AbilityOverviewGamepad_BP

#include "Basic.hpp"

#include "Indiana_structs.hpp"
#include "SlateCore_structs.hpp"


namespace SDK::Params
{

// Function AbilityOverviewGamepad_BP.AbilityOverviewGamepad_BP_C.ExecuteUbergraph_AbilityOverviewGamepad_BP
// 0x0068 (0x0068 - 0x0000)
struct AbilityOverviewGamepad_BP_C_ExecuteUbergraph_AbilityOverviewGamepad_BP final
{
public:
	int32                                         EntryPoint;                                        // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_Event_IsPlayerInCombat;                     // 0x0004(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          K2Node_Event_bRestoring;                           // 0x0005(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	EAbilityPosition                              K2Node_Event_AbillityPosition;                     // 0x0006(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_SwitchEnum_CmpSuccess;                      // 0x0007(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	class UUMGSequencePlayer*                     CallFunc_PlayAnimation_ReturnValue;                // 0x0008(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UUMGSequencePlayer*                     CallFunc_PlayAnimation_ReturnValue_1;              // 0x0010(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UUMGSequencePlayer*                     CallFunc_PlayAnimation_ReturnValue_2;              // 0x0018(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FGeometry                              K2Node_Event_MyGeometry;                           // 0x0020(0x0038)(IsPlainOldData, NoDestructor)
	float                                         K2Node_Event_InDeltaTime;                          // 0x0058(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_5C[0x4];                                       // 0x005C(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class UUMGSequencePlayer*                     CallFunc_PlayAnimation_ReturnValue_3;              // 0x0060(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(AbilityOverviewGamepad_BP_C_ExecuteUbergraph_AbilityOverviewGamepad_BP) == 0x000008, "Wrong alignment on AbilityOverviewGamepad_BP_C_ExecuteUbergraph_AbilityOverviewGamepad_BP");
static_assert(sizeof(AbilityOverviewGamepad_BP_C_ExecuteUbergraph_AbilityOverviewGamepad_BP) == 0x000068, "Wrong size on AbilityOverviewGamepad_BP_C_ExecuteUbergraph_AbilityOverviewGamepad_BP");
static_assert(offsetof(AbilityOverviewGamepad_BP_C_ExecuteUbergraph_AbilityOverviewGamepad_BP, EntryPoint) == 0x000000, "Member 'AbilityOverviewGamepad_BP_C_ExecuteUbergraph_AbilityOverviewGamepad_BP::EntryPoint' has a wrong offset!");
static_assert(offsetof(AbilityOverviewGamepad_BP_C_ExecuteUbergraph_AbilityOverviewGamepad_BP, K2Node_Event_IsPlayerInCombat) == 0x000004, "Member 'AbilityOverviewGamepad_BP_C_ExecuteUbergraph_AbilityOverviewGamepad_BP::K2Node_Event_IsPlayerInCombat' has a wrong offset!");
static_assert(offsetof(AbilityOverviewGamepad_BP_C_ExecuteUbergraph_AbilityOverviewGamepad_BP, K2Node_Event_bRestoring) == 0x000005, "Member 'AbilityOverviewGamepad_BP_C_ExecuteUbergraph_AbilityOverviewGamepad_BP::K2Node_Event_bRestoring' has a wrong offset!");
static_assert(offsetof(AbilityOverviewGamepad_BP_C_ExecuteUbergraph_AbilityOverviewGamepad_BP, K2Node_Event_AbillityPosition) == 0x000006, "Member 'AbilityOverviewGamepad_BP_C_ExecuteUbergraph_AbilityOverviewGamepad_BP::K2Node_Event_AbillityPosition' has a wrong offset!");
static_assert(offsetof(AbilityOverviewGamepad_BP_C_ExecuteUbergraph_AbilityOverviewGamepad_BP, K2Node_SwitchEnum_CmpSuccess) == 0x000007, "Member 'AbilityOverviewGamepad_BP_C_ExecuteUbergraph_AbilityOverviewGamepad_BP::K2Node_SwitchEnum_CmpSuccess' has a wrong offset!");
static_assert(offsetof(AbilityOverviewGamepad_BP_C_ExecuteUbergraph_AbilityOverviewGamepad_BP, CallFunc_PlayAnimation_ReturnValue) == 0x000008, "Member 'AbilityOverviewGamepad_BP_C_ExecuteUbergraph_AbilityOverviewGamepad_BP::CallFunc_PlayAnimation_ReturnValue' has a wrong offset!");
static_assert(offsetof(AbilityOverviewGamepad_BP_C_ExecuteUbergraph_AbilityOverviewGamepad_BP, CallFunc_PlayAnimation_ReturnValue_1) == 0x000010, "Member 'AbilityOverviewGamepad_BP_C_ExecuteUbergraph_AbilityOverviewGamepad_BP::CallFunc_PlayAnimation_ReturnValue_1' has a wrong offset!");
static_assert(offsetof(AbilityOverviewGamepad_BP_C_ExecuteUbergraph_AbilityOverviewGamepad_BP, CallFunc_PlayAnimation_ReturnValue_2) == 0x000018, "Member 'AbilityOverviewGamepad_BP_C_ExecuteUbergraph_AbilityOverviewGamepad_BP::CallFunc_PlayAnimation_ReturnValue_2' has a wrong offset!");
static_assert(offsetof(AbilityOverviewGamepad_BP_C_ExecuteUbergraph_AbilityOverviewGamepad_BP, K2Node_Event_MyGeometry) == 0x000020, "Member 'AbilityOverviewGamepad_BP_C_ExecuteUbergraph_AbilityOverviewGamepad_BP::K2Node_Event_MyGeometry' has a wrong offset!");
static_assert(offsetof(AbilityOverviewGamepad_BP_C_ExecuteUbergraph_AbilityOverviewGamepad_BP, K2Node_Event_InDeltaTime) == 0x000058, "Member 'AbilityOverviewGamepad_BP_C_ExecuteUbergraph_AbilityOverviewGamepad_BP::K2Node_Event_InDeltaTime' has a wrong offset!");
static_assert(offsetof(AbilityOverviewGamepad_BP_C_ExecuteUbergraph_AbilityOverviewGamepad_BP, CallFunc_PlayAnimation_ReturnValue_3) == 0x000060, "Member 'AbilityOverviewGamepad_BP_C_ExecuteUbergraph_AbilityOverviewGamepad_BP::CallFunc_PlayAnimation_ReturnValue_3' has a wrong offset!");

// Function AbilityOverviewGamepad_BP.AbilityOverviewGamepad_BP_C.Tick
// 0x003C (0x003C - 0x0000)
struct AbilityOverviewGamepad_BP_C_Tick final
{
public:
	struct FGeometry                              MyGeometry;                                        // 0x0000(0x0038)(BlueprintVisible, BlueprintReadOnly, Parm, IsPlainOldData, NoDestructor)
	float                                         InDeltaTime;                                       // 0x0038(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(AbilityOverviewGamepad_BP_C_Tick) == 0x000004, "Wrong alignment on AbilityOverviewGamepad_BP_C_Tick");
static_assert(sizeof(AbilityOverviewGamepad_BP_C_Tick) == 0x00003C, "Wrong size on AbilityOverviewGamepad_BP_C_Tick");
static_assert(offsetof(AbilityOverviewGamepad_BP_C_Tick, MyGeometry) == 0x000000, "Member 'AbilityOverviewGamepad_BP_C_Tick::MyGeometry' has a wrong offset!");
static_assert(offsetof(AbilityOverviewGamepad_BP_C_Tick, InDeltaTime) == 0x000038, "Member 'AbilityOverviewGamepad_BP_C_Tick::InDeltaTime' has a wrong offset!");

// Function AbilityOverviewGamepad_BP.AbilityOverviewGamepad_BP_C.OnAbilityCooldownFinished
// 0x0001 (0x0001 - 0x0000)
struct AbilityOverviewGamepad_BP_C_OnAbilityCooldownFinished final
{
public:
	EAbilityPosition                              AbillityPosition;                                  // 0x0000(0x0001)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(AbilityOverviewGamepad_BP_C_OnAbilityCooldownFinished) == 0x000001, "Wrong alignment on AbilityOverviewGamepad_BP_C_OnAbilityCooldownFinished");
static_assert(sizeof(AbilityOverviewGamepad_BP_C_OnAbilityCooldownFinished) == 0x000001, "Wrong size on AbilityOverviewGamepad_BP_C_OnAbilityCooldownFinished");
static_assert(offsetof(AbilityOverviewGamepad_BP_C_OnAbilityCooldownFinished, AbillityPosition) == 0x000000, "Member 'AbilityOverviewGamepad_BP_C_OnAbilityCooldownFinished::AbillityPosition' has a wrong offset!");

// Function AbilityOverviewGamepad_BP.AbilityOverviewGamepad_BP_C.OnPlayerCombatStateChange
// 0x0002 (0x0002 - 0x0000)
struct AbilityOverviewGamepad_BP_C_OnPlayerCombatStateChange final
{
public:
	bool                                          IsPlayerInCombat;                                  // 0x0000(0x0001)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          bRestoring;                                        // 0x0001(0x0001)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(AbilityOverviewGamepad_BP_C_OnPlayerCombatStateChange) == 0x000001, "Wrong alignment on AbilityOverviewGamepad_BP_C_OnPlayerCombatStateChange");
static_assert(sizeof(AbilityOverviewGamepad_BP_C_OnPlayerCombatStateChange) == 0x000002, "Wrong size on AbilityOverviewGamepad_BP_C_OnPlayerCombatStateChange");
static_assert(offsetof(AbilityOverviewGamepad_BP_C_OnPlayerCombatStateChange, IsPlayerInCombat) == 0x000000, "Member 'AbilityOverviewGamepad_BP_C_OnPlayerCombatStateChange::IsPlayerInCombat' has a wrong offset!");
static_assert(offsetof(AbilityOverviewGamepad_BP_C_OnPlayerCombatStateChange, bRestoring) == 0x000001, "Member 'AbilityOverviewGamepad_BP_C_OnPlayerCombatStateChange::bRestoring' has a wrong offset!");

}

