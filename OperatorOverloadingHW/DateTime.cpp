#define _CRT_SECURE_NO_WARNINGS
#include "DateTime.h"
#include <ctime>

DateTime::DateTime() : seconds(0),
                       minutes(0),
                       hours(12),
                       week_day(1),
                       month_day(1),
                       year_day(1),
                       month(1),
                       year(1990)
{}

int DateTime::get_seconds() const
{
    return seconds;
}

int DateTime::get_minutes() const
{
    return minutes;
}

int DateTime::get_hours() const
{
    return hours;
}

int DateTime::get_week_day() const
{
    return week_day;
}

int DateTime::get_month_day() const
{
    return month_day;
}

int DateTime::get_year_day() const
{
    return year_day;
}

int DateTime::get_month() const
{
    return month;
}

int DateTime::get_year() const
{
    return year;
}

DateTime DateTime::get_now()
{
    const std::time_t time_now = std::time(nullptr);
    const std::tm* date_now = std::localtime(&time_now);
    
    DateTime date_time;
    date_time.hours = date_now->tm_hour;
    date_time.minutes = date_now->tm_min;
    date_time.seconds = date_now->tm_sec;
    date_time.year = date_now->tm_year + 1900;
    date_time.month = date_now->tm_mon + 1;
    date_time.week_day = date_now->tm_wday;
    if (date_time.week_day == 0)
    {
        date_time.week_day = 7;
    }
    date_time.month_day = date_now->tm_mday;
    date_time.year_day = date_now->tm_yday;

    return date_time;
}
