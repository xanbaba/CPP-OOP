#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class Random
{
public:
    Random()
    {
        m_seed = 1;
    }
    size_t operator()(long long a_min, long long a_max)
    {
        auto seed = time(nullptr);
        if (seed % 10 % 2 == 0)
        {
            seed -= m_seed++;
        }
        else
        {
            seed += m_seed++;
        }
        size_t random_value = m_seed * seed %(a_max-a_min+1)+a_min;
        m_seed += random_value * seed % 100 + seed % 10;
        if (m_seed % 2 == 0)
        {
            m_seed += seed % 100 + seed % 10;
        }
        else
        {
            m_seed = seed;
        }
        
        return random_value;
    }
private:
    size_t m_seed;
};

int main(int argc, char* argv[])
{
    Random rand;
    std::cout << rand(1, 10) << '\n';
    std::cout << rand(1, 10) << '\n';
    return 0;
}
