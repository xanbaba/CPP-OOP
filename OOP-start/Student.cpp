#include "Student.h"
#include <iostream>

void Student::info()
{
    std::cout << name << '\n';
    std::cout << surname << '\n';
    std::cout << age << '\n';
    for (int i = 0; i < 5; ++i)
    {
        std::cout << marks[i] << ' ';
    }
    std::cout << "\n\n\n";
}