#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: PrefabAsset

#include "Basic.hpp"

#include "Engine_structs.hpp"


namespace SDK::Params
{

// Function PrefabAsset.PrefabActor.DestroyPrefabActor
// 0x0001 (0x0001 - 0x0000)
struct PrefabActor_DestroyPrefabActor final
{
public:
	bool                                          bDestroyAttachedChildren;                          // 0x0000(0x0001)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};
static_assert(alignof(PrefabActor_DestroyPrefabActor) == 0x000001, "Wrong alignment on PrefabActor_DestroyPrefabActor");
static_assert(sizeof(PrefabActor_DestroyPrefabActor) == 0x000001, "Wrong size on PrefabActor_DestroyPrefabActor");
static_assert(offsetof(PrefabActor_DestroyPrefabActor, bDestroyAttachedChildren) == 0x000000, "Member 'PrefabActor_DestroyPrefabActor::bDestroyAttachedChildren' has a wrong offset!");

// Function PrefabAsset.PrefabActor.GetPrefab
// 0x0008 (0x0008 - 0x0000)
struct PrefabActor_GetPrefab final
{
public:
	class UPrefabAsset*                           ReturnValue;                                       // 0x0000(0x0008)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};
static_assert(alignof(PrefabActor_GetPrefab) == 0x000008, "Wrong alignment on PrefabActor_GetPrefab");
static_assert(sizeof(PrefabActor_GetPrefab) == 0x000008, "Wrong size on PrefabActor_GetPrefab");
static_assert(offsetof(PrefabActor_GetPrefab, ReturnValue) == 0x000000, "Member 'PrefabActor_GetPrefab::ReturnValue' has a wrong offset!");

// Function PrefabAsset.PrefabActor.SetMobility
// 0x0001 (0x0001 - 0x0000)
struct PrefabActor_SetMobility final
{
public:
	EComponentMobility                            InMobility;                                        // 0x0000(0x0001)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};
static_assert(alignof(PrefabActor_SetMobility) == 0x000001, "Wrong alignment on PrefabActor_SetMobility");
static_assert(sizeof(PrefabActor_SetMobility) == 0x000001, "Wrong size on PrefabActor_SetMobility");
static_assert(offsetof(PrefabActor_SetMobility, InMobility) == 0x000000, "Member 'PrefabActor_SetMobility::InMobility' has a wrong offset!");

// Function PrefabAsset.PrefabActor.SetPrefab
// 0x0010 (0x0010 - 0x0000)
struct PrefabActor_SetPrefab final
{
public:
	class UPrefabAsset*                           NewPrefab;                                         // 0x0000(0x0008)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          bForceRevertEvenDisconnected;                      // 0x0008(0x0001)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_9[0x7];                                        // 0x0009(0x0007)(Fixing Struct Size After Last Property [ Dumper-7 ])
};
static_assert(alignof(PrefabActor_SetPrefab) == 0x000008, "Wrong alignment on PrefabActor_SetPrefab");
static_assert(sizeof(PrefabActor_SetPrefab) == 0x000010, "Wrong size on PrefabActor_SetPrefab");
static_assert(offsetof(PrefabActor_SetPrefab, NewPrefab) == 0x000000, "Member 'PrefabActor_SetPrefab::NewPrefab' has a wrong offset!");
static_assert(offsetof(PrefabActor_SetPrefab, bForceRevertEvenDisconnected) == 0x000008, "Member 'PrefabActor_SetPrefab::bForceRevertEvenDisconnected' has a wrong offset!");

}

