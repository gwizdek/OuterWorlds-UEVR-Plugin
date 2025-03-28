#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: Compass_BP

#include "Basic.hpp"

#include "Compass_BP_classes.hpp"
#include "Compass_BP_parameters.hpp"


namespace SDK
{

// Function Compass_BP.Compass_BP_C.ExecuteUbergraph_Compass_BP
// (Final, UbergraphFunction, HasDefaults)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UCompass_BP_C::ExecuteUbergraph_Compass_BP(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("Compass_BP_C", "ExecuteUbergraph_Compass_BP");

	Params::Compass_BP_C_ExecuteUbergraph_Compass_BP Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function Compass_BP.Compass_BP_C.Tick
// (BlueprintCosmetic, Event, Public, BlueprintEvent)
// Parameters:
// struct FGeometry                        MyGeometry                                             (BlueprintVisible, BlueprintReadOnly, Parm, IsPlainOldData, NoDestructor)
// float                                   InDeltaTime                                            (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UCompass_BP_C::Tick(const struct FGeometry& MyGeometry, float InDeltaTime)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("Compass_BP_C", "Tick");

	Params::Compass_BP_C_Tick Parms{};

	Parms.MyGeometry = std::move(MyGeometry);
	Parms.InDeltaTime = InDeltaTime;

	UObject::ProcessEvent(Func, &Parms);
}


// Function Compass_BP.Compass_BP_C.Construct
// (BlueprintCosmetic, Event, Public, BlueprintEvent)

void UCompass_BP_C::Construct()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("Compass_BP_C", "Construct");

	UObject::ProcessEvent(Func, nullptr);
}

}

