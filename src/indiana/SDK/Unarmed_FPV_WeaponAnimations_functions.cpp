#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: Unarmed_FPV_WeaponAnimations

#include "Basic.hpp"

#include "Unarmed_FPV_WeaponAnimations_classes.hpp"
#include "Unarmed_FPV_WeaponAnimations_parameters.hpp"


namespace SDK
{

// Function Unarmed_FPV_WeaponAnimations.Unarmed_FPV_WeaponAnimations_C.ExecuteUbergraph_Unarmed_FPV_WeaponAnimations
// (Final, UbergraphFunction, HasDefaults)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UUnarmed_FPV_WeaponAnimations_C::ExecuteUbergraph_Unarmed_FPV_WeaponAnimations(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("Unarmed_FPV_WeaponAnimations_C", "ExecuteUbergraph_Unarmed_FPV_WeaponAnimations");

	Params::Unarmed_FPV_WeaponAnimations_C_ExecuteUbergraph_Unarmed_FPV_WeaponAnimations Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function Unarmed_FPV_WeaponAnimations.Unarmed_FPV_WeaponAnimations_C.EnterStateBP
// (Event, Protected, HasOutParams, BlueprintEvent)
// Parameters:
// EWeaponState                            WeaponState                                            (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// struct FEventEffectParams               Params_0                                               (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm)

void UUnarmed_FPV_WeaponAnimations_C::EnterStateBP(EWeaponState WeaponState, const struct FEventEffectParams& Params_0)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("Unarmed_FPV_WeaponAnimations_C", "EnterStateBP");

	Params::Unarmed_FPV_WeaponAnimations_C_EnterStateBP Parms{};

	Parms.WeaponState = WeaponState;
	Parms.Params_0 = std::move(Params_0);

	UObject::ProcessEvent(Func, &Parms);
}


// Function Unarmed_FPV_WeaponAnimations.Unarmed_FPV_WeaponAnimations_C.LeaveStateBP
// (Event, Protected, BlueprintEvent)
// Parameters:
// EWeaponState                            WeaponState                                            (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UUnarmed_FPV_WeaponAnimations_C::LeaveStateBP(EWeaponState WeaponState)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("Unarmed_FPV_WeaponAnimations_C", "LeaveStateBP");

	Params::Unarmed_FPV_WeaponAnimations_C_LeaveStateBP Parms{};

	Parms.WeaponState = WeaponState;

	UObject::ProcessEvent(Func, &Parms);
}


// Function Unarmed_FPV_WeaponAnimations.Unarmed_FPV_WeaponAnimations_C.TriggerEventBP
// (Event, Protected, HasOutParams, BlueprintEvent)
// Parameters:
// EWeaponEvent                            WeaponEvent                                            (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// struct FEventEffectParams               Params_0                                               (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm)

void UUnarmed_FPV_WeaponAnimations_C::TriggerEventBP(EWeaponEvent WeaponEvent, const struct FEventEffectParams& Params_0)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("Unarmed_FPV_WeaponAnimations_C", "TriggerEventBP");

	Params::Unarmed_FPV_WeaponAnimations_C_TriggerEventBP Parms{};

	Parms.WeaponEvent = WeaponEvent;
	Parms.Params_0 = std::move(Params_0);

	UObject::ProcessEvent(Func, &Parms);
}

}

