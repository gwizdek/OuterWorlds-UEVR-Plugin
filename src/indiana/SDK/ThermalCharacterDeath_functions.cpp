#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: ThermalCharacterDeath

#include "Basic.hpp"

#include "ThermalCharacterDeath_classes.hpp"
#include "ThermalCharacterDeath_parameters.hpp"


namespace SDK
{

// Function ThermalCharacterDeath.ThermalCharacterDeath_C.ExecuteUbergraph_ThermalCharacterDeath
// (Final, UbergraphFunction)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UThermalCharacterDeath_C::ExecuteUbergraph_ThermalCharacterDeath(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("ThermalCharacterDeath_C", "ExecuteUbergraph_ThermalCharacterDeath");

	Params::ThermalCharacterDeath_C_ExecuteUbergraph_ThermalCharacterDeath Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function ThermalCharacterDeath.ThermalCharacterDeath_C.ExecuteOnReload
// (Event, Public, BlueprintEvent)
// Parameters:
// class UCharacterDeathComponent*         InDeathComponent                                       (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UThermalCharacterDeath_C::ExecuteOnReload(class UCharacterDeathComponent* InDeathComponent)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("ThermalCharacterDeath_C", "ExecuteOnReload");

	Params::ThermalCharacterDeath_C_ExecuteOnReload Parms{};

	Parms.InDeathComponent = InDeathComponent;

	UObject::ProcessEvent(Func, &Parms);
}


// Function ThermalCharacterDeath.ThermalCharacterDeath_C.Tick
// (Event, Public, BlueprintEvent)
// Parameters:
// float                                   Delta                                                  (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UThermalCharacterDeath_C::Tick(float Delta)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("ThermalCharacterDeath_C", "Tick");

	Params::ThermalCharacterDeath_C_Tick Parms{};

	Parms.Delta = Delta;

	UObject::ProcessEvent(Func, &Parms);
}


// Function ThermalCharacterDeath.ThermalCharacterDeath_C.Execute
// (Event, Public, BlueprintEvent)
// Parameters:
// class UCharacterDeathComponent*         InDeathComponent                                       (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UThermalCharacterDeath_C::Execute(class UCharacterDeathComponent* InDeathComponent)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("ThermalCharacterDeath_C", "Execute");

	Params::ThermalCharacterDeath_C_Execute Parms{};

	Parms.InDeathComponent = InDeathComponent;

	UObject::ProcessEvent(Func, &Parms);
}


// Function ThermalCharacterDeath.ThermalCharacterDeath_C.TriggerParticleEffects
// (Public, BlueprintCallable, BlueprintEvent)

void UThermalCharacterDeath_C::TriggerParticleEffects()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("ThermalCharacterDeath_C", "TriggerParticleEffects");

	UObject::ProcessEvent(Func, nullptr);
}

}

