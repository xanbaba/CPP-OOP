#include <iostream>

#include "IntArray.h"

int main(int argc, char* argv[])
{
    // while (true)
    {
        IntArray array{5};
        array.append(10);
        array.append(20);
        array.append(30);
        array.prepend(40);
        array.prepend(50);
        array.prepend(60);

        for (int i = 0; i < array.length(); ++i)
        {
            std::cout << array.get(i) << ' ';
        }
        std::cout << '\n';

        std::cout << "lenght: " << array.length() << '\n';
        std::cout << "capacity: " << array.get_capacity() << '\n';
        std::cout << std::boolalpha << "is array empty: " << array.is_empty() << '\n';
    }
    return 0;
}
