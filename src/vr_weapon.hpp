#pragma once
#include "vr_common.hpp"

class OuterWorldsCommon;

class OuterWorldsVRWeapon
{
private:
    OuterWorldsCommon* m_common{ nullptr };

public:
    OuterWorldsVRWeapon(OuterWorldsCommon* common) { m_common = common; };
    virtual ~OuterWorldsVRWeapon() {};

    void tick();
};
