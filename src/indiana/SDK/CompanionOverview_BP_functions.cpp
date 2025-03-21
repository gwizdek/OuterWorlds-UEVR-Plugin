#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: CompanionOverview_BP

#include "Basic.hpp"

#include "CompanionOverview_BP_classes.hpp"
#include "CompanionOverview_BP_parameters.hpp"


namespace SDK
{

// Function CompanionOverview_BP.CompanionOverview_BP_C.ExecuteUbergraph_CompanionOverview_BP
// (Final, UbergraphFunction, HasDefaults)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UCompanionOverview_BP_C::ExecuteUbergraph_CompanionOverview_BP(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("CompanionOverview_BP_C", "ExecuteUbergraph_CompanionOverview_BP");

	Params::CompanionOverview_BP_C_ExecuteUbergraph_CompanionOverview_BP Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function CompanionOverview_BP.CompanionOverview_BP_C.OnAnimInOutComplete
// (BlueprintCallable, BlueprintEvent)

void UCompanionOverview_BP_C::OnAnimInOutComplete()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("CompanionOverview_BP_C", "OnAnimInOutComplete");

	UObject::ProcessEvent(Func, nullptr);
}


// Function CompanionOverview_BP.CompanionOverview_BP_C.OnFirstStatusEffect
// (Event, Protected, BlueprintEvent)

void UCompanionOverview_BP_C::OnFirstStatusEffect()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("CompanionOverview_BP_C", "OnFirstStatusEffect");

	UObject::ProcessEvent(Func, nullptr);
}


// Function CompanionOverview_BP.CompanionOverview_BP_C.OnNoStatusEffect
// (Event, Protected, BlueprintEvent)

void UCompanionOverview_BP_C::OnNoStatusEffect()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("CompanionOverview_BP_C", "OnNoStatusEffect");

	UObject::ProcessEvent(Func, nullptr);
}


// Function CompanionOverview_BP.CompanionOverview_BP_C.OnMadeInactive
// (Event, Protected, BlueprintEvent)

void UCompanionOverview_BP_C::OnMadeInactive()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("CompanionOverview_BP_C", "OnMadeInactive");

	UObject::ProcessEvent(Func, nullptr);
}


// Function CompanionOverview_BP.CompanionOverview_BP_C.OnMadeActive
// (Event, Protected, BlueprintEvent)

void UCompanionOverview_BP_C::OnMadeActive()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("CompanionOverview_BP_C", "OnMadeActive");

	UObject::ProcessEvent(Func, nullptr);
}


// Function CompanionOverview_BP.CompanionOverview_BP_C.Tick
// (BlueprintCosmetic, Event, Public, BlueprintEvent)
// Parameters:
// struct FGeometry                        MyGeometry                                             (BlueprintVisible, BlueprintReadOnly, Parm, IsPlainOldData, NoDestructor)
// float                                   InDeltaTime                                            (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UCompanionOverview_BP_C::Tick(const struct FGeometry& MyGeometry, float InDeltaTime)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("CompanionOverview_BP_C", "Tick");

	Params::CompanionOverview_BP_C_Tick Parms{};

	Parms.MyGeometry = std::move(MyGeometry);
	Parms.InDeltaTime = InDeltaTime;

	UObject::ProcessEvent(Func, &Parms);
}


// Function CompanionOverview_BP.CompanionOverview_BP_C.Construct
// (BlueprintCosmetic, Event, Public, BlueprintEvent)

void UCompanionOverview_BP_C::Construct()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("CompanionOverview_BP_C", "Construct");

	UObject::ProcessEvent(Func, nullptr);
}

}

