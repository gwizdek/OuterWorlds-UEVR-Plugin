#pragma once
#include "main.hpp"

class OuterWorldsMain;

class OuterWorldsNativeFix
{
private:
    OuterWorldsMain* m_main{ nullptr };

    static bool m_is_paused_daytime;
    static int m_toggle_native_fix_counter;

public:
    OuterWorldsNativeFix(OuterWorldsMain* main);
    virtual ~OuterWorldsNativeFix() {};

    void pause_daytime(bool pause);
    static void cycle(int delay);
    static void on_tick();
};
