#include "Word.h"

#include <iostream>

Word::Word(const std::string& word)
{
    data = word;
    guessed_letters_size = 0;
    guessed_letters = new char[word.size()]{};
}

Word::Word(const Word& a_original)
{
    data = a_original.data;
    const size_t letters_size = a_original.data.size();
    guessed_letters = new char[letters_size]{};
    memcpy(guessed_letters, a_original.guessed_letters, letters_size);
    guessed_letters_size = a_original.guessed_letters_size;
}

Word::Word(Word&& a_original) noexcept
{
    data = std::move(a_original.data);
    guessed_letters = a_original.guessed_letters;
    guessed_letters_size = a_original.guessed_letters_size;

    a_original.guessed_letters = nullptr;
    a_original.guessed_letters_size = 0;
}

Word::~Word()
{
    delete[] guessed_letters;
}

Word& Word::operator=(const Word& a_original)
{
    if (this != &a_original)
    {
        this->~Word();
        
        data = a_original.data;
        const size_t letters_size = a_original.data.size();
        guessed_letters = new char[letters_size];
        memcpy(guessed_letters, a_original.guessed_letters, letters_size);
        guessed_letters_size = a_original.guessed_letters_size;
    }

    return *this;
}

Word& Word::operator=(Word&& a_original) noexcept
{
    if (this != &a_original)
    {
        this->~Word();
        
        data = std::move(a_original.data);
        guessed_letters = a_original.guessed_letters;
        guessed_letters_size = a_original.guessed_letters_size;

        a_original.guessed_letters = nullptr;
        a_original.guessed_letters_size = 0;
    }
    return *this;
}

std::string Word::GetWord() const
{
    return data;
}

std::string Word::GetGuessedWord() const
{
    std::string guessed_word = data;
    for (size_t i = 0; i < guessed_word.size(); ++i)
    {
        const char current_sym = guessed_word[i];
        bool is_found{};
        for (int j = 0; j < guessed_letters_size; ++j)
        {
            if (current_sym == guessed_letters[j])
            {
                is_found = true;
            }
        }
        if (!is_found)
        {
            guessed_word[i] = '*';
        }
    }

    return guessed_word;
}

void Word::AddGuessedLetter(const char letter)
{
    guessed_letters[guessed_letters_size] = letter;
    ++guessed_letters_size; 
}

int Word::GetGuessedLettersSize() const
{
    return guessed_letters_size;
}

const char* Word::GetGuessedLetters() const
{
    return guessed_letters;
}
