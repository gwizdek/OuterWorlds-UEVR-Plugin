#pragma once
#include "main.hpp"

class OuterWorldsMain;

class OuterWorldsNativeFix
{
private:
    OuterWorldsMain* m_main{ nullptr };

    bool m_is_paused_daytime{ false };
    int m_toggle_native_fix_counter{ -1 };

public:
    OuterWorldsNativeFix(OuterWorldsMain* main) { m_main = main; };
    virtual ~OuterWorldsNativeFix() {};

    void pause_daytime(bool pause);
    void cycle_native_fix();
    void handle_native_fix();
};
