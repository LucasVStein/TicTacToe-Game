#include <iostream>
#include <vector>
#include <limits>

#include "headers/GameState.h"

int main() {

    std::cout << "\n//////////////////////////////////////////////////" << std::endl;
    std::cout << "/// WELCOME TO THE GAME TIC-TAC-TOE" << std::endl;
    std::cout << "////////////////////////////////////////" << std::endl << std::endl;

    std::cout << "Enter 1 to start the game OR 0 to exit: ";

    char input;
    std::cin >> input;

    if(input == '0') {
        std::cout << "Thank you for playing. Cya next time!" << std::endl;
        return 0;
    }
    else if(input != '1') {

        while(input != '1' && input != '0') {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clean the input buffer
            std::cout << "Thats the wrong input. Pls enter 1 to play or 0 to exit the game: ";
            std::cin >> input;
        }

        if(input == '0') {
            std::cout << "Thank you for playing. Cya next time!" << std::endl;
            return 0;
        }
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Present the game map to the players

    std::cout << "\n//////////////////////" << std::endl;
    std::cout << "/// INSTRUCTIONS" << std::endl;
    std::cout << "//////////////////" << std::endl << std::endl;

    std::cout << "Pls use the following mapping to select cells to play:\n" << std::endl;

    std::cout << " (1) | (2) | (3) " << std::endl;
    std::cout << "-----------------" << std::endl;
    std::cout << " (4) | (5) | (6) " << std::endl;
    std::cout << "-----------------" << std::endl;
    std::cout << " (7) | (8) | (9) \n" << std::endl;

    std::cout << "Player 1 is 'O'." << std::endl;
    std::cout << "Player 2 is 'X'.\n" << std::endl;

    std::cout << "//////////////////" << std::endl << std::endl;

    // Game logic begins
    GameState game;

    bool repeatGame = true;
    while(repeatGame) {
        int winner = game.play();

        std::cout << "////////////////////////////////////////////////" << std::endl;
        std::cout << "/// THE WINNER OF THE GAME IS PLAYER " << winner << std::endl;
        std::cout << "//////////////////////////////////////////" << std::endl << std::endl;

        game.reset();

        char r = ' ';
        bool err = false;
        while(r != 'y' && r != 'Y' && r != 'n' && r != 'N') {
            if(err) { std::cout << "Invalid input. "; }

            std::cout << "Do you wish to play again? (y/n) ";

            std::cin >> r;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            if(r == 'n' || r == 'N')
                repeatGame = false;
            else if(r != 'y' && r != 'Y')
                err = true;
            
            std::cout << std::endl;
        }
    }

    std::cout << "Thank you for playing. Cya next time!\n" << std::endl;

    return 0;

}