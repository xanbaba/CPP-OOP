#include "IntArray.h"
#include <iostream>

int main(int argc, char* argv[])
{
    // Task 1
    {
        IntArray array;
        array.append(12);
        array.append(1);
        array.append(15);
        IntArray array2;
        array.append(11);
        array.append(12);
        array[0] = 25;
        IntArray array_concat = array + array2;
        for (int i = 0; i < array_concat.length(); ++i)
        {
            std::cout << array_concat[i] << '\n';
        }
    }
    return 0;
}
