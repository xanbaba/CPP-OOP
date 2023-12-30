#include "CodeParser.h"
#include "Stack.h"

bool CodeParser::are_brackets_correct(const std::string& string)
{
    Stack<brackets> stack;
    for (char i : string)
    {
        const auto current_symbol = static_cast<brackets>(i);
        switch (current_symbol)
        {
        case brackets::opening_parenthesis:
        case brackets::opening_curly:
        case brackets::opening_square:
            stack.Push(current_symbol);
            break;

        case brackets::closing_parenthesis:
            if (stack.Size() == 0) continue;
            if (stack.Peek() != brackets::opening_parenthesis) return false;
            stack.Pop();
            break;
        case brackets::closing_curly:
            if (stack.Size() == 0) continue;
            if (stack.Peek() != brackets::opening_curly) return false;
            stack.Pop();
            break;
        case brackets::closing_square:
            if (stack.Size() == 0) continue;
            if (stack.Peek() != brackets::opening_square) return false;
            stack.Pop();
            break;
        }
    }
    
    return stack.Empty();
}
