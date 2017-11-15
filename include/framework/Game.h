// Copyright 2017 Andy Taylor

#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "objects/Player.h"
#include "objects/Deck.h"
#include <vector>

class Game {
 private:
    std::vector<Player> players;
    Deck deck;

    int turn_delay;
    int current_player = 0;
    int cards_dealt = 0;
    int num_players;

    std::vector<glm::vec3> hand_positions = {
        glm::vec3(0.15f, 0, 0.8f),
        glm::vec3(1.35f, 0, 0.45f),
        glm::vec3(-1.20f, 0, 0.45f),
        glm::vec3(0.15f, 0, -0.8f)
    };

    std::vector<glm::vec3> player_positions = {
        glm::vec3(0.15f, 0, 0.8f),
        glm::vec3(1.35f, 0, 0.45f),
        glm::vec3(-1.20f, 0, 0.45f),
        glm::vec3(0.15f, 0, -0.8f)
    };

    std::vector<glm::vec3> hand_rots = {
        glm::vec3(0, 0, 0),
        glm::vec3(0, 45, 0),
        glm::vec3(0, -45, 0),
        glm::vec3(0, 0, 0)
    };

 public:
    Game(int _num_players, int turn_delay);

    bool hit = false;
    bool stand = false;

    void update(int tick);
    void render(glm::mat4 p, glm::mat4 v, Renderer texRenderer);

    void nextPlayer();
};

#endif
