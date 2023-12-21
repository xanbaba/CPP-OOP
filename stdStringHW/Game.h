#pragma once
#include "Word.h"

class Game
{
public:
    Game();
    bool WinCheck(const Word& word);
    void WinOutput();
    void LoseOutput(const Word& word);
    void operator()();
private:
    int m_attempts_count;

    static void WelcomeMessage();
    void LetterChoiceOutput(bool is_guessed);
    void GuessedWordOutput(const Word& word);
};
