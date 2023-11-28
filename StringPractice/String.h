#pragma once

class String
{
public:
    String();
    String(const char* str);
    String(const String& original_string);
    ~String();
    const char* GetString() const;
    int Length() const;
    char Front() const;
    char Back() const;
    bool IsEmpty() const;
    void AddSymbol(char symbol);
    void Append(const char* str);
    void Append(const String&);
    int Find(char symbol, bool reverse = false) const;
    void Clear();
    String Substring(int start_index, int symbols_count);
    void LeftTrim();
    void RightTrim();
private:
    char* m_string_array;
    int m_size;
    int m_capacity;

    void Reallocate();
};
