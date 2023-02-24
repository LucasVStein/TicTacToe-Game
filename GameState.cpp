#include "headers/GameState.h"

GameState::GameState() {
    game_map = std::vector<char>(9, '0');
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