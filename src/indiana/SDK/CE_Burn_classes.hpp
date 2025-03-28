#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: CE_Burn

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "Indiana_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass CE_Burn.CE_Burn_C
// 0x0008 (0x01C0 - 0x01B8)
class UCE_Burn_C final : public UMultiStatusEffect
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x01B8(0x0008)(ZeroConstructor, Transient, DuplicateTransient)

public:
	void ExecuteUbergraph_CE_Burn(int32 EntryPoint);
	void ReceiveApplyEffect(class AActor* Target, float Ratio, bool bRestoredFromSave);
	void ReceiveClearEffect(class AActor* Target);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"CE_Burn_C">();
	}
	static class UCE_Burn_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UCE_Burn_C>();
	}
};
static_assert(alignof(UCE_Burn_C) == 0x000008, "Wrong alignment on UCE_Burn_C");
static_assert(sizeof(UCE_Burn_C) == 0x0001C0, "Wrong size on UCE_Burn_C");
static_assert(offsetof(UCE_Burn_C, UberGraphFrame) == 0x0001B8, "Member 'UCE_Burn_C::UberGraphFrame' has a wrong offset!");

}

