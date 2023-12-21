#include "Array.h"
#include "Dictionary.h"
#include <string>

int main(int argc, char* argv[])
{
    // while (true)
    /*{
        {
            Dictionary<const char*, int> dictionary;
            dictionary["first"] = 10;
            dictionary["four"] = 4;
            Dictionary<const char*, int> dictionary2 = dictionary;
            std::cout << dictionary["first"] << '\n';
            std::cout << dictionary2["first"] << '\n';
            Dictionary<const char*, int> dictionary3;
            const char* second = "second";
            dictionary3[second] = 15;
            dictionary2 = dictionary3 = dictionary3;
            std::cout << dictionary3["second"] << '\n';
            dictionary3 = std::move(dictionary);
            Dictionary<const char*, int> dictionary4 = std::move(dictionary3);
            std::cout << dictionary4["four"] << '\n';
        }

        {
            Dictionary<std::string, int> dictionary;
            dictionary["first"] = 10;
            dictionary["four"] = 4;
            Dictionary<std::string, int> dictionary2 = dictionary;
            std::cout << dictionary["first"] << '\n';
            std::cout << dictionary2["first"] << '\n';
            Dictionary<std::string, int> dictionary3;
            dictionary3["second"] = 15;
            dictionary2 = dictionary3 = dictionary3;
            std::cout << dictionary3["second"] << '\n';
            dictionary3 = std::move(dictionary);
            Dictionary<std::string, int> dictionary4 = std::move(dictionary3);
            std::cout << dictionary4["four"] << '\n';
        }

        {
            Dictionary<std::string, int> dictionary;
            dictionary["first"] = 10;
            dictionary["four"] = 4;
            Dictionary<std::string, int> dictionary2 = dictionary;
            std::cout << dictionary["first"] << '\n';
            std::cout << dictionary2["first"] << '\n';
            Dictionary<std::string, int> dictionary3;
            dictionary3["second"] = 15;
            dictionary2 = dictionary3 = dictionary3;
            std::cout << dictionary3["second"] << '\n';
            dictionary3 = std::move(dictionary);
            Dictionary<std::string, int> dictionary4 = std::move(dictionary3);
            std::cout << dictionary4["four"] << '\n';
        }
    }*/

    // while (true)
    {
        Array<std::string> array1{2};
        array1.Prepend("Hello ");
        array1.Insert("World ", 1);
        array1.Append("!!!");
        Array<std::string> array2{array1};
        std::cout << array1 << '\n';
        array1.Append("I Love You!");
        std::cout << array1 << '\n';
        std::cout << array2 << '\n';
        Array<std::string> array3{std::move(array1)};
        std::cout << array3 << '\n';
        std::cout << array1 << '\n';
        Array<std::string> array4;
        array4 = array3;
        array3.Append("AA");
        std::cout << array4 << '\n';
        Array<std::string> array5;
        array5 = std::move(array3);
        std::cout << array3 << '\n';
        std::cout << array5 << '\n';
    }
    return 0;
}
