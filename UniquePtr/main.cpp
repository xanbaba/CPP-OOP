#include <iostream>
#include "UniquePtr.h"

// class for testing purposes
class User
{
public:
    int a;
};
// class for testing purposes

int main(int argc, char* argv[])
{
    UniquePtr<int[]> ptr = new int[10]{10, 20, 30, 40};
    UniquePtr<int> ptr2 = new int{10};

    UniquePtr<User> user_ptr = new User{10};

    std::cout << user_ptr->a << '\n';
    std::cout << *ptr2 << '\n';
    std::cout << ptr[1] << '\n';
    std::cout << *ptr << '\n';

    return 0;
}
