#pragma once
#include <iostream>

template <typename T>
class Array
{
public:
    ~Array();
    Array();
    Array(int a_capacity);
    Array(const Array& a_original);
    Array(Array&& a_original) noexcept;
    Array& operator=(const Array& a_original);
    Array& operator=(Array&& a_original) noexcept;
    T& operator[](int a_index);
    void Append(const T& a_item);
    void Prepend(const T& a_item);
    void Insert(const T& a_item, int a_index);
    int IndexOf(const T& a_item);
    int LastIndexOf(const T& a_item);
    int Size();
    int GetCapacity();
private:
    T* m_data;
    int m_size;
    int m_capacity;

    constexpr static int default_capacity = 16;

    void Reallocate();
    void MoveArrayRight(int start_index);
};

template <typename T>
Array<T>::~Array()
{
    delete[] m_data;
}

template <typename T>
Array<T>::Array() : Array(default_capacity) {}

template <typename T>
Array<T>::Array(int a_capacity)
{
    m_capacity = a_capacity;
    m_size = 0;
    m_data = new T[m_capacity];
}

template <typename T>
Array<T>::Array(const Array& a_original)
{
    m_capacity = a_original.m_capacity;
    m_size = a_original.m_size;
    m_data = new T[m_capacity];
    for (int i = 0; i < m_size; ++i)
    {
        m_data[i] = a_original.m_data[i];
    }
}

template <typename T>
Array<T>::Array(Array&& a_original) noexcept
{
    m_capacity = a_original.m_capacity;
    m_size = a_original.m_size;
    m_data = a_original.m_data;

    a_original.m_capacity = 0;
    a_original.m_size = 0;
    a_original.m_data = nullptr;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& a_original)
{
    if (this != &a_original)
    {
        this->~Array();
        
        m_capacity = a_original.m_capacity;
        m_size = a_original.m_size;
        m_data = new T[m_capacity];
        for (int i = 0; i < m_size; ++i)
        {
            m_data[i] = a_original.m_data[i];
        }
    }

    return *this;
}

template <typename T>
Array<T>& Array<T>::operator=(Array&& a_original) noexcept
{
    if (this != &a_original)
    {
        this->~Array();
        
        m_capacity = a_original.m_capacity;
        m_size = a_original.m_size;
        m_data = a_original.m_data;

        a_original.m_capacity = 0;
        a_original.m_size = 0;
        a_original.m_data = nullptr;
    }

    return *this;
}

template <typename T>
T& Array<T>::operator[](int a_index)
{
    return m_data[a_index];
}

template <typename T>
void Array<T>::Append(const T& a_item)
{
    if (m_size == m_capacity)
    {
        Reallocate();
    }

    m_data[m_size] = a_item;
    ++m_size;
}

template <typename T>
void Array<T>::Prepend(const T& a_item)
{
    Insert(a_item, 0);
}

template <typename T>
void Array<T>::Insert(const T& a_item, int a_index)
{
    if (m_size == m_capacity)
    {
        Reallocate();
    }
    MoveArrayRight(a_index);
    m_data[a_index] = a_item;
    ++m_size;
}

template <typename T>
int Array<T>::IndexOf(const T& a_item)
{
    for (int i = 0; i < m_size; ++i)
    {
        if (m_data[i] == a_item)
        {
            return i;
        }
    }

    return -1;
}

template <typename T>
int Array<T>::LastIndexOf(const T& a_item)
{
    for (int i = m_size - 1; i >= 0; --i)
    {
        if (m_data[i] == a_item)
        {
            return i;
        }
    }
    
    return -1;
}

template <typename T>
int Array<T>::Size()
{
    return m_size;
}

template <typename T>
int Array<T>::GetCapacity()
{
    return m_capacity;
}

template <typename T>
void Array<T>::Reallocate()
{
    m_capacity *= 2;
    T* new_data = new T[m_capacity];

    for (int i = 0; i < m_size; ++i)
    {
        new_data[i] = m_data[i];
    }

    delete[] m_data;
    m_data = new_data;
}

template <typename T>
void Array<T>::MoveArrayRight(int start_index)
{
    for (int i = m_size; i > start_index; --i)
    {
        m_data[i] = m_data[i - 1];
    }
}

template<typename T>
std::ostream& operator<<(std::ostream& out, Array<T>& array)
{
    out << "[ ";
    for (int i = 0; i < array.Size(); ++i)
    {
        out << array[i] << ", ";
    }
    out << "]";
    return out;
}
