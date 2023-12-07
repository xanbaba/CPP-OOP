#pragma once

class DateTime
{
public:
    DateTime();
    bool is_leap_year() const;
    bool operator>(const DateTime& a_datetime) const;
    bool operator<(const DateTime& a_datetime) const;
    bool operator>=(const DateTime& a_datetime) const;
    bool operator<=(const DateTime& a_datetime) const;
    bool operator==(const DateTime& a_datetime) const;
    bool operator!=(const DateTime& a_datetime) const;
    int get_seconds() const;
    int get_minutes() const;
    int get_hours() const;
    int get_week_day() const;
    int get_month_day() const;
    int get_year_day() const;
    int get_month() const;
    int get_year() const;
    static DateTime get_now();

private:
    int seconds;
    int minutes;
    int hours;
    int week_day;
    int month_day;
    int year_day;
    int month;
    int year;
};
