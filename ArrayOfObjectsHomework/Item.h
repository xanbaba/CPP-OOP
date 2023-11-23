#pragma once

class Item
{
public:
    Item(const char* a_name, int a_price);

    ~Item();

    char* get_name();

    int get_price();

    void set_name(const char* a_name);

    void set_price(int a_price);

    
private:
    char* m_name;
    int m_price;
};
