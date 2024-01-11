#pragma once
#include <iostream>
#include <functional>

#include "Array.h"

template <typename T>
class HashSet
{
public:
    ~HashSet();

    HashSet();
    HashSet(const HashSet& a_original);
    HashSet(HashSet&& a_original) noexcept;
    HashSet& operator=(const HashSet& a_original);
    HashSet& operator=(HashSet&& a_original) noexcept;
    // methods
    void Add(const T& a_element);
    void Remove(const T& a_element);
    double GetLoadFactor();
private:
    size_t m_buckets_count = 10;
    std::hash<T> m_hash;
    Array<T>* m_buckets_array;

    void Reallocate();
};

template <typename T>
HashSet<T>::~HashSet()
{
    delete[] m_buckets_array;
}

template <typename T>
HashSet<T>::HashSet()
{
    m_buckets_array = new Array<T>[m_buckets_count];
}

template <typename T>
HashSet<T>::HashSet(const HashSet& a_original)
{
    m_buckets_count = a_original.m_buckets_count;
    m_buckets_array = new Array<T>[m_buckets_count];
    for (size_t i = 0; i < m_buckets_count; ++i)
    {
        m_buckets_array[i] = a_original.m_buckets_array[i];
    }
};

template <typename T>
HashSet<T>::HashSet(HashSet&& a_original) noexcept
{
    m_buckets_array = a_original.m_buckets_array;
    a_original.m_buckets_array = nullptr;

    m_buckets_count = a_original.m_buckets_count;
    a_original.m_buckets_count = 0;
}

template <typename T>
HashSet<T>& HashSet<T>::operator=(const HashSet& a_original)
{
    if (this != &a_original)
    {
        m_buckets_count = a_original.m_buckets_count;
        m_buckets_array = new Array<T>[m_buckets_count];
        for (size_t i = 0; i < m_buckets_count; ++i)
        {
            m_buckets_array[i] = a_original.m_buckets_array[i];
        }
    }

    return *this;
};

template <typename T>
HashSet<T>& HashSet<T>::operator=(HashSet&& a_original) noexcept
{
    if (this != &a_original)
    {
        m_buckets_array = a_original.m_buckets_array;
        a_original.m_buckets_array = nullptr;

        m_buckets_count = a_original.m_buckets_count;
        a_original.m_buckets_count = 0;
    }

    return *this;
};

template <typename T>
void HashSet<T>::Add(const T& a_element)
{
    auto hash_index = m_hash(a_element) % m_buckets_count;
    m_buckets_array[hash_index].Append(a_element);
    if (GetLoadFactor() > 0.7)
    {
        Reallocate();
    }
}

template <typename T>
void HashSet<T>::Remove(const T& a_element)
{
    size_t hash_index = m_hash(a_element) % m_buckets_count;
    m_buckets_array[hash_index].Pop(m_buckets_array[hash_index].IndexOf(a_element));
}

template <typename T>
double HashSet<T>::GetLoadFactor()
{
    size_t full_buckets{};
    for (int i = 0; i < m_buckets_count; ++i)
    {
        m_buckets_array[i].Size() == 0 ? ++full_buckets : 0;
    }

    return static_cast<double>(full_buckets) / static_cast<double>(m_buckets_count);
}

template <typename T>
void HashSet<T>::Reallocate()
{
    const size_t new_buckets_count = m_buckets_count * 2;
    auto new_data = m_buckets_array = new Array<T>[new_buckets_count];
    for (int i = 0; i < m_buckets_count; ++i)
    {
        for (int j = 0; j < m_buckets_array[i].Size(); ++j)
        {
            size_t hash_index = m_hash(m_buckets_array[i][j]) % new_buckets_count;
            new_data[hash_index].Append(std::move(m_buckets_array[i][j]));
        }
    }

    this->~HashSet();
    m_buckets_array = new_data;
    m_buckets_count = new_buckets_count;
}
