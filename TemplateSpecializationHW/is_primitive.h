#pragma once
#define GENERATE_PRIMITIVE(TYPE)\
template <> \
struct is_primitive<TYPE> \
{ \
    constexpr static bool value = true; \
} \

template <typename T>
struct is_primitive
{
    constexpr static bool value = false;
};

GENERATE_PRIMITIVE(int);
GENERATE_PRIMITIVE(bool);
GENERATE_PRIMITIVE(char);
GENERATE_PRIMITIVE(short);
