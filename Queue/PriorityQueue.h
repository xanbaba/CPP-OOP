#pragma once
#include <iostream>

template <typename T, template<typename > typename Comparor>
class PriorityQueue
{
public:
    // destructor
    ~PriorityQueue()
    {
        for (size_t i = 0; i < m_size; ++i)
        {
            m_data[m_start_index + i].~T();
        }

        operator delete(m_data);
    }

    // constructors
    PriorityQueue() : PriorityQueue(default_capacity)
    {
    }

    PriorityQueue(size_t a_capacity)
    {
        m_size = 0;
        m_start_index = 0;
        m_capacity = a_capacity;

        m_data = static_cast<T*>(operator new(sizeof(T) * m_capacity));
    }

    PriorityQueue(const PriorityQueue& a_original)
    {
        m_size = a_original.m_size;
        m_capacity = a_original.m_capacity;
        m_start_index = 0;

        m_data = static_cast<T*>(operator new(sizeof(T) * m_capacity));

        for (size_t i = 0; i < m_size; ++i)
        {
            new(m_data + i) T{a_original.m_data[a_original.m_start_index + i]};
        }
    }

    PriorityQueue(PriorityQueue&& a_original) noexcept
    {
        m_size = a_original.m_size;
        a_original.m_size = 0;

        m_capacity = a_original.m_capacity;
        a_original.m_capacity = 0;

        m_start_index = a_original.m_start_index;
        a_original.m_start_index = 0;

        m_data = a_original.m_data;
        a_original.m_data = nullptr;
    }

    // operators
    PriorityQueue& operator=(const PriorityQueue& a_original)
    {
        if (this != &a_original)
        {
            this->~PriorityQueue();

            m_size = a_original.m_size;
            m_capacity = a_original.m_capacity;
            m_start_index = 0;

            m_data = static_cast<T*>(operator new(sizeof(T) * m_capacity));

            for (size_t i = 0; i < m_size; ++i)
            {
                new(m_data + i) T{a_original.m_data[a_original.m_start_index + i]};
            }
        }

        return *this;
    }

    PriorityQueue& operator=(PriorityQueue&& a_original) noexcept
    {
        if (this != &a_original)
        {
            this->~PriorityQueue();

            m_size = a_original.m_size;
            a_original.m_size = 0;

            m_capacity = a_original.m_capacity;
            a_original.m_capacity = 0;

            m_start_index = a_original.m_start_index;
            a_original.m_start_index = 0;

            m_data = a_original.m_data;
            a_original.m_data = nullptr;
        }

        return *this;
    }

    // methods
    T& Front()
    {
        return m_data[m_start_index];
    }

    T& Back()
    {
        return m_data[m_start_index + m_size - 1];
    }

    T Pop()
    {
        T deleted_element = m_data[m_start_index];
        m_data[m_start_index].~T();
        ++m_start_index;
        --m_size;
        return deleted_element;
    }

    void MoveQueueUp(size_t move_start_index)
    {
        if (move_start_index == m_size)
        {
            return;
        }

        for (size_t i = m_start_index + m_size - move_start_index; i > m_start_index; --i)
        {
            if (i != m_start_index + m_size - move_start_index)
            {
               m_data[move_start_index + i].~T(); 
            }
            
            new(m_data + move_start_index + i) T{m_data[move_start_index + i - 1]};
        }
    }

    void Push(const T& a_element)
    {
        if (m_start_index + m_size == m_capacity)
        {
            if (m_start_index > 0)
            {
                Shrink();
            }
            else
            {
                Reallocate();
            }
        }

        Comparor<T> comparor;
        PriorityQueue priority_queue_copy{*this};

        size_t push_index = m_size;

        for (int i = 0; i < m_size; ++i)
        {
            auto current_element = priority_queue_copy.Pop();
            if (comparor(a_element, current_element))
            {
                push_index = i;
                break;
            }
        }

        MoveQueueUp(push_index);
        if (push_index != m_start_index + m_size)
        {
            m_data[m_start_index + push_index].~T();
        }

        new(m_data + m_start_index + push_index) T{a_element};

        ++m_size;
    }

    size_t Count() const
    {
        return m_size;
    }

    bool IsEmpty() const
    {
        return m_size == 0;
    }

private:
    T* m_data;
    size_t m_size;
    size_t m_capacity;
    size_t m_start_index;

    // default capacity
    constexpr static size_t default_capacity = 16;

    // memory management methods
    void Shrink()
    {
        for (size_t i = 0; i < m_size; ++i)
        {
            new(m_data + i) T{m_data[m_start_index + i]};
            m_data[m_start_index + i].~T();
        }
        m_start_index = 0;
    }

    void Reallocate()
    {
        m_capacity *= 2;
        T* new_data = static_cast<T*>(operator new(sizeof(T) * m_capacity));
        for (size_t i = 0; i < m_size; ++i)
        {
            new(new_data + i) T{m_data[m_start_index + i]};
        }
        this->~PriorityQueue();
        m_data = new_data;
        m_start_index = 0;
    }
};

template <typename T, template<typename> typename Comparor>
std::ostream& operator<<(std::ostream& out, PriorityQueue<T, Comparor> priority_queue)
{
    const size_t queue_size = priority_queue.Count();
    for (size_t i = 0; i < queue_size; ++i)
    {
        out << priority_queue.Pop() << '\n';
    }
    return out;
}
