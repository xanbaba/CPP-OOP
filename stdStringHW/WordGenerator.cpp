#include "WordGenerator.h"
#include <fstream>

bool WordGenerator::GenerateWord(std::string& generated_word, const std::string& file_path)
{
    std::ifstream file{file_path};
    if (file.is_open())
    {
        file.close();
    }
}
