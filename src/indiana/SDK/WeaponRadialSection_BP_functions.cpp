#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: WeaponRadialSection_BP

#include "Basic.hpp"

#include "WeaponRadialSection_BP_classes.hpp"
#include "WeaponRadialSection_BP_parameters.hpp"


namespace SDK
{

// Function WeaponRadialSection_BP.WeaponRadialSection_BP_C.ExecuteUbergraph_WeaponRadialSection_BP
// (Final, UbergraphFunction)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWeaponRadialSection_BP_C::ExecuteUbergraph_WeaponRadialSection_BP(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WeaponRadialSection_BP_C", "ExecuteUbergraph_WeaponRadialSection_BP");

	Params::WeaponRadialSection_BP_C_ExecuteUbergraph_WeaponRadialSection_BP Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WeaponRadialSection_BP.WeaponRadialSection_BP_C.Construct
// (BlueprintCosmetic, Event, Public, BlueprintEvent)

void UWeaponRadialSection_BP_C::Construct()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WeaponRadialSection_BP_C", "Construct");

	UObject::ProcessEvent(Func, nullptr);
}

}

