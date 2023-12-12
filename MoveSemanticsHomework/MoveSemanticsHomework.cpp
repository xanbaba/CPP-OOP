#include <iostream>

#include "IntArray.h"

int main(int argc, char* argv[])
{
    while (true)
    {
        {
            IntArray array1{};
            array1.append(0);
            array1.append(1);
            array1.append(2);
            IntArray array2 = array1;
            for (int i = 0; i < array2.length(); ++i)
            {
                std::cout << array2[i] << '\n';
            }
        }
        std::cout << "-------------------\n";
        {
            IntArray array1{};
            array1.append(0);
            array1.append(1);
            array1.append(2);
            IntArray array2 = std::move(array1);
            for (int i = 0; i < array2.length(); ++i)
            {
                std::cout << array2[i] << '\n';
            }
        }
        std::cout << "-------------------\n";
        {
            IntArray array1{};
            array1.append(0);
            array1.append(1);
            array1.append(2);
            IntArray array2;
            array2 = array1;
            for (int i = 0; i < array2.length(); ++i)
            {
                std::cout << array2[i] << '\n';
            }
        }
        std::cout << "-------------------\n";
        {
            IntArray array1{};
            array1.append(0);
            array1.append(1);
            array1.append(2);
            IntArray array2;
            array2 = std::move(array1);
            for (int i = 0; i < array2.length(); ++i)
            {
                std::cout << array2[i] << '\n';
            }
        }
        std::cout << "-------------------\n";
    }
    return 0;
}
