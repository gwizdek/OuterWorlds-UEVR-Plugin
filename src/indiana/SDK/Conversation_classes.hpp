#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: Conversation

#include "Basic.hpp"

#include "Indiana_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass Conversation.Conversation_C
// 0x0000 (0x0048 - 0x0048)
class UConversation_C final : public UDecisionTree_CombinedRequests
{
public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"Conversation_C">();
	}
	static class UConversation_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UConversation_C>();
	}
};
static_assert(alignof(UConversation_C) == 0x000008, "Wrong alignment on UConversation_C");
static_assert(sizeof(UConversation_C) == 0x000048, "Wrong size on UConversation_C");

}

