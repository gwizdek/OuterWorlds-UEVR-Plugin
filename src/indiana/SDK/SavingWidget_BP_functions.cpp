#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: SavingWidget_BP

#include "Basic.hpp"

#include "SavingWidget_BP_classes.hpp"
#include "SavingWidget_BP_parameters.hpp"


namespace SDK
{

// Function SavingWidget_BP.SavingWidget_BP_C.OnMaximize
// (Event, Protected, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// TDelegate<void()>                       AnimationCompleteCallback                              (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ZeroConstructor, ReferenceParm, NoDestructor)
// bool                                    ReturnValue                                            (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor)

bool USavingWidget_BP_C::OnMaximize(const TDelegate<void()>& AnimationCompleteCallback)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("SavingWidget_BP_C", "OnMaximize");

	Params::SavingWidget_BP_C_OnMaximize Parms{};

	Parms.AnimationCompleteCallback = AnimationCompleteCallback;

	UObject::ProcessEvent(Func, &Parms);

	return Parms.ReturnValue;
}


// Function SavingWidget_BP.SavingWidget_BP_C.OnMinimize
// (Event, Protected, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// TDelegate<void()>                       AnimationCompleteCallback                              (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ZeroConstructor, ReferenceParm, NoDestructor)
// bool                                    ReturnValue                                            (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor)

bool USavingWidget_BP_C::OnMinimize(const TDelegate<void()>& AnimationCompleteCallback)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("SavingWidget_BP_C", "OnMinimize");

	Params::SavingWidget_BP_C_OnMinimize Parms{};

	Parms.AnimationCompleteCallback = AnimationCompleteCallback;

	UObject::ProcessEvent(Func, &Parms);

	return Parms.ReturnValue;
}

}

