#include <iostream>

#include "Equals.h"
#include "Greater.h"
#include "Less.h"
#include "GreaterEquals.h"
#include "LessEquals.h"
#include "NotEquals.h"

int main(int argc, char* argv[])
{
    Equals equals;
    Greater greater;
    Less less;
    GreaterEquals greater_equals;
    LessEquals less_equals;
    NotEquals not_equals;

    std::cout << std::boolalpha;
    std::cout << equals(0, 10) << '\n';
    std::cout << greater(0, 10) << '\n';
    std::cout << less(0, 10) << '\n';
    std::cout << greater_equals(0, 10) << '\n';
    std::cout << less_equals(0, 10) << '\n';
    std::cout << not_equals(0, 10) << '\n';
    return 0;
}
