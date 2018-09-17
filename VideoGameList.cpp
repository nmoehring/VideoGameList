/*VideoGameList.cpp
Made by Nathan Moehring for IN200 @ BCC
Chapter 3 Assignment

List of probably fake games that can be searched or added to.
*/

#include <iostream>
#include <string>
#include <array>
#include <thread>
#include <chrono>
#include <cstdlib>
using namespace std;

int main() {
    // 1. Create an array of strings and use a Collection Initializer to add 4
    // video games to the list. (or whatever you like)
    array<string,10> game_list = {"Portal 3", "Team Fortress 3",
            "Left for Dead 3", "Counter Strike: Space Force"};
    //TIL: array declarations of type name[x] are C-style arrays
    // https://en.cppreference.com/w/cpp/container/array
    // C++ style arrays are objects that have the size() method
    array<string,3> menu_options = {"Search", "Add Game", "Quit"};
    string default_search_term = "Half-Life 3";
    int num_games = 4;
    bool quit = false;
    // Beyond the Requirements 3. Include a "Random game of the day" at the start
    // that asks the player if they've played a randomly chosen game from the array.
    srand(time(0));
    string random_game = game_list[rand() % num_games];

    // Beyond the Requirements 2. Create dialogue that makes the program feel
    // more intuitive
    cout << "\nWelcome to Valve's active development list!\n" << endl;
    this_thread::sleep_for(chrono::milliseconds(1500));
    cout << "Hey! Did you know about the game " << random_game << "? You should";
    cout << " Google it sometime." << endl;

    while (!quit) { /* Main Loop */
        this_thread::sleep_for(chrono::milliseconds(1500));
        cout << "\nWhat would you like to do?" << endl;
        for (int i = 0; i < menu_options.size(); i++) {
            cout << "[" << i+1 << "] " << menu_options[i] << "\n";
        }
        cout << ">>> ";
        int choice;
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1: { /* Search */
            cout << "Enter a search term.\n>>> ";
            string search_term;
            getline(cin,search_term);

            //If nothing entered, use default search term
            if (search_term == "") {
                search_term = default_search_term;
            }

            // 2. Create a for loop that will iterate through the list and look
            // for the game "Half-Life 2" (or whatever you like)
            int list_position = -1;
            cout << "Searching database for " << search_term << "..." << endl;
            this_thread::sleep_for(chrono::milliseconds(1000));
            for (int i = 0; i < num_games; i++) {
                if (game_list[i] == search_term) {
                    list_position = i;
                    break;
                }
            }

            if (list_position != -1) {
                cout << search_term << " was found at index " << list_position;
                cout << "." << endl;
            } else {
                cout << "That game is not currently in development." << endl;
            }

            break;
        }

        case 2: { /* Add Game */
        // 3. Create code that will ask the player for another video game to add
        // to the list, and then add it.
            if (num_games == 10) {
                cout << "Valve's development team is too busy developing";
                cout << " trading cards for the Steam Store to take on more";
                cout << " projects." << endl;
                continue;
            }

            cout << "What game would you like to add?\n>>> ";
            string game;
            getline(cin,game);

            if (game != "Half-Life 3") {
                game_list[num_games] = game;
                num_games++;
                cout << game << " added to Valve's development list!" << endl;
            }
            break;
        }

        case 3: /* Quit */
            quit = true;
            break;

        default: /* Not An Option */
            cout << "That's not a valid option.";
        }//switch(choice)
    } //while(!quit)

    cout << "Bye!" << endl;
    return 0;
}
