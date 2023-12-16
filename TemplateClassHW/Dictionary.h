#pragma once
#include "KeyValue.h"
#include <iostream>

template <typename KeyT, typename ValueT>
class Dictionary
{
public:
    Dictionary();
    Dictionary(const Dictionary& a_original);
    Dictionary(Dictionary&& a_original) noexcept;
    Dictionary& operator=(const Dictionary& a_original);
    Dictionary& operator=(Dictionary&& a_original) noexcept;
    ValueT& operator[](const KeyT& a_key);
    ~Dictionary();

private:
    int m_size;
    int m_capacity;
    KeyValue<KeyT, ValueT>* key_value_array;
};

template <typename KeyT, typename ValueT>
Dictionary<KeyT, ValueT>::Dictionary()
{
    m_capacity = 16;
    m_size = 0;
    key_value_array = new KeyValue<KeyT, ValueT>[m_capacity]{};
}

template <typename KeyT, typename ValueT>
Dictionary<KeyT, ValueT>::Dictionary(const Dictionary& a_original)
{
    m_capacity = a_original.m_capacity;
    m_size = a_original.m_size;
    key_value_array = new KeyValue<KeyT, ValueT>[m_capacity]{};
    for (int i = 0; i < m_size; ++i)
    {
        key_value_array[i].key = a_original.key_value_array[i].key;
        key_value_array[i].value = a_original.key_value_array[i].value;
    }
}

template <typename KeyT, typename ValueT>
Dictionary<KeyT, ValueT>::Dictionary(Dictionary&& a_original) noexcept
{
    m_capacity = a_original.m_capacity;
    m_size = a_original.m_size;
    key_value_array = a_original.key_value_array;

    a_original.m_capacity = 0;
    a_original.m_size = 0;
    a_original.key_value_array = nullptr;
}

template <typename KeyT, typename ValueT>
Dictionary<KeyT, ValueT>& Dictionary<KeyT, ValueT>::operator=(const Dictionary& a_original)
{
    if (this != &a_original)
    {
        this->~Dictionary();
        
        m_capacity = a_original.m_capacity;
        m_size = a_original.m_size;
        key_value_array = new KeyValue<KeyT, ValueT>[m_capacity]{};
        for (int i = 0; i < m_size; ++i)
        {
            key_value_array[i].key = a_original.key_value_array[i].key;
            key_value_array[i].value = a_original.key_value_array[i].value;
        }
    }
    return *this;
}


template <typename KeyT, typename ValueT>
Dictionary<KeyT, ValueT>& Dictionary<KeyT, ValueT>::operator=(Dictionary&& a_original) noexcept
{
    if (this != &a_original)
    {
        this->~Dictionary();
        
        m_capacity = a_original.m_capacity;
        m_size = a_original.m_size;
        key_value_array = a_original.key_value_array;

        a_original.m_capacity = 0;
        a_original.m_size = 0;
        a_original.key_value_array = nullptr;
    }
    return *this;
}

template <typename KeyT, typename ValueT>
ValueT& Dictionary<KeyT, ValueT>::operator[](const KeyT& a_key)
{
    for (int i = 0; i < m_size; ++i)
    {
        if (key_value_array[i].key == a_key)
        {
            return key_value_array[i].value;
        }
    }

    if (m_size == m_capacity)
    {
        m_capacity *= 2;
        auto new_key_value_array = new KeyValue<KeyT, ValueT>[m_capacity];
        for (int i = 0; i < m_size; ++i)
        {
            new_key_value_array[i].key = key_value_array->key;
            new_key_value_array[i].value = key_value_array->value;
        }
        this->~Dictionary();
        key_value_array = new_key_value_array;
    }
    key_value_array[m_size].key = a_key;
    ++m_size;
    return key_value_array[m_size - 1].value;
}

template <typename KeyT, typename ValueT>
Dictionary<KeyT, ValueT>::~Dictionary()
{
    delete[] key_value_array;
}
