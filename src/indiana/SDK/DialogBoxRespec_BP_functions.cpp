#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: DialogBoxRespec_BP

#include "Basic.hpp"

#include "DialogBoxRespec_BP_classes.hpp"
#include "DialogBoxRespec_BP_parameters.hpp"


namespace SDK
{

// Function DialogBoxRespec_BP.DialogBoxRespec_BP_C.ExecuteUbergraph_DialogBoxRespec_BP
// (Final, UbergraphFunction)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UDialogBoxRespec_BP_C::ExecuteUbergraph_DialogBoxRespec_BP(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("DialogBoxRespec_BP_C", "ExecuteUbergraph_DialogBoxRespec_BP");

	Params::DialogBoxRespec_BP_C_ExecuteUbergraph_DialogBoxRespec_BP Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function DialogBoxRespec_BP.DialogBoxRespec_BP_C.SetNewBackingMaterialHeight
// (Event, Protected, BlueprintEvent)
// Parameters:
// float                                   NewHeight                                              (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UDialogBoxRespec_BP_C::SetNewBackingMaterialHeight(float NewHeight)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("DialogBoxRespec_BP_C", "SetNewBackingMaterialHeight");

	Params::DialogBoxRespec_BP_C_SetNewBackingMaterialHeight Parms{};

	Parms.NewHeight = NewHeight;

	UObject::ProcessEvent(Func, &Parms);
}


// Function DialogBoxRespec_BP.DialogBoxRespec_BP_C.Construct
// (BlueprintCosmetic, Event, Public, BlueprintEvent)

void UDialogBoxRespec_BP_C::Construct()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("DialogBoxRespec_BP_C", "Construct");

	UObject::ProcessEvent(Func, nullptr);
}

}

