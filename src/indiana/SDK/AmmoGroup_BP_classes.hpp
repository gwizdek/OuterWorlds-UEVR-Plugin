#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: AmmoGroup_BP

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "Indiana_classes.hpp"
#include "UMG_structs.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass AmmoGroup_BP.AmmoGroup_BP_C
// 0x0028 (0x0340 - 0x0318)
class UAmmoGroup_BP_C final : public UInventoryWeaponAmmoGroupWidget
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0318(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	class UWidgetAnimation*                       FadeBackground;                                    // 0x0320(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, RepSkip, NoDestructor, HasGetValueTypeHash)
	class UImage*                                 Background;                                        // 0x0328(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UTexture2D*                             BackgroundTexture;                                 // 0x0330(0x0008)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UTexture2D*                             AmmoTexture0;                                      // 0x0338(0x0008)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	void ExecuteUbergraph_AmmoGroup_BP(int32 EntryPoint);
	void OnHighlightChange(bool bHighlight);
	void Construct();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"AmmoGroup_BP_C">();
	}
	static class UAmmoGroup_BP_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UAmmoGroup_BP_C>();
	}
};
static_assert(alignof(UAmmoGroup_BP_C) == 0x000008, "Wrong alignment on UAmmoGroup_BP_C");
static_assert(sizeof(UAmmoGroup_BP_C) == 0x000340, "Wrong size on UAmmoGroup_BP_C");
static_assert(offsetof(UAmmoGroup_BP_C, UberGraphFrame) == 0x000318, "Member 'UAmmoGroup_BP_C::UberGraphFrame' has a wrong offset!");
static_assert(offsetof(UAmmoGroup_BP_C, FadeBackground) == 0x000320, "Member 'UAmmoGroup_BP_C::FadeBackground' has a wrong offset!");
static_assert(offsetof(UAmmoGroup_BP_C, Background) == 0x000328, "Member 'UAmmoGroup_BP_C::Background' has a wrong offset!");
static_assert(offsetof(UAmmoGroup_BP_C, BackgroundTexture) == 0x000330, "Member 'UAmmoGroup_BP_C::BackgroundTexture' has a wrong offset!");
static_assert(offsetof(UAmmoGroup_BP_C, AmmoTexture0) == 0x000338, "Member 'UAmmoGroup_BP_C::AmmoTexture0' has a wrong offset!");

}

