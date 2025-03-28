#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: CE_NRay_PostProcess

#include "Basic.hpp"

#include "CE_NRay_PostProcess_classes.hpp"
#include "CE_NRay_PostProcess_parameters.hpp"


namespace SDK
{

// Function CE_NRay_PostProcess.CE_NRay_PostProcess_C.ExecuteUbergraph_CE_NRay_PostProcess
// (Final, UbergraphFunction)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UCE_NRay_PostProcess_C::ExecuteUbergraph_CE_NRay_PostProcess(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("CE_NRay_PostProcess_C", "ExecuteUbergraph_CE_NRay_PostProcess");

	Params::CE_NRay_PostProcess_C_ExecuteUbergraph_CE_NRay_PostProcess Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function CE_NRay_PostProcess.CE_NRay_PostProcess_C.ReceiveClearEffect
// (Event, Protected, BlueprintEvent)
// Parameters:
// class AActor*                           Target                                                 (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UCE_NRay_PostProcess_C::ReceiveClearEffect(class AActor* Target)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("CE_NRay_PostProcess_C", "ReceiveClearEffect");

	Params::CE_NRay_PostProcess_C_ReceiveClearEffect Parms{};

	Parms.Target = Target;

	UObject::ProcessEvent(Func, &Parms);
}


// Function CE_NRay_PostProcess.CE_NRay_PostProcess_C.ReceiveApplyEffect
// (Event, Protected, BlueprintEvent)
// Parameters:
// class AActor*                           Target                                                 (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// float                                   Ratio                                                  (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// bool                                    bRestoredFromSave                                      (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UCE_NRay_PostProcess_C::ReceiveApplyEffect(class AActor* Target, float Ratio, bool bRestoredFromSave)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("CE_NRay_PostProcess_C", "ReceiveApplyEffect");

	Params::CE_NRay_PostProcess_C_ReceiveApplyEffect Parms{};

	Parms.Target = Target;
	Parms.Ratio = Ratio;
	Parms.bRestoredFromSave = bRestoredFromSave;

	UObject::ProcessEvent(Func, &Parms);
}

}

