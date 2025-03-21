#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: Base_Ai_Character

#include "Basic.hpp"

#include "CoreUObject_structs.hpp"
#include "Indiana_structs.hpp"


namespace SDK::Params
{

// Function Base_Ai_Character.Base_Ai_Character_C.ExecuteUbergraph_Base_Ai_Character
// 0x0004 (0x0004 - 0x0000)
struct Base_Ai_Character_C_ExecuteUbergraph_Base_Ai_Character final
{
public:
	int32                                         EntryPoint;                                        // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(Base_Ai_Character_C_ExecuteUbergraph_Base_Ai_Character) == 0x000004, "Wrong alignment on Base_Ai_Character_C_ExecuteUbergraph_Base_Ai_Character");
static_assert(sizeof(Base_Ai_Character_C_ExecuteUbergraph_Base_Ai_Character) == 0x000004, "Wrong size on Base_Ai_Character_C_ExecuteUbergraph_Base_Ai_Character");
static_assert(offsetof(Base_Ai_Character_C_ExecuteUbergraph_Base_Ai_Character, EntryPoint) == 0x000000, "Member 'Base_Ai_Character_C_ExecuteUbergraph_Base_Ai_Character::EntryPoint' has a wrong offset!");

// Function Base_Ai_Character.Base_Ai_Character_C.UserConstructionScript
// 0x0060 (0x0060 - 0x0000)
struct Base_Ai_Character_C_UserConstructionScript final
{
public:
	struct FTransform                             CallFunc_GetTransform_ReturnValue;                 // 0x0000(0x0030)(ConstParm, IsPlainOldData, NoDestructor)
	struct FVector                                CallFunc_BreakTransform_Location;                  // 0x0030(0x000C)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FRotator                               CallFunc_BreakTransform_Rotation;                  // 0x003C(0x000C)(ZeroConstructor, IsPlainOldData, NoDestructor)
	struct FVector                                CallFunc_BreakTransform_Scale;                     // 0x0048(0x000C)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CallFunc_BreakVector_X;                            // 0x0054(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CallFunc_BreakVector_Y;                            // 0x0058(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CallFunc_BreakVector_Z;                            // 0x005C(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(Base_Ai_Character_C_UserConstructionScript) == 0x000010, "Wrong alignment on Base_Ai_Character_C_UserConstructionScript");
static_assert(sizeof(Base_Ai_Character_C_UserConstructionScript) == 0x000060, "Wrong size on Base_Ai_Character_C_UserConstructionScript");
static_assert(offsetof(Base_Ai_Character_C_UserConstructionScript, CallFunc_GetTransform_ReturnValue) == 0x000000, "Member 'Base_Ai_Character_C_UserConstructionScript::CallFunc_GetTransform_ReturnValue' has a wrong offset!");
static_assert(offsetof(Base_Ai_Character_C_UserConstructionScript, CallFunc_BreakTransform_Location) == 0x000030, "Member 'Base_Ai_Character_C_UserConstructionScript::CallFunc_BreakTransform_Location' has a wrong offset!");
static_assert(offsetof(Base_Ai_Character_C_UserConstructionScript, CallFunc_BreakTransform_Rotation) == 0x00003C, "Member 'Base_Ai_Character_C_UserConstructionScript::CallFunc_BreakTransform_Rotation' has a wrong offset!");
static_assert(offsetof(Base_Ai_Character_C_UserConstructionScript, CallFunc_BreakTransform_Scale) == 0x000048, "Member 'Base_Ai_Character_C_UserConstructionScript::CallFunc_BreakTransform_Scale' has a wrong offset!");
static_assert(offsetof(Base_Ai_Character_C_UserConstructionScript, CallFunc_BreakVector_X) == 0x000054, "Member 'Base_Ai_Character_C_UserConstructionScript::CallFunc_BreakVector_X' has a wrong offset!");
static_assert(offsetof(Base_Ai_Character_C_UserConstructionScript, CallFunc_BreakVector_Y) == 0x000058, "Member 'Base_Ai_Character_C_UserConstructionScript::CallFunc_BreakVector_Y' has a wrong offset!");
static_assert(offsetof(Base_Ai_Character_C_UserConstructionScript, CallFunc_BreakVector_Z) == 0x00005C, "Member 'Base_Ai_Character_C_UserConstructionScript::CallFunc_BreakVector_Z' has a wrong offset!");

// Function Base_Ai_Character.Base_Ai_Character_C.SetEmotion
// 0x0002 (0x0002 - 0x0000)
struct Base_Ai_Character_C_SetEmotion final
{
public:
	EEmotion                                      NewEmotion;                                        // 0x0000(0x0001)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_SetNextEmotion_ReturnValue;               // 0x0001(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(Base_Ai_Character_C_SetEmotion) == 0x000001, "Wrong alignment on Base_Ai_Character_C_SetEmotion");
static_assert(sizeof(Base_Ai_Character_C_SetEmotion) == 0x000002, "Wrong size on Base_Ai_Character_C_SetEmotion");
static_assert(offsetof(Base_Ai_Character_C_SetEmotion, NewEmotion) == 0x000000, "Member 'Base_Ai_Character_C_SetEmotion::NewEmotion' has a wrong offset!");
static_assert(offsetof(Base_Ai_Character_C_SetEmotion, CallFunc_SetNextEmotion_ReturnValue) == 0x000001, "Member 'Base_Ai_Character_C_SetEmotion::CallFunc_SetNextEmotion_ReturnValue' has a wrong offset!");

}

