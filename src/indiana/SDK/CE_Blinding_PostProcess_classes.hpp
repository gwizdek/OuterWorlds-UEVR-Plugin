#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: CE_Blinding_PostProcess

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "Indiana_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass CE_Blinding_PostProcess.CE_Blinding_PostProcess_C
// 0x0588 (0x0790 - 0x0208)
class UCE_Blinding_PostProcess_C final : public UPostProcessStatusEffect
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0208(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	float                                         Ratio;                                             // 0x0210(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_214[0xC];                                      // 0x0214(0x000C)(Fixing Size After Last Property [ Dumper-7 ])
	struct FPostProcessSettings                   Player_Default_PP_Settings;                        // 0x0220(0x0570)(Edit, BlueprintVisible, DisableEditOnInstance)

public:
	void ExecuteUbergraph_CE_Blinding_PostProcess(int32 EntryPoint);
	void ReceiveClearEffect(class AActor* Target);
	void ReceiveApplyEffect(class AActor* Target, float Ratio_0, bool bRestoredFromSave);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"CE_Blinding_PostProcess_C">();
	}
	static class UCE_Blinding_PostProcess_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UCE_Blinding_PostProcess_C>();
	}
};
static_assert(alignof(UCE_Blinding_PostProcess_C) == 0x000010, "Wrong alignment on UCE_Blinding_PostProcess_C");
static_assert(sizeof(UCE_Blinding_PostProcess_C) == 0x000790, "Wrong size on UCE_Blinding_PostProcess_C");
static_assert(offsetof(UCE_Blinding_PostProcess_C, UberGraphFrame) == 0x000208, "Member 'UCE_Blinding_PostProcess_C::UberGraphFrame' has a wrong offset!");
static_assert(offsetof(UCE_Blinding_PostProcess_C, Ratio) == 0x000210, "Member 'UCE_Blinding_PostProcess_C::Ratio' has a wrong offset!");
static_assert(offsetof(UCE_Blinding_PostProcess_C, Player_Default_PP_Settings) == 0x000220, "Member 'UCE_Blinding_PostProcess_C::Player_Default_PP_Settings' has a wrong offset!");

}

