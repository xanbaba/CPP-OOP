#include <iostream>

#include "LinkedList.h"

// TEST CLASS TO TEST LIST WITH OBJECTS
// --------------------------------------------------- //
class User
{
public:
    ~User()
    {
        delete[] data;
    }

    User()
    {
        data = new int[5];
    }

    User(const User& a_other)
    {
        data = new int[5];
        memcpy(data, a_other.data, sizeof(int) * 5);
    }

    User& operator=(const User& a_other)
    {
        if (this != &a_other)
        {
            this->~User();
            data = new int[5];
            memcpy(data, a_other.data, sizeof(int) * 5);
        }
        return *this;
    }

    int* data;
};

// TEST CLASS TO TEST LIST WITH OBJECTS
// --------------------------------------------------- //


std::ostream& operator<<(std::ostream& out, User queue)
{
    out << 1;
    return out;
}

int main(int argc, char* argv[])
{
    while (true)
    {
        {
            LinkedList<int> LList;
            auto el1 = LList.PushBack(10);
            LList.Remove(el1);
            auto el2 = LList.PushBack(20);
            LList.PushBack(30);
            LList.InsertAfter(40, el2);
            LList.PushBack(50);
            LList.PopBack();
            LList.PopFront();
            LList.PushBack(15);
            LList.InsertAfter(25, LList.GetHeadNode());
            std::cout << LList << '\n';
            std::cout << LList.GetHeadNode()->Value << "\n\n";

            LinkedList<int> LListEmpty;

            LinkedList<int> LList2{LList};
            std::cout << LList2 << '\n';

            LinkedList<int> LList3{LListEmpty};

            LinkedList<int> LList4;
            LList4 = LList2;
            std::cout << LList4 << '\n';

            LinkedList<int> LList5;
            LList5 = LListEmpty;
            std::cout << LList5 << '\n';
        }
        
        {
            LinkedList<User> LList;
            auto el1 = LList.PushBack(User{});
            LList.Remove(el1);
            auto el2 = LList.PushBack(User{});
            LList.PushBack(User{});
            LList.InsertAfter(User{}, el2);
            LList.PushBack(User{});
            LList.PopBack();
            LList.PopFront();
            LList.PushBack(User{});
            LList.InsertAfter(User{}, LList.GetHeadNode());
            std::cout << LList << '\n';
            std::cout << LList.GetHeadNode()->Value << "\n\n";

            LinkedList<User> LListEmpty;

            LinkedList<User> LList2{LList};
            std::cout << LList2 << '\n';

            LinkedList<User> LList3{LListEmpty};

            LinkedList<User> LList4;
            LList4 = LList2;
            std::cout << LList4 << '\n';

            LinkedList<User> LList5;
            LList5 = LListEmpty;
            std::cout << LList5 << '\n';
        }
    }
    return 0;
}
