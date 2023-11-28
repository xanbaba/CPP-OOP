#include <iostream>

#include "String.h"

int main(int argc, char* argv[])
{
    String string{"Hello"};
    std::cout << string.GetString() << '\n';
    std::cout << string.Length() << '\n';
    std::cout << string.Front() << '\n';
    std::cout << string.Back() << '\n';
    string.Append(" World");
    string.AddSymbol('!');
    std::cout << string.GetString() << '\n';
    std::cout << string.Find('l') << '\n';
    std::cout << string.Find('l', true) << '\n';
    std::cout << string.Length() << '\n';
    string.Clear();
    std::cout << string.Length() << '\n';
    std::cout << string.GetString() << '\n';
    String string2{"Jumaysinba!"};
    string.Append(string2);
    std::cout << string.GetString() << '\n';
    std::cout << string.Length() << '\n';
    String string3{string2};
    string3.AddSymbol('!');
    std::cout << string3.GetString() << '\n';
    auto substring = string.Substring(3, 4);
    std::cout << substring.GetString() << '\n';
    
    
    return 0;
}
