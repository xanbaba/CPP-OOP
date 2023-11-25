#include "Stock.h"

#include <cstring>
#include <iostream>

Stock::Stock()
{
    m_items_count = 0;
    m_capacity = 4;
    items_array = static_cast<Item*>(operator new(sizeof(Item) * m_capacity));
}

Stock::~Stock()
{
    operator delete(items_array);
}

int Stock::get_items_count()
{
    return m_items_count;
}

Item* Stock::get_item(const char* item_name)
{
    for (int i = 0; i < m_items_count; ++i)
    {
        const auto current_item_name = get_item(i)->get_name();
        if (strcmp(current_item_name, item_name) == 0)
        {
            delete[] current_item_name;
            return get_item(i);
        }
        delete[] current_item_name;
    }

    return nullptr;
}

Item* Stock::get_item(int item_index)
{
    if (item_index >= m_items_count || item_index < 0)
    {
        return nullptr;
    }
    return &items_array[item_index];
}

bool Stock::is_in_stock(const char* item_name)
{
    for (int i = 0; i < m_items_count; ++i)
    {
        const auto current_item_name = get_item(i)->get_name();
        if (strcmp(current_item_name, item_name) == 0)
        {
            delete[] current_item_name;
            return true;
        }
        delete[] current_item_name;
    }

    return false;
}

void Stock::add_item(Item& item)
{
    if (m_items_count == m_capacity)
    {
        m_capacity *= 2;
        const auto new_array = static_cast<Item*>(operator new(sizeof(Item) * m_capacity));

        for (int i = 0; i < m_items_count; ++i)
        {
            new_array[i] = items_array[i];
        }

        operator delete(items_array);
        items_array = new_array;
    }
    items_array[m_items_count] = item;
    ++m_items_count;
}
