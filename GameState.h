#include <vector>

class GameState {

    std::vector<char> game_map;

public:

    GameState();
    std::vector<char> getMap();

};