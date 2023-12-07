#pragma once

class Clock
{
public:
    Clock();
    Clock(int a_hours, int a_minutes);
    int get_hours() const;
    int get_minutes() const;
    void operator++();
    Clock operator++(int);
    void operator--();
    Clock operator--(int);
    bool operator>(const Clock& a_other_clock) const;
    bool operator<(const Clock& a_other_clock) const;
    bool operator>=(const Clock& a_other_clock) const;
    bool operator<=(const Clock& a_other_clock) const;
    bool operator!=(const Clock& a_other_clock) const;
    bool operator==(const Clock& a_other_clock) const;
private:
    int m_hours;
    int m_minutes;
};
