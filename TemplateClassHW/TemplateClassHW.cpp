
#include "Dictionary.h"

int main(int argc, char* argv[])
{
    // while (true)
    {
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
    }
    return 0;
}
