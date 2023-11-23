#define _CRT_SECURE_NO_WARNINGS
#include "Item.h"
#include <iostream>

Item::Item(const char* a_name, int a_price)
{
    m_name = new char[strlen(a_name) + 1];
    strcpy(m_name, a_name);
    m_price = a_price;
}

Item::~Item()
{
    delete[] m_name;
}

char* Item::get_name()
{
    return m_name;
}

int Item::get_price()
{
    return m_price;
}

void Item::set_name(const char* a_name)
{
    delete[] m_name;
    m_name = new char[strlen(a_name) + 1];
    strcpy(m_name, a_name);
}

void Item::set_price(int a_price)
{
    m_price = a_price;
}

