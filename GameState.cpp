#include "GameState.h"

GameState::GameState() {
    game_map = std::vector<char>('0', 9);
}

std::vector<char> GameState::getMap() {
    return game_map;
}