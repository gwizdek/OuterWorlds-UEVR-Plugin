#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: StackSplitting_BP

#include "Basic.hpp"

#include "StackSplitting_BP_classes.hpp"
#include "StackSplitting_BP_parameters.hpp"


namespace SDK
{

// Function StackSplitting_BP.StackSplitting_BP_C.ExecuteUbergraph_StackSplitting_BP
// (Final, UbergraphFunction)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UStackSplitting_BP_C::ExecuteUbergraph_StackSplitting_BP(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("StackSplitting_BP_C", "ExecuteUbergraph_StackSplitting_BP");

	Params::StackSplitting_BP_C_ExecuteUbergraph_StackSplitting_BP Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function StackSplitting_BP.StackSplitting_BP_C.SetNewBackingMaterialHeight
// (Event, Protected, BlueprintEvent)
// Parameters:
// float                                   NewHeight                                              (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UStackSplitting_BP_C::SetNewBackingMaterialHeight(float NewHeight)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("StackSplitting_BP_C", "SetNewBackingMaterialHeight");

	Params::StackSplitting_BP_C_SetNewBackingMaterialHeight Parms{};

	Parms.NewHeight = NewHeight;

	UObject::ProcessEvent(Func, &Parms);
}


// Function StackSplitting_BP.StackSplitting_BP_C.Construct
// (BlueprintCosmetic, Event, Public, BlueprintEvent)

void UStackSplitting_BP_C::Construct()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("StackSplitting_BP_C", "Construct");

	UObject::ProcessEvent(Func, nullptr);
}

}

