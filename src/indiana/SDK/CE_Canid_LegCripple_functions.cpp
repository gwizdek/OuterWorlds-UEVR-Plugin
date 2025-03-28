#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: CE_Canid_LegCripple

#include "Basic.hpp"

#include "CE_Canid_LegCripple_classes.hpp"
#include "CE_Canid_LegCripple_parameters.hpp"


namespace SDK
{

// Function CE_Canid_LegCripple.CE_Canid_LegCripple_C.ExecuteUbergraph_CE_Canid_LegCripple
// (Final, UbergraphFunction)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UCE_Canid_LegCripple_C::ExecuteUbergraph_CE_Canid_LegCripple(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("CE_Canid_LegCripple_C", "ExecuteUbergraph_CE_Canid_LegCripple");

	Params::CE_Canid_LegCripple_C_ExecuteUbergraph_CE_Canid_LegCripple Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function CE_Canid_LegCripple.CE_Canid_LegCripple_C.ReceiveClearEffect
// (Event, Protected, BlueprintEvent)
// Parameters:
// class AActor*                           Target                                                 (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UCE_Canid_LegCripple_C::ReceiveClearEffect(class AActor* Target)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("CE_Canid_LegCripple_C", "ReceiveClearEffect");

	Params::CE_Canid_LegCripple_C_ReceiveClearEffect Parms{};

	Parms.Target = Target;

	UObject::ProcessEvent(Func, &Parms);
}


// Function CE_Canid_LegCripple.CE_Canid_LegCripple_C.ReceiveApplyEffect
// (Event, Protected, BlueprintEvent)
// Parameters:
// class AActor*                           Target                                                 (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// float                                   Ratio                                                  (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// bool                                    bRestoredFromSave                                      (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UCE_Canid_LegCripple_C::ReceiveApplyEffect(class AActor* Target, float Ratio, bool bRestoredFromSave)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("CE_Canid_LegCripple_C", "ReceiveApplyEffect");

	Params::CE_Canid_LegCripple_C_ReceiveApplyEffect Parms{};

	Parms.Target = Target;
	Parms.Ratio = Ratio;
	Parms.bRestoredFromSave = bRestoredFromSave;

	UObject::ProcessEvent(Func, &Parms);
}

}

