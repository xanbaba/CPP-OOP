#pragma once
#include <string>

class Device
{
protected:
   Device();
public:
   std::string get_name();
   void set_name(const std::string& a_name);
   int get_id();
   void set_id(int a_id);
   void On();
   void Off();
private:
   std::string name;
   int id;
};
