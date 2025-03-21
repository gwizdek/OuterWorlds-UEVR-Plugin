#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: DisguiseWidget_BP

#include "Basic.hpp"

#include "DisguiseWidget_BP_classes.hpp"
#include "DisguiseWidget_BP_parameters.hpp"


namespace SDK
{

// Function DisguiseWidget_BP.DisguiseWidget_BP_C.ExecuteUbergraph_DisguiseWidget_BP
// (Final, UbergraphFunction)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UDisguiseWidget_BP_C::ExecuteUbergraph_DisguiseWidget_BP(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("DisguiseWidget_BP_C", "ExecuteUbergraph_DisguiseWidget_BP");

	Params::DisguiseWidget_BP_C_ExecuteUbergraph_DisguiseWidget_BP Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function DisguiseWidget_BP.DisguiseWidget_BP_C.HideDisguiseMeterTip
// (Event, Protected, BlueprintEvent)
// Parameters:
// float                                   StartTime                                              (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UDisguiseWidget_BP_C::HideDisguiseMeterTip(float StartTime)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("DisguiseWidget_BP_C", "HideDisguiseMeterTip");

	Params::DisguiseWidget_BP_C_HideDisguiseMeterTip Parms{};

	Parms.StartTime = StartTime;

	UObject::ProcessEvent(Func, &Parms);
}


// Function DisguiseWidget_BP.DisguiseWidget_BP_C.ShowDisguiseMeterTip
// (Event, Protected, BlueprintEvent)
// Parameters:
// float                                   StartTime                                              (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UDisguiseWidget_BP_C::ShowDisguiseMeterTip(float StartTime)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("DisguiseWidget_BP_C", "ShowDisguiseMeterTip");

	Params::DisguiseWidget_BP_C_ShowDisguiseMeterTip Parms{};

	Parms.StartTime = StartTime;

	UObject::ProcessEvent(Func, &Parms);
}


// Function DisguiseWidget_BP.DisguiseWidget_BP_C.UpdateDisguiseMeterInnerAnim
// (Event, Protected, BlueprintEvent)
// Parameters:
// int32                                   CurrentFrame                                           (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UDisguiseWidget_BP_C::UpdateDisguiseMeterInnerAnim(int32 CurrentFrame)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("DisguiseWidget_BP_C", "UpdateDisguiseMeterInnerAnim");

	Params::DisguiseWidget_BP_C_UpdateDisguiseMeterInnerAnim Parms{};

	Parms.CurrentFrame = CurrentFrame;

	UObject::ProcessEvent(Func, &Parms);
}


// Function DisguiseWidget_BP.DisguiseWidget_BP_C.UpdateDisguiseMeterFill
// (Event, Protected, BlueprintEvent)
// Parameters:
// float                                   NewValue                                               (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UDisguiseWidget_BP_C::UpdateDisguiseMeterFill(float NewValue)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("DisguiseWidget_BP_C", "UpdateDisguiseMeterFill");

	Params::DisguiseWidget_BP_C_UpdateDisguiseMeterFill Parms{};

	Parms.NewValue = NewValue;

	UObject::ProcessEvent(Func, &Parms);
}


// Function DisguiseWidget_BP.DisguiseWidget_BP_C.OnDisguiseImageLoaded
// (Event, Protected, BlueprintEvent)

void UDisguiseWidget_BP_C::OnDisguiseImageLoaded()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("DisguiseWidget_BP_C", "OnDisguiseImageLoaded");

	UObject::ProcessEvent(Func, nullptr);
}


// Function DisguiseWidget_BP.DisguiseWidget_BP_C.OnDisguiseEnd
// (Event, Protected, BlueprintEvent)

void UDisguiseWidget_BP_C::OnDisguiseEnd()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("DisguiseWidget_BP_C", "OnDisguiseEnd");

	UObject::ProcessEvent(Func, nullptr);
}


// Function DisguiseWidget_BP.DisguiseWidget_BP_C.OnDisguiseBegin
// (Event, Protected, BlueprintEvent)

void UDisguiseWidget_BP_C::OnDisguiseBegin()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("DisguiseWidget_BP_C", "OnDisguiseBegin");

	UObject::ProcessEvent(Func, nullptr);
}


// Function DisguiseWidget_BP.DisguiseWidget_BP_C.Construct
// (BlueprintCosmetic, Event, Public, BlueprintEvent)

void UDisguiseWidget_BP_C::Construct()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("DisguiseWidget_BP_C", "Construct");

	UObject::ProcessEvent(Func, nullptr);
}

}

