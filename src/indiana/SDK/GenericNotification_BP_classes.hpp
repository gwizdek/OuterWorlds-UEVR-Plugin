#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: GenericNotification_BP

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "Indiana_classes.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass GenericNotification_BP.GenericNotification_BP_C
// 0x0028 (0x0488 - 0x0460)
class UGenericNotification_BP_C final : public UGenericNotificationWidget
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0460(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	class UWidgetAnimation*                       FadeOut;                                           // 0x0468(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, RepSkip, NoDestructor, HasGetValueTypeHash)
	class UWidgetAnimation*                       FadeIn;                                            // 0x0470(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, RepSkip, NoDestructor, HasGetValueTypeHash)
	class UBorder*                                ContentContainer;                                  // 0x0478(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UMaterialInstanceDynamic*               ContentContainerMat;                               // 0x0480(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	void ExecuteUbergraph_GenericNotification_BP(int32 EntryPoint);
	void WidgetAnimationEvt_FadeOut_K2Node_WidgetAnimationEvent_1();
	void WidgetAnimationEvt_FadeIn_K2Node_WidgetAnimationEvent_0();
	void SetBackingMaterialHeight(float NewHeight);
	void TriggerFadeOut();
	void TriggerFadeIn();
	void Construct();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"GenericNotification_BP_C">();
	}
	static class UGenericNotification_BP_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UGenericNotification_BP_C>();
	}
};
static_assert(alignof(UGenericNotification_BP_C) == 0x000008, "Wrong alignment on UGenericNotification_BP_C");
static_assert(sizeof(UGenericNotification_BP_C) == 0x000488, "Wrong size on UGenericNotification_BP_C");
static_assert(offsetof(UGenericNotification_BP_C, UberGraphFrame) == 0x000460, "Member 'UGenericNotification_BP_C::UberGraphFrame' has a wrong offset!");
static_assert(offsetof(UGenericNotification_BP_C, FadeOut) == 0x000468, "Member 'UGenericNotification_BP_C::FadeOut' has a wrong offset!");
static_assert(offsetof(UGenericNotification_BP_C, FadeIn) == 0x000470, "Member 'UGenericNotification_BP_C::FadeIn' has a wrong offset!");
static_assert(offsetof(UGenericNotification_BP_C, ContentContainer) == 0x000478, "Member 'UGenericNotification_BP_C::ContentContainer' has a wrong offset!");
static_assert(offsetof(UGenericNotification_BP_C, ContentContainerMat) == 0x000480, "Member 'UGenericNotification_BP_C::ContentContainerMat' has a wrong offset!");

}

