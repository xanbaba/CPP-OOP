#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
    {
        std::string s = "Hello C++ String";
        int a = 99;
        s += std::to_string(a);
        std::cout << s << '\n';
    }

    // append
    {
        std::string s = "C# ";
        std::string s2 = "C";
        s.append("C++ ");
        s.append(s2);
        std::cout << s << '\n';
    }

    // insert
    {
        std::string s = "C vs C++";
        s.insert(1, std::string{'#'});
        std::cout << s << '\n';
    }

    // erase
    {
        std::string s = "C++17";
        s.erase(3, 2);
        s += "23";
        std::cout << s << '\n';
    }

    // at
    {
        std::string s = "Javascript";

        std::cout << s[0] << '\n';
        std::cout << s.at(0) << '\n';
    }

    // reserve & shrink_to_fit
    {
        std::string s = "c++";
        std::cout << "capacity: " << s.capacity() << '\n';
        s.reserve(90);
        std::cout << "capacity: " << s.capacity() << '\n';
        s.shrink_to_fit();
        std::cout << "capacity: " << s.capacity() << '\n';

        std::cout << s << '\n';
    }
    
    // find & rfind
    {
        std::string s = "Hello world.";

        std::cout << s.find('o') << '\n';
        std::cout << s.rfind('o') << '\n';

    }

    {
        std::string s1 = "C++";
        std::string s2 = "C++";

        if (s1 == s2)
        {
            std::cout << "Equals" << '\n';
        }
    }
    return 0;
}
