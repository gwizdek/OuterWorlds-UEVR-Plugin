#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: CommonOCLLibrary

#include "Basic.hpp"

#include "Indiana_structs.hpp"


namespace SDK::Params
{

// Function CommonOCLLibrary.CommonOCLLibrary_C.OCL_Library_ToggleOpenCloseState
// 0x0030 (0x0030 - 0x0000)
struct CommonOCLLibrary_C_OCL_Library_ToggleOpenCloseState final
{
public:
	class UOCLComponent*                          Target;                                            // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class AActor*                                 Initiator;                                         // 0x0008(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          Force;                                             // 0x0010(0x0001)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          Lock;                                              // 0x0011(0x0001)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          Seal;                                              // 0x0012(0x0001)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          IgnoreLockStatus;                                  // 0x0013(0x0001)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          IgnoreStartEvent;                                  // 0x0014(0x0001)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          IgnoreEndEvent;                                    // 0x0015(0x0001)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          IgnoreSound;                                       // 0x0016(0x0001)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          InstantAnimation;                                  // 0x0017(0x0001)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
	class UObject*                                __WorldContext;                                    // 0x0018(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          IsOpen;                                            // 0x0020(0x0001)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          IsOpening;                                         // 0x0021(0x0001)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          IsClosed;                                          // 0x0022(0x0001)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          IsClosing;                                         // 0x0023(0x0001)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_IsOpen_ReturnValue;                       // 0x0024(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	EOCLResult                                    CallFunc_AttemptOpen_ReturnValue;                  // 0x0025(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	EOCLResult                                    CallFunc_AttemptClose_ReturnValue;                 // 0x0026(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_IsClosing_ReturnValue;                    // 0x0027(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_IsClosed_ReturnValue;                     // 0x0028(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_IsOpening_ReturnValue;                    // 0x0029(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_IsOpen_ReturnValue_1;                     // 0x002A(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(CommonOCLLibrary_C_OCL_Library_ToggleOpenCloseState) == 0x000008, "Wrong alignment on CommonOCLLibrary_C_OCL_Library_ToggleOpenCloseState");
static_assert(sizeof(CommonOCLLibrary_C_OCL_Library_ToggleOpenCloseState) == 0x000030, "Wrong size on CommonOCLLibrary_C_OCL_Library_ToggleOpenCloseState");
static_assert(offsetof(CommonOCLLibrary_C_OCL_Library_ToggleOpenCloseState, Target) == 0x000000, "Member 'CommonOCLLibrary_C_OCL_Library_ToggleOpenCloseState::Target' has a wrong offset!");
static_assert(offsetof(CommonOCLLibrary_C_OCL_Library_ToggleOpenCloseState, Initiator) == 0x000008, "Member 'CommonOCLLibrary_C_OCL_Library_ToggleOpenCloseState::Initiator' has a wrong offset!");
static_assert(offsetof(CommonOCLLibrary_C_OCL_Library_ToggleOpenCloseState, Force) == 0x000010, "Member 'CommonOCLLibrary_C_OCL_Library_ToggleOpenCloseState::Force' has a wrong offset!");
static_assert(offsetof(CommonOCLLibrary_C_OCL_Library_ToggleOpenCloseState, Lock) == 0x000011, "Member 'CommonOCLLibrary_C_OCL_Library_ToggleOpenCloseState::Lock' has a wrong offset!");
static_assert(offsetof(CommonOCLLibrary_C_OCL_Library_ToggleOpenCloseState, Seal) == 0x000012, "Member 'CommonOCLLibrary_C_OCL_Library_ToggleOpenCloseState::Seal' has a wrong offset!");
static_assert(offsetof(CommonOCLLibrary_C_OCL_Library_ToggleOpenCloseState, IgnoreLockStatus) == 0x000013, "Member 'CommonOCLLibrary_C_OCL_Library_ToggleOpenCloseState::IgnoreLockStatus' has a wrong offset!");
static_assert(offsetof(CommonOCLLibrary_C_OCL_Library_ToggleOpenCloseState, IgnoreStartEvent) == 0x000014, "Member 'CommonOCLLibrary_C_OCL_Library_ToggleOpenCloseState::IgnoreStartEvent' has a wrong offset!");
static_assert(offsetof(CommonOCLLibrary_C_OCL_Library_ToggleOpenCloseState, IgnoreEndEvent) == 0x000015, "Member 'CommonOCLLibrary_C_OCL_Library_ToggleOpenCloseState::IgnoreEndEvent' has a wrong offset!");
static_assert(offsetof(CommonOCLLibrary_C_OCL_Library_ToggleOpenCloseState, IgnoreSound) == 0x000016, "Member 'CommonOCLLibrary_C_OCL_Library_ToggleOpenCloseState::IgnoreSound' has a wrong offset!");
static_assert(offsetof(CommonOCLLibrary_C_OCL_Library_ToggleOpenCloseState, InstantAnimation) == 0x000017, "Member 'CommonOCLLibrary_C_OCL_Library_ToggleOpenCloseState::InstantAnimation' has a wrong offset!");
static_assert(offsetof(CommonOCLLibrary_C_OCL_Library_ToggleOpenCloseState, __WorldContext) == 0x000018, "Member 'CommonOCLLibrary_C_OCL_Library_ToggleOpenCloseState::__WorldContext' has a wrong offset!");
static_assert(offsetof(CommonOCLLibrary_C_OCL_Library_ToggleOpenCloseState, IsOpen) == 0x000020, "Member 'CommonOCLLibrary_C_OCL_Library_ToggleOpenCloseState::IsOpen' has a wrong offset!");
static_assert(offsetof(CommonOCLLibrary_C_OCL_Library_ToggleOpenCloseState, IsOpening) == 0x000021, "Member 'CommonOCLLibrary_C_OCL_Library_ToggleOpenCloseState::IsOpening' has a wrong offset!");
static_assert(offsetof(CommonOCLLibrary_C_OCL_Library_ToggleOpenCloseState, IsClosed) == 0x000022, "Member 'CommonOCLLibrary_C_OCL_Library_ToggleOpenCloseState::IsClosed' has a wrong offset!");
static_assert(offsetof(CommonOCLLibrary_C_OCL_Library_ToggleOpenCloseState, IsClosing) == 0x000023, "Member 'CommonOCLLibrary_C_OCL_Library_ToggleOpenCloseState::IsClosing' has a wrong offset!");
static_assert(offsetof(CommonOCLLibrary_C_OCL_Library_ToggleOpenCloseState, CallFunc_IsOpen_ReturnValue) == 0x000024, "Member 'CommonOCLLibrary_C_OCL_Library_ToggleOpenCloseState::CallFunc_IsOpen_ReturnValue' has a wrong offset!");
static_assert(offsetof(CommonOCLLibrary_C_OCL_Library_ToggleOpenCloseState, CallFunc_AttemptOpen_ReturnValue) == 0x000025, "Member 'CommonOCLLibrary_C_OCL_Library_ToggleOpenCloseState::CallFunc_AttemptOpen_ReturnValue' has a wrong offset!");
static_assert(offsetof(CommonOCLLibrary_C_OCL_Library_ToggleOpenCloseState, CallFunc_AttemptClose_ReturnValue) == 0x000026, "Member 'CommonOCLLibrary_C_OCL_Library_ToggleOpenCloseState::CallFunc_AttemptClose_ReturnValue' has a wrong offset!");
static_assert(offsetof(CommonOCLLibrary_C_OCL_Library_ToggleOpenCloseState, CallFunc_IsClosing_ReturnValue) == 0x000027, "Member 'CommonOCLLibrary_C_OCL_Library_ToggleOpenCloseState::CallFunc_IsClosing_ReturnValue' has a wrong offset!");
static_assert(offsetof(CommonOCLLibrary_C_OCL_Library_ToggleOpenCloseState, CallFunc_IsClosed_ReturnValue) == 0x000028, "Member 'CommonOCLLibrary_C_OCL_Library_ToggleOpenCloseState::CallFunc_IsClosed_ReturnValue' has a wrong offset!");
static_assert(offsetof(CommonOCLLibrary_C_OCL_Library_ToggleOpenCloseState, CallFunc_IsOpening_ReturnValue) == 0x000029, "Member 'CommonOCLLibrary_C_OCL_Library_ToggleOpenCloseState::CallFunc_IsOpening_ReturnValue' has a wrong offset!");
static_assert(offsetof(CommonOCLLibrary_C_OCL_Library_ToggleOpenCloseState, CallFunc_IsOpen_ReturnValue_1) == 0x00002A, "Member 'CommonOCLLibrary_C_OCL_Library_ToggleOpenCloseState::CallFunc_IsOpen_ReturnValue_1' has a wrong offset!");

}

