#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: QuestList_BP

#include "Basic.hpp"

#include "Indiana_classes.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass QuestList_BP.QuestList_BP_C
// 0x0000 (0x03B8 - 0x03B8)
class UQuestList_BP_C final : public UQuestListWidget
{
public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"QuestList_BP_C">();
	}
	static class UQuestList_BP_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UQuestList_BP_C>();
	}
};
static_assert(alignof(UQuestList_BP_C) == 0x000008, "Wrong alignment on UQuestList_BP_C");
static_assert(sizeof(UQuestList_BP_C) == 0x0003B8, "Wrong size on UQuestList_BP_C");

}

