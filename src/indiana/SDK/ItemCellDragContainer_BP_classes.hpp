#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: ItemCellDragContainer_BP

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "Indiana_classes.hpp"
#include "UMG_structs.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass ItemCellDragContainer_BP.ItemCellDragContainer_BP_C
// 0x0030 (0x02E8 - 0x02B8)
class UItemCellDragContainer_BP_C final : public UDragContainerWidget
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x02B8(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	class UWidgetAnimation*                       Drop;                                              // 0x02C0(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, RepSkip, NoDestructor, HasGetValueTypeHash)
	class UWidgetAnimation*                       Flash;                                             // 0x02C8(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, RepSkip, NoDestructor, HasGetValueTypeHash)
	class UBorder*                                DropBorder;                                        // 0x02D0(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UBorder*                                FlashBorder;                                       // 0x02D8(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UBorder*                                PendingDropBorder;                                 // 0x02E0(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)

public:
	void ExecuteUbergraph_ItemCellDragContainer_BP(int32 EntryPoint);
	void OnDragGroupDrop(class UIndianaDragDropOperation* Operation);
	void OnDragGroupCancelled(class UIndianaDragDropOperation* Operation);
	void OnDragConfirmDrop(class UIndianaDragDropOperation* Operation);
	void OnDragGroupStarted(class UIndianaDragDropOperation* Operation);
	void OnDragCancelled(const struct FPointerEvent& PointerEvent, class UDragDropOperation* Operation);
	void OnDragLeave(const struct FPointerEvent& PointerEvent, class UDragDropOperation* Operation);
	void OnDragEnter(const struct FGeometry& MyGeometry, const struct FPointerEvent& PointerEvent, class UDragDropOperation* Operation);
	struct FEventReply OnPreviewMouseButtonDown(const struct FGeometry& MyGeometry, const struct FPointerEvent& MouseEvent);
	void SetPendingDropAnimationEnabled(bool Enabled);
	void StopAnimations();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"ItemCellDragContainer_BP_C">();
	}
	static class UItemCellDragContainer_BP_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UItemCellDragContainer_BP_C>();
	}
};
static_assert(alignof(UItemCellDragContainer_BP_C) == 0x000008, "Wrong alignment on UItemCellDragContainer_BP_C");
static_assert(sizeof(UItemCellDragContainer_BP_C) == 0x0002E8, "Wrong size on UItemCellDragContainer_BP_C");
static_assert(offsetof(UItemCellDragContainer_BP_C, UberGraphFrame) == 0x0002B8, "Member 'UItemCellDragContainer_BP_C::UberGraphFrame' has a wrong offset!");
static_assert(offsetof(UItemCellDragContainer_BP_C, Drop) == 0x0002C0, "Member 'UItemCellDragContainer_BP_C::Drop' has a wrong offset!");
static_assert(offsetof(UItemCellDragContainer_BP_C, Flash) == 0x0002C8, "Member 'UItemCellDragContainer_BP_C::Flash' has a wrong offset!");
static_assert(offsetof(UItemCellDragContainer_BP_C, DropBorder) == 0x0002D0, "Member 'UItemCellDragContainer_BP_C::DropBorder' has a wrong offset!");
static_assert(offsetof(UItemCellDragContainer_BP_C, FlashBorder) == 0x0002D8, "Member 'UItemCellDragContainer_BP_C::FlashBorder' has a wrong offset!");
static_assert(offsetof(UItemCellDragContainer_BP_C, PendingDropBorder) == 0x0002E0, "Member 'UItemCellDragContainer_BP_C::PendingDropBorder' has a wrong offset!");

}

