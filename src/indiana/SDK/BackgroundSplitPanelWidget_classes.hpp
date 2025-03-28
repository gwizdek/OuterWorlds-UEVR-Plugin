#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: BackgroundSplitPanelWidget

#include "Basic.hpp"

#include "SlateCore_structs.hpp"
#include "Engine_structs.hpp"
#include "Indiana_classes.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass BackgroundSplitPanelWidget.BackgroundSplitPanelWidget_C
// 0x0258 (0x05B8 - 0x0360)
class UBackgroundSplitPanelWidget_C final : public UBackgroundSplitPanelWidget
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0360(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	class UWidgetAnimation*                       FadeOpacity;                                       // 0x0368(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, RepSkip, NoDestructor, HasGetValueTypeHash)
	class UImage*                                 BorderBottom;                                      // 0x0370(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UImage*                                 BorderInnerBottom;                                 // 0x0378(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UImage*                                 BorderInnerTop;                                    // 0x0380(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UImage*                                 BorderTop;                                         // 0x0388(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UNamedSlot*                             NamedSlot;                                         // 0x0390(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	struct FSlateBrush                            OuterTopBrush;                                     // 0x0398(0x0088)(Edit, BlueprintVisible)
	struct FSlateBrush                            InnerTopBrush;                                     // 0x0420(0x0088)(Edit, BlueprintVisible)
	struct FSlateBrush                            OuterBottomBrush;                                  // 0x04A8(0x0088)(Edit, BlueprintVisible)
	struct FSlateBrush                            InnerBotttomBrush;                                 // 0x0530(0x0088)(Edit, BlueprintVisible)

public:
	void ExecuteUbergraph_BackgroundSplitPanelWidget(int32 EntryPoint);
	void OnInnerBottomTextureLoaded(class UTexture2D* Texture);
	void OnInnerTopTextureLoaded(class UTexture2D* Texture);
	void OnOuterBottomTextureLoaded(class UTexture2D* Texture);
	void OnOuterTopTextureLoaded(class UTexture2D* Texture);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"BackgroundSplitPanelWidget_C">();
	}
	static class UBackgroundSplitPanelWidget_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UBackgroundSplitPanelWidget_C>();
	}
};
static_assert(alignof(UBackgroundSplitPanelWidget_C) == 0x000008, "Wrong alignment on UBackgroundSplitPanelWidget_C");
static_assert(sizeof(UBackgroundSplitPanelWidget_C) == 0x0005B8, "Wrong size on UBackgroundSplitPanelWidget_C");
static_assert(offsetof(UBackgroundSplitPanelWidget_C, UberGraphFrame) == 0x000360, "Member 'UBackgroundSplitPanelWidget_C::UberGraphFrame' has a wrong offset!");
static_assert(offsetof(UBackgroundSplitPanelWidget_C, FadeOpacity) == 0x000368, "Member 'UBackgroundSplitPanelWidget_C::FadeOpacity' has a wrong offset!");
static_assert(offsetof(UBackgroundSplitPanelWidget_C, BorderBottom) == 0x000370, "Member 'UBackgroundSplitPanelWidget_C::BorderBottom' has a wrong offset!");
static_assert(offsetof(UBackgroundSplitPanelWidget_C, BorderInnerBottom) == 0x000378, "Member 'UBackgroundSplitPanelWidget_C::BorderInnerBottom' has a wrong offset!");
static_assert(offsetof(UBackgroundSplitPanelWidget_C, BorderInnerTop) == 0x000380, "Member 'UBackgroundSplitPanelWidget_C::BorderInnerTop' has a wrong offset!");
static_assert(offsetof(UBackgroundSplitPanelWidget_C, BorderTop) == 0x000388, "Member 'UBackgroundSplitPanelWidget_C::BorderTop' has a wrong offset!");
static_assert(offsetof(UBackgroundSplitPanelWidget_C, NamedSlot) == 0x000390, "Member 'UBackgroundSplitPanelWidget_C::NamedSlot' has a wrong offset!");
static_assert(offsetof(UBackgroundSplitPanelWidget_C, OuterTopBrush) == 0x000398, "Member 'UBackgroundSplitPanelWidget_C::OuterTopBrush' has a wrong offset!");
static_assert(offsetof(UBackgroundSplitPanelWidget_C, InnerTopBrush) == 0x000420, "Member 'UBackgroundSplitPanelWidget_C::InnerTopBrush' has a wrong offset!");
static_assert(offsetof(UBackgroundSplitPanelWidget_C, OuterBottomBrush) == 0x0004A8, "Member 'UBackgroundSplitPanelWidget_C::OuterBottomBrush' has a wrong offset!");
static_assert(offsetof(UBackgroundSplitPanelWidget_C, InnerBotttomBrush) == 0x000530, "Member 'UBackgroundSplitPanelWidget_C::InnerBotttomBrush' has a wrong offset!");

}

