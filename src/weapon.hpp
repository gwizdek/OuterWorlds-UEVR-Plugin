#pragma once
#include "main.hpp"

class OuterWorldsMain;

class OuterWorldsWeapon
{
private:
    OuterWorldsMain* m_main{ nullptr };

public:
    OuterWorldsWeapon(OuterWorldsMain* main) { m_main = main; };
    virtual ~OuterWorldsWeapon() {};

    void tick();

};
