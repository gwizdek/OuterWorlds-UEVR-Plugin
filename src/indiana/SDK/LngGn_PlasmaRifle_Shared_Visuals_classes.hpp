#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: LngGn_PlasmaRifle_Shared_Visuals

#include "Basic.hpp"

#include "EN_Material_Parameters_structs.hpp"
#include "Engine_structs.hpp"
#include "Indiana_structs.hpp"
#include "Indiana_classes.hpp"
#include "CoreUObject_structs.hpp"


namespace SDK
{

// BlueprintGeneratedClass LngGn_PlasmaRifle_Shared_Visuals.LngGn_PlasmaRifle_Shared_Visuals_C
// 0x0108 (0x0308 - 0x0200)
class ULngGn_PlasmaRifle_Shared_Visuals_C final : public USharedWeaponVisuals
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0200(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	bool                                          Overcharge_Bool;                                   // 0x0208(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	uint8                                         Pad_209[0x3];                                      // 0x0209(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         Overcharge;                                        // 0x020C(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UParticleSystemComponent*               Overcharge_Effect_Muzzle;                          // 0x0210(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UParticleSystemComponent*               Overcharge_Effect;                                 // 0x0218(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	TArray<class FName>                           Emitters_Overcharge;                               // 0x0220(0x0010)(Edit, BlueprintVisible, DisableEditOnInstance)
	float                                         Emissive_Intensity;                                // 0x0230(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FLinearColor                           Emissive_Color;                                    // 0x0234(0x0010)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         Overcharge_Override;                               // 0x0244(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	TArray<class UMaterialInstanceDynamic*>       MIDs;                                              // 0x0248(0x0010)(Edit, BlueprintVisible, DisableEditOnInstance)
	TArray<int32>                                 Mat_MID_Index;                                     // 0x0258(0x0010)(Edit, BlueprintVisible, DisableEditOnInstance)
	TArray<class FName>                           Mat_Slot_Parameters;                               // 0x0268(0x0010)(Edit, BlueprintVisible, DisableEditOnInstance)
	TArray<struct FVector>                        Mat_Slot_Values;                                   // 0x0278(0x0010)(Edit, BlueprintVisible, DisableEditOnInstance)
	TArray<struct FLinearColor>                   Mat_Slot_Colors_A;                                 // 0x0288(0x0010)(Edit, BlueprintVisible, DisableEditOnInstance)
	TArray<struct FLinearColor>                   Mat_Slot_Colors_B;                                 // 0x0298(0x0010)(Edit, BlueprintVisible, DisableEditOnInstance)
	TArray<EN_Material_Parameters>                Mat_Param;                                         // 0x02A8(0x0010)(Edit, BlueprintVisible, DisableEditOnInstance)
	TArray<float>                                 Edited_Scalars;                                    // 0x02B8(0x0010)(Edit, BlueprintVisible, DisableEditOnInstance)
	TArray<struct FLinearColor>                   Edited_Colors;                                     // 0x02C8(0x0010)(Edit, BlueprintVisible, DisableEditOnInstance)
	bool                                          Reset_Values;                                      // 0x02D8(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	uint8                                         Pad_2D9[0x7];                                      // 0x02D9(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	TArray<class FName>                           Child_Comp_Tags;                                   // 0x02E0(0x0010)(Edit, BlueprintVisible, DisableEditOnInstance)
	TArray<class FName>                           Mat_Slot_Names;                                    // 0x02F0(0x0010)(Edit, BlueprintVisible, DisableEditOnInstance)
	class UNiagaraComponent*                      Overcharge_Effect_Muzzle_Niagara;                  // 0x0300(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	void ExecuteUbergraph_LngGn_PlasmaRifle_Shared_Visuals(int32 EntryPoint);
	void EnterStateBP(EWeaponState WeaponState, const struct FEventEffectParams& Params_0);
	void TriggerEventBP(EWeaponEvent WeaponEvent, const struct FEventEffectParams& Params_0);
	void LeaveStateBP(EWeaponState WeaponState);
	void TickBP(float DeltaTime);
	void Lerp(float Progress, bool Complete);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"LngGn_PlasmaRifle_Shared_Visuals_C">();
	}
	static class ULngGn_PlasmaRifle_Shared_Visuals_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<ULngGn_PlasmaRifle_Shared_Visuals_C>();
	}
};
static_assert(alignof(ULngGn_PlasmaRifle_Shared_Visuals_C) == 0x000008, "Wrong alignment on ULngGn_PlasmaRifle_Shared_Visuals_C");
static_assert(sizeof(ULngGn_PlasmaRifle_Shared_Visuals_C) == 0x000308, "Wrong size on ULngGn_PlasmaRifle_Shared_Visuals_C");
static_assert(offsetof(ULngGn_PlasmaRifle_Shared_Visuals_C, UberGraphFrame) == 0x000200, "Member 'ULngGn_PlasmaRifle_Shared_Visuals_C::UberGraphFrame' has a wrong offset!");
static_assert(offsetof(ULngGn_PlasmaRifle_Shared_Visuals_C, Overcharge_Bool) == 0x000208, "Member 'ULngGn_PlasmaRifle_Shared_Visuals_C::Overcharge_Bool' has a wrong offset!");
static_assert(offsetof(ULngGn_PlasmaRifle_Shared_Visuals_C, Overcharge) == 0x00020C, "Member 'ULngGn_PlasmaRifle_Shared_Visuals_C::Overcharge' has a wrong offset!");
static_assert(offsetof(ULngGn_PlasmaRifle_Shared_Visuals_C, Overcharge_Effect_Muzzle) == 0x000210, "Member 'ULngGn_PlasmaRifle_Shared_Visuals_C::Overcharge_Effect_Muzzle' has a wrong offset!");
static_assert(offsetof(ULngGn_PlasmaRifle_Shared_Visuals_C, Overcharge_Effect) == 0x000218, "Member 'ULngGn_PlasmaRifle_Shared_Visuals_C::Overcharge_Effect' has a wrong offset!");
static_assert(offsetof(ULngGn_PlasmaRifle_Shared_Visuals_C, Emitters_Overcharge) == 0x000220, "Member 'ULngGn_PlasmaRifle_Shared_Visuals_C::Emitters_Overcharge' has a wrong offset!");
static_assert(offsetof(ULngGn_PlasmaRifle_Shared_Visuals_C, Emissive_Intensity) == 0x000230, "Member 'ULngGn_PlasmaRifle_Shared_Visuals_C::Emissive_Intensity' has a wrong offset!");
static_assert(offsetof(ULngGn_PlasmaRifle_Shared_Visuals_C, Emissive_Color) == 0x000234, "Member 'ULngGn_PlasmaRifle_Shared_Visuals_C::Emissive_Color' has a wrong offset!");
static_assert(offsetof(ULngGn_PlasmaRifle_Shared_Visuals_C, Overcharge_Override) == 0x000244, "Member 'ULngGn_PlasmaRifle_Shared_Visuals_C::Overcharge_Override' has a wrong offset!");
static_assert(offsetof(ULngGn_PlasmaRifle_Shared_Visuals_C, MIDs) == 0x000248, "Member 'ULngGn_PlasmaRifle_Shared_Visuals_C::MIDs' has a wrong offset!");
static_assert(offsetof(ULngGn_PlasmaRifle_Shared_Visuals_C, Mat_MID_Index) == 0x000258, "Member 'ULngGn_PlasmaRifle_Shared_Visuals_C::Mat_MID_Index' has a wrong offset!");
static_assert(offsetof(ULngGn_PlasmaRifle_Shared_Visuals_C, Mat_Slot_Parameters) == 0x000268, "Member 'ULngGn_PlasmaRifle_Shared_Visuals_C::Mat_Slot_Parameters' has a wrong offset!");
static_assert(offsetof(ULngGn_PlasmaRifle_Shared_Visuals_C, Mat_Slot_Values) == 0x000278, "Member 'ULngGn_PlasmaRifle_Shared_Visuals_C::Mat_Slot_Values' has a wrong offset!");
static_assert(offsetof(ULngGn_PlasmaRifle_Shared_Visuals_C, Mat_Slot_Colors_A) == 0x000288, "Member 'ULngGn_PlasmaRifle_Shared_Visuals_C::Mat_Slot_Colors_A' has a wrong offset!");
static_assert(offsetof(ULngGn_PlasmaRifle_Shared_Visuals_C, Mat_Slot_Colors_B) == 0x000298, "Member 'ULngGn_PlasmaRifle_Shared_Visuals_C::Mat_Slot_Colors_B' has a wrong offset!");
static_assert(offsetof(ULngGn_PlasmaRifle_Shared_Visuals_C, Mat_Param) == 0x0002A8, "Member 'ULngGn_PlasmaRifle_Shared_Visuals_C::Mat_Param' has a wrong offset!");
static_assert(offsetof(ULngGn_PlasmaRifle_Shared_Visuals_C, Edited_Scalars) == 0x0002B8, "Member 'ULngGn_PlasmaRifle_Shared_Visuals_C::Edited_Scalars' has a wrong offset!");
static_assert(offsetof(ULngGn_PlasmaRifle_Shared_Visuals_C, Edited_Colors) == 0x0002C8, "Member 'ULngGn_PlasmaRifle_Shared_Visuals_C::Edited_Colors' has a wrong offset!");
static_assert(offsetof(ULngGn_PlasmaRifle_Shared_Visuals_C, Reset_Values) == 0x0002D8, "Member 'ULngGn_PlasmaRifle_Shared_Visuals_C::Reset_Values' has a wrong offset!");
static_assert(offsetof(ULngGn_PlasmaRifle_Shared_Visuals_C, Child_Comp_Tags) == 0x0002E0, "Member 'ULngGn_PlasmaRifle_Shared_Visuals_C::Child_Comp_Tags' has a wrong offset!");
static_assert(offsetof(ULngGn_PlasmaRifle_Shared_Visuals_C, Mat_Slot_Names) == 0x0002F0, "Member 'ULngGn_PlasmaRifle_Shared_Visuals_C::Mat_Slot_Names' has a wrong offset!");
static_assert(offsetof(ULngGn_PlasmaRifle_Shared_Visuals_C, Overcharge_Effect_Muzzle_Niagara) == 0x000300, "Member 'ULngGn_PlasmaRifle_Shared_Visuals_C::Overcharge_Effect_Muzzle_Niagara' has a wrong offset!");

}

