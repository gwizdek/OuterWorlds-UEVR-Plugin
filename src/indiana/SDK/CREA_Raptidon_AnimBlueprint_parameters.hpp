#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: CREA_Raptidon_AnimBlueprint

#include "Basic.hpp"

#include "Engine_structs.hpp"


namespace SDK::Params
{

// Function CREA_Raptidon_AnimBlueprint.CREA_Raptidon_AnimBlueprint_C.ExecuteUbergraph_CREA_Raptidon_AnimBlueprint
// 0x0028 (0x0028 - 0x0000)
struct CREA_Raptidon_AnimBlueprint_C_ExecuteUbergraph_CREA_Raptidon_AnimBlueprint final
{
public:
	int32                                         EntryPoint;                                        // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_4[0x4];                                        // 0x0004(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class UWeaponAnimations*                      K2Node_Event_NewWeaponAnimations;                  // 0x0008(0x0008)(ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UCREA_Raptidon_WeaponAnimations_C*      K2Node_DynamicCast_AsCREA_Raptidon_Weapon_Animations; // 0x0010(0x0008)(ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_DynamicCast_bSuccess;                       // 0x0018(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_19[0x3];                                       // 0x0019(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         K2Node_Event_DeltaTimeX;                           // 0x001C(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_IsMontagePlayingOnSlot_ReturnValue;       // 0x0020(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_21[0x3];                                       // 0x0021(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         CallFunc_Conv_BoolToFloat_ReturnValue;             // 0x0024(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(CREA_Raptidon_AnimBlueprint_C_ExecuteUbergraph_CREA_Raptidon_AnimBlueprint) == 0x000008, "Wrong alignment on CREA_Raptidon_AnimBlueprint_C_ExecuteUbergraph_CREA_Raptidon_AnimBlueprint");
static_assert(sizeof(CREA_Raptidon_AnimBlueprint_C_ExecuteUbergraph_CREA_Raptidon_AnimBlueprint) == 0x000028, "Wrong size on CREA_Raptidon_AnimBlueprint_C_ExecuteUbergraph_CREA_Raptidon_AnimBlueprint");
static_assert(offsetof(CREA_Raptidon_AnimBlueprint_C_ExecuteUbergraph_CREA_Raptidon_AnimBlueprint, EntryPoint) == 0x000000, "Member 'CREA_Raptidon_AnimBlueprint_C_ExecuteUbergraph_CREA_Raptidon_AnimBlueprint::EntryPoint' has a wrong offset!");
static_assert(offsetof(CREA_Raptidon_AnimBlueprint_C_ExecuteUbergraph_CREA_Raptidon_AnimBlueprint, K2Node_Event_NewWeaponAnimations) == 0x000008, "Member 'CREA_Raptidon_AnimBlueprint_C_ExecuteUbergraph_CREA_Raptidon_AnimBlueprint::K2Node_Event_NewWeaponAnimations' has a wrong offset!");
static_assert(offsetof(CREA_Raptidon_AnimBlueprint_C_ExecuteUbergraph_CREA_Raptidon_AnimBlueprint, K2Node_DynamicCast_AsCREA_Raptidon_Weapon_Animations) == 0x000010, "Member 'CREA_Raptidon_AnimBlueprint_C_ExecuteUbergraph_CREA_Raptidon_AnimBlueprint::K2Node_DynamicCast_AsCREA_Raptidon_Weapon_Animations' has a wrong offset!");
static_assert(offsetof(CREA_Raptidon_AnimBlueprint_C_ExecuteUbergraph_CREA_Raptidon_AnimBlueprint, K2Node_DynamicCast_bSuccess) == 0x000018, "Member 'CREA_Raptidon_AnimBlueprint_C_ExecuteUbergraph_CREA_Raptidon_AnimBlueprint::K2Node_DynamicCast_bSuccess' has a wrong offset!");
static_assert(offsetof(CREA_Raptidon_AnimBlueprint_C_ExecuteUbergraph_CREA_Raptidon_AnimBlueprint, K2Node_Event_DeltaTimeX) == 0x00001C, "Member 'CREA_Raptidon_AnimBlueprint_C_ExecuteUbergraph_CREA_Raptidon_AnimBlueprint::K2Node_Event_DeltaTimeX' has a wrong offset!");
static_assert(offsetof(CREA_Raptidon_AnimBlueprint_C_ExecuteUbergraph_CREA_Raptidon_AnimBlueprint, CallFunc_IsMontagePlayingOnSlot_ReturnValue) == 0x000020, "Member 'CREA_Raptidon_AnimBlueprint_C_ExecuteUbergraph_CREA_Raptidon_AnimBlueprint::CallFunc_IsMontagePlayingOnSlot_ReturnValue' has a wrong offset!");
static_assert(offsetof(CREA_Raptidon_AnimBlueprint_C_ExecuteUbergraph_CREA_Raptidon_AnimBlueprint, CallFunc_Conv_BoolToFloat_ReturnValue) == 0x000024, "Member 'CREA_Raptidon_AnimBlueprint_C_ExecuteUbergraph_CREA_Raptidon_AnimBlueprint::CallFunc_Conv_BoolToFloat_ReturnValue' has a wrong offset!");

// Function CREA_Raptidon_AnimBlueprint.CREA_Raptidon_AnimBlueprint_C.OnNewWeaponAnimations
// 0x0008 (0x0008 - 0x0000)
struct CREA_Raptidon_AnimBlueprint_C_OnNewWeaponAnimations final
{
public:
	class UWeaponAnimations*                      NewWeaponAnimations;                               // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(CREA_Raptidon_AnimBlueprint_C_OnNewWeaponAnimations) == 0x000008, "Wrong alignment on CREA_Raptidon_AnimBlueprint_C_OnNewWeaponAnimations");
static_assert(sizeof(CREA_Raptidon_AnimBlueprint_C_OnNewWeaponAnimations) == 0x000008, "Wrong size on CREA_Raptidon_AnimBlueprint_C_OnNewWeaponAnimations");
static_assert(offsetof(CREA_Raptidon_AnimBlueprint_C_OnNewWeaponAnimations, NewWeaponAnimations) == 0x000000, "Member 'CREA_Raptidon_AnimBlueprint_C_OnNewWeaponAnimations::NewWeaponAnimations' has a wrong offset!");

// Function CREA_Raptidon_AnimBlueprint.CREA_Raptidon_AnimBlueprint_C.BlueprintUpdateAnimation
// 0x0004 (0x0004 - 0x0000)
struct CREA_Raptidon_AnimBlueprint_C_BlueprintUpdateAnimation final
{
public:
	float                                         DeltaTimeX;                                        // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(CREA_Raptidon_AnimBlueprint_C_BlueprintUpdateAnimation) == 0x000004, "Wrong alignment on CREA_Raptidon_AnimBlueprint_C_BlueprintUpdateAnimation");
static_assert(sizeof(CREA_Raptidon_AnimBlueprint_C_BlueprintUpdateAnimation) == 0x000004, "Wrong size on CREA_Raptidon_AnimBlueprint_C_BlueprintUpdateAnimation");
static_assert(offsetof(CREA_Raptidon_AnimBlueprint_C_BlueprintUpdateAnimation, DeltaTimeX) == 0x000000, "Member 'CREA_Raptidon_AnimBlueprint_C_BlueprintUpdateAnimation::DeltaTimeX' has a wrong offset!");

// Function CREA_Raptidon_AnimBlueprint.CREA_Raptidon_AnimBlueprint_C.CheckHitFlinches
// 0x0030 (0x0030 - 0x0000)
struct CREA_Raptidon_AnimBlueprint_C_CheckHitFlinches final
{
public:
	class FString                                 CallFunc_GetObjectName_ReturnValue;                // 0x0000(0x0010)(ZeroConstructor, HasGetValueTypeHash)
	int32                                         CallFunc_Array_Length_ReturnValue;                 // 0x0010(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_14[0x4];                                       // 0x0014(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class FString                                 CallFunc_Concat_StrStr_ReturnValue;                // 0x0018(0x0010)(ZeroConstructor, HasGetValueTypeHash)
	bool                                          CallFunc_Greater_IntInt_ReturnValue;               // 0x0028(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(CREA_Raptidon_AnimBlueprint_C_CheckHitFlinches) == 0x000008, "Wrong alignment on CREA_Raptidon_AnimBlueprint_C_CheckHitFlinches");
static_assert(sizeof(CREA_Raptidon_AnimBlueprint_C_CheckHitFlinches) == 0x000030, "Wrong size on CREA_Raptidon_AnimBlueprint_C_CheckHitFlinches");
static_assert(offsetof(CREA_Raptidon_AnimBlueprint_C_CheckHitFlinches, CallFunc_GetObjectName_ReturnValue) == 0x000000, "Member 'CREA_Raptidon_AnimBlueprint_C_CheckHitFlinches::CallFunc_GetObjectName_ReturnValue' has a wrong offset!");
static_assert(offsetof(CREA_Raptidon_AnimBlueprint_C_CheckHitFlinches, CallFunc_Array_Length_ReturnValue) == 0x000010, "Member 'CREA_Raptidon_AnimBlueprint_C_CheckHitFlinches::CallFunc_Array_Length_ReturnValue' has a wrong offset!");
static_assert(offsetof(CREA_Raptidon_AnimBlueprint_C_CheckHitFlinches, CallFunc_Concat_StrStr_ReturnValue) == 0x000018, "Member 'CREA_Raptidon_AnimBlueprint_C_CheckHitFlinches::CallFunc_Concat_StrStr_ReturnValue' has a wrong offset!");
static_assert(offsetof(CREA_Raptidon_AnimBlueprint_C_CheckHitFlinches, CallFunc_Greater_IntInt_ReturnValue) == 0x000028, "Member 'CREA_Raptidon_AnimBlueprint_C_CheckHitFlinches::CallFunc_Greater_IntInt_ReturnValue' has a wrong offset!");

// Function CREA_Raptidon_AnimBlueprint.CREA_Raptidon_AnimBlueprint_C.AnimGraph
// 0x0010 (0x0010 - 0x0000)
struct CREA_Raptidon_AnimBlueprint_C_AnimGraph final
{
public:
	struct FPoseLink                              AnimGraph_0;                                       // 0x0000(0x0010)(Parm, OutParm, NoDestructor)
};
static_assert(alignof(CREA_Raptidon_AnimBlueprint_C_AnimGraph) == 0x000008, "Wrong alignment on CREA_Raptidon_AnimBlueprint_C_AnimGraph");
static_assert(sizeof(CREA_Raptidon_AnimBlueprint_C_AnimGraph) == 0x000010, "Wrong size on CREA_Raptidon_AnimBlueprint_C_AnimGraph");
static_assert(offsetof(CREA_Raptidon_AnimBlueprint_C_AnimGraph, AnimGraph_0) == 0x000000, "Member 'CREA_Raptidon_AnimBlueprint_C_AnimGraph::AnimGraph_0' has a wrong offset!");

}

