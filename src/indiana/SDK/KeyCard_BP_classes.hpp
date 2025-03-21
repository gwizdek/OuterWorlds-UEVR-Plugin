#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: KeyCard_BP

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "Indiana_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass KeyCard_BP.KeyCard_BP_C
// 0x0070 (0x0378 - 0x0308)
class AKeyCard_BP_C : public AInteractableActor
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0308(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	class UPointLightComponent*                   PointLight;                                        // 0x0310(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UTextRenderComponent*                   TextRender;                                        // 0x0318(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UStaticMeshComponent*                   Gear;                                              // 0x0320(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UStaticMeshComponent*                   Frame;                                             // 0x0328(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	float                                         GearAnimation_Alpha_22A0BCBD46B2A29FA4BCA3912FD807E8; // 0x0330(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	ETimelineDirection                            GearAnimation__Direction_22A0BCBD46B2A29FA4BCA3912FD807E8; // 0x0334(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_335[0x3];                                      // 0x0335(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	class UTimelineComponent*                     GearAnimation;                                     // 0x0338(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         Timeline_0_Jiggle_Alpha_73717ADD49FD5B9C6C2F889D6D5F9070; // 0x0340(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	ETimelineDirection                            Timeline_0__Direction_73717ADD49FD5B9C6C2F889D6D5F9070; // 0x0344(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_345[0x3];                                      // 0x0345(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	class UTimelineComponent*                     Timeline_0;                                        // 0x0348(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UMaterialInstanceDynamic*               LockedLightMaterial;                               // 0x0350(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UMaterialInstanceDynamic*               UnlockedLightMaterial;                             // 0x0358(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UOCLComponent*                          OCL;                                               // 0x0360(0x0008)(Edit, BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UMaterialInstanceDynamic*               TopLightMaterial;                                  // 0x0368(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         PointLightIntensity;                               // 0x0370(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          Container_Empty;                                   // 0x0374(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)

public:
	void Update(bool IsEmpty, bool* Unused);
	void Setup(class UOCLComponent* OCL_0, bool* Unused);
	void Set_ContainerState(bool Container_Empty_Value);
	void ApplyLights(bool IsEmpty);
	void UserConstructionScript();
	void GearAnimation__FinishedFunc();
	void GearAnimation__UpdateFunc();
	void Timeline_0__FinishedFunc();
	void Timeline_0__UpdateFunc();
	void BindEvents(class UOCLComponent* OCL_0);
	void OnOCLLockpickStart_Event_0(class AActor* Initiator, float LockpickSeconds, int32 LockpickNumResources);
	void OnOCLLockpickInterrupted_Event_0(class AActor* Initiator);
	void OnOCLLockpickSuccess_Event_0(class AActor* Initiator);
	void OnOCLAnimateOpen_Event_0(class AActor* Initiator, bool InFrontOfDoor, bool IgnoreSound, bool InstantAnimation);
	void OnOCLAnimateClose_Event_0(class AActor* Initiator, bool IgnoreSound, bool InstantAnimation);
	void ReceiveBeginPlay();
	void ExecuteUbergraph_KeyCard_BP(int32 EntryPoint);

	bool CanInteract(class AIndianaCharacter* Initiator, const struct FInteractPayload& Payload) const;

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"KeyCard_BP_C">();
	}
	static class AKeyCard_BP_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<AKeyCard_BP_C>();
	}
};
static_assert(alignof(AKeyCard_BP_C) == 0x000008, "Wrong alignment on AKeyCard_BP_C");
static_assert(sizeof(AKeyCard_BP_C) == 0x000378, "Wrong size on AKeyCard_BP_C");
static_assert(offsetof(AKeyCard_BP_C, UberGraphFrame) == 0x000308, "Member 'AKeyCard_BP_C::UberGraphFrame' has a wrong offset!");
static_assert(offsetof(AKeyCard_BP_C, PointLight) == 0x000310, "Member 'AKeyCard_BP_C::PointLight' has a wrong offset!");
static_assert(offsetof(AKeyCard_BP_C, TextRender) == 0x000318, "Member 'AKeyCard_BP_C::TextRender' has a wrong offset!");
static_assert(offsetof(AKeyCard_BP_C, Gear) == 0x000320, "Member 'AKeyCard_BP_C::Gear' has a wrong offset!");
static_assert(offsetof(AKeyCard_BP_C, Frame) == 0x000328, "Member 'AKeyCard_BP_C::Frame' has a wrong offset!");
static_assert(offsetof(AKeyCard_BP_C, GearAnimation_Alpha_22A0BCBD46B2A29FA4BCA3912FD807E8) == 0x000330, "Member 'AKeyCard_BP_C::GearAnimation_Alpha_22A0BCBD46B2A29FA4BCA3912FD807E8' has a wrong offset!");
static_assert(offsetof(AKeyCard_BP_C, GearAnimation__Direction_22A0BCBD46B2A29FA4BCA3912FD807E8) == 0x000334, "Member 'AKeyCard_BP_C::GearAnimation__Direction_22A0BCBD46B2A29FA4BCA3912FD807E8' has a wrong offset!");
static_assert(offsetof(AKeyCard_BP_C, GearAnimation) == 0x000338, "Member 'AKeyCard_BP_C::GearAnimation' has a wrong offset!");
static_assert(offsetof(AKeyCard_BP_C, Timeline_0_Jiggle_Alpha_73717ADD49FD5B9C6C2F889D6D5F9070) == 0x000340, "Member 'AKeyCard_BP_C::Timeline_0_Jiggle_Alpha_73717ADD49FD5B9C6C2F889D6D5F9070' has a wrong offset!");
static_assert(offsetof(AKeyCard_BP_C, Timeline_0__Direction_73717ADD49FD5B9C6C2F889D6D5F9070) == 0x000344, "Member 'AKeyCard_BP_C::Timeline_0__Direction_73717ADD49FD5B9C6C2F889D6D5F9070' has a wrong offset!");
static_assert(offsetof(AKeyCard_BP_C, Timeline_0) == 0x000348, "Member 'AKeyCard_BP_C::Timeline_0' has a wrong offset!");
static_assert(offsetof(AKeyCard_BP_C, LockedLightMaterial) == 0x000350, "Member 'AKeyCard_BP_C::LockedLightMaterial' has a wrong offset!");
static_assert(offsetof(AKeyCard_BP_C, UnlockedLightMaterial) == 0x000358, "Member 'AKeyCard_BP_C::UnlockedLightMaterial' has a wrong offset!");
static_assert(offsetof(AKeyCard_BP_C, OCL) == 0x000360, "Member 'AKeyCard_BP_C::OCL' has a wrong offset!");
static_assert(offsetof(AKeyCard_BP_C, TopLightMaterial) == 0x000368, "Member 'AKeyCard_BP_C::TopLightMaterial' has a wrong offset!");
static_assert(offsetof(AKeyCard_BP_C, PointLightIntensity) == 0x000370, "Member 'AKeyCard_BP_C::PointLightIntensity' has a wrong offset!");
static_assert(offsetof(AKeyCard_BP_C, Container_Empty) == 0x000374, "Member 'AKeyCard_BP_C::Container_Empty' has a wrong offset!");

}

