#include <iostream>

#include "is_primitive.h"
#include "is_ref.h"

class Class { };

int main(int argc, char* argv[])
{
    std::cout << std::boolalpha;
    {
        std::cout << is_primitive<int>::value << '\n';
        std::cout << is_primitive<bool>::value << '\n';
        std::cout << is_primitive<char>::value << '\n';
        std::cout << is_primitive<short>::value << '\n';
        std::cout << is_primitive<Class>::value << '\n';
    }
    {
        std::cout << is_ref<int&>::value << '\n';
        std::cout << is_ref<int>::value << '\n';
        std::cout << is_ref<int&&>::value << '\n';
    }
    return 0;
}
