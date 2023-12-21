#include "UserInputHandler.h"
#include <iostream>

char UserInputHandler::operator()() const
{
    char input_char;
    std::cout << "Enter symbol: ";
    std::cin >> input_char;
    
    return input_char;
}
