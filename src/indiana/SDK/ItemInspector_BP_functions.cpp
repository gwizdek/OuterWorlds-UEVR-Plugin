#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: ItemInspector_BP

#include "Basic.hpp"

#include "ItemInspector_BP_classes.hpp"
#include "ItemInspector_BP_parameters.hpp"


namespace SDK
{

// Function ItemInspector_BP.ItemInspector_BP_C.ExecuteUbergraph_ItemInspector_BP
// (Final, UbergraphFunction)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UItemInspector_BP_C::ExecuteUbergraph_ItemInspector_BP(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("ItemInspector_BP_C", "ExecuteUbergraph_ItemInspector_BP");

	Params::ItemInspector_BP_C_ExecuteUbergraph_ItemInspector_BP Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function ItemInspector_BP.ItemInspector_BP_C.ZoomToggled
// (Event, Protected, BlueprintEvent)
// Parameters:
// bool                                    bFullZoom                                              (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UItemInspector_BP_C::ZoomToggled(bool bFullZoom)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("ItemInspector_BP_C", "ZoomToggled");

	Params::ItemInspector_BP_C_ZoomToggled Parms{};

	Parms.bFullZoom = bFullZoom;

	UObject::ProcessEvent(Func, &Parms);
}

}

