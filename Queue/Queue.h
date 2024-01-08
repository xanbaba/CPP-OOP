#pragma once
#include <iostream>

template <typename T>
class Queue
{

public:
    // destructor
    ~Queue();

    // constructors
    Queue();
    Queue(size_t a_capacity);
    Queue(const Queue& a_original);
    Queue(Queue&& a_original) noexcept;

    // operators
    Queue& operator=(const Queue& a_original);
    Queue& operator=(Queue&& a_original) noexcept;

    // methods
    T& Front();
    T& Back();
    T Pop();
    void Push(const T& a_element);
    size_t Count() const;
    bool IsEmpty() const;

private:
    T* m_data;
    size_t m_size;
    size_t m_capacity;
    size_t m_start_index;

    // default capacity
    constexpr static size_t default_capacity = 16;

    // memory management methods
    void Shrink();
    void Reallocate();
};

template <typename T>
Queue<T>::~Queue()
{
    for (size_t i = 0; i < m_size; ++i)
    {
        m_data[m_start_index + i].~T();
    }

    operator delete(m_data);
}

template <typename T>
Queue<T>::Queue() : Queue(default_capacity)
{
}

template <typename T>
Queue<T>::Queue(size_t a_capacity)
{
    m_size = m_start_index = 0;
    m_capacity = a_capacity;

    m_data = static_cast<T*>(operator new(sizeof(T) * m_capacity));
}

template <typename T>
Queue<T>::Queue(const Queue& a_original)
{
    m_size = a_original.m_size;
    m_capacity = a_original.m_capacity;
    m_start_index = 0;

    m_data = static_cast<T*>(operator new(sizeof(T) * m_capacity));

    for (size_t i = 0; i < m_size; ++i)
    {
        new(m_data + i) T{a_original.m_data[a_original.m_start_index + i]};
    }
}

template <typename T>
Queue<T>::Queue(Queue&& a_original) noexcept
{
    m_size = a_original.m_size;
    a_original.m_size = 0;

    m_capacity = a_original.m_capacity;
    a_original.m_capacity = 0;

    m_start_index = a_original.m_start_index;
    a_original.m_start_index = 0;

    m_data = a_original.m_data;
    a_original.m_data = nullptr;
}

template <typename T>
Queue<T>& Queue<T>::operator=(const Queue& a_original)
{
    if (this != &a_original)
    {
        this->~Queue();

        m_size = a_original.m_size;
        m_capacity = a_original.m_capacity;
        m_start_index = 0;

        m_data = static_cast<T*>(operator new(sizeof(T) * m_capacity));

        for (size_t i = 0; i < m_size; ++i)
        {
            new(m_data + i) T{a_original.m_data[a_original.m_start_index + i]};
        }
    }

    return *this;
}

template <typename T>
Queue<T>& Queue<T>::operator=(Queue&& a_original) noexcept
{
    if (this != &a_original)
    {
        this->~Queue();

        m_size = a_original.m_size;
        a_original.m_size = 0;

        m_capacity = a_original.m_capacity;
        a_original.m_capacity = 0;

        m_start_index = a_original.m_start_index;
        a_original.m_start_index = 0;

        m_data = a_original.m_data;
        a_original.m_data = nullptr;
    }

    return *this;
}

template <typename T>
T& Queue<T>::Front()
{
    return m_data[m_start_index];
}

template <typename T>
T& Queue<T>::Back()
{
    return m_data[m_start_index + m_size - 1];
}

template <typename T>
T Queue<T>::Pop()
{
    T popped_element = m_data[m_start_index];
    m_data[m_start_index].~T();
    --m_size;
    ++m_start_index;
    return popped_element;
}

template <typename T>
void Queue<T>::Push(const T& a_element)
{
    if (m_start_index + m_size == m_capacity)
    {
        if (m_start_index > 0)
        {
            Shrink();
        }
        else
        {
            Reallocate();
        }
    }

    new(m_data + m_start_index + m_size) T{a_element};
    ++m_size;
}

template <typename T>
size_t Queue<T>::Count() const
{
    return m_size;
}

template <typename T>
bool Queue<T>::IsEmpty() const
{
    return m_size == 0;
}

template <typename T>
void Queue<T>::Shrink()
{
    for (size_t i = 0; i < m_size; ++i)
    {
        m_data[i] = m_data[m_start_index + i];
    }

    m_data[m_start_index + m_size - 1].~T();

    m_start_index = 0;
}

template <typename T>
void Queue<T>::Reallocate()
{
    m_capacity *= 2;
    T* new_data = static_cast<T*>(operator new(sizeof(T) * m_capacity));
    for (size_t i = 0; i < m_size; ++i)
    {
        new(new_data + i) T{m_data[m_start_index + i]};
    }
    this->~Queue();
    m_data = new_data;
    m_start_index = 0;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, Queue<T> queue)
{
    size_t queue_size = queue.Count();
    for (size_t i = 0; i < queue_size; ++i)
    {
        out << queue.Pop() << '\n';
    }
    return out;
}
