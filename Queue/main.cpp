#include "Queue.h"

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

std::ostream& operator<<(std::ostream& out, User queue)
{
    out << 1;
    return out;
}

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
    
        Queue<User> queue_user{2};
    
        queue_user.Push(User{});
        queue_user.Pop();
        queue_user.Push(User{});
        std::cout << queue_user.Count() << '\n';
        //
        queue_user.Push(User{});
        queue_user.Push(User{});
        
        queue_user.Pop();
        queue_user.Pop();
        queue_user.Pop();

        std::cout << queue_user << "\n---------------\n";

        Queue<User> queue_user2{queue_user};
        queue_user2.Push(User{});
        queue_user2.Push(User{});
        queue_user2.Push(User{});
        std::cout << queue_user2 << "\n---------------\n";
        queue_user2.Pop();
        std::cout << queue_user2 << "\n---------------\n";
        //
        Queue<User> queue_user3;
        queue_user3 = queue_user2;
        queue_user3.Pop();
        queue_user3.Push(User{});
        queue_user3.Push(User{});
        queue_user3.Push(User{});
        std::cout << queue_user3 << "\n---------------\n";
        //
        //
        Queue<User> queue_user4 = std::move(queue_user3);
        queue_user4.Push(User{});
        std::cout << queue_user4 << "\n---------------\n";
        std::cout << queue_user4 << "\n---------------\n";
        //
        Queue<User> queue_user5;
        queue_user5 = std::move(queue_user4);
        queue_user5.Push(User{});
        queue_user5.Pop();
        queue_user5.Pop();
        queue_user5.Pop();
        queue_user5.Pop();
        std::cout << queue_user5 << "\n---------------\n";
        std::cout << queue_user4 << "\n---------------\n";
        std::cout << std::boolalpha << queue_user5.IsEmpty();
    }
}
