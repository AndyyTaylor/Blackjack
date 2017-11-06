// Copyright 2017 Andy Taylor

#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "objects/Player.h"
#include <vector>

class Game {
 private:
    std::vector<Player> players;
    int turn_delay;

    std::vector<glm::vec3> hand_positions = {
        glm::vec3(0.15f, 0, -0.8f),
        glm::vec3(1.0f, 0, -0.8f),
        glm::vec3(0.15f, 0, 0.8f)
    };

    std::vector<glm::vec3> player_positions = {
        glm::vec3(0.15f, 0, -0.8f),
        glm::vec3(1.0f, 0, -0.8f),
        glm::vec3(0.15f, 0, 0.8f)
    };

 public:
    Game(int num_players, int turn_delay);

    void update();
};

#endif
