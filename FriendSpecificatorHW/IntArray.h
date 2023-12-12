#pragma once
#include <iostream>

class IntArray
{
    friend std::ostream& operator<<(std::ostream& os, const IntArray& a_int_array);
    friend std::istream& operator>>(std::istream& is, IntArray& a_int_array);
public:
    IntArray();
    IntArray(int a_capacity);
    IntArray(const IntArray& a_original);
    IntArray(IntArray&& a_original) noexcept;
    ~IntArray();
    void append(int value);
    void prepend(int value);
    int get(int index) const;
    int length() const;
    int get_capacity() const;
    bool is_empty() const;
    void sort(bool reverse = false);
    IntArray& operator=(const IntArray& a_original);
    IntArray& operator=(IntArray&& a_original) noexcept;
    int& operator[](int a_index);
    int operator[](int a_index) const;
    IntArray operator+(const IntArray& a_original) const;
private:
    int m_size;
    int m_capacity;
    int* array;
    
    void reallocate();
    void move_array_right();
};
