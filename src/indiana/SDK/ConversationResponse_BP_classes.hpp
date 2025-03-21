#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: ConversationResponse_BP

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "Indiana_classes.hpp"
#include "UMG_structs.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass ConversationResponse_BP.ConversationResponse_BP_C
// 0x0028 (0x02F8 - 0x02D0)
class UConversationResponse_BP_C final : public UConversationResponseWidget
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x02D0(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	class UWidgetAnimation*                       NewAnimation_1;                                    // 0x02D8(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, RepSkip, NoDestructor, HasGetValueTypeHash)
	class UImage*                                 CompanionContributedImage;                         // 0x02E0(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UImage*                                 NearMissImage;                                     // 0x02E8(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UHorizontalBox*                         TextHorizontalBox;                                 // 0x02F0(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)

public:
	void ExecuteUbergraph_ConversationResponse_BP(int32 EntryPoint);
	void OnSetSkillCheckRequiredCompanion(bool bSelectable);
	void OnSetSelectableOption(bool bSelectable);
	void OnResponseSkillsChanged(bool bContainsSkillCheck);
	void Construct();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"ConversationResponse_BP_C">();
	}
	static class UConversationResponse_BP_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UConversationResponse_BP_C>();
	}
};
static_assert(alignof(UConversationResponse_BP_C) == 0x000008, "Wrong alignment on UConversationResponse_BP_C");
static_assert(sizeof(UConversationResponse_BP_C) == 0x0002F8, "Wrong size on UConversationResponse_BP_C");
static_assert(offsetof(UConversationResponse_BP_C, UberGraphFrame) == 0x0002D0, "Member 'UConversationResponse_BP_C::UberGraphFrame' has a wrong offset!");
static_assert(offsetof(UConversationResponse_BP_C, NewAnimation_1) == 0x0002D8, "Member 'UConversationResponse_BP_C::NewAnimation_1' has a wrong offset!");
static_assert(offsetof(UConversationResponse_BP_C, CompanionContributedImage) == 0x0002E0, "Member 'UConversationResponse_BP_C::CompanionContributedImage' has a wrong offset!");
static_assert(offsetof(UConversationResponse_BP_C, NearMissImage) == 0x0002E8, "Member 'UConversationResponse_BP_C::NearMissImage' has a wrong offset!");
static_assert(offsetof(UConversationResponse_BP_C, TextHorizontalBox) == 0x0002F0, "Member 'UConversationResponse_BP_C::TextHorizontalBox' has a wrong offset!");

}

