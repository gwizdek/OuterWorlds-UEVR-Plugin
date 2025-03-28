#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: SmallAmmoContainer_A_BP

#include "Basic.hpp"

#include "SimpleContainer_BP_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass SmallAmmoContainer_A_BP.SmallAmmoContainer_A_BP_C
// 0x0000 (0x0558 - 0x0558)
class ASmallAmmoContainer_A_BP_C final : public ASimpleContainer_BP_C
{
public:
	void GetLightingConfig(class UStaticMeshComponent** Mesh, class FName* MaterialSlot);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"SmallAmmoContainer_A_BP_C">();
	}
	static class ASmallAmmoContainer_A_BP_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<ASmallAmmoContainer_A_BP_C>();
	}
};
static_assert(alignof(ASmallAmmoContainer_A_BP_C) == 0x000008, "Wrong alignment on ASmallAmmoContainer_A_BP_C");
static_assert(sizeof(ASmallAmmoContainer_A_BP_C) == 0x000558, "Wrong size on ASmallAmmoContainer_A_BP_C");

}

