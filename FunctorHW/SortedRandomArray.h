#pragma once
#include "Greater.h"
#include "IntArray.h"
#include "Less.h"
#include <random>

class SortedRandomArray
{
public:
    SortedRandomArray(int a_numbers_count);
    SortedRandomArray(const SortedRandomArray& a_original);
    SortedRandomArray(SortedRandomArray&& a_original) noexcept;
    SortedRandomArray& operator=(const SortedRandomArray& a_original);
    SortedRandomArray& operator=(SortedRandomArray&& a_original) noexcept;
    ~SortedRandomArray();
    void Sort(Greater a_greater);
    void Sort(Less a_less);
private:
    IntArray m_array;
    inline static std::default_random_engine m_engine{static_cast<unsigned int>(time(nullptr))};
    inline static std::uniform_int_distribution m_range{0, 99};
};
