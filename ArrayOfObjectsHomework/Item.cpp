﻿#define _CRT_SECURE_NO_WARNINGS
#include "Item.h"

#include <iostream>

Item::Item(const char* a_name, int a_price)
{
    set_price(a_price);
    set_name(a_name);
}

Item::~Item()
{
    delete[] m_name;
}

char* Item::get_name()
{
    const auto name_copy = new char[strlen(m_name) + 1];
    strcpy(name_copy, m_name);
    return name_copy;
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
