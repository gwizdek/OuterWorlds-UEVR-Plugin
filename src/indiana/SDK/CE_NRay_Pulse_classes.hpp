#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: CE_NRay_Pulse

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "Indiana_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass CE_NRay_Pulse.CE_NRay_Pulse_C
// 0x0010 (0x0220 - 0x0210)
class UCE_NRay_Pulse_C final : public UDamageStatusEffect
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0210(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	bool                                          UseNiagara;                                        // 0x0218(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)

public:
	void ExecuteUbergraph_CE_NRay_Pulse(int32 EntryPoint);
	void ReceiveApplyEffect(class AActor* Target, float Ratio, bool bRestoredFromSave);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"CE_NRay_Pulse_C">();
	}
	static class UCE_NRay_Pulse_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UCE_NRay_Pulse_C>();
	}
};
static_assert(alignof(UCE_NRay_Pulse_C) == 0x000010, "Wrong alignment on UCE_NRay_Pulse_C");
static_assert(sizeof(UCE_NRay_Pulse_C) == 0x000220, "Wrong size on UCE_NRay_Pulse_C");
static_assert(offsetof(UCE_NRay_Pulse_C, UberGraphFrame) == 0x000210, "Member 'UCE_NRay_Pulse_C::UberGraphFrame' has a wrong offset!");
static_assert(offsetof(UCE_NRay_Pulse_C, UseNiagara) == 0x000218, "Member 'UCE_NRay_Pulse_C::UseNiagara' has a wrong offset!");

}

