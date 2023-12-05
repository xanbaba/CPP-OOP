#pragma once

class IntArray
{
public:
    IntArray();
    IntArray(int a_capacity);
    IntArray(const IntArray& a_original);
    ~IntArray();
    void append(int value);
    void prepend(int value);
    int get(int index);
    int length();
    int get_capacity();
    bool is_empty();
    void sort(bool reverse = false);
    int& operator[](int a_index);
    int operator[](int a_index) const;
    IntArray operator+(const IntArray& a_original);
private:
    int m_size;
    int m_capacity;
    int* array;
    
    void reallocate();
    void move_array_right();
};
