#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: QuestObjectiveTitle_BP

#include "Basic.hpp"

#include "QuestObjectiveTitle_BP_classes.hpp"
#include "QuestObjectiveTitle_BP_parameters.hpp"


namespace SDK
{

// Function QuestObjectiveTitle_BP.QuestObjectiveTitle_BP_C.ExecuteUbergraph_QuestObjectiveTitle_BP
// (Final, UbergraphFunction, HasDefaults)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UQuestObjectiveTitle_BP_C::ExecuteUbergraph_QuestObjectiveTitle_BP(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("QuestObjectiveTitle_BP_C", "ExecuteUbergraph_QuestObjectiveTitle_BP");

	Params::QuestObjectiveTitle_BP_C_ExecuteUbergraph_QuestObjectiveTitle_BP Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function QuestObjectiveTitle_BP.QuestObjectiveTitle_BP_C.OnObjectiveStatusChange
// (Event, Protected, BlueprintEvent)
// Parameters:
// ECompletionStatus                       ObjectiveStatus                                        (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UQuestObjectiveTitle_BP_C::OnObjectiveStatusChange(ECompletionStatus ObjectiveStatus)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("QuestObjectiveTitle_BP_C", "OnObjectiveStatusChange");

	Params::QuestObjectiveTitle_BP_C_OnObjectiveStatusChange Parms{};

	Parms.ObjectiveStatus = ObjectiveStatus;

	UObject::ProcessEvent(Func, &Parms);
}

}

