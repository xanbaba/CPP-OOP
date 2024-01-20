#pragma once
#include "Device.h"

class Laptop : public Device
{
public:
    Laptop();
    void open_browser();
    void toggle_touchpad();

    std::string get_manufacturer();
    void set_manufacturer(const std::string& a_manufacturer);

    bool get_touchpad_status();
private:
    std::string manufacturer;
    bool touchpad_status;
};
