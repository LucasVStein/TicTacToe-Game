#include <iostream>
#include <vector>
#include <limits>

class GameState {

    std::vector<char> game_map;
    char curr_player;

public:

    GameState();
    const std::vector<char> getMap() const;
    const char getPlayer() const;
    void outputMap() const;
    void makePlay(int pos);
    int askInput() const;
    bool winningCondition();
    void switchPlayer();
    bool validInput(char input) const;
    const int getWinner() const;

    const int play();
    void reset();

};