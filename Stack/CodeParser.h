#pragma once
#include <string>

enum class brackets
{
    opening_parenthesis = '(',
    opening_curly = '{',
    opening_square = '[',
    
    closing_parenthesis = ')',
    closing_curly = '}',
    closing_square = ']'
};

class CodeParser
{
public:
    static bool are_brackets_correct(const std::string& string);
};
