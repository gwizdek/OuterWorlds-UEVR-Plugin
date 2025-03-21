#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: VendingContainer_BP

#include "Basic.hpp"

#include "VendingContainer_BP_classes.hpp"
#include "VendingContainer_BP_parameters.hpp"


namespace SDK
{

// Function VendingContainer_BP.VendingContainer_BP_C.ReceiveBeginPlay
// (Event, Protected, BlueprintEvent)

void AVendingContainer_BP_C::ReceiveBeginPlay()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("VendingContainer_BP_C", "ReceiveBeginPlay");

	UObject::ProcessEvent(Func, nullptr);
}


// Function VendingContainer_BP.VendingContainer_BP_C.BndEvt__OCLComponent_K2Node_ComponentBoundEvent_0_OCLCloseStart__DelegateSignature
// (BlueprintEvent)
// Parameters:
// class AActor*                           Initiator                                              (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void AVendingContainer_BP_C::BndEvt__OCLComponent_K2Node_ComponentBoundEvent_0_OCLCloseStart__DelegateSignature(class AActor* Initiator)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("VendingContainer_BP_C", "BndEvt__OCLComponent_K2Node_ComponentBoundEvent_0_OCLCloseStart__DelegateSignature");

	Params::VendingContainer_BP_C_BndEvt__OCLComponent_K2Node_ComponentBoundEvent_0_OCLCloseStart__DelegateSignature Parms{};

	Parms.Initiator = Initiator;

	UObject::ProcessEvent(Func, &Parms);
}


// Function VendingContainer_BP.VendingContainer_BP_C.ExecuteUbergraph_VendingContainer_BP
// (Final, UbergraphFunction, HasDefaults)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void AVendingContainer_BP_C::ExecuteUbergraph_VendingContainer_BP(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("VendingContainer_BP_C", "ExecuteUbergraph_VendingContainer_BP");

	Params::VendingContainer_BP_C_ExecuteUbergraph_VendingContainer_BP Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function VendingContainer_BP.VendingContainer_BP_C.UserConstructionScript
// (Event, Public, BlueprintCallable, BlueprintEvent)

void AVendingContainer_BP_C::UserConstructionScript()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("VendingContainer_BP_C", "UserConstructionScript");

	UObject::ProcessEvent(Func, nullptr);
}

}

