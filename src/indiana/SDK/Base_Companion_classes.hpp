#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: Base_Companion

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "Base_Human_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass Base_Companion.Base_Companion_C
// 0x00A0 (0x0F70 - 0x0ED0)
class ABase_Companion_C : public ABase_Human_C
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame_Base_Companion_C;                   // 0x0ED0(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	class UCompanionComponent*                    Companion;                                         // 0x0ED8(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UBeaconComponent*                       Beacon;                                            // 0x0EE0(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	bool                                          bPlayerIsInCombat;                                 // 0x0EE8(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	uint8                                         Pad_EE9[0x3];                                      // 0x0EE9(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         CombatStartTime;                                   // 0x0EEC(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CombatEndTime;                                     // 0x0EF0(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CombatTime;                                        // 0x0EF4(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CombatTimeThreshold;                               // 0x0EF8(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         CombatKills;                                       // 0x0EFC(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         CombatKillThreshold;                               // 0x0F00(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         ChanceToPlay;                                      // 0x0F04(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         ChanceToPlayIncrease;                              // 0x0F08(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_F0C[0x4];                                      // 0x0F0C(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	TArray<class UAnimMontage*>                   VictoryMontages;                                   // 0x0F10(0x0010)(Edit, BlueprintVisible, DisableEditOnInstance)
	TArray<class UAnimMontage*>                   HandGunMontages;                                   // 0x0F20(0x0010)(Edit, BlueprintVisible, DisableEditOnInstance)
	TArray<class UAnimMontage*>                   LongGunMontages;                                   // 0x0F30(0x0010)(Edit, BlueprintVisible, DisableEditOnInstance)
	TArray<class UAnimMontage*>                   HeavyWeapMontages;                                 // 0x0F40(0x0010)(Edit, BlueprintVisible, DisableEditOnInstance)
	TArray<class UAnimMontage*>                   LightMeleeMontages;                                // 0x0F50(0x0010)(Edit, BlueprintVisible, DisableEditOnInstance)
	TArray<class UAnimMontage*>                   HeavyMeleeMontages;                                // 0x0F60(0x0010)(Edit, BlueprintVisible, DisableEditOnInstance)

public:
	void ExecuteUbergraph_Base_Companion(int32 EntryPoint);
	void TryHolsterWeapon();
	void OnCompanionCauseDamage(const struct FCauseDamageInfo& CauseDamageInfo);
	void TryPlayVictoryMontage();
	void PlayerCombatStateChange(bool bIsInCombat, bool bRestoring);
	void Cinematic_Mode_Change(bool bCinematicMode);
	void CompanionOutline(bool bEnable);
	void ReceiveBeginPlay();
	void OnCompleted_BB47D0DD4FD7D7ECFF34BEBB31820E3D(class FName NotifyName);
	void OnBlendOut_BB47D0DD4FD7D7ECFF34BEBB31820E3D(class FName NotifyName);
	void OnInterrupted_BB47D0DD4FD7D7ECFF34BEBB31820E3D(class FName NotifyName);
	void OnNotifyBegin_BB47D0DD4FD7D7ECFF34BEBB31820E3D(class FName NotifyName);
	void OnNotifyEnd_BB47D0DD4FD7D7ECFF34BEBB31820E3D(class FName NotifyName);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"Base_Companion_C">();
	}
	static class ABase_Companion_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<ABase_Companion_C>();
	}
};
static_assert(alignof(ABase_Companion_C) == 0x000010, "Wrong alignment on ABase_Companion_C");
static_assert(sizeof(ABase_Companion_C) == 0x000F70, "Wrong size on ABase_Companion_C");
static_assert(offsetof(ABase_Companion_C, UberGraphFrame_Base_Companion_C) == 0x000ED0, "Member 'ABase_Companion_C::UberGraphFrame_Base_Companion_C' has a wrong offset!");
static_assert(offsetof(ABase_Companion_C, Companion) == 0x000ED8, "Member 'ABase_Companion_C::Companion' has a wrong offset!");
static_assert(offsetof(ABase_Companion_C, Beacon) == 0x000EE0, "Member 'ABase_Companion_C::Beacon' has a wrong offset!");
static_assert(offsetof(ABase_Companion_C, bPlayerIsInCombat) == 0x000EE8, "Member 'ABase_Companion_C::bPlayerIsInCombat' has a wrong offset!");
static_assert(offsetof(ABase_Companion_C, CombatStartTime) == 0x000EEC, "Member 'ABase_Companion_C::CombatStartTime' has a wrong offset!");
static_assert(offsetof(ABase_Companion_C, CombatEndTime) == 0x000EF0, "Member 'ABase_Companion_C::CombatEndTime' has a wrong offset!");
static_assert(offsetof(ABase_Companion_C, CombatTime) == 0x000EF4, "Member 'ABase_Companion_C::CombatTime' has a wrong offset!");
static_assert(offsetof(ABase_Companion_C, CombatTimeThreshold) == 0x000EF8, "Member 'ABase_Companion_C::CombatTimeThreshold' has a wrong offset!");
static_assert(offsetof(ABase_Companion_C, CombatKills) == 0x000EFC, "Member 'ABase_Companion_C::CombatKills' has a wrong offset!");
static_assert(offsetof(ABase_Companion_C, CombatKillThreshold) == 0x000F00, "Member 'ABase_Companion_C::CombatKillThreshold' has a wrong offset!");
static_assert(offsetof(ABase_Companion_C, ChanceToPlay) == 0x000F04, "Member 'ABase_Companion_C::ChanceToPlay' has a wrong offset!");
static_assert(offsetof(ABase_Companion_C, ChanceToPlayIncrease) == 0x000F08, "Member 'ABase_Companion_C::ChanceToPlayIncrease' has a wrong offset!");
static_assert(offsetof(ABase_Companion_C, VictoryMontages) == 0x000F10, "Member 'ABase_Companion_C::VictoryMontages' has a wrong offset!");
static_assert(offsetof(ABase_Companion_C, HandGunMontages) == 0x000F20, "Member 'ABase_Companion_C::HandGunMontages' has a wrong offset!");
static_assert(offsetof(ABase_Companion_C, LongGunMontages) == 0x000F30, "Member 'ABase_Companion_C::LongGunMontages' has a wrong offset!");
static_assert(offsetof(ABase_Companion_C, HeavyWeapMontages) == 0x000F40, "Member 'ABase_Companion_C::HeavyWeapMontages' has a wrong offset!");
static_assert(offsetof(ABase_Companion_C, LightMeleeMontages) == 0x000F50, "Member 'ABase_Companion_C::LightMeleeMontages' has a wrong offset!");
static_assert(offsetof(ABase_Companion_C, HeavyMeleeMontages) == 0x000F60, "Member 'ABase_Companion_C::HeavyMeleeMontages' has a wrong offset!");

}

