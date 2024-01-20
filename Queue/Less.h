#pragma once

template <typename T>
class Less
{
public:
    bool operator()(const T& a_lhs, const T& a_rhs) const
    {
        return a_lhs < a_rhs;
    }
};
