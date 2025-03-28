#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: Ammo_BP

#include "Basic.hpp"

#include "Ammo_BP_classes.hpp"
#include "Ammo_BP_parameters.hpp"


namespace SDK
{

// Function Ammo_BP.Ammo_BP_C.ExecuteUbergraph_Ammo_BP
// (Final, UbergraphFunction, HasDefaults)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UAmmo_BP_C::ExecuteUbergraph_Ammo_BP(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("Ammo_BP_C", "ExecuteUbergraph_Ammo_BP");

	Params::Ammo_BP_C_ExecuteUbergraph_Ammo_BP Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function Ammo_BP.Ammo_BP_C.BndEvt__Button_K2Node_ComponentBoundEvent_264_ComponentEventMCD__DelegateSignature
// (HasOutParams, BlueprintEvent)
// Parameters:
// struct FComponentEvent                  Event                                                  (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm, ContainsInstancedReference)

void UAmmo_BP_C::BndEvt__Button_K2Node_ComponentBoundEvent_264_ComponentEventMCD__DelegateSignature(const struct FComponentEvent& Event)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("Ammo_BP_C", "BndEvt__Button_K2Node_ComponentBoundEvent_264_ComponentEventMCD__DelegateSignature");

	Params::Ammo_BP_C_BndEvt__Button_K2Node_ComponentBoundEvent_264_ComponentEventMCD__DelegateSignature Parms{};

	Parms.Event = std::move(Event);

	UObject::ProcessEvent(Func, &Parms);
}


// Function Ammo_BP.Ammo_BP_C.BndEvt__Button_K2Node_ComponentBoundEvent_240_ComponentEventMCD__DelegateSignature
// (HasOutParams, BlueprintEvent)
// Parameters:
// struct FComponentEvent                  Event                                                  (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm, ContainsInstancedReference)

void UAmmo_BP_C::BndEvt__Button_K2Node_ComponentBoundEvent_240_ComponentEventMCD__DelegateSignature(const struct FComponentEvent& Event)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("Ammo_BP_C", "BndEvt__Button_K2Node_ComponentBoundEvent_240_ComponentEventMCD__DelegateSignature");

	Params::Ammo_BP_C_BndEvt__Button_K2Node_ComponentBoundEvent_240_ComponentEventMCD__DelegateSignature Parms{};

	Parms.Event = std::move(Event);

	UObject::ProcessEvent(Func, &Parms);
}


// Function Ammo_BP.Ammo_BP_C.BndEvt__Button_K2Node_ComponentBoundEvent_216_NoParamMCD__DelegateSignature
// (BlueprintEvent)

void UAmmo_BP_C::BndEvt__Button_K2Node_ComponentBoundEvent_216_NoParamMCD__DelegateSignature()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("Ammo_BP_C", "BndEvt__Button_K2Node_ComponentBoundEvent_216_NoParamMCD__DelegateSignature");

	UObject::ProcessEvent(Func, nullptr);
}


// Function Ammo_BP.Ammo_BP_C.BndEvt__Button_K2Node_ComponentBoundEvent_189_NoParamMCD__DelegateSignature
// (BlueprintEvent)

void UAmmo_BP_C::BndEvt__Button_K2Node_ComponentBoundEvent_189_NoParamMCD__DelegateSignature()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("Ammo_BP_C", "BndEvt__Button_K2Node_ComponentBoundEvent_189_NoParamMCD__DelegateSignature");

	UObject::ProcessEvent(Func, nullptr);
}

}

