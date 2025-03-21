#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: Parvati_Comp_Female

#include "Basic.hpp"

#include "Indiana_structs.hpp"


namespace SDK::Params
{

// Function Parvati_Comp_Female.Parvati_Comp_Female_C.ExecuteUbergraph_Parvati_Comp_Female
// 0x0148 (0x0148 - 0x0000)
struct Parvati_Comp_Female_C_ExecuteUbergraph_Parvati_Comp_Female final
{
public:
	int32                                         EntryPoint;                                        // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_CustomEvent_bCompanionDied;                 // 0x0004(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_5[0x3];                                        // 0x0005(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	TDelegate<void(class AActor* Instigator, struct FCauseDamageInfo& CauseDamageInfo)> K2Node_CreateDelegate_OutputDelegate;              // 0x0008(0x0010)(ZeroConstructor, NoDestructor)
	TDelegate<void(bool bCompanionDied)>          K2Node_CreateDelegate_OutputDelegate_1;            // 0x0018(0x0010)(ZeroConstructor, NoDestructor)
	class AActor*                                 K2Node_CustomEvent_Instigator;                     // 0x0028(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FCauseDamageInfo                       K2Node_CustomEvent_CauseDamageInfo;                // 0x0030(0x0110)(ConstParm, NoDestructor)
	bool                                          CallFunc_IsCompanionInActiveParty_ReturnValue;     // 0x0140(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	EGameDifficulty                               CallFunc_GetGameDifficulty_ReturnValue;            // 0x0141(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_EqualEqual_ByteByte_ReturnValue;          // 0x0142(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(Parvati_Comp_Female_C_ExecuteUbergraph_Parvati_Comp_Female) == 0x000008, "Wrong alignment on Parvati_Comp_Female_C_ExecuteUbergraph_Parvati_Comp_Female");
static_assert(sizeof(Parvati_Comp_Female_C_ExecuteUbergraph_Parvati_Comp_Female) == 0x000148, "Wrong size on Parvati_Comp_Female_C_ExecuteUbergraph_Parvati_Comp_Female");
static_assert(offsetof(Parvati_Comp_Female_C_ExecuteUbergraph_Parvati_Comp_Female, EntryPoint) == 0x000000, "Member 'Parvati_Comp_Female_C_ExecuteUbergraph_Parvati_Comp_Female::EntryPoint' has a wrong offset!");
static_assert(offsetof(Parvati_Comp_Female_C_ExecuteUbergraph_Parvati_Comp_Female, K2Node_CustomEvent_bCompanionDied) == 0x000004, "Member 'Parvati_Comp_Female_C_ExecuteUbergraph_Parvati_Comp_Female::K2Node_CustomEvent_bCompanionDied' has a wrong offset!");
static_assert(offsetof(Parvati_Comp_Female_C_ExecuteUbergraph_Parvati_Comp_Female, K2Node_CreateDelegate_OutputDelegate) == 0x000008, "Member 'Parvati_Comp_Female_C_ExecuteUbergraph_Parvati_Comp_Female::K2Node_CreateDelegate_OutputDelegate' has a wrong offset!");
static_assert(offsetof(Parvati_Comp_Female_C_ExecuteUbergraph_Parvati_Comp_Female, K2Node_CreateDelegate_OutputDelegate_1) == 0x000018, "Member 'Parvati_Comp_Female_C_ExecuteUbergraph_Parvati_Comp_Female::K2Node_CreateDelegate_OutputDelegate_1' has a wrong offset!");
static_assert(offsetof(Parvati_Comp_Female_C_ExecuteUbergraph_Parvati_Comp_Female, K2Node_CustomEvent_Instigator) == 0x000028, "Member 'Parvati_Comp_Female_C_ExecuteUbergraph_Parvati_Comp_Female::K2Node_CustomEvent_Instigator' has a wrong offset!");
static_assert(offsetof(Parvati_Comp_Female_C_ExecuteUbergraph_Parvati_Comp_Female, K2Node_CustomEvent_CauseDamageInfo) == 0x000030, "Member 'Parvati_Comp_Female_C_ExecuteUbergraph_Parvati_Comp_Female::K2Node_CustomEvent_CauseDamageInfo' has a wrong offset!");
static_assert(offsetof(Parvati_Comp_Female_C_ExecuteUbergraph_Parvati_Comp_Female, CallFunc_IsCompanionInActiveParty_ReturnValue) == 0x000140, "Member 'Parvati_Comp_Female_C_ExecuteUbergraph_Parvati_Comp_Female::CallFunc_IsCompanionInActiveParty_ReturnValue' has a wrong offset!");
static_assert(offsetof(Parvati_Comp_Female_C_ExecuteUbergraph_Parvati_Comp_Female, CallFunc_GetGameDifficulty_ReturnValue) == 0x000141, "Member 'Parvati_Comp_Female_C_ExecuteUbergraph_Parvati_Comp_Female::CallFunc_GetGameDifficulty_ReturnValue' has a wrong offset!");
static_assert(offsetof(Parvati_Comp_Female_C_ExecuteUbergraph_Parvati_Comp_Female, CallFunc_EqualEqual_ByteByte_ReturnValue) == 0x000142, "Member 'Parvati_Comp_Female_C_ExecuteUbergraph_Parvati_Comp_Female::CallFunc_EqualEqual_ByteByte_ReturnValue' has a wrong offset!");

// Function Parvati_Comp_Female.Parvati_Comp_Female_C.OnCompanionDismissed_Event_0
// 0x0001 (0x0001 - 0x0000)
struct Parvati_Comp_Female_C_OnCompanionDismissed_Event_0 final
{
public:
	bool                                          bCompanionDied;                                    // 0x0000(0x0001)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(Parvati_Comp_Female_C_OnCompanionDismissed_Event_0) == 0x000001, "Wrong alignment on Parvati_Comp_Female_C_OnCompanionDismissed_Event_0");
static_assert(sizeof(Parvati_Comp_Female_C_OnCompanionDismissed_Event_0) == 0x000001, "Wrong size on Parvati_Comp_Female_C_OnCompanionDismissed_Event_0");
static_assert(offsetof(Parvati_Comp_Female_C_OnCompanionDismissed_Event_0, bCompanionDied) == 0x000000, "Member 'Parvati_Comp_Female_C_OnCompanionDismissed_Event_0::bCompanionDied' has a wrong offset!");

// Function Parvati_Comp_Female.Parvati_Comp_Female_C.DEATH_PARVATI
// 0x0118 (0x0118 - 0x0000)
struct Parvati_Comp_Female_C_DEATH_PARVATI final
{
public:
	class AActor*                                 Instigator_0;                                      // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FCauseDamageInfo                       CauseDamageInfo;                                   // 0x0008(0x0110)(ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm, NoDestructor)
};
static_assert(alignof(Parvati_Comp_Female_C_DEATH_PARVATI) == 0x000008, "Wrong alignment on Parvati_Comp_Female_C_DEATH_PARVATI");
static_assert(sizeof(Parvati_Comp_Female_C_DEATH_PARVATI) == 0x000118, "Wrong size on Parvati_Comp_Female_C_DEATH_PARVATI");
static_assert(offsetof(Parvati_Comp_Female_C_DEATH_PARVATI, Instigator_0) == 0x000000, "Member 'Parvati_Comp_Female_C_DEATH_PARVATI::Instigator_0' has a wrong offset!");
static_assert(offsetof(Parvati_Comp_Female_C_DEATH_PARVATI, CauseDamageInfo) == 0x000008, "Member 'Parvati_Comp_Female_C_DEATH_PARVATI::CauseDamageInfo' has a wrong offset!");

}

