#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: W_hndgn_PistolBP

#include "Basic.hpp"

#include "Engine_structs.hpp"


namespace SDK::Params
{

// Function w_hndgn_PistolBP.w_hndgn_PistolBP_C.ExecuteUbergraph_w_hndgn_PistolBP
// 0x0004 (0x0004 - 0x0000)
struct W_hndgn_PistolBP_C_ExecuteUbergraph_w_hndgn_PistolBP final
{
public:
	int32                                         EntryPoint;                                        // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(W_hndgn_PistolBP_C_ExecuteUbergraph_w_hndgn_PistolBP) == 0x000004, "Wrong alignment on W_hndgn_PistolBP_C_ExecuteUbergraph_w_hndgn_PistolBP");
static_assert(sizeof(W_hndgn_PistolBP_C_ExecuteUbergraph_w_hndgn_PistolBP) == 0x000004, "Wrong size on W_hndgn_PistolBP_C_ExecuteUbergraph_w_hndgn_PistolBP");
static_assert(offsetof(W_hndgn_PistolBP_C_ExecuteUbergraph_w_hndgn_PistolBP, EntryPoint) == 0x000000, "Member 'W_hndgn_PistolBP_C_ExecuteUbergraph_w_hndgn_PistolBP::EntryPoint' has a wrong offset!");

// Function w_hndgn_PistolBP.w_hndgn_PistolBP_C.AnimGraph
// 0x0010 (0x0010 - 0x0000)
struct W_hndgn_PistolBP_C_AnimGraph final
{
public:
	struct FPoseLink                              AnimGraph_0;                                       // 0x0000(0x0010)(Parm, OutParm, NoDestructor)
};
static_assert(alignof(W_hndgn_PistolBP_C_AnimGraph) == 0x000008, "Wrong alignment on W_hndgn_PistolBP_C_AnimGraph");
static_assert(sizeof(W_hndgn_PistolBP_C_AnimGraph) == 0x000010, "Wrong size on W_hndgn_PistolBP_C_AnimGraph");
static_assert(offsetof(W_hndgn_PistolBP_C_AnimGraph, AnimGraph_0) == 0x000000, "Member 'W_hndgn_PistolBP_C_AnimGraph::AnimGraph_0' has a wrong offset!");

}

