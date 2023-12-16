#pragma once
#include <string>

class Word
{
public:
    Word(const std::string& word);
    Word(const Word& a_original);
    Word(Word&& a_original) noexcept;
    ~Word();
    Word& operator=(const Word& a_original);
    Word& operator=(Word&& a_original) noexcept;
    std::string GetWord() const;
    std::string GetGuessedWord() const;
    void AddGuessedLetter(char letter);
    int GetGuessedLettersSize() const;
    const char* GetGuessedLetters() const;
private:
    std::string data;
    char* guessed_letters;
    int guessed_letters_size;
};
