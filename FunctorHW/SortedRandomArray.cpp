#include "SortedRandomArray.h"

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
{
    m_array = a_original.m_array;
    return *this;
}

SortedRandomArray& SortedRandomArray::operator=(SortedRandomArray&& a_original) noexcept
= default;

SortedRandomArray::~SortedRandomArray()
= default;
