#include <iostream>
#define print(...) {Print(...);}

template <typename T> // Generic
class Array
{
public:
    Array(int a_capacity = 10)
    {
        std::cout << "Array<T>" << '\n';
        m_data = new T[a_capacity];
    }

    ~Array()
    {
        delete[] m_data;
    }

    T* GetData()
    {
        return m_data;
    }

private:
    T* m_data;
};

template <> // concrete
class Array<char>
{
public:
    Array(int a_capacity = 15)
    {
        std::cout << "Array<char>" << '\n';
        m_data = new char[a_capacity];
    }

    ~Array()
    {
        delete[] m_data;
    }

    char* GetCharData()
    {
        return m_data;
    }

private:
    char* m_data;
};

template <typename T>
class Array<T*>
{
public:
    Array(int a_capacity = 15)
    {
        std::cout << "Array<T*>" << '\n';
        m_data = static_cast<T*>(operator new(sizeof(T) * a_capacity));
    }

    ~Array()
    {
        operator delete(m_data);
    }

private:
    T* m_data;
};

template <typename T, int Size>
class FixedArray
{
public:
    FixedArray()
    {
        std::cout << "Array<T, int>" << '\n';
    }

private:
    T m_data[Size];
};

class A
{
public:
    A()
    {
        std::cout << "A()" << '\n';
    }
};

template <int Size>
void foo(int (&arr)[Size])
{
    for (int i = 0; i < Size; ++i)
    {
        std::cout << arr[i] << '\n';
    }
}

template <typename... Args>
void Print(Args&&... args)
{
    ((std::cout << args << ' '), ...);
    std::cout << '\n';
}


int main(int argc, char* argv[])
{
    Array<int> int_array;
    Array<char> char_array;
    auto ptr = int_array.GetData();
    auto ptr2 = char_array.GetCharData();
    Array<int*> int_ptr_array;
    FixedArray<int, 4> fixed_array;
    FixedArray<int, 10> fixed_array2;
    FixedArray<int, 17> fixed_array3;

    int arr[4]{1, 2, 3, 4};
    foo(arr);

    print(23, 12.5f, "Hello", true)

    return 0;
}
