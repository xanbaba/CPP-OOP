#include <iostream>
#include "String.h"

int main(int argc, char* argv[])
{
    // while (true)
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

        String string4{"   Hello World!     "};
        String string5{string4};
        std::cout << string4.Compare(string5) << '\n';
        string5.Trim();
        string5.ToUpper();
        std::cout << string5.GetString() << '\"' << '\n';
        string4.LeftTrim();
        std::cout << string4.GetString() << '\"' << '\n';
        string4.RightTrim();
        string4.ToLower();
        string4.Reverse();
        std::cout << string4.GetString() << '\"' << '\n';
        std::cout << string4.Length() << '\n';
        std::cout << string4.StartsWith(String{"ed"}) << '\n';
        std::cout << string4.EndsWith(String{"leh"}) << '\n';
    }
    return 0;
}
