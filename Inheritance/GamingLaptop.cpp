#include "GamingLaptop.h"

#include <iostream>

GamingLaptop::GamingLaptop() : is_boosted(false), extreme_cooling_status(), network_priority_status()
{
}

void GamingLaptop::toggle_extreme_cooling()
{
    extreme_cooling_status ? extreme_cooling_status = false : extreme_cooling_status = true;
}

void GamingLaptop::toggle_network_priority()
{
    network_priority_status ? network_priority_status = false : network_priority_status = true;

}

bool GamingLaptop::get_is_boosted()
{
    return is_boosted;
}

void GamingLaptop::set_is_boosted(bool a_is_boosted)
{
    is_boosted = a_is_boosted;
}

bool GamingLaptop::get_extreme_cooling_status()
{
    return extreme_cooling_status;
}

bool GamingLaptop::get_network_priority_status()
{
    return network_priority_status;
}
