#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: ConversationHistory_BP

#include "Basic.hpp"

#include "Indiana_classes.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass ConversationHistory_BP.ConversationHistory_BP_C
// 0x0008 (0x02A8 - 0x02A0)
class UConversationHistory_BP_C final : public UConversationHistoryWidget
{
public:
	class UImage*                                 Image_0;                                           // 0x02A0(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"ConversationHistory_BP_C">();
	}
	static class UConversationHistory_BP_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UConversationHistory_BP_C>();
	}
};
static_assert(alignof(UConversationHistory_BP_C) == 0x000008, "Wrong alignment on UConversationHistory_BP_C");
static_assert(sizeof(UConversationHistory_BP_C) == 0x0002A8, "Wrong size on UConversationHistory_BP_C");
static_assert(offsetof(UConversationHistory_BP_C, Image_0) == 0x0002A0, "Member 'UConversationHistory_BP_C::Image_0' has a wrong offset!");

}

