// Copyright 2017 Andy Taylor

#include "framework/Game.h"

Game::Game(int num_players, int _turn_delay)
: deck(-0.3f, 0.04f, -0.0f, 1, 0.08f)
, turn_delay(_turn_delay) {
    for (int i = 0; i < num_players - 1; i++) {
        players.push_back(Player(player_positions[i], hand_positions[i], 0.2f));
    }
    players.push_back(Player(player_positions[hand_positions.size() - 1], hand_positions[hand_positions.size() - 1], 0.2f));
}

void Game::update(int tick) {
    deck.update();

    if (tick % turn_delay == 0) {
        if (players[current_player].getHandValue() < 17) {
            players[current_player].addCard(deck.deal());
        }
        nextPlayer();
    }
}

void Game::render(glm::mat4 p, glm::mat4 v, Renderer texRenderer) {
    deck.render(p, v, texRenderer);
}

void Game::nextPlayer() {
    if (++current_player >= players.size()) {
        current_player = 0;
    }
}
