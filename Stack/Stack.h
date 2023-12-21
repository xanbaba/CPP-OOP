#pragma once
#include <iostream>

template <typename T>
class Stack
{
    constexpr static size_t default_stack_capacity = 128;

public:
    ~Stack();
    Stack();
    Stack(int a_stack_size);
    Stack(const Stack& a_original);
    Stack(Stack&& a_original) noexcept;
    Stack& operator=(const Stack& a_original);
    Stack& operator=(Stack&& a_original) noexcept;

    // methods
    T& Peek();
    T& Pop();
    void Push(const T& a_element);
    int Size() const;
    void Swap(Stack& a_other);
    bool Empty() const;
private:
    T* m_stack_data;
    size_t m_capacity;
    size_t m_size;

    void Reallocate();
};

template <typename T>
Stack<T>::~Stack()
{
    operator delete(m_stack_data);
}

template <typename T>
Stack<T>::Stack() : Stack(default_stack_capacity) {}

template <typename T>
Stack<T>::Stack(int a_stack_size)
{
    m_stack_data = static_cast<T*>(operator new(a_stack_size * sizeof(T)));
    m_size = 0;
    m_capacity = a_stack_size;
}

template <typename T>
Stack<T>::Stack(const Stack& a_original)
{
    m_size = a_original.m_size;
    m_capacity = a_original.m_capacity;
    m_stack_data = static_cast<T*>(operator new(m_capacity * sizeof(T)));
    for (int i = 0; i < m_size; ++i)
    {
        m_stack_data[i] = a_original.m_stack_data[i];
    }
}

template <typename T>
Stack<T>::Stack(Stack&& a_original) noexcept
{
    m_size = a_original.m_size;
    m_capacity = a_original.m_capacity;
    m_stack_data = a_original.m_stack_data;

    a_original.m_size = 0;
    a_original.m_capacity = 0;
    a_original.m_stack_data = nullptr;
}

template <typename T>
Stack<T>& Stack<T>::operator=(const Stack& a_original)
{
    if (this != &a_original)
    {
        m_size = a_original.m_size;
        m_capacity = a_original.m_capacity;
        m_stack_data = static_cast<T*>(operator new(m_capacity * sizeof(T)));
        for (int i = 0; i < m_size; ++i)
        {
            m_stack_data[i] = a_original.m_stack_data[i];
        }
    }

    return *this;
}

template <typename T>
Stack<T>& Stack<T>::operator=(Stack&& a_original) noexcept
{
    if (this != &a_original)
    {
        m_size = a_original.m_size;
        m_capacity = a_original.m_capacity;
        m_stack_data = a_original.m_stack_data;

        a_original.m_size = 0;
        a_original.m_capacity = 0;
        a_original.m_stack_data = nullptr;
    }

    return *this;
}

template <typename T>
T& Stack<T>::Peek()
{
    return m_stack_data[m_size - 1];
}

template <typename T>
T& Stack<T>::Pop()
{
    --m_size;
    return m_stack_data[m_size];
}

template <typename T>
void Stack<T>::Push(const T& a_element)
{
    Reallocate();
    m_stack_data[m_size++] = a_element;
}

template <typename T>
int Stack<T>::Size() const
{
    return m_size;
}

template <typename T>
void Stack<T>::Swap(Stack& a_other)
{
    std::swap(m_capacity, a_other.m_capacity);
    std::swap(m_size, a_other.m_size);
    std::swap(m_stack_data, a_other.m_stack_data);
}

template <typename T>
bool Stack<T>::Empty() const
{
    return m_size == 0;
}

template <typename T>
void Stack<T>::Reallocate()
{
    if (m_size == m_capacity)
    {
        m_capacity += default_stack_capacity;
        T* new_data = static_cast<T*>(operator new(m_capacity * sizeof(T)));
        for (int i = 0; i < m_size; ++i)
        {
            new_data[i] = m_stack_data[i];
        }

        operator delete(m_stack_data);
        m_stack_data = new_data;
    }
}

template <typename T>
std::ostream& operator<<(std::ostream& out, Stack<T> stack)
{
    const int size = stack.Size();
    for (int i = 0; i < size; ++i)
    {
        out << stack.Pop() << '\n';
    }
    return out;
}
