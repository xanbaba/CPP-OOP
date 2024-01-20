#pragma once
#include "Laptop.h"

class GamingLaptop : public Laptop
{
public:
    GamingLaptop();
    void toggle_extreme_cooling();
    void toggle_network_priority();

    bool get_is_boosted();
    void set_is_boosted(bool a_is_boosted);

    bool get_extreme_cooling_status();
    bool get_network_priority_status();
    
private:
    bool is_boosted;
    bool extreme_cooling_status;
    bool network_priority_status;
};
