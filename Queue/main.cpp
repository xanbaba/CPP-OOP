#include "Queue.h"

int main(int argc, char* argv[])
{
    // while (true)
    {
        Queue<int> queue_int{2};
    
        queue_int.Push(5);
        queue_int.Pop();
        queue_int.Push(15);

        queue_int.Push(25);
        queue_int.Push(35);

        queue_int.Pop();
        queue_int.Pop();
        // queue_int.Pop();

        std::cout << queue_int << "\n---------------\n";

        Queue<int> queue_int2{queue_int};
        queue_int2.Push(45);
        queue_int2.Push(55);
        queue_int2.Push(65);
        std::cout << queue_int2 << "\n---------------\n";
        queue_int2.Pop();
        std::cout << queue_int2 << "\n---------------\n";

        Queue<int> queue_int3;
        queue_int3 = queue_int2;
        queue_int3.Pop();
        queue_int3.Push(75);
        queue_int3.Push(85);
        queue_int3.Push(95);
        std::cout << queue_int3 << "\n---------------\n";

    
        Queue<int> queue_int4 = std::move(queue_int3);
        queue_int4.Push(105);
        std::cout << queue_int4 << "\n---------------\n";
        std::cout << queue_int3 << "\n---------------\n";

        Queue<int> queue_int5;
        queue_int5 = std::move(queue_int4);
        queue_int5.Push(115);
        queue_int5.Pop();
        queue_int5.Pop();
        queue_int5.Pop();
        queue_int5.Pop();
        queue_int5.Pop();
        queue_int5.Pop();
        queue_int5.Pop();
        std::cout << queue_int5 << "\n---------------\n";
        std::cout << queue_int4 << "\n---------------\n";
        std::cout << std::boolalpha << queue_int5.IsEmpty();
    }
}
