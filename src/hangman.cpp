/*
 * Hangman
 * Program that lets you play a text version of Hangman.
 * Written by Jordan Sola 2020
 * This program uses the MIT license.
 */

#include <iostream>
#include "read_file.h"
#include "read_file.h"
#include "random_word.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    cout << "Starting a new game of hangman..." << endl;

    cout << endl;

    int failed_attempts = 0;
    cout << "How many failed attempts do you need? [1-25] ";
    cin >> failed_attempts;

    cout << endl;

    int word_length = 0;
    cout << "How many letters do you want in your word? [1-25] ";
    cin >> word_length;

    cout << endl;

    cout << "Generating a word for you..." << endl;

    cout << endl;

    //get word randomly from source text file
    string word = "";
    switch (word_length)
    {
    case 2:
    {
        word = WordChooser(AcquireFileContents("src/words/two_letter_words.txt"));
        break;
    }
    }

    //Create a holder for the '#' characters to be replaced by correct guesses.
    vector<char> word_holder;
    for (string::size_type i = 0; i < word.size(); i++)
    {
        word_holder.push_back('#');
    }

    //game state
    bool game_over = false;
    bool correct = false;

    //game variables
    vector<char> previous_guesses;
    char guess = ' ';

    //game loop
    while (!game_over)
    {
        cout << "Word: ";
        for (size_t i = 0; i < word_holder.size(); i++)
        {
            cout << word_holder[i];
        }
        cout << endl;
        if (previous_guesses.empty())
        {
            cout << "First guess: ";
            cin >> guess;
        }
        else
        {
            if (previous_guesses.size() < 2)
            {
                cout << "Previous guess: " << previous_guesses[0] << endl;
            }
            else
            {
                cout << "Previous guesses: ";
                for (size_t i = 0; i < previous_guesses.size(); i++)
                {
                    if (i != previous_guesses.size())
                    {
                        cout << i << ", ";
                    }
                    else
                    {
                        cout << i << endl;
                    }
                }
            }
            cout << "Next guess: ";
            cin >> guess;
        }

        //check guess against word
        for (size_t i = 0; i < word.size(); i++)
        {
            if (word[i] == guess)
            {
                word_holder[i] = guess;
                correct = true;
            }
        }
        
        //output appropriate guess prompt
        if (correct)
        {
            correct = false;
        }
        else
        {
            cout << guess << " is NOT in your word!" << endl;
        }

        cout << endl;
    }
    return 0;
}