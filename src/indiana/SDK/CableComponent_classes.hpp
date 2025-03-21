#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: CableComponent

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "Engine_classes.hpp"
#include "CoreUObject_structs.hpp"


namespace SDK
{

// Class CableComponent.CableActor
// 0x0008 (0x02C0 - 0x02B8)
class ACableActor final : public AActor
{
public:
	class UCableComponent*                        CableComponent;                                    // 0x02B8(0x0008)(Edit, BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, EditConst, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"CableActor">();
	}
	static class ACableActor* GetDefaultObj()
	{
		return GetDefaultObjImpl<ACableActor>();
	}
};
static_assert(alignof(ACableActor) == 0x000008, "Wrong alignment on ACableActor");
static_assert(sizeof(ACableActor) == 0x0002C0, "Wrong size on ACableActor");
static_assert(offsetof(ACableActor, CableComponent) == 0x0002B8, "Member 'ACableActor::CableComponent' has a wrong offset!");

// Class CableComponent.CableComponent
// 0x0090 (0x05B0 - 0x0520)
class UCableComponent final : public UMeshComponent
{
public:
	bool                                          bAttachStart;                                      // 0x0520(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          bAttachEnd;                                        // 0x0521(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_522[0x6];                                      // 0x0522(0x0006)(Fixing Size After Last Property [ Dumper-7 ])
	struct FComponentReference                    AttachEndTo;                                       // 0x0528(0x0028)(Edit, NativeAccessSpecifierPublic)
	class FName                                   AttachEndToSocketName;                             // 0x0550(0x0008)(Edit, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FVector                                EndLocation;                                       // 0x0558(0x000C)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         CableLength;                                       // 0x0564(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	int32                                         NumSegments;                                       // 0x0568(0x0004)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         SubstepTime;                                       // 0x056C(0x0004)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData, NoDestructor, AdvancedDisplay, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	int32                                         SolverIterations;                                  // 0x0570(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          bEnableStiffness;                                  // 0x0574(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, AdvancedDisplay, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          bUseSubstepping;                                   // 0x0575(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, AdvancedDisplay, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          bSkipCableUpdateWhenNotVisible;                    // 0x0576(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, AdvancedDisplay, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          bSkipCableUpdateWhenNotOwnerRecentlyRendered;      // 0x0577(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, AdvancedDisplay, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          bEnableCollision;                                  // 0x0578(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, AdvancedDisplay, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_579[0x3];                                      // 0x0579(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         CollisionFriction;                                 // 0x057C(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, AdvancedDisplay, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FVector                                CableForce;                                        // 0x0580(0x000C)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         CableGravityScale;                                 // 0x058C(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         CableWidth;                                        // 0x0590(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	int32                                         NumSides;                                          // 0x0594(0x0004)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         TileMaterial;                                      // 0x0598(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_59C[0x14];                                     // 0x059C(0x0014)(Fixing Struct Size After Last Property [ Dumper-7 ])

public:
	void SetAttachEndTo(class AActor* Actor, class FName ComponentProperty, class FName SocketName);
	void SetAttachEndToComponent(class USceneComponent* Component, class FName SocketName);

	class AActor* GetAttachedActor() const;
	class USceneComponent* GetAttachedComponent() const;
	void GetCableParticleLocations(TArray<struct FVector>* Locations) const;

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"CableComponent">();
	}
	static class UCableComponent* GetDefaultObj()
	{
		return GetDefaultObjImpl<UCableComponent>();
	}
};
static_assert(alignof(UCableComponent) == 0x000010, "Wrong alignment on UCableComponent");
static_assert(sizeof(UCableComponent) == 0x0005B0, "Wrong size on UCableComponent");
static_assert(offsetof(UCableComponent, bAttachStart) == 0x000520, "Member 'UCableComponent::bAttachStart' has a wrong offset!");
static_assert(offsetof(UCableComponent, bAttachEnd) == 0x000521, "Member 'UCableComponent::bAttachEnd' has a wrong offset!");
static_assert(offsetof(UCableComponent, AttachEndTo) == 0x000528, "Member 'UCableComponent::AttachEndTo' has a wrong offset!");
static_assert(offsetof(UCableComponent, AttachEndToSocketName) == 0x000550, "Member 'UCableComponent::AttachEndToSocketName' has a wrong offset!");
static_assert(offsetof(UCableComponent, EndLocation) == 0x000558, "Member 'UCableComponent::EndLocation' has a wrong offset!");
static_assert(offsetof(UCableComponent, CableLength) == 0x000564, "Member 'UCableComponent::CableLength' has a wrong offset!");
static_assert(offsetof(UCableComponent, NumSegments) == 0x000568, "Member 'UCableComponent::NumSegments' has a wrong offset!");
static_assert(offsetof(UCableComponent, SubstepTime) == 0x00056C, "Member 'UCableComponent::SubstepTime' has a wrong offset!");
static_assert(offsetof(UCableComponent, SolverIterations) == 0x000570, "Member 'UCableComponent::SolverIterations' has a wrong offset!");
static_assert(offsetof(UCableComponent, bEnableStiffness) == 0x000574, "Member 'UCableComponent::bEnableStiffness' has a wrong offset!");
static_assert(offsetof(UCableComponent, bUseSubstepping) == 0x000575, "Member 'UCableComponent::bUseSubstepping' has a wrong offset!");
static_assert(offsetof(UCableComponent, bSkipCableUpdateWhenNotVisible) == 0x000576, "Member 'UCableComponent::bSkipCableUpdateWhenNotVisible' has a wrong offset!");
static_assert(offsetof(UCableComponent, bSkipCableUpdateWhenNotOwnerRecentlyRendered) == 0x000577, "Member 'UCableComponent::bSkipCableUpdateWhenNotOwnerRecentlyRendered' has a wrong offset!");
static_assert(offsetof(UCableComponent, bEnableCollision) == 0x000578, "Member 'UCableComponent::bEnableCollision' has a wrong offset!");
static_assert(offsetof(UCableComponent, CollisionFriction) == 0x00057C, "Member 'UCableComponent::CollisionFriction' has a wrong offset!");
static_assert(offsetof(UCableComponent, CableForce) == 0x000580, "Member 'UCableComponent::CableForce' has a wrong offset!");
static_assert(offsetof(UCableComponent, CableGravityScale) == 0x00058C, "Member 'UCableComponent::CableGravityScale' has a wrong offset!");
static_assert(offsetof(UCableComponent, CableWidth) == 0x000590, "Member 'UCableComponent::CableWidth' has a wrong offset!");
static_assert(offsetof(UCableComponent, NumSides) == 0x000594, "Member 'UCableComponent::NumSides' has a wrong offset!");
static_assert(offsetof(UCableComponent, TileMaterial) == 0x000598, "Member 'UCableComponent::TileMaterial' has a wrong offset!");

}

