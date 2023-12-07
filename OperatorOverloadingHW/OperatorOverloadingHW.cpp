#include "IntArray.h"
#include "Clock.h"
#include <iostream>
#define show_clock(CLOCK) std::cout << "clock: " << (CLOCK).get_hours() << ':' << (CLOCK).get_minutes() << '\n'

int main(int argc, char* argv[])
{
    // Task 1
    /*{
        IntArray array;
        array.append(12);
        array.append(1);
        array.append(15);
        IntArray array2;
        array2.append(11);
        array2.append(12);
        array[0] = 25;
        IntArray array_concat = array + array2;
        std::cout << array_concat.length() << '\n';
        for (int i = 0; i < array_concat.length(); ++i)
        {
            std::cout << array_concat[i] << '\n';
        }
    }*/
    // Task 2
    /*{
        Clock clock{9, 20};
        Clock clock2{9, 19};
        show_clock(clock);
        ++clock;
        show_clock(clock);
        for (int i = 0; i < 60; ++i)
        {
            ++clock;
        }
        show_clock(clock);
        --clock;
        --clock;
        show_clock(clock);
        for (int i = 0; i < 59; ++i)
        {
            --clock;
        }
        show_clock(clock);
        --clock;
        show_clock(clock);
        std::cout << std::boolalpha;
        std::cout << (clock2 != clock) << '\n';
    }*/
    // Task 3
    return 0;
}
