#pragma once

template <typename T>
class UniquePtr
{
public:
    ~UniquePtr();
    UniquePtr(T* a_data);
    UniquePtr(const UniquePtr&) = delete;
    UniquePtr(UniquePtr&& a_original) noexcept;
    UniquePtr& operator=(const UniquePtr&) = delete;
    UniquePtr& operator=(UniquePtr&& a_original) noexcept;

    T& operator*();
    T* operator->();

private:
    T* m_data;
};

template <typename T>
UniquePtr<T>::~UniquePtr()
{
    delete m_data;
}

template <typename T>
UniquePtr<T>::UniquePtr(T* a_data) : m_data(a_data)
{
}

template <typename T>
UniquePtr<T>::UniquePtr(UniquePtr&& a_original) noexcept
{
    m_data = a_original.m_data;
    a_original.m_data = nullptr;
}

template <typename T>
UniquePtr<T>& UniquePtr<T>::operator=(UniquePtr&& a_original) noexcept
{
    if (this != &a_original)
    {
        this->~UniquePtr();
        m_data = a_original.m_data;
        a_original.m_data = nullptr;
    }

    return *this;
}

template <typename T>
T& UniquePtr<T>::operator*()
{
    return *m_data;
}

template <typename T>
T* UniquePtr<T>::operator->()
{
    return m_data;
}


//////////////////////////////////////////////


template <typename T>
class UniquePtr<T[]>
{
public:
    ~UniquePtr();
    UniquePtr(T* a_data);
    UniquePtr(const UniquePtr&) = delete;
    UniquePtr(UniquePtr&& a_original) noexcept;
    UniquePtr& operator=(const UniquePtr&) = delete;
    UniquePtr& operator=(UniquePtr&& a_original) noexcept;

    T& operator*();
    T* operator->();
    T& operator[](size_t index);
private:
    T* m_data;
};

template <typename T>
UniquePtr<T[]>::~UniquePtr()
{
    delete[] m_data;
}

template <typename T>
UniquePtr<T[]>::UniquePtr(T* a_data) : m_data(a_data)
{
}

template <typename T>
UniquePtr<T[]>::UniquePtr(UniquePtr&& a_original) noexcept
{
    m_data = a_original.m_data;
    a_original.m_data = nullptr;
}

template <typename T>
UniquePtr<T[]>& UniquePtr<T[]>::operator=(UniquePtr&& a_original) noexcept
{
    if (this != &a_original)
    {
        this->~UniquePtr();
        m_data = a_original.m_data;
        a_original.m_data = nullptr;
    }

    return *this;
}

template <typename T>
T& UniquePtr<T[]>::operator*()
{
    return *m_data;
}

template <typename T>
T* UniquePtr<T[]>::operator->()
{
    return *m_data;
}

template <typename T>
T& UniquePtr<T[]>::operator[](size_t index)
{
    return m_data[index];
}
