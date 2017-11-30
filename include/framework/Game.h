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
    int pot = 0;
    int game_over_ticks = 0;

    std::vector<glm::vec3> hand_positions = {
        glm::vec3(0.15f, 0, 0.715f),
        glm::vec3(1.78f, 0, -0.4f),
        glm::vec3(1.45f, 0, 0.25f),
        glm::vec3(-1.15f, 0, 0.35f),
        glm::vec3(-1.63f, 0, -0.4f),
        glm::vec3(0.15f, 0, -0.715f)
    };

    std::vector<glm::vec3> player_positions = {
        glm::vec3(0.15f, 0, 0.715f),
        glm::vec3(1.35f, 0, 0.35f),
        glm::vec3(-1.20f, 0, 0.35f),
        glm::vec3(-1.15f, 0, 0.35f),
        glm::vec3(-1.15f, 0, 0.35f),
        glm::vec3(0.15f, 0, -0.715f)
    };

    std::vector<glm::vec3> hand_rots = {
        glm::vec3(0, 0, 0),
        glm::vec3(0, -90, 0),
        glm::vec3(0, 45, 0),
        glm::vec3(0, -45, 0),
        glm::vec3(0, -90, 0),
        glm::vec3(0, 0, 0)
    };

 public:
    Game(int _num_players, int turn_delay);

    bool hit = false;
    bool stand = false;
    bool roundStarted = false;

    void update(int tick);
    void render(glm::mat4 p, glm::mat4 v, Renderer texRenderer);

    void nextPlayer();
    void genPlayers();

    void changeNumPlayers(int inc);
    void changePlaystyle(int player);

    void placeBet();

    Player& getHumanPlayer();
};

#endif
