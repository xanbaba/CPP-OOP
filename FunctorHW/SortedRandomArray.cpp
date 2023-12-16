#include "SortedRandomArray.h"
#include <iostream>

SortedRandomArray::SortedRandomArray(int a_numbers_count)
{
    for (int i = 0; i < a_numbers_count; ++i)
    {
        m_array.append(m_range(m_engine));
    }
}

SortedRandomArray::SortedRandomArray(const SortedRandomArray& a_original)
{
    m_array = a_original.m_array;
}

SortedRandomArray::SortedRandomArray(SortedRandomArray&& a_original) noexcept
{
    m_array = std::move(a_original.m_array);
}

SortedRandomArray& SortedRandomArray::operator=(const SortedRandomArray& a_original)
= default;

SortedRandomArray& SortedRandomArray::operator=(SortedRandomArray&& a_original) noexcept
= default;

SortedRandomArray::~SortedRandomArray()
= default;

void SortedRandomArray::Sort(const Greater& a_greater)
{
    for (int i = 0; i < m_array.length(); i++)
    {
        bool is_sorted = true;
        for (int j = 0; j < m_array.length() - i - 1; j++)
        {
            if (a_greater(m_array[j], m_array[j + 1]))
            {
                int temp = m_array[j];

                m_array[j] = m_array[j + 1];
                m_array[j + 1] = temp;
                is_sorted = false;
            }
        }
        if (is_sorted)
        {
            break;
        }
    }
}

void SortedRandomArray::Sort(const Less& a_less)
{
    for (int i = 0; i < m_array.length(); i++)
    {
        bool is_sorted = true;
        for (int j = 0; j < m_array.length() - i - 1; j++)
        {
            if (a_less(m_array[j], m_array[j + 1]))
            {
                int temp = m_array[j];

                m_array[j] = m_array[j + 1];
                m_array[j + 1] = temp;
                is_sorted = false;
            }
        }
        if (is_sorted)
        {
            break;
        }
    }
}

std::ostream& operator<<(std::ostream& lhs, const SortedRandomArray& rhs)
{
    lhs << "[ ";
    for (int i = 0; i < rhs.m_array.length() - 1; ++i)
    {
        lhs << rhs.m_array[i] << ", ";
    }
    lhs << rhs.m_array[rhs.m_array.length() - 1] << " ]";
    return lhs;
}


