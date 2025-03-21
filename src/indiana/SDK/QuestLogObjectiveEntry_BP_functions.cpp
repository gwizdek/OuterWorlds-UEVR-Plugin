#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: QuestLogObjectiveEntry_BP

#include "Basic.hpp"

#include "QuestLogObjectiveEntry_BP_classes.hpp"
#include "QuestLogObjectiveEntry_BP_parameters.hpp"


namespace SDK
{

// Function QuestLogObjectiveEntry_BP.QuestLogObjectiveEntry_BP_C.ExecuteUbergraph_QuestLogObjectiveEntry_BP
// (Final, UbergraphFunction)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UQuestLogObjectiveEntry_BP_C::ExecuteUbergraph_QuestLogObjectiveEntry_BP(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("QuestLogObjectiveEntry_BP_C", "ExecuteUbergraph_QuestLogObjectiveEntry_BP");

	Params::QuestLogObjectiveEntry_BP_C_ExecuteUbergraph_QuestLogObjectiveEntry_BP Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function QuestLogObjectiveEntry_BP.QuestLogObjectiveEntry_BP_C.OnObjectiveMadeInactive
// (Event, Protected, BlueprintEvent)

void UQuestLogObjectiveEntry_BP_C::OnObjectiveMadeInactive()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("QuestLogObjectiveEntry_BP_C", "OnObjectiveMadeInactive");

	UObject::ProcessEvent(Func, nullptr);
}


// Function QuestLogObjectiveEntry_BP.QuestLogObjectiveEntry_BP_C.OnObjectiveMadeActive
// (Event, Protected, BlueprintEvent)

void UQuestLogObjectiveEntry_BP_C::OnObjectiveMadeActive()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("QuestLogObjectiveEntry_BP_C", "OnObjectiveMadeActive");

	UObject::ProcessEvent(Func, nullptr);
}


// Function QuestLogObjectiveEntry_BP.QuestLogObjectiveEntry_BP_C.OnCompletedAnim
// (BlueprintCallable, BlueprintEvent)

void UQuestLogObjectiveEntry_BP_C::OnCompletedAnim()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("QuestLogObjectiveEntry_BP_C", "OnCompletedAnim");

	UObject::ProcessEvent(Func, nullptr);
}


// Function QuestLogObjectiveEntry_BP.QuestLogObjectiveEntry_BP_C.OnFailedAnim
// (BlueprintCallable, BlueprintEvent)

void UQuestLogObjectiveEntry_BP_C::OnFailedAnim()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("QuestLogObjectiveEntry_BP_C", "OnFailedAnim");

	UObject::ProcessEvent(Func, nullptr);
}


// Function QuestLogObjectiveEntry_BP.QuestLogObjectiveEntry_BP_C.OnOutroAnim
// (BlueprintCallable, BlueprintEvent)

void UQuestLogObjectiveEntry_BP_C::OnOutroAnim()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("QuestLogObjectiveEntry_BP_C", "OnOutroAnim");

	UObject::ProcessEvent(Func, nullptr);
}


// Function QuestLogObjectiveEntry_BP.QuestLogObjectiveEntry_BP_C.OnIntroAnim
// (BlueprintCallable, BlueprintEvent)

void UQuestLogObjectiveEntry_BP_C::OnIntroAnim()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("QuestLogObjectiveEntry_BP_C", "OnIntroAnim");

	UObject::ProcessEvent(Func, nullptr);
}


// Function QuestLogObjectiveEntry_BP.QuestLogObjectiveEntry_BP_C.StartFailAnim
// (Event, Protected, BlueprintEvent)

void UQuestLogObjectiveEntry_BP_C::StartFailAnim()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("QuestLogObjectiveEntry_BP_C", "StartFailAnim");

	UObject::ProcessEvent(Func, nullptr);
}


// Function QuestLogObjectiveEntry_BP.QuestLogObjectiveEntry_BP_C.StartCompleteAnim
// (Event, Protected, BlueprintEvent)

void UQuestLogObjectiveEntry_BP_C::StartCompleteAnim()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("QuestLogObjectiveEntry_BP_C", "StartCompleteAnim");

	UObject::ProcessEvent(Func, nullptr);
}


// Function QuestLogObjectiveEntry_BP.QuestLogObjectiveEntry_BP_C.Construct
// (BlueprintCosmetic, Event, Public, BlueprintEvent)

void UQuestLogObjectiveEntry_BP_C::Construct()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("QuestLogObjectiveEntry_BP_C", "Construct");

	UObject::ProcessEvent(Func, nullptr);
}

}

