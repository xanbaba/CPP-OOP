#include "IntArray.h"
#include <iostream>

IntArray::IntArray() : IntArray(16)
{
}

IntArray::IntArray(const int a_capacity)
{
    array = new int[a_capacity]{};
    m_size = 0;
    m_capacity = a_capacity;
}

IntArray::IntArray(const IntArray& a_original)
{
    m_size = a_original.m_size;
    m_capacity = a_original.m_capacity;
    array = new int[m_capacity]{};
    for (int i = 0; i < m_size; ++i)
    {
        array[i] = a_original.array[i];
    }
}

IntArray::IntArray(IntArray&& a_original) noexcept
{
    m_size = a_original.m_size;
    m_capacity = a_original.m_capacity;
    array = a_original.array;
    a_original.m_size = 0;
    a_original.m_capacity = 0;
    a_original.array = nullptr;
}

IntArray::~IntArray()
{
    delete[] array;
}


void IntArray::append(int value)
{
    if (m_size == m_capacity)
    {
        reallocate();
    }

    array[m_size] = value;
    ++m_size;
}

void IntArray::prepend(int value)
{
    if (m_size == m_capacity)
    {
        reallocate();
    }
    move_array_right();
    array[0] = value;
    ++m_size;
}

void IntArray::reallocate()
{
    m_capacity *= 2;
    const auto new_array = new int[m_capacity]{};

    for (int i = 0; i < m_size; ++i)
    {
        new_array[i] = array[i];
    }

    delete[] array;
    array = new_array;
}

void IntArray::move_array_right()
{
    for (int i = m_size; i > 0; --i)
    {
        array[i] = array[i - 1];
    }
    array[0] = 0;
}

int IntArray::get(const int index) const
{
    return array[index];
}


int IntArray::length() const
{
    return m_size;
}

int IntArray::get_capacity() const
{
    return m_capacity;
}

bool IntArray::is_empty() const
{
    return m_size == 0;
}

void IntArray::sort()
{
    for (int i = 0; i < m_size; i++)
    {
        bool is_sorted = true;
        for (int j = 0; j < m_size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j];

                array[j] = array[j + 1];
                array[j + 1] = temp;
                is_sorted = false;
            }
        }
        if (is_sorted)
        {
            break;
        }
    }
}

IntArray& IntArray::operator=(const IntArray& a_original)
{
    if (this != &a_original)
    {
        this->~IntArray();
        m_size = a_original.m_size;
        m_capacity = a_original.m_capacity;
        array = new int[m_capacity]{};
        for (int i = 0; i < m_size; ++i)
        {
            array[i] = a_original.array[i];
        }
    }

    return *this;
}

IntArray& IntArray::operator=(IntArray&& a_original) noexcept
{
    if (this != &a_original)
    {
        this->~IntArray();
        m_size = a_original.m_size;
        m_capacity = a_original.m_capacity;
        array = a_original.array;
        a_original.m_size = 0;
        a_original.m_capacity = 0;
        a_original.array = nullptr;
    }
    return *this;
}

int& IntArray::operator[](int a_index)
{
    return array[a_index];
}

int IntArray::operator[](int a_index) const
{
    return array[a_index];
}

IntArray IntArray::operator+(const IntArray& a_original) const
{
    IntArray copy_array{*this};
    for (int i = 0; i < a_original.m_size; ++i)
    {
        copy_array.append(a_original[i]);
    }
    return copy_array;
}

std::ostream& operator<<(std::ostream& os, const IntArray& a_int_array)
{
    os << "[ ";
    for (int i = 0; i < a_int_array.m_size - 1; ++i)
    {
        os << a_int_array.array[i] << ", ";
    }
    os << a_int_array.array[a_int_array.m_size - 1] << " ]";
    return os;
}

std::istream& operator>>(std::istream& is, IntArray& a_int_array)
{
    for (int i = 0; i < a_int_array.m_capacity; ++i)
    {
        is >> a_int_array[i];
    }
    a_int_array.m_size = a_int_array.m_capacity;
    return is;
}
