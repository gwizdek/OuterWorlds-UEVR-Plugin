#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: RagdollCharacterDeath

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "BaseCharacterDeath_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass RagdollCharacterDeath.RagdollCharacterDeath_C
// 0x0018 (0x0170 - 0x0158)
class URagdollCharacterDeath_C final : public UBaseCharacterDeath_C
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0158(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	class UStaticMesh*                            LootPile;                                          // 0x0160(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UMaterialInterface*                     LootPileMaterial;                                  // 0x0168(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	void ExecuteUbergraph_RagdollCharacterDeath(int32 EntryPoint);
	void ExecuteOnReload(class UCharacterDeathComponent* InDeathComponent);
	void Execute(class UCharacterDeathComponent* InDeathComponent);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"RagdollCharacterDeath_C">();
	}
	static class URagdollCharacterDeath_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<URagdollCharacterDeath_C>();
	}
};
static_assert(alignof(URagdollCharacterDeath_C) == 0x000008, "Wrong alignment on URagdollCharacterDeath_C");
static_assert(sizeof(URagdollCharacterDeath_C) == 0x000170, "Wrong size on URagdollCharacterDeath_C");
static_assert(offsetof(URagdollCharacterDeath_C, UberGraphFrame) == 0x000158, "Member 'URagdollCharacterDeath_C::UberGraphFrame' has a wrong offset!");
static_assert(offsetof(URagdollCharacterDeath_C, LootPile) == 0x000160, "Member 'URagdollCharacterDeath_C::LootPile' has a wrong offset!");
static_assert(offsetof(URagdollCharacterDeath_C, LootPileMaterial) == 0x000168, "Member 'URagdollCharacterDeath_C::LootPileMaterial' has a wrong offset!");

}

