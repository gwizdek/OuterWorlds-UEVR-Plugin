#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: MeleeLt_SentrySabre_Shared_Visuals

#include "Basic.hpp"

#include "Indiana_structs.hpp"


namespace SDK::Params
{

// Function MeleeLt_SentrySabre_Shared_Visuals.MeleeLt_SentrySabre_Shared_Visuals_C.ExecuteUbergraph_MeleeLt_SentrySabre_Shared_Visuals
// 0x0130 (0x0130 - 0x0000)
struct MeleeLt_SentrySabre_Shared_Visuals_C_ExecuteUbergraph_MeleeLt_SentrySabre_Shared_Visuals final
{
public:
	int32                                         EntryPoint;                                        // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	EWeaponEvent                                  K2Node_Event_WeaponEvent;                          // 0x0004(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_5[0x3];                                        // 0x0005(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	struct FEventEffectParams                     K2Node_Event_Params;                               // 0x0008(0x0080)(ConstParm)
	bool                                          K2Node_SwitchEnum_CmpSuccess;                      // 0x0088(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	EWeaponState                                  K2Node_Event_WeaponState_1;                        // 0x0089(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_8A[0x6];                                       // 0x008A(0x0006)(Fixing Size After Last Property [ Dumper-7 ])
	struct FEventEffectParams                     K2Node_Event_Params_1;                             // 0x0090(0x0080)(ConstParm)
	class UParticleSystemComponent*               CallFunc_SpawnEmitterAttached_ReturnValue;         // 0x0110(0x0008)(ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	TArray<class FName>                           CallFunc_GetEventEffectEnabledEmitters_ReturnValue; // 0x0118(0x0010)(ConstParm, ReferenceParm)
	bool                                          K2Node_SwitchEnum_CmpSuccess_1;                    // 0x0128(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	EWeaponState                                  K2Node_Event_WeaponState;                          // 0x0129(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_SwitchEnum_CmpSuccess_2;                    // 0x012A(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(MeleeLt_SentrySabre_Shared_Visuals_C_ExecuteUbergraph_MeleeLt_SentrySabre_Shared_Visuals) == 0x000008, "Wrong alignment on MeleeLt_SentrySabre_Shared_Visuals_C_ExecuteUbergraph_MeleeLt_SentrySabre_Shared_Visuals");
static_assert(sizeof(MeleeLt_SentrySabre_Shared_Visuals_C_ExecuteUbergraph_MeleeLt_SentrySabre_Shared_Visuals) == 0x000130, "Wrong size on MeleeLt_SentrySabre_Shared_Visuals_C_ExecuteUbergraph_MeleeLt_SentrySabre_Shared_Visuals");
static_assert(offsetof(MeleeLt_SentrySabre_Shared_Visuals_C_ExecuteUbergraph_MeleeLt_SentrySabre_Shared_Visuals, EntryPoint) == 0x000000, "Member 'MeleeLt_SentrySabre_Shared_Visuals_C_ExecuteUbergraph_MeleeLt_SentrySabre_Shared_Visuals::EntryPoint' has a wrong offset!");
static_assert(offsetof(MeleeLt_SentrySabre_Shared_Visuals_C_ExecuteUbergraph_MeleeLt_SentrySabre_Shared_Visuals, K2Node_Event_WeaponEvent) == 0x000004, "Member 'MeleeLt_SentrySabre_Shared_Visuals_C_ExecuteUbergraph_MeleeLt_SentrySabre_Shared_Visuals::K2Node_Event_WeaponEvent' has a wrong offset!");
static_assert(offsetof(MeleeLt_SentrySabre_Shared_Visuals_C_ExecuteUbergraph_MeleeLt_SentrySabre_Shared_Visuals, K2Node_Event_Params) == 0x000008, "Member 'MeleeLt_SentrySabre_Shared_Visuals_C_ExecuteUbergraph_MeleeLt_SentrySabre_Shared_Visuals::K2Node_Event_Params' has a wrong offset!");
static_assert(offsetof(MeleeLt_SentrySabre_Shared_Visuals_C_ExecuteUbergraph_MeleeLt_SentrySabre_Shared_Visuals, K2Node_SwitchEnum_CmpSuccess) == 0x000088, "Member 'MeleeLt_SentrySabre_Shared_Visuals_C_ExecuteUbergraph_MeleeLt_SentrySabre_Shared_Visuals::K2Node_SwitchEnum_CmpSuccess' has a wrong offset!");
static_assert(offsetof(MeleeLt_SentrySabre_Shared_Visuals_C_ExecuteUbergraph_MeleeLt_SentrySabre_Shared_Visuals, K2Node_Event_WeaponState_1) == 0x000089, "Member 'MeleeLt_SentrySabre_Shared_Visuals_C_ExecuteUbergraph_MeleeLt_SentrySabre_Shared_Visuals::K2Node_Event_WeaponState_1' has a wrong offset!");
static_assert(offsetof(MeleeLt_SentrySabre_Shared_Visuals_C_ExecuteUbergraph_MeleeLt_SentrySabre_Shared_Visuals, K2Node_Event_Params_1) == 0x000090, "Member 'MeleeLt_SentrySabre_Shared_Visuals_C_ExecuteUbergraph_MeleeLt_SentrySabre_Shared_Visuals::K2Node_Event_Params_1' has a wrong offset!");
static_assert(offsetof(MeleeLt_SentrySabre_Shared_Visuals_C_ExecuteUbergraph_MeleeLt_SentrySabre_Shared_Visuals, CallFunc_SpawnEmitterAttached_ReturnValue) == 0x000110, "Member 'MeleeLt_SentrySabre_Shared_Visuals_C_ExecuteUbergraph_MeleeLt_SentrySabre_Shared_Visuals::CallFunc_SpawnEmitterAttached_ReturnValue' has a wrong offset!");
static_assert(offsetof(MeleeLt_SentrySabre_Shared_Visuals_C_ExecuteUbergraph_MeleeLt_SentrySabre_Shared_Visuals, CallFunc_GetEventEffectEnabledEmitters_ReturnValue) == 0x000118, "Member 'MeleeLt_SentrySabre_Shared_Visuals_C_ExecuteUbergraph_MeleeLt_SentrySabre_Shared_Visuals::CallFunc_GetEventEffectEnabledEmitters_ReturnValue' has a wrong offset!");
static_assert(offsetof(MeleeLt_SentrySabre_Shared_Visuals_C_ExecuteUbergraph_MeleeLt_SentrySabre_Shared_Visuals, K2Node_SwitchEnum_CmpSuccess_1) == 0x000128, "Member 'MeleeLt_SentrySabre_Shared_Visuals_C_ExecuteUbergraph_MeleeLt_SentrySabre_Shared_Visuals::K2Node_SwitchEnum_CmpSuccess_1' has a wrong offset!");
static_assert(offsetof(MeleeLt_SentrySabre_Shared_Visuals_C_ExecuteUbergraph_MeleeLt_SentrySabre_Shared_Visuals, K2Node_Event_WeaponState) == 0x000129, "Member 'MeleeLt_SentrySabre_Shared_Visuals_C_ExecuteUbergraph_MeleeLt_SentrySabre_Shared_Visuals::K2Node_Event_WeaponState' has a wrong offset!");
static_assert(offsetof(MeleeLt_SentrySabre_Shared_Visuals_C_ExecuteUbergraph_MeleeLt_SentrySabre_Shared_Visuals, K2Node_SwitchEnum_CmpSuccess_2) == 0x00012A, "Member 'MeleeLt_SentrySabre_Shared_Visuals_C_ExecuteUbergraph_MeleeLt_SentrySabre_Shared_Visuals::K2Node_SwitchEnum_CmpSuccess_2' has a wrong offset!");

// Function MeleeLt_SentrySabre_Shared_Visuals.MeleeLt_SentrySabre_Shared_Visuals_C.TriggerEventBP
// 0x0088 (0x0088 - 0x0000)
struct MeleeLt_SentrySabre_Shared_Visuals_C_TriggerEventBP final
{
public:
	EWeaponEvent                                  WeaponEvent;                                       // 0x0000(0x0001)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_1[0x7];                                        // 0x0001(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	struct FEventEffectParams                     Params_0;                                          // 0x0008(0x0080)(ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm)
};
static_assert(alignof(MeleeLt_SentrySabre_Shared_Visuals_C_TriggerEventBP) == 0x000008, "Wrong alignment on MeleeLt_SentrySabre_Shared_Visuals_C_TriggerEventBP");
static_assert(sizeof(MeleeLt_SentrySabre_Shared_Visuals_C_TriggerEventBP) == 0x000088, "Wrong size on MeleeLt_SentrySabre_Shared_Visuals_C_TriggerEventBP");
static_assert(offsetof(MeleeLt_SentrySabre_Shared_Visuals_C_TriggerEventBP, WeaponEvent) == 0x000000, "Member 'MeleeLt_SentrySabre_Shared_Visuals_C_TriggerEventBP::WeaponEvent' has a wrong offset!");
static_assert(offsetof(MeleeLt_SentrySabre_Shared_Visuals_C_TriggerEventBP, Params_0) == 0x000008, "Member 'MeleeLt_SentrySabre_Shared_Visuals_C_TriggerEventBP::Params_0' has a wrong offset!");

// Function MeleeLt_SentrySabre_Shared_Visuals.MeleeLt_SentrySabre_Shared_Visuals_C.LeaveStateBP
// 0x0001 (0x0001 - 0x0000)
struct MeleeLt_SentrySabre_Shared_Visuals_C_LeaveStateBP final
{
public:
	EWeaponState                                  WeaponState;                                       // 0x0000(0x0001)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(MeleeLt_SentrySabre_Shared_Visuals_C_LeaveStateBP) == 0x000001, "Wrong alignment on MeleeLt_SentrySabre_Shared_Visuals_C_LeaveStateBP");
static_assert(sizeof(MeleeLt_SentrySabre_Shared_Visuals_C_LeaveStateBP) == 0x000001, "Wrong size on MeleeLt_SentrySabre_Shared_Visuals_C_LeaveStateBP");
static_assert(offsetof(MeleeLt_SentrySabre_Shared_Visuals_C_LeaveStateBP, WeaponState) == 0x000000, "Member 'MeleeLt_SentrySabre_Shared_Visuals_C_LeaveStateBP::WeaponState' has a wrong offset!");

// Function MeleeLt_SentrySabre_Shared_Visuals.MeleeLt_SentrySabre_Shared_Visuals_C.EnterStateBP
// 0x0088 (0x0088 - 0x0000)
struct MeleeLt_SentrySabre_Shared_Visuals_C_EnterStateBP final
{
public:
	EWeaponState                                  WeaponState;                                       // 0x0000(0x0001)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_1[0x7];                                        // 0x0001(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	struct FEventEffectParams                     Params_0;                                          // 0x0008(0x0080)(ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm)
};
static_assert(alignof(MeleeLt_SentrySabre_Shared_Visuals_C_EnterStateBP) == 0x000008, "Wrong alignment on MeleeLt_SentrySabre_Shared_Visuals_C_EnterStateBP");
static_assert(sizeof(MeleeLt_SentrySabre_Shared_Visuals_C_EnterStateBP) == 0x000088, "Wrong size on MeleeLt_SentrySabre_Shared_Visuals_C_EnterStateBP");
static_assert(offsetof(MeleeLt_SentrySabre_Shared_Visuals_C_EnterStateBP, WeaponState) == 0x000000, "Member 'MeleeLt_SentrySabre_Shared_Visuals_C_EnterStateBP::WeaponState' has a wrong offset!");
static_assert(offsetof(MeleeLt_SentrySabre_Shared_Visuals_C_EnterStateBP, Params_0) == 0x000008, "Member 'MeleeLt_SentrySabre_Shared_Visuals_C_EnterStateBP::Params_0' has a wrong offset!");

}

