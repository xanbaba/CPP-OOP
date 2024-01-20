#include "Laptop.h"

#include <iostream>

Laptop::Laptop() : touchpad_status()
{
}

void Laptop::open_browser()
{
    std::cout << "Browser opened \n";
}

void Laptop::toggle_touchpad()
{
    touchpad_status ? touchpad_status = false : touchpad_status = true;
}

std::string Laptop::get_manufacturer()
{
    return manufacturer;
}

void Laptop::set_manufacturer(const std::string& a_manufacturer)
{
    manufacturer = a_manufacturer;
}

bool Laptop::get_touchpad_status()
{
    return touchpad_status;
}
