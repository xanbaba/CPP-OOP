
#include <iostream>

#include "GamingLaptop.h"
#include "Smartphone.h"

int main(int argc, char* argv[])
{
    GamingLaptop gaming_laptop;
    
    gaming_laptop.set_name("MSI Turbo Ultra Mega Max 3000x");
    gaming_laptop.set_manufacturer("MSI");
    gaming_laptop.set_is_boosted(true);
    gaming_laptop.set_id(10234);
    gaming_laptop.toggle_extreme_cooling();
    gaming_laptop.toggle_network_priority();
    gaming_laptop.toggle_extreme_cooling();
    gaming_laptop.toggle_touchpad();
    
    std::cout << gaming_laptop.get_name() << '\n';
    std::cout << gaming_laptop.get_manufacturer() << '\n';
    std::cout << gaming_laptop.get_is_boosted() << '\n';
    std::cout << gaming_laptop.get_id() << '\n';
    std::cout << gaming_laptop.get_extreme_cooling_status() << '\n';
    std::cout << gaming_laptop.get_network_priority_status() << '\n';
    std::cout << gaming_laptop.get_touchpad_status() << '\n';
    
    std::cout << "-----------------\n\n";
    Smartphone smartphone;
    smartphone.set_alarm();
    smartphone.record_video();
    smartphone.take_photo();
    return 0;
}
