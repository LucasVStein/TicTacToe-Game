#include "headers/GameState.h"

GameState::GameState() {
    game_map = std::vector<char>(9, ' ');
    curr_player = 'X';
}

const std::vector<char> GameState::getMap() const {
    return game_map;
}

void GameState::outputMap() const {

    printf(" ( %c ) | ( %c ) | ( %c ) \n", game_map.at(0), game_map.at(1), game_map.at(2));
    printf(" ( %c ) | ( %c ) | ( %c ) \n", game_map.at(3), game_map.at(4), game_map.at(5));
    printf(" ( %c ) | ( %c ) | ( %c ) \n", game_map.at(6), game_map.at(7), game_map.at(8));

}

void GameState::makePlay(int pos) {
    if(pos > 0 && pos < 10)
        game_map[pos-1] = curr_player;
}

int GameState::askInput() const {

    char input = ' ';
    bool err = false;

    while(!validInput(input)) {

        if(err) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Pls select a position between 1 and 9 that is not already occupied.\n";
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

bool GameState::winningCondition() {

    // iterate horizontally
    for(int ite = 0; ite < game_map.size(); ite += 3) {
        if(game_map[ite] == curr_player && game_map[ite+1] == curr_player && game_map[ite+2] == curr_player)
            return true;
    }

    // iterate vertically
    for(int ite = 0; ite < 3; ite++) {
        if(game_map[ite] == curr_player && game_map[ite+3] == curr_player && game_map[ite+6] == curr_player)
            return true;
    }

    // iterate diagonally
    if(game_map[0] == curr_player && game_map[4] == curr_player && game_map[8] == curr_player)
            return true;
    else if(game_map[2] == curr_player && game_map[4] == curr_player && game_map[6] == curr_player)
            return true;
    
    switchPlayer();
    
    return false;
}

void GameState::switchPlayer() {
    if(curr_player == 'O') 
        curr_player = 'X';
    else
        curr_player = 'O';
}

bool GameState::validInput(char input) const {
    if(input != '1' &&
       input != '2' &&
       input != '3' &&
       input != '4' &&
       input != '5' &&
       input != '6' &&
       input != '7' &&
       input != '8' &&
       input != '9')
       return false;
    else if(game_map[(int)input-49] != ' ')
        return false;

    return true;
}