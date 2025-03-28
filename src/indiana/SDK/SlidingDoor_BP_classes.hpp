#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: SlidingDoor_BP

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "MeshMaterialInstance_structs.hpp"
#include "TimelineMeshTransform_structs.hpp"
#include "DoorBase_BP_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass SlidingDoor_BP.SlidingDoor_BP_C
// 0x0060 (0x0588 - 0x0528)
class ASlidingDoor_BP_C : public ADoorBase_BP_C
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame_SlidingDoor_BP_C;                   // 0x0528(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	class UStaticMeshComponent*                   RightDoor;                                         // 0x0530(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UStaticMeshComponent*                   TopDoor;                                           // 0x0538(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UStaticMeshComponent*                   LeftDoor;                                          // 0x0540(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UStaticMeshComponent*                   Frame;                                             // 0x0548(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	float                                         AnimateDoors_Main_250119A74231DCEC009921BED99351C3; // 0x0550(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	ETimelineDirection                            AnimateDoors__Direction_250119A74231DCEC009921BED99351C3; // 0x0554(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_555[0x3];                                      // 0x0555(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	class UTimelineComponent*                     AnimateDoors;                                      // 0x0558(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	TArray<struct FMeshMaterialInstance>          MeshMaterialInstances;                             // 0x0560(0x0010)(Edit, BlueprintVisible, DisableEditOnInstance)
	TArray<struct FTimelineMeshTransform>         MeshTransforms;                                    // 0x0570(0x0010)(Edit, BlueprintVisible, DisableEditOnInstance)
	float                                         TimelineTime;                                      // 0x0580(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	void AnimateDoors__FinishedFunc();
	void AnimateDoors__UpdateFunc();
	void AnimateDoors__NewTrack_0__EventFunc();
	void OnStateChanged();
	void OnAnimateOpen(bool InstantAnimation);
	void OnAnimateClose(bool IgnoreSound_0, bool InstantAnimation);
	void ExecuteUbergraph_SlidingDoor_BP(int32 EntryPoint);
	void UserConstructionScript();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"SlidingDoor_BP_C">();
	}
	static class ASlidingDoor_BP_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<ASlidingDoor_BP_C>();
	}
};
static_assert(alignof(ASlidingDoor_BP_C) == 0x000008, "Wrong alignment on ASlidingDoor_BP_C");
static_assert(sizeof(ASlidingDoor_BP_C) == 0x000588, "Wrong size on ASlidingDoor_BP_C");
static_assert(offsetof(ASlidingDoor_BP_C, UberGraphFrame_SlidingDoor_BP_C) == 0x000528, "Member 'ASlidingDoor_BP_C::UberGraphFrame_SlidingDoor_BP_C' has a wrong offset!");
static_assert(offsetof(ASlidingDoor_BP_C, RightDoor) == 0x000530, "Member 'ASlidingDoor_BP_C::RightDoor' has a wrong offset!");
static_assert(offsetof(ASlidingDoor_BP_C, TopDoor) == 0x000538, "Member 'ASlidingDoor_BP_C::TopDoor' has a wrong offset!");
static_assert(offsetof(ASlidingDoor_BP_C, LeftDoor) == 0x000540, "Member 'ASlidingDoor_BP_C::LeftDoor' has a wrong offset!");
static_assert(offsetof(ASlidingDoor_BP_C, Frame) == 0x000548, "Member 'ASlidingDoor_BP_C::Frame' has a wrong offset!");
static_assert(offsetof(ASlidingDoor_BP_C, AnimateDoors_Main_250119A74231DCEC009921BED99351C3) == 0x000550, "Member 'ASlidingDoor_BP_C::AnimateDoors_Main_250119A74231DCEC009921BED99351C3' has a wrong offset!");
static_assert(offsetof(ASlidingDoor_BP_C, AnimateDoors__Direction_250119A74231DCEC009921BED99351C3) == 0x000554, "Member 'ASlidingDoor_BP_C::AnimateDoors__Direction_250119A74231DCEC009921BED99351C3' has a wrong offset!");
static_assert(offsetof(ASlidingDoor_BP_C, AnimateDoors) == 0x000558, "Member 'ASlidingDoor_BP_C::AnimateDoors' has a wrong offset!");
static_assert(offsetof(ASlidingDoor_BP_C, MeshMaterialInstances) == 0x000560, "Member 'ASlidingDoor_BP_C::MeshMaterialInstances' has a wrong offset!");
static_assert(offsetof(ASlidingDoor_BP_C, MeshTransforms) == 0x000570, "Member 'ASlidingDoor_BP_C::MeshTransforms' has a wrong offset!");
static_assert(offsetof(ASlidingDoor_BP_C, TimelineTime) == 0x000580, "Member 'ASlidingDoor_BP_C::TimelineTime' has a wrong offset!");

}

