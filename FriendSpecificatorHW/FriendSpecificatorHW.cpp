#include <iostream>

#include "IntArray.h"

int main(int argc, char* argv[])
{
    IntArray array;
    array.append(0);
    array.append(1);
    array.append(2);
    array.append(3);
    array.append(4);
    std::cout << array << '\n';
    std::cin >> array;
    std::cout << array << '\n';
    
    return 0;
}
