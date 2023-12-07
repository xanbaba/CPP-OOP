#include "Clock.h"

Clock::Clock() : m_hours(0), m_minutes(0) {}

Clock::Clock(const int a_hours, const int a_minutes)
{
    if (a_hours > 23 || a_hours < 0 || a_minutes > 59 || a_minutes < 0)
    {
        m_hours = 0;
        m_minutes = 0;
        return;
    }
    m_hours = a_hours;
    m_minutes = a_minutes;
}

int Clock::get_hours() const
{
    return m_hours;
}

int Clock::get_minutes() const
{
    return m_minutes;
}

void Clock::operator++()
{
    ++m_minutes;
    if (m_minutes == 60)
    {
        m_minutes = 0;
        ++m_hours;
        if (m_hours == 24)
        {
            m_hours = 0;
        }
    }
}

Clock Clock::operator++(int)
{
    const Clock copy_clock{*this};
    ++*this;
    return copy_clock;
}

void Clock::operator--()
{
    --m_minutes;
    if (m_minutes == -1)
    {
        m_minutes = 59;
        --m_hours;
        if (m_hours == -1)
        {
            m_hours = 23;
        }
    }
}

Clock Clock::operator--(int)
{
    const Clock copy_clock{*this};
    --*this;
    return copy_clock;
}

bool Clock::operator>(const Clock& a_other_clock) const
{
    if (m_hours > a_other_clock.m_hours)
    {
        return true;
    }
    if (m_minutes > a_other_clock. m_minutes)
    {
        return true;
    }

    return false;
}

bool Clock::operator<(const Clock& a_other_clock) const
{
    if (m_hours < a_other_clock.m_hours)
    {
        return true;
    }
    if (m_minutes < a_other_clock. m_minutes)
    {
        return true;
    }

    return false;
}

bool Clock::operator>=(const Clock& a_other_clock) const
{
    if (m_hours >= a_other_clock.m_hours)
    {
        return true;
    }
    if (m_minutes >= a_other_clock. m_minutes)
    {
        return true;
    }

    return false;
}

bool Clock::operator<=(const Clock& a_other_clock) const
{
    if (m_hours <= a_other_clock.m_hours)
    {
        return true;
    }
    if (m_minutes <= a_other_clock. m_minutes)
    {
        return true;
    }

    return false;
}

bool Clock::operator!=(const Clock& a_other_clock) const
{
    if (m_hours != a_other_clock.m_hours)
    {
        return true;
    }
    if (m_minutes != a_other_clock. m_minutes)
    {
        return true;
    }

    return false;
}

bool Clock::operator==(const Clock& a_other_clock) const
{
    if (m_hours == a_other_clock.m_hours)
    {
        return true;
    }
    if (m_minutes == a_other_clock. m_minutes)
    {
        return true;
    }

    return false;
}
