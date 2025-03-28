#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: GenericNotificationEntry_BP

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "Indiana_classes.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass GenericNotificationEntry_BP.GenericNotificationEntry_BP_C
// 0x0018 (0x0458 - 0x0440)
class UGenericNotificationEntry_BP_C final : public UGenericNotificationEntryWidget
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0440(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	class UWidgetAnimation*                       FadeIn;                                            // 0x0448(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, RepSkip, NoDestructor, HasGetValueTypeHash)
	class UWidgetAnimation*                       FadeOut;                                           // 0x0450(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, RepSkip, NoDestructor, HasGetValueTypeHash)

public:
	void ExecuteUbergraph_GenericNotificationEntry_BP(int32 EntryPoint);
	void OnFadeInFinished();
	void PrepareNextMessage();
	void OnFadeOutFinished();
	void PrepareNewMessage();
	void Construct();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"GenericNotificationEntry_BP_C">();
	}
	static class UGenericNotificationEntry_BP_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UGenericNotificationEntry_BP_C>();
	}
};
static_assert(alignof(UGenericNotificationEntry_BP_C) == 0x000008, "Wrong alignment on UGenericNotificationEntry_BP_C");
static_assert(sizeof(UGenericNotificationEntry_BP_C) == 0x000458, "Wrong size on UGenericNotificationEntry_BP_C");
static_assert(offsetof(UGenericNotificationEntry_BP_C, UberGraphFrame) == 0x000440, "Member 'UGenericNotificationEntry_BP_C::UberGraphFrame' has a wrong offset!");
static_assert(offsetof(UGenericNotificationEntry_BP_C, FadeIn) == 0x000448, "Member 'UGenericNotificationEntry_BP_C::FadeIn' has a wrong offset!");
static_assert(offsetof(UGenericNotificationEntry_BP_C, FadeOut) == 0x000450, "Member 'UGenericNotificationEntry_BP_C::FadeOut' has a wrong offset!");

}

