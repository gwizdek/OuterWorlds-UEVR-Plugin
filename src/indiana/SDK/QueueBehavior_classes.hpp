#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: QueueBehavior

#include "Basic.hpp"

#include "Indiana_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass QueueBehavior.QueueBehavior_C
// 0x0000 (0x0078 - 0x0078)
class UQueueBehavior_C final : public UDecisionTree_QueueBehavior
{
public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"QueueBehavior_C">();
	}
	static class UQueueBehavior_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UQueueBehavior_C>();
	}
};
static_assert(alignof(UQueueBehavior_C) == 0x000008, "Wrong alignment on UQueueBehavior_C");
static_assert(sizeof(UQueueBehavior_C) == 0x000078, "Wrong size on UQueueBehavior_C");

}

