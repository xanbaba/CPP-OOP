#pragma once
#include "Item.h"

class Stock
{
public:
    Stock();
    ~Stock();
    int get_items_count();
    Item* get_item(const char* item_name);
    Item* get_item(int item_index);
    bool is_in_stock(const char* item_name);
    void add_item(Item& item);
    
private:
    int m_items_count;
    int m_capacity;
    Item* items_array;
};
