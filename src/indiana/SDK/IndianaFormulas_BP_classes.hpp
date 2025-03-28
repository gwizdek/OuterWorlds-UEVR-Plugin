#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: IndianaFormulas_BP

#include "Basic.hpp"

#include "Indiana_structs.hpp"
#include "Indiana_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass IndianaFormulas_BP.IndianaFormulas_BP_C
// 0x0000 (0x0158 - 0x0158)
class UIndianaFormulas_BP_C final : public UIndianaFormulas
{
public:
	uint8 LockpickToughness(uint8 ExactLockpickDifficulty, int32 PlayerLockpickSkill) const;
	float LockpickTime(uint8 ExactLockpickDifficulty, int32 PlayerLockpickSkill, int32 BasePlayerLockpickSkill) const;
	float LockpickNoise(uint8 ExactLockpickDifficulty, int32 PlayerLockpickSkill) const;
	uint8 LockpickNumResources(uint8 ExactLockpickDifficulty, int32 PlayerLockpickSkill, int32 BasePlayerLockpickSkill) const;
	bool CanLockpick(uint8 ExactLockpickDifficulty, int32 PlayerLockpickSkill) const;
	uint8 LockpickDifficultyFullRange() const;
	uint8 LockpickDifficultyNumRanges() const;
	float LockpickDifficultyRange() const;
	uint8 ComputeExactLockpickDifficulty(EOCLDifficulty LockpickDifficulty) const;
	uint8 HackToughness(uint8 ExactHackDifficulty, int32 PlayerHackSkill) const;
	uint8 HackNumResources(uint8 ExactHackDifficulty, int32 PlayerHackSkill) const;
	uint8 HackTime(uint8 ExactHackDifficulty, int32 PlayerHackSkill) const;
	float HackNoise(uint8 ExactHackDifficulty, int32 PlayerHackSkill) const;
	float HackDifficultyRange() const;
	uint8 HackDifficultyNumRanges() const;
	uint8 HackDifficultyFullRange() const;
	uint8 ComputeExactHackDifficulty(EOCLDifficulty HackDifficulty) const;
	bool CanHack(uint8 ExactComputerDifficulty, int32 PlayerHackSkill) const;
	uint8 TrapToughness(uint8 ExactTrapDifficulty, int32 PlayerEngineeringSkill) const;
	uint8 ArmTime(uint8 ExactTrapDifficulty, int32 PlayerEngineeringSkill) const;
	uint8 DisarmTime(uint8 ExactTrapDifficulty, int32 PlayerEngineeringSkill) const;
	float TrapArmNoise(uint8 ExactTrapDifficulty, int32 PlayerEngineeringSkill) const;
	float TrapDisarmNoise(uint8 ExactTrapDifficulty, int32 PlayerEngineeringSkill) const;
	bool CanArm(uint8 ExactTrapDifficulty, int32 PlayerEngineeringSkill) const;
	bool CanDisarm(uint8 ExactTrapDifficulty, int32 PlayerEngineeringSkill) const;
	uint8 ComputeExactTrapDifficulty(ETrapDifficulty TrapDifficulty) const;
	uint8 TrapDifficultyFullRange() const;
	uint8 TrapDifficultyNumRanges() const;
	float TrapDifficultyRange() const;
	float TrapDamagePercent(ETrapDifficulty TrapDifficulty) const;
	float PlayerSneakEnemyDetectionRage(bool bInterior, int32 PlayerSneakSkill) const;
	int32 ComputeSkillPointsForPrimaryAttribute(uint8 AttributeRank) const;
	int32 ComputeSkillPointsForSecondaryAttribute(uint8 AttributeRank) const;
	float ComputeFallingDamagePercent(float DistanceFallen) const;
	float PickPocketTime(int32 LockpickSkill, int32 TargetPerception) const;
	bool ShouldDrawFireSwitchCompanionTargets(float OldHealth, float OldDTBody, float OldDTHead, float NewHealth, float NewDTBody, float NewDTHead) const;
	float CalculateIntialMorale(int32 TemperamentAttribute) const;
	float CalculateMoraleAdjustment(float AddedMoral, int32 CharmAttribute, int32 TemperamentAttribute) const;
	int32 GetInterrogationBribeAmount(ECrimeType CrimeType, bool bRestrictedArea, bool bDisguised, int32 DisguiseInterrogationsPassed, int32 PlayerLevel, int32 MerchantSkill, int32 StolenItemsValue) const;
	int32 GetBribeAmount(EBribeDifficulty BribeDifficulty, int32 Level, int32 MerchantSkill) const;
	int32 ConversationSkillNearMissThreshold() const;
	ECharacterSkillRange ComputeSkillValueToRange(int32 SkillValue) const;
	int32 ConversationAttributeNearMissThreshold() const;
	int32 ConversationNearMissMaxOptions() const;
	float GetDisguiseDrainRate(int32 StealthSkill, bool bMoving, bool bSprinting, bool bCrouching) const;
	uint8 HackRobotTime(uint8 ExactHackDifficulty, int32 PlayerHackSkill) const;
	uint8 OCLToughness(int32 Difficulty, int32 PlayerSkill) const;
	bool CanUseOCL(int32 Difficulty, int32 PlayerSkill, int32 MaxDelta) const;
	float BaseRepairPartCost(float Durability, int32 ItemLevel) const;
	int32 FieldRepairPartCost(float Durability, int32 ItemLevel, int32 EngineerSkill) const;
	int32 WorkbenchRepairPartCost(float Durability, int32 ItemLevel, int32 EngineerSkill) const;
	int32 VendorRepairCurrencyCost(float Durability, int32 ItemLevel) const;
	int32 GetRespecCost(int32 NumRespecs) const;
	void GetOCLSkillCheckValue(uint8 OCLDifficulty, uint8* OCLSkillCheckValue) const;

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"IndianaFormulas_BP_C">();
	}
	static class UIndianaFormulas_BP_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UIndianaFormulas_BP_C>();
	}
};
static_assert(alignof(UIndianaFormulas_BP_C) == 0x000008, "Wrong alignment on UIndianaFormulas_BP_C");
static_assert(sizeof(UIndianaFormulas_BP_C) == 0x000158, "Wrong size on UIndianaFormulas_BP_C");

}

