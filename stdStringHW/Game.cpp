#include "Game.h"
#include <iostream>
#include "UserInputHandler.h"
#include "WordGenerator.h"

Game::Game() : m_attempts_count(0)
{
}

void Game::operator()()
{
    WelcomeMessage();

    WordGenerator word_generator;
    UserInputHandler user_input_handler;
    Word random_word = word_generator.GenerateWord("random_words.txt");
    while (true)
    {
        const char user_input = user_input_handler();
        if (user_input == '0')
        {
            LoseOutput(random_word);
            break;
        }
        bool guessed{};
        if (random_word.GetWord().find(user_input) != static_cast<size_t>(-1))
        {
            bool is_duplicate{};
            const auto guessed_letters = random_word.GetGuessedLetters();
            for (int i = 0; i < random_word.GetGuessedLettersSize(); ++i)
            {
                if (guessed_letters[i] == user_input)
                {
                    is_duplicate = true;
                }
            }
            guessed = true;
            if (!is_duplicate)
            {
                random_word.AddGuessedLetter(user_input);
            }
        }
        LetterChoiceOutput(guessed);
        GuessedWordOutput(random_word);
        ++m_attempts_count;
        if (WinCheck(random_word))
        {
            WinOutput();
            break;
        }
    }
}

bool Game::WinCheck(const Word& word)
{
    const auto word_string = word.GetWord();
    const auto word_string_size = word_string.size();
    const auto guessed_letter_size = word.GetGuessedLettersSize();
    const auto guessed_letter = word.GetGuessedLetters();
    for (size_t i = 0; i < word_string_size; ++i)
    {
        const char current_symbol = word_string[i];
        bool is_found{};
        for (int j = 0; j < guessed_letter_size; ++j)
        {
            if (current_symbol == guessed_letter[j])
            {
                is_found = true;
            }
        }

        if (!is_found)
        {
            return false;
        }
    }

    return true;
}

void Game::WinOutput()
{
    std::cout << "\nCongratulations!!! You won!\n"
                 "The number of attempts is: " << m_attempts_count << '\n';
}

void Game::LoseOutput(const Word& word)
{
    std::cout << "\nUnfortunately, you lost. The word was: " << word.GetWord() << '\n';
}

void Game::WelcomeMessage()
{
    std::cout << "This mini-game has made a word and you need to guess it.\n"
        "On each step you need to type one letters which you think is in the word.\n"
        "After each step you will be given word with hidden letters except which you have guessed.\n"
        "If you want to exit the game, type 0\n\n";
}

void Game::LetterChoiceOutput(bool is_guessed)
{
    switch (static_cast<int>(is_guessed))
    {
    case true:
        std::cout << "This letter is in the word!\n";
        break;
    case false:
        std::cout << "Try another one!\n";
        break;
    default: ;
    }
}

void Game::GuessedWordOutput(const Word& word)
{
    std::cout << "The guessed word is: " << word.GetGuessedWord() << "\n\n";
}
