#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: QuestJournalMaster_BP

#include "Basic.hpp"

#include "QuestJournalMaster_BP_classes.hpp"
#include "QuestJournalMaster_BP_parameters.hpp"


namespace SDK
{

// Function QuestJournalMaster_BP.QuestJournalMaster_BP_C.ExecuteUbergraph_QuestJournalMaster_BP
// (Final, UbergraphFunction)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UQuestJournalMaster_BP_C::ExecuteUbergraph_QuestJournalMaster_BP(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("QuestJournalMaster_BP_C", "ExecuteUbergraph_QuestJournalMaster_BP");

	Params::QuestJournalMaster_BP_C_ExecuteUbergraph_QuestJournalMaster_BP Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function QuestJournalMaster_BP.QuestJournalMaster_BP_C.OnQuestImageLoaded
// (Event, Protected, BlueprintEvent)

void UQuestJournalMaster_BP_C::OnQuestImageLoaded()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("QuestJournalMaster_BP_C", "OnQuestImageLoaded");

	UObject::ProcessEvent(Func, nullptr);
}

}

