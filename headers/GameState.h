#include <iostream>
#include <vector>
#include <limits>

class GameState {

    std::vector<char> game_map;
    char curr_player;

public:

    GameState();
    std::vector<char> getMap();
    void outputMap();
    void makePlay(int pos);
    int askInput();
    bool winningCondition();
    void switchPlayer();

};