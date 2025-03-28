#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: WeaponSelect_BP

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "Indiana_classes.hpp"
#include "UMG_structs.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass WeaponSelect_BP.WeaponSelect_BP_C
// 0x00B8 (0x0548 - 0x0490)
class UWeaponSelect_BP_C final : public UWeaponSelectWidget
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0490(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	class UWidgetAnimation*                       FadeOutAmmoBackground;                             // 0x0498(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, RepSkip, NoDestructor, HasGetValueTypeHash)
	class UWidgetAnimation*                       FadeOutWeaponBackground;                           // 0x04A0(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, RepSkip, NoDestructor, HasGetValueTypeHash)
	class UWidgetAnimation*                       IntroOutro;                                        // 0x04A8(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, RepSkip, NoDestructor, HasGetValueTypeHash)
	class UImage*                                 AmmoBackground;                                    // 0x04B0(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UImage*                                 Background;                                        // 0x04B8(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UBorder*                                Border_0;                                          // 0x04C0(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UImage*                                 BulbOff;                                           // 0x04C8(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UImage*                                 BulbOn;                                            // 0x04D0(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UImage*                                 InnerCircle;                                       // 0x04D8(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UImage*                                 InnerCircle2;                                      // 0x04E0(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UInvalidationBox*                       InvalidationBox_0;                                 // 0x04E8(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UVerticalBox*                           OrientatorVerticalBox;                             // 0x04F0(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UImage*                                 WeaponBackground;                                  // 0x04F8(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UImage*                                 WeaponHighlight;                                   // 0x0500(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	TArray<class UWeaponRadialBackgroundSection_BP_C*> BackgroundSections;                                // 0x0508(0x0010)(Edit, BlueprintVisible, DisableEditOnInstance, ContainsInstancedReference)
	TArray<class UWeaponRadialBackgroundSection_BP_C*> WeaponBackgroundSections;                          // 0x0518(0x0010)(Edit, BlueprintVisible, DisableEditOnInstance, ContainsInstancedReference)
	float                                         BackgroundFadeSpeed;                               // 0x0528(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_52C[0x4];                                      // 0x052C(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	TArray<class UWeaponRadialBackgroundSection_BP_C*> AmmoBackgroundSections;                            // 0x0530(0x0010)(Edit, BlueprintVisible, DisableEditOnInstance, ContainsInstancedReference)
	float                                         OrientatorClamped;                                 // 0x0540(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	void ExecuteUbergraph_WeaponSelect_BP(int32 EntryPoint);
	void BndEvt__Radial_K2Node_ComponentBoundEvent_1_SectionSelectedSignature__DelegateSignature(int32 Index_0);
	void OnSectionSelected(int32 Index_0);
	void OnSetAmmoEquippedDelegate_Event_0(bool bEquipped, int32 AmmoIndex);
	void OnSetWeaponEquippedDelegate_Event_0(int32 WeaponIndex);
	void Tick(const struct FGeometry& MyGeometry, float InDeltaTime);
	void Construct();
	bool OnIntro(const TDelegate<void()>& AnimationCompleteCallback);
	void GetBackgroundSection(class UObject* Object, class UWeaponRadialBackgroundSection_BP_C** AsHUDRadial_Section_BP);
	void UpdateBackgroundVisibility(const TArray<class UWeaponRadialBackgroundSection_BP_C*>& TargetArray, int32 IndexToTest);
	void SetBackgroundVisibility(TArray<class UWeaponRadialBackgroundSection_BP_C*>& Array, int32 Index_0, bool Enabled);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"WeaponSelect_BP_C">();
	}
	static class UWeaponSelect_BP_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UWeaponSelect_BP_C>();
	}
};
static_assert(alignof(UWeaponSelect_BP_C) == 0x000008, "Wrong alignment on UWeaponSelect_BP_C");
static_assert(sizeof(UWeaponSelect_BP_C) == 0x000548, "Wrong size on UWeaponSelect_BP_C");
static_assert(offsetof(UWeaponSelect_BP_C, UberGraphFrame) == 0x000490, "Member 'UWeaponSelect_BP_C::UberGraphFrame' has a wrong offset!");
static_assert(offsetof(UWeaponSelect_BP_C, FadeOutAmmoBackground) == 0x000498, "Member 'UWeaponSelect_BP_C::FadeOutAmmoBackground' has a wrong offset!");
static_assert(offsetof(UWeaponSelect_BP_C, FadeOutWeaponBackground) == 0x0004A0, "Member 'UWeaponSelect_BP_C::FadeOutWeaponBackground' has a wrong offset!");
static_assert(offsetof(UWeaponSelect_BP_C, IntroOutro) == 0x0004A8, "Member 'UWeaponSelect_BP_C::IntroOutro' has a wrong offset!");
static_assert(offsetof(UWeaponSelect_BP_C, AmmoBackground) == 0x0004B0, "Member 'UWeaponSelect_BP_C::AmmoBackground' has a wrong offset!");
static_assert(offsetof(UWeaponSelect_BP_C, Background) == 0x0004B8, "Member 'UWeaponSelect_BP_C::Background' has a wrong offset!");
static_assert(offsetof(UWeaponSelect_BP_C, Border_0) == 0x0004C0, "Member 'UWeaponSelect_BP_C::Border_0' has a wrong offset!");
static_assert(offsetof(UWeaponSelect_BP_C, BulbOff) == 0x0004C8, "Member 'UWeaponSelect_BP_C::BulbOff' has a wrong offset!");
static_assert(offsetof(UWeaponSelect_BP_C, BulbOn) == 0x0004D0, "Member 'UWeaponSelect_BP_C::BulbOn' has a wrong offset!");
static_assert(offsetof(UWeaponSelect_BP_C, InnerCircle) == 0x0004D8, "Member 'UWeaponSelect_BP_C::InnerCircle' has a wrong offset!");
static_assert(offsetof(UWeaponSelect_BP_C, InnerCircle2) == 0x0004E0, "Member 'UWeaponSelect_BP_C::InnerCircle2' has a wrong offset!");
static_assert(offsetof(UWeaponSelect_BP_C, InvalidationBox_0) == 0x0004E8, "Member 'UWeaponSelect_BP_C::InvalidationBox_0' has a wrong offset!");
static_assert(offsetof(UWeaponSelect_BP_C, OrientatorVerticalBox) == 0x0004F0, "Member 'UWeaponSelect_BP_C::OrientatorVerticalBox' has a wrong offset!");
static_assert(offsetof(UWeaponSelect_BP_C, WeaponBackground) == 0x0004F8, "Member 'UWeaponSelect_BP_C::WeaponBackground' has a wrong offset!");
static_assert(offsetof(UWeaponSelect_BP_C, WeaponHighlight) == 0x000500, "Member 'UWeaponSelect_BP_C::WeaponHighlight' has a wrong offset!");
static_assert(offsetof(UWeaponSelect_BP_C, BackgroundSections) == 0x000508, "Member 'UWeaponSelect_BP_C::BackgroundSections' has a wrong offset!");
static_assert(offsetof(UWeaponSelect_BP_C, WeaponBackgroundSections) == 0x000518, "Member 'UWeaponSelect_BP_C::WeaponBackgroundSections' has a wrong offset!");
static_assert(offsetof(UWeaponSelect_BP_C, BackgroundFadeSpeed) == 0x000528, "Member 'UWeaponSelect_BP_C::BackgroundFadeSpeed' has a wrong offset!");
static_assert(offsetof(UWeaponSelect_BP_C, AmmoBackgroundSections) == 0x000530, "Member 'UWeaponSelect_BP_C::AmmoBackgroundSections' has a wrong offset!");
static_assert(offsetof(UWeaponSelect_BP_C, OrientatorClamped) == 0x000540, "Member 'UWeaponSelect_BP_C::OrientatorClamped' has a wrong offset!");

}

