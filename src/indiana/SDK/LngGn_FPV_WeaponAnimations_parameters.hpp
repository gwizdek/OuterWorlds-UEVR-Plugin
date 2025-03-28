#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: LngGn_FPV_WeaponAnimations

#include "Basic.hpp"

#include "Indiana_structs.hpp"


namespace SDK::Params
{

// Function LngGn_FPV_WeaponAnimations.LngGn_FPV_WeaponAnimations_C.ExecuteUbergraph_LngGn_FPV_WeaponAnimations
// 0x0110 (0x0110 - 0x0000)
struct LngGn_FPV_WeaponAnimations_C_ExecuteUbergraph_LngGn_FPV_WeaponAnimations final
{
public:
	int32                                         EntryPoint;                                        // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	EWeaponState                                  K2Node_Event_WeaponState;                          // 0x0004(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	EWeaponState                                  K2Node_Event_WeaponState_1;                        // 0x0005(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_6[0x2];                                        // 0x0006(0x0002)(Fixing Size After Last Property [ Dumper-7 ])
	struct FEventEffectParams                     K2Node_Event_Params_1;                             // 0x0008(0x0080)(ConstParm)
	EWeaponEvent                                  K2Node_Event_WeaponEvent;                          // 0x0088(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_89[0x7];                                       // 0x0089(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	struct FEventEffectParams                     K2Node_Event_Params;                               // 0x0090(0x0080)(ConstParm)
};
static_assert(alignof(LngGn_FPV_WeaponAnimations_C_ExecuteUbergraph_LngGn_FPV_WeaponAnimations) == 0x000008, "Wrong alignment on LngGn_FPV_WeaponAnimations_C_ExecuteUbergraph_LngGn_FPV_WeaponAnimations");
static_assert(sizeof(LngGn_FPV_WeaponAnimations_C_ExecuteUbergraph_LngGn_FPV_WeaponAnimations) == 0x000110, "Wrong size on LngGn_FPV_WeaponAnimations_C_ExecuteUbergraph_LngGn_FPV_WeaponAnimations");
static_assert(offsetof(LngGn_FPV_WeaponAnimations_C_ExecuteUbergraph_LngGn_FPV_WeaponAnimations, EntryPoint) == 0x000000, "Member 'LngGn_FPV_WeaponAnimations_C_ExecuteUbergraph_LngGn_FPV_WeaponAnimations::EntryPoint' has a wrong offset!");
static_assert(offsetof(LngGn_FPV_WeaponAnimations_C_ExecuteUbergraph_LngGn_FPV_WeaponAnimations, K2Node_Event_WeaponState) == 0x000004, "Member 'LngGn_FPV_WeaponAnimations_C_ExecuteUbergraph_LngGn_FPV_WeaponAnimations::K2Node_Event_WeaponState' has a wrong offset!");
static_assert(offsetof(LngGn_FPV_WeaponAnimations_C_ExecuteUbergraph_LngGn_FPV_WeaponAnimations, K2Node_Event_WeaponState_1) == 0x000005, "Member 'LngGn_FPV_WeaponAnimations_C_ExecuteUbergraph_LngGn_FPV_WeaponAnimations::K2Node_Event_WeaponState_1' has a wrong offset!");
static_assert(offsetof(LngGn_FPV_WeaponAnimations_C_ExecuteUbergraph_LngGn_FPV_WeaponAnimations, K2Node_Event_Params_1) == 0x000008, "Member 'LngGn_FPV_WeaponAnimations_C_ExecuteUbergraph_LngGn_FPV_WeaponAnimations::K2Node_Event_Params_1' has a wrong offset!");
static_assert(offsetof(LngGn_FPV_WeaponAnimations_C_ExecuteUbergraph_LngGn_FPV_WeaponAnimations, K2Node_Event_WeaponEvent) == 0x000088, "Member 'LngGn_FPV_WeaponAnimations_C_ExecuteUbergraph_LngGn_FPV_WeaponAnimations::K2Node_Event_WeaponEvent' has a wrong offset!");
static_assert(offsetof(LngGn_FPV_WeaponAnimations_C_ExecuteUbergraph_LngGn_FPV_WeaponAnimations, K2Node_Event_Params) == 0x000090, "Member 'LngGn_FPV_WeaponAnimations_C_ExecuteUbergraph_LngGn_FPV_WeaponAnimations::K2Node_Event_Params' has a wrong offset!");

// Function LngGn_FPV_WeaponAnimations.LngGn_FPV_WeaponAnimations_C.LeaveStateBP
// 0x0001 (0x0001 - 0x0000)
struct LngGn_FPV_WeaponAnimations_C_LeaveStateBP final
{
public:
	EWeaponState                                  WeaponState;                                       // 0x0000(0x0001)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(LngGn_FPV_WeaponAnimations_C_LeaveStateBP) == 0x000001, "Wrong alignment on LngGn_FPV_WeaponAnimations_C_LeaveStateBP");
static_assert(sizeof(LngGn_FPV_WeaponAnimations_C_LeaveStateBP) == 0x000001, "Wrong size on LngGn_FPV_WeaponAnimations_C_LeaveStateBP");
static_assert(offsetof(LngGn_FPV_WeaponAnimations_C_LeaveStateBP, WeaponState) == 0x000000, "Member 'LngGn_FPV_WeaponAnimations_C_LeaveStateBP::WeaponState' has a wrong offset!");

// Function LngGn_FPV_WeaponAnimations.LngGn_FPV_WeaponAnimations_C.TriggerEventBP
// 0x0088 (0x0088 - 0x0000)
struct LngGn_FPV_WeaponAnimations_C_TriggerEventBP final
{
public:
	EWeaponEvent                                  WeaponEvent;                                       // 0x0000(0x0001)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_1[0x7];                                        // 0x0001(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	struct FEventEffectParams                     Params_0;                                          // 0x0008(0x0080)(ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm)
};
static_assert(alignof(LngGn_FPV_WeaponAnimations_C_TriggerEventBP) == 0x000008, "Wrong alignment on LngGn_FPV_WeaponAnimations_C_TriggerEventBP");
static_assert(sizeof(LngGn_FPV_WeaponAnimations_C_TriggerEventBP) == 0x000088, "Wrong size on LngGn_FPV_WeaponAnimations_C_TriggerEventBP");
static_assert(offsetof(LngGn_FPV_WeaponAnimations_C_TriggerEventBP, WeaponEvent) == 0x000000, "Member 'LngGn_FPV_WeaponAnimations_C_TriggerEventBP::WeaponEvent' has a wrong offset!");
static_assert(offsetof(LngGn_FPV_WeaponAnimations_C_TriggerEventBP, Params_0) == 0x000008, "Member 'LngGn_FPV_WeaponAnimations_C_TriggerEventBP::Params_0' has a wrong offset!");

// Function LngGn_FPV_WeaponAnimations.LngGn_FPV_WeaponAnimations_C.EnterStateBP
// 0x0088 (0x0088 - 0x0000)
struct LngGn_FPV_WeaponAnimations_C_EnterStateBP final
{
public:
	EWeaponState                                  WeaponState;                                       // 0x0000(0x0001)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_1[0x7];                                        // 0x0001(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	struct FEventEffectParams                     Params_0;                                          // 0x0008(0x0080)(ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm)
};
static_assert(alignof(LngGn_FPV_WeaponAnimations_C_EnterStateBP) == 0x000008, "Wrong alignment on LngGn_FPV_WeaponAnimations_C_EnterStateBP");
static_assert(sizeof(LngGn_FPV_WeaponAnimations_C_EnterStateBP) == 0x000088, "Wrong size on LngGn_FPV_WeaponAnimations_C_EnterStateBP");
static_assert(offsetof(LngGn_FPV_WeaponAnimations_C_EnterStateBP, WeaponState) == 0x000000, "Member 'LngGn_FPV_WeaponAnimations_C_EnterStateBP::WeaponState' has a wrong offset!");
static_assert(offsetof(LngGn_FPV_WeaponAnimations_C_EnterStateBP, Params_0) == 0x000008, "Member 'LngGn_FPV_WeaponAnimations_C_EnterStateBP::Params_0' has a wrong offset!");

}

