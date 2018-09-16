#include <iostream> //<string> and I think <array> are included with iostream
#include <thread>
#include <chrono>
using namespace std;

int main() {
    //There might be some other way to access the array methods like size() and
    // empty(), but using the array template was the only way I could get it
    // working .
    array<string,10> game_list = {"Portal 3", "Team Fortress 3", "Left for Dead 3",\
                        "Counter Strike: Space Force"};
    int num_games = 4;
    bool quit = false;
    array<string,3> menu_options = {"Search", "Add Game", "Quit"};
    string default_search_term = "Half-Life 3";

    //Introduction
    cout << "\nWelcome to Valve's active development list!\n" << endl;

    //Main Loop
    while (!quit) {
        cout << "\nWhat would you like to do?" << endl;
        for (int i = 0; i < menu_options.size(); i++) {
            cout << "[" << i+1 << "] " << menu_options[i] << "\n";
        }
        cout << ">>> ";
        int choice;
        cin >> choice;

        //Search
        if (choice == 1) {
            cout << "Enter a search term.\n>>> ";
            string search_term;
            cin.ignore();
            getline(cin,search_term);

            //If nothing entered, use default search term
            if (search_term == "") {
                search_term = default_search_term;
            }

            int list_position = -1;
            cout << "Searching database for " << search_term << "..." << endl;
            this_thread::sleep_for(chrono::milliseconds(3000));

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

        //Add Game
        } else if (choice == 2) {
            if (num_games == 10) {
                cout << "Valve's development team is too busy developing";
                cout << " trading cards for the Steam Store to take on more";
                cout << " projects." << endl;
                continue;
            }

            cout << "What game would you like to add?\n>>> ";
            string game;
            cin >> game;

            if (game != "Half-Life 3") {
                game_list[num_games] = game;
                num_games++;
                cout << game << " added to Valve's development list!" << endl;
            }

        //Quit
        } else if (choice == 3) {
            quit = true;

        //Not an option
        } else {
            cout << "That's not a valid option.";
        }

    } // end while(!quit)
    cout << "Bye!" << endl;
} // end main()
