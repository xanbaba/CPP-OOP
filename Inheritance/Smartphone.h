#pragma once
#include "Device.h"

class Smartphone : public Device
{
public:
    Smartphone();
    void take_photo();
    void record_video();
    void set_alarm();
    std::string get_manufacturer();
    void set_manufacturer(const std::string& a_manufacturer);
private:
    std::string manufacturer; 
};
