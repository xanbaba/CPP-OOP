#include "Smartphone.h"

#include <iostream>

Smartphone::Smartphone()
= default;

void Smartphone::take_photo()
{
    std::cout << "Photo was taken \n";
}

void Smartphone::record_video()
{
    std::cout << "Video recording started\n";
}

void Smartphone::set_alarm()
{
    std::cout << "Alarm was set \n";
}

std::string Smartphone::get_manufacturer()
{
    return manufacturer;
}

void Smartphone::set_manufacturer(const std::string& a_manufacturer)
{
    manufacturer = a_manufacturer;
}
