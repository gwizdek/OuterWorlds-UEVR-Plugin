#pragma once


class OuterWorldsVRWeapon
{
private:
    //OuterWorldsPlugin* m_plugin{ nullptr };

public:
    //OuterWorldsVRWeapon(OuterWorldsPlugin* plugin);
    OuterWorldsVRWeapon() = default;

    virtual ~OuterWorldsVRWeapon();

    void tick();

};
