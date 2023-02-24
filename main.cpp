#include <iostream>
#include <vector>
#include <limits>

#include "headers/GameState.h"

int main() {

    std::cout << "//////////////////////////////////////////////////" << std::endl;
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

    // Present the game map to the players

    std::cout << "Pls use the following mapping to select cells to play:\n" << std::endl;

    std::cout << " (1) | (2) | (3) " << std::endl;
    std::cout << "-----------------" << std::endl;
    std::cout << " (4) | (5) | (6) " << std::endl;
    std::cout << "-----------------" << std::endl;
    std::cout << " (7) | (8) | (9) \n" << std::endl;

    std::cout << "Player 1 is 'O'." << std::endl;
    std::cout << "Player 2 is 'X'.\n" << std::endl;

    // Game logic begins
    GameState game;

    /* game.outputMap();
    game.makePlay(5);
    std::cout << '\n';
    game.makePlay(6);
    std::cout << '\n';
    game.outputMap(); */

    return 0;

}