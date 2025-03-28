#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: ItemModding_BP

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "Indiana_classes.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass ItemModding_BP.ItemModding_BP_C
// 0x0068 (0x0720 - 0x06B8)
class UItemModding_BP_C final : public UItemModdingWidget
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x06B8(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	class UWidgetAnimation*                       FadeOut;                                           // 0x06C0(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, RepSkip, NoDestructor, HasGetValueTypeHash)
	class UInputLabel_BP_C*                       ActionInputLabelModify;                            // 0x06C8(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UBackground1_BP_C*                      Background;                                        // 0x06D0(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UTextBlockBase*                         EquipmentDescriptionTextBlock;                     // 0x06D8(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UImage*                                 IconImage;                                         // 0x06E0(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UImage*                                 Image_0;                                           // 0x06E8(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UTextBlockBase*                         ModificationTitleTextBlock;                        // 0x06F0(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UPageAnchor1_BP_C*                      PageAnchorLeft;                                    // 0x06F8(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UPageAnchor2_BP_C*                      PageAnchorRight;                                   // 0x0700(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UImage*                                 Smoke;                                             // 0x0708(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UImage*                                 Smoke_Behind;                                      // 0x0710(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class USurvivalBarGroupWidget_BP_C*           SurvivalBar;                                       // 0x0718(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)

public:
	void ExecuteUbergraph_ItemModding_BP(int32 EntryPoint);
	void ZoomToggled_1();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"ItemModding_BP_C">();
	}
	static class UItemModding_BP_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UItemModding_BP_C>();
	}
};
static_assert(alignof(UItemModding_BP_C) == 0x000008, "Wrong alignment on UItemModding_BP_C");
static_assert(sizeof(UItemModding_BP_C) == 0x000720, "Wrong size on UItemModding_BP_C");
static_assert(offsetof(UItemModding_BP_C, UberGraphFrame) == 0x0006B8, "Member 'UItemModding_BP_C::UberGraphFrame' has a wrong offset!");
static_assert(offsetof(UItemModding_BP_C, FadeOut) == 0x0006C0, "Member 'UItemModding_BP_C::FadeOut' has a wrong offset!");
static_assert(offsetof(UItemModding_BP_C, ActionInputLabelModify) == 0x0006C8, "Member 'UItemModding_BP_C::ActionInputLabelModify' has a wrong offset!");
static_assert(offsetof(UItemModding_BP_C, Background) == 0x0006D0, "Member 'UItemModding_BP_C::Background' has a wrong offset!");
static_assert(offsetof(UItemModding_BP_C, EquipmentDescriptionTextBlock) == 0x0006D8, "Member 'UItemModding_BP_C::EquipmentDescriptionTextBlock' has a wrong offset!");
static_assert(offsetof(UItemModding_BP_C, IconImage) == 0x0006E0, "Member 'UItemModding_BP_C::IconImage' has a wrong offset!");
static_assert(offsetof(UItemModding_BP_C, Image_0) == 0x0006E8, "Member 'UItemModding_BP_C::Image_0' has a wrong offset!");
static_assert(offsetof(UItemModding_BP_C, ModificationTitleTextBlock) == 0x0006F0, "Member 'UItemModding_BP_C::ModificationTitleTextBlock' has a wrong offset!");
static_assert(offsetof(UItemModding_BP_C, PageAnchorLeft) == 0x0006F8, "Member 'UItemModding_BP_C::PageAnchorLeft' has a wrong offset!");
static_assert(offsetof(UItemModding_BP_C, PageAnchorRight) == 0x000700, "Member 'UItemModding_BP_C::PageAnchorRight' has a wrong offset!");
static_assert(offsetof(UItemModding_BP_C, Smoke) == 0x000708, "Member 'UItemModding_BP_C::Smoke' has a wrong offset!");
static_assert(offsetof(UItemModding_BP_C, Smoke_Behind) == 0x000710, "Member 'UItemModding_BP_C::Smoke_Behind' has a wrong offset!");
static_assert(offsetof(UItemModding_BP_C, SurvivalBar) == 0x000718, "Member 'UItemModding_BP_C::SurvivalBar' has a wrong offset!");

}

