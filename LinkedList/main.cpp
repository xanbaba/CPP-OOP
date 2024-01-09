
#include <iostream>

#include "LinkedList.h"

int main(int argc, char* argv[])
{
    while (true)
    {
        LinkedList<int> LList;
        LList.PushBack(10);
        LList.PushBack(20); 
        LList.PushBack(30);

        std::cout << LList.GetHead() << '\n';
    }
    return 0;
}
