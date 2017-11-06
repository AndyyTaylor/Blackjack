// Copyright 2017 Andy Taylor

#include "framework/Game.h"

Game::Game(int num_players, int _turn_delay)
: turn_delay(_turn_delay) {
    for (int i = 0; i < num_players - 1; i++) {
        players.push_back(Player(player_positions[i], hand_positions[i], 0.2f));
    }
    players.push_back(Player(player_positions[hand_positions.size() - 1], hand_positions[hand_positions.size() - 1], 0.2f));
}
