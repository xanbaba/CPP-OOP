﻿#pragma once

class IntArray
{
public:
    IntArray();
    IntArray(int a_capacity);
    ~IntArray();
    void append(int value);
    void prepend(int value);
    int get(int index);
    int length();
    int get_capacity();
    bool is_empty();
    void sort(bool reverse = false);
private:
    int m_size;
    int m_capacity;
    int* array;
    
    void reallocate();
    void move_array_right();
};
