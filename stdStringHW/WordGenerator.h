#pragma once
#include <string>

class WordGenerator
{
public:
    static bool GenerateWord(std::string& generated_word, const std::string& file_path);
};
