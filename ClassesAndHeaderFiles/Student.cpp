#define _CRT_SECURE_NO_WARNINGS
#include "Student.h"
#include <iostream>
#include "StudentHelper.h"

int Student::StaticValue = 0;

Student::~Student()
{
    std::cout << "Destructor" << '\n';
    delete[] m_name;
}

Student::Student() : Student(0, 0, "", 0)
{
    std::cout << "Default constructor" << '\n';
}

Student::Student(int a_diamonds, int a_coins, const char* a_name) : Student(a_diamonds, a_coins, a_name, 0)
{
    std::cout << "Overloaded constructor" << '\n';
}

Student::Student(int a_diamonds, int a_coins, const char* a_name, int a_badges)
{
    std::cout << "Overloaded constructor" << '\n';

    SetDiamonds(a_diamonds);
    SetCoins(a_coins);
    SetName(a_name);

    strcpy(m_name, a_name);
    m_badges = a_badges;

    ++StaticValue;
}

int Student::GetDiamonds()
{
    return m_diamonds;
}

void Student:: SetDiamonds(int a_diamonds)
{
    if (StudentHelper::IsDiamondsValid(a_diamonds))
    {
        m_diamonds = a_diamonds;
    }
}

int Student::GetCoins()
{
    return m_coins;
}

void Student::SetCoins(int a_coins)
{
    if (a_coins >= 0 && a_coins < 2000)
    {
        m_coins = a_coins;
    }
}

const char* Student:: GetName()
{
    return m_name;
}

void Student::SetName(const char* a_name)
{
    delete[] m_name;

    size_t len = strlen(a_name) + 1;

    m_name = new char[len];

    strcpy(m_name, a_name);
}

int Student::get_static_value()
{
    return StaticValue;
}
