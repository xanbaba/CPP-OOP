#define _CRT_SECURE_NO_WARNINGS
#include "String.h"
#include <iostream>

String::String()
{
    m_size = 0;
    m_capacity = 16;
    m_string_array = new char[m_capacity]{};
}

String::String(const char* str)
{
    const int str_len = static_cast<int>(strlen(str));
    m_size = str_len;
    m_capacity = str_len + 1;
    m_string_array = new char[m_capacity]{};
    strcpy(m_string_array, str);
}

String::String(const String& original_string)
{
    m_size = original_string.m_size;
    m_capacity = original_string.m_capacity;
    m_string_array = new char[m_capacity]{};
    strcpy(m_string_array, original_string.m_string_array);
}

String::~String()
{
    delete[] m_string_array;
}

const char* String::GetString() const
{
    return m_string_array;
}

int String::Length() const
{
    return m_size;
}

char String::Front() const
{
    return m_string_array[0];
}

char String::Back() const
{
    return m_string_array[m_size - 1];
}

bool String::IsEmpty() const
{
    return m_size == 0;
}

void String::AddSymbol(const char symbol)
{
    if (m_size + 1 == m_capacity)
    {
        Reallocate();
    }

    m_string_array[m_size] = symbol;
    ++m_size;
}

void String::Append(const char* str)
{
    const int str_len = static_cast<int>(strlen(str));
    for (int i = 0; i < str_len; ++i)
    {
        AddSymbol(str[i]);
    }
}

void String::Append(const String& str)
{
    Append(str.m_string_array);
}

int String::Find(const char symbol, bool reverse) const
{
    if (!reverse)
    {
        for (int i = 0; i < m_size; ++i)
        {
            if (m_string_array[i] == symbol)
            {
                return i;
            }
        }
        return -1;
    }
    
    for (int i = m_size - 1; i >= 0; --i)
    {
        if (m_string_array[i] == symbol)
        {
            return i;
        }
    }
    return -1;
}

void String::Clear()
{
    for (int i = 0; i < m_size; ++i)
    {
        m_string_array[i] = '\0';
    }

    m_size = 0;
}

String String::Substring(const int start_index, int symbols_count)
{
    if (start_index + symbols_count > m_size)
    {
        symbols_count = m_size - start_index;
    }
    String substring;
    for (int i = 0; i < symbols_count; ++i)
    {
        substring.AddSymbol(m_string_array[start_index + i]);
    }

    return substring;
}

void String::LeftTrim()
{
    
}

void String::RightTrim()
{
    
}

void String::Reallocate()
{
    m_capacity *= 2;
    const auto new_string_array = new char[m_capacity]{};
    for (int i = 0; i < m_size; ++i)
    {
        new_string_array[i] = m_string_array[i];
    }

    delete[] m_string_array;
    m_string_array = new_string_array;
}
