#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: TL_StunBaton_Weapon_Base

#include "Basic.hpp"

#include "TL_StunBaton_Weapon_Base_classes.hpp"
#include "TL_StunBaton_Weapon_Base_parameters.hpp"


namespace SDK
{

// Function TL_StunBaton_Weapon_Base.TL_StunBaton_Weapon_Base_C.ExecuteUbergraph_TL_StunBaton_Weapon_Base
// (Final, UbergraphFunction)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UTL_StunBaton_Weapon_Base_C::ExecuteUbergraph_TL_StunBaton_Weapon_Base(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("TL_StunBaton_Weapon_Base_C", "ExecuteUbergraph_TL_StunBaton_Weapon_Base");

	Params::TL_StunBaton_Weapon_Base_C_ExecuteUbergraph_TL_StunBaton_Weapon_Base Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function TL_StunBaton_Weapon_Base.TL_StunBaton_Weapon_Base_C.ReceiveTick
// (BlueprintCallable, BlueprintEvent)
// Parameters:
// float                                   DeltaSeconds                                           (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UTL_StunBaton_Weapon_Base_C::ReceiveTick(float DeltaSeconds)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("TL_StunBaton_Weapon_Base_C", "ReceiveTick");

	Params::TL_StunBaton_Weapon_Base_C_ReceiveTick Parms{};

	Parms.DeltaSeconds = DeltaSeconds;

	UObject::ProcessEvent(Func, &Parms);
}


// Function TL_StunBaton_Weapon_Base.TL_StunBaton_Weapon_Base_C.ReceiveActorBeginOverlap
// (BlueprintCallable, BlueprintEvent)
// Parameters:
// class AActor*                           OtherActor                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UTL_StunBaton_Weapon_Base_C::ReceiveActorBeginOverlap(class AActor* OtherActor)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("TL_StunBaton_Weapon_Base_C", "ReceiveActorBeginOverlap");

	Params::TL_StunBaton_Weapon_Base_C_ReceiveActorBeginOverlap Parms{};

	Parms.OtherActor = OtherActor;

	UObject::ProcessEvent(Func, &Parms);
}


// Function TL_StunBaton_Weapon_Base.TL_StunBaton_Weapon_Base_C.ReceiveBeginPlay
// (BlueprintCallable, BlueprintEvent)

void UTL_StunBaton_Weapon_Base_C::ReceiveBeginPlay()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("TL_StunBaton_Weapon_Base_C", "ReceiveBeginPlay");

	UObject::ProcessEvent(Func, nullptr);
}

}

