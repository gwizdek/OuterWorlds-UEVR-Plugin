#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: MRMesh

#include "Basic.hpp"

#include "MRMesh_structs.hpp"
#include "CoreUObject_structs.hpp"
#include "CoreUObject_classes.hpp"
#include "Engine_classes.hpp"


namespace SDK
{

// Class MRMesh.MeshReconstructorBase
// 0x0000 (0x0030 - 0x0030)
class UMeshReconstructorBase final : public UObject
{
public:
	void ConnectMRMesh(class UMRMeshComponent* Mesh);
	void DisconnectMRMesh();
	void PauseReconstruction();
	void StartReconstruction();
	void StopReconstruction();

	bool IsReconstructionPaused() const;
	bool IsReconstructionStarted() const;

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"MeshReconstructorBase">();
	}
	static class UMeshReconstructorBase* GetDefaultObj()
	{
		return GetDefaultObjImpl<UMeshReconstructorBase>();
	}
};
static_assert(alignof(UMeshReconstructorBase) == 0x000008, "Wrong alignment on UMeshReconstructorBase");
static_assert(sizeof(UMeshReconstructorBase) == 0x000030, "Wrong size on UMeshReconstructorBase");

// Class MRMesh.MockDataMeshTrackerComponent
// 0x0070 (0x02E0 - 0x0270)
class UMockDataMeshTrackerComponent final : public USceneComponent
{
public:
	FMulticastInlineDelegateProperty_             OnMeshTrackerUpdated;                              // 0x0268(0x0010)(ZeroConstructor, InstancedReference, BlueprintAssignable, NativeAccessSpecifierPublic)
	bool                                          ScanWorld;                                         // 0x0278(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          RequestNormals;                                    // 0x0279(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          RequestVertexConfidence;                           // 0x027A(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	EMeshTrackerVertexColorMode                   VertexColorMode;                                   // 0x027B(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_27C[0x4];                                      // 0x027C(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	TArray<struct FColor>                         BlockVertexColors;                                 // 0x0280(0x0010)(Edit, BlueprintVisible, ZeroConstructor, NativeAccessSpecifierPublic)
	struct FLinearColor                           VertexColorFromConfidenceZero;                     // 0x0290(0x0010)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FLinearColor                           VertexColorFromConfidenceOne;                      // 0x02A0(0x0010)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         UpdateInterval;                                    // 0x02B0(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_2B4[0x4];                                      // 0x02B4(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class UMRMeshComponent*                       MRMesh;                                            // 0x02B8(0x0008)(ExportObject, ZeroConstructor, Transient, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_2C0[0x20];                                     // 0x02C0(0x0020)(Fixing Struct Size After Last Property [ Dumper-7 ])

public:
	void ConnectMRMesh(class UMRMeshComponent* InMRMeshPtr);
	void DisconnectMRMesh(class UMRMeshComponent* InMRMeshPtr);
	void OnMockDataMeshTrackerUpdated__DelegateSignature(int32 Index_0, const TArray<struct FVector>& Vertices, const TArray<int32>& Triangles, const TArray<struct FVector>& Normals, const TArray<float>& Confidence);

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"MockDataMeshTrackerComponent">();
	}
	static class UMockDataMeshTrackerComponent* GetDefaultObj()
	{
		return GetDefaultObjImpl<UMockDataMeshTrackerComponent>();
	}
};
static_assert(alignof(UMockDataMeshTrackerComponent) == 0x000010, "Wrong alignment on UMockDataMeshTrackerComponent");
static_assert(sizeof(UMockDataMeshTrackerComponent) == 0x0002E0, "Wrong size on UMockDataMeshTrackerComponent");
static_assert(offsetof(UMockDataMeshTrackerComponent, OnMeshTrackerUpdated) == 0x000268, "Member 'UMockDataMeshTrackerComponent::OnMeshTrackerUpdated' has a wrong offset!");
static_assert(offsetof(UMockDataMeshTrackerComponent, ScanWorld) == 0x000278, "Member 'UMockDataMeshTrackerComponent::ScanWorld' has a wrong offset!");
static_assert(offsetof(UMockDataMeshTrackerComponent, RequestNormals) == 0x000279, "Member 'UMockDataMeshTrackerComponent::RequestNormals' has a wrong offset!");
static_assert(offsetof(UMockDataMeshTrackerComponent, RequestVertexConfidence) == 0x00027A, "Member 'UMockDataMeshTrackerComponent::RequestVertexConfidence' has a wrong offset!");
static_assert(offsetof(UMockDataMeshTrackerComponent, VertexColorMode) == 0x00027B, "Member 'UMockDataMeshTrackerComponent::VertexColorMode' has a wrong offset!");
static_assert(offsetof(UMockDataMeshTrackerComponent, BlockVertexColors) == 0x000280, "Member 'UMockDataMeshTrackerComponent::BlockVertexColors' has a wrong offset!");
static_assert(offsetof(UMockDataMeshTrackerComponent, VertexColorFromConfidenceZero) == 0x000290, "Member 'UMockDataMeshTrackerComponent::VertexColorFromConfidenceZero' has a wrong offset!");
static_assert(offsetof(UMockDataMeshTrackerComponent, VertexColorFromConfidenceOne) == 0x0002A0, "Member 'UMockDataMeshTrackerComponent::VertexColorFromConfidenceOne' has a wrong offset!");
static_assert(offsetof(UMockDataMeshTrackerComponent, UpdateInterval) == 0x0002B0, "Member 'UMockDataMeshTrackerComponent::UpdateInterval' has a wrong offset!");
static_assert(offsetof(UMockDataMeshTrackerComponent, MRMesh) == 0x0002B8, "Member 'UMockDataMeshTrackerComponent::MRMesh' has a wrong offset!");

// Class MRMesh.MRMeshComponent
// 0x00B0 (0x05B0 - 0x0500)
class UMRMeshComponent final : public UPrimitiveComponent
{
public:
	uint8                                         Pad_4F8[0x10];                                     // 0x04F8(0x0010)(Fixing Size After Last Property [ Dumper-7 ])
	class UMaterialInterface*                     Material;                                          // 0x0508(0x0008)(Edit, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPrivate)
	class UMaterialInterface*                     WireframeMaterial;                                 // 0x0510(0x0008)(Edit, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPrivate)
	bool                                          bCreateMeshProxySections;                          // 0x0518(0x0001)(Edit, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPrivate)
	bool                                          bUpdateNavMeshOnMeshUpdate;                        // 0x0519(0x0001)(Edit, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPrivate)
	bool                                          bNeverCreateCollisionMesh;                         // 0x051A(0x0001)(Edit, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPrivate)
	uint8                                         Pad_51B[0x5];                                      // 0x051B(0x0005)(Fixing Size After Last Property [ Dumper-7 ])
	class UBodySetup*                             CachedBodySetup;                                   // 0x0520(0x0008)(ZeroConstructor, Transient, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPrivate)
	TArray<class UBodySetup*>                     BodySetups;                                        // 0x0528(0x0010)(ZeroConstructor, Transient, NativeAccessSpecifierPrivate)
	uint8                                         Pad_538[0x78];                                     // 0x0538(0x0078)(Fixing Struct Size After Last Property [ Dumper-7 ])

public:
	void Clear();
	void ForceNavMeshUpdate();
	void SetEnableMeshOcclusion(bool bEnable);
	void SetUseWireframe(bool bUseWireframe);
	void SetWireframeColor(const struct FLinearColor& InColor);
	void SetWireframeMaterial(class UMaterialInterface* InMaterial);

	bool GetEnableMeshOcclusion() const;
	bool GetUseWireframe() const;
	const struct FLinearColor GetWireframeColor() const;
	bool IsConnected() const;

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"MRMeshComponent">();
	}
	static class UMRMeshComponent* GetDefaultObj()
	{
		return GetDefaultObjImpl<UMRMeshComponent>();
	}
};
static_assert(alignof(UMRMeshComponent) == 0x000010, "Wrong alignment on UMRMeshComponent");
static_assert(sizeof(UMRMeshComponent) == 0x0005B0, "Wrong size on UMRMeshComponent");
static_assert(offsetof(UMRMeshComponent, Material) == 0x000508, "Member 'UMRMeshComponent::Material' has a wrong offset!");
static_assert(offsetof(UMRMeshComponent, WireframeMaterial) == 0x000510, "Member 'UMRMeshComponent::WireframeMaterial' has a wrong offset!");
static_assert(offsetof(UMRMeshComponent, bCreateMeshProxySections) == 0x000518, "Member 'UMRMeshComponent::bCreateMeshProxySections' has a wrong offset!");
static_assert(offsetof(UMRMeshComponent, bUpdateNavMeshOnMeshUpdate) == 0x000519, "Member 'UMRMeshComponent::bUpdateNavMeshOnMeshUpdate' has a wrong offset!");
static_assert(offsetof(UMRMeshComponent, bNeverCreateCollisionMesh) == 0x00051A, "Member 'UMRMeshComponent::bNeverCreateCollisionMesh' has a wrong offset!");
static_assert(offsetof(UMRMeshComponent, CachedBodySetup) == 0x000520, "Member 'UMRMeshComponent::CachedBodySetup' has a wrong offset!");
static_assert(offsetof(UMRMeshComponent, BodySetups) == 0x000528, "Member 'UMRMeshComponent::BodySetups' has a wrong offset!");

}

