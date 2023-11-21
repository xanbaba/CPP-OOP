#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class StudentHelder
{
public:
    static bool IsDiamondsValid(int value)
    {
        return value >= 0 && value <= 1000;
    }
};

class Student
{
    int m_diamonds;
    int m_coins;
    char* m_name = nullptr;
    static int StaticValue;

public:
    ~Student()
    {
        std::cout << "Destructor" << '\n';
        delete[] m_name;
    }

    Student()
    {
        std::cout << "Default constructor" << '\n';

        m_coins = 0;
        m_diamonds = 0;
        m_name = nullptr;
        ++StaticValue;
    }

    Student(int a_diamonds, int a_coins, const char* a_name)
    {
        std::cout << "Overloaded constructor" << '\n';

        SetDiamonds(a_diamonds);
        SetCoins(a_coins);
        SetName(a_name);

        strcpy(m_name, a_name);
        ++StaticValue;
    }

    int GetDiamonds()
    {
        return m_diamonds;
    }

    void SetDiamonds(int a_diamonds)
    {
        if (StudentHelder::IsDiamondsValid(a_diamonds))
        {
            m_diamonds = a_diamonds;
        }
    }

    int GetCoins()
    {
        return m_coins;
    }

    void SetCoins(int a_coins)
    {
        if (a_coins >= 0 && a_coins < 2000)
        {
            m_coins = a_coins;
        }
    }

    const char* GetName()
    {
        return m_name;
    }

    void SetName(const char* a_name)
    {
        delete[] m_name;

        size_t len = strlen(a_name) + 1;

        m_name = new char[len];

        strcpy(m_name, a_name);
    }

    static int get_static_value()
    {
        return StaticValue;
    }
};


int Student::StaticValue = 0;

int main(int argc, char* argv[])
{
    Student student1{100, 75, "Xanbaba"};
    std::cout << student1.get_static_value() << '\n';

    student1.SetDiamonds(10);
    std::cout << student1.GetDiamonds() << '\n';

    std::cout << student1.GetName() << '\n';
    return 0;
}
