#pragma once
#include <random>
#include <string>

#include "Word.h"

class WordGenerator
{
public:
    Word GenerateWord(const std::string& file_path);
private:
    std::default_random_engine engine{static_cast<unsigned int>(time(nullptr))};
};
