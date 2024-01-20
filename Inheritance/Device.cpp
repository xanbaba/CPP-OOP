#include "Device.h"

#include <iostream>

Device::Device() : id()
{
}

std::string Device::get_name()
{
    return name;
}

void Device::set_name(const std::string& a_name)
{
    name = a_name;
}

int Device::get_id()
{
    return id;
}

void Device::set_id(int a_id)
{
    id = a_id;
}

void Device::On()
{
    std::cout << "Turned On \n";
}

void Device::Off()
{
    std::cout << "Turned Off \n";
}
