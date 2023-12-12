#include <iostream>
#include <string>

void Task1()
{
    std::cout << "This mini-game has made a word and you need to guess it.\n"
                 "If you want to exit the game, type 0\n\n";
    
    const std::string word = "Lamp";
    bool is_word_guessed = false;
    std::string guessed_word;
    while (!is_word_guessed)
    {
        std::cout << "Enter word: ";
        std::cin >> guessed_word;
        if (guessed_word == "0")
        {
            break;
        }
        if (guessed_word == word)
        {
            is_word_guessed = true;
        }
    }

    if (is_word_guessed)
    {
        std::cout << "You win!\n";
    }
    else
    {
        std::cout << "You lose!\n";
    }
}

int main(int argc, char* argv[])
{
    // Task1();
    return 0;
}
