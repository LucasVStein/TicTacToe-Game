#include "headers/GameState.h"

GameState::GameState() {
    game_map = std::vector<char>(9, ' ');
    curr_player = 'O';
}

std::vector<char> GameState::getMap() {
    return game_map;
}

void GameState::outputMap() {

    printf(" ( %c ) | ( %c ) | ( %c ) \n", game_map.at(0), game_map.at(1), game_map.at(2));
    printf(" ( %c ) | ( %c ) | ( %c ) \n", game_map.at(3), game_map.at(4), game_map.at(5));
    printf(" ( %c ) | ( %c ) | ( %c ) \n", game_map.at(6), game_map.at(7), game_map.at(8));

}

void GameState::makePlay(int pos) {
    if(pos > 0 && pos < 10)
        game_map[pos-1] = curr_player;

    if(curr_player == 'O') 
        curr_player = 'X';
    else
        curr_player = 'O';
}

int GameState::askInput() {

    char input = ' ';
    bool err = false;

    while(input != '1' &&
          input != '2' &&
          input != '3' &&
          input != '4' &&
          input != '5' &&
          input != '6' &&
          input != '7' &&
          input != '8' &&
          input != '9') {

        if(err) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Pls select a position between 1 and 9.\n";
        }

        std::cout << "Player ";

        if(curr_player == 'O')
            std::cout << "1";
        else
            std::cout << "2";
    
        std::cout << " pls select a position to play: ";

        std::cin >> input;

        err = true;
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return (int)input-48;
}