#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: HealthKitTooltip_BP

#include "Basic.hpp"

#include "HealthKitTooltip_BP_classes.hpp"
#include "HealthKitTooltip_BP_parameters.hpp"


namespace SDK
{

// Function HealthKitTooltip_BP.HealthKitTooltip_BP_C.OnIntro
// (Event, Protected, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// TDelegate<void()>                       AnimationCompleteCallback                              (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ZeroConstructor, ReferenceParm, NoDestructor)
// bool                                    ReturnValue                                            (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor)

bool UHealthKitTooltip_BP_C::OnIntro(const TDelegate<void()>& AnimationCompleteCallback)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("HealthKitTooltip_BP_C", "OnIntro");

	Params::HealthKitTooltip_BP_C_OnIntro Parms{};

	Parms.AnimationCompleteCallback = AnimationCompleteCallback;

	UObject::ProcessEvent(Func, &Parms);

	return Parms.ReturnValue;
}

}

