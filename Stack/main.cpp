#include <iostream>
#include "Stack.h"
#include "CodeParser.h"

int main(int argc, char* argv[])
{
    // Task 1
    {
        Stack<int> stack{5};
        stack.Push(5);
        stack.Push(15);
        stack.Push(54);
        stack.Push(73);
        stack.Push(12);
        stack.Push(87);
        stack.Push(44);
        auto stack2 = stack;
        stack2.Pop();
        stack2.Pop();
        std::cout << stack << "-----\n";
        std::cout << stack2 << "-----\n";
        stack.Swap(stack2);
        std::cout << stack << "-----\n";
        std::cout << stack2 << "-----\n";
    }

    // Task 2
    {
        std::cout << std::boolalpha << CodeParser::are_brackets_correct("[[}]");
    }
    return 0;
}
