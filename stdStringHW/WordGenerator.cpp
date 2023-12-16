#include "WordGenerator.h"
#include <fstream>
#include <iostream>

Word WordGenerator::GenerateWord(const std::string& file_path)
{
    auto file = std::ifstream{file_path};
    if (file.is_open())
    {
        std::string line_string;
        int lines{};
        while (!file.eof())
        {
            file >> line_string;
            ++lines;
        }
        if (lines <= 0)
        {
            file.close();
            return Word{""};
        }
        std::uniform_int_distribution range{1, lines};
        const int random_line = range(engine);
        file.seekg(0, SEEK_SET);
        for (int i = 1; i < lines + 1; ++i)
        {
            std::getline(file, line_string);
            if (i == random_line)
            {
                file.close();
                return Word{line_string};
            }
        }
        file.close();
    }
    return Word{""};
}
