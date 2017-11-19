// Copyright 2017 Andy Taylor

#include "framework/Game.h"
#include <iostream>

Game::Game(int _num_players, int _turn_delay)
: deck(-0.0f, 0.04f, -0.4f, 1, 0.08f)
, turn_delay(_turn_delay)
, num_players(_num_players) {
    genPlayers();
}

void Game::update(int tick) {
    deck.update();

    if (tick % turn_delay == 0) {
        if (cards_dealt < num_players * 2) {
            players[current_player].addCard(deck.deal());
            cards_dealt++;
            nextPlayer();
        } else if (players[current_player].isHuman()) {
            if (hit) {
                players[current_player].addCard(deck.deal());
                hit = false;
            } else if (stand) {
                stand = false;
                nextPlayer();
            }
        } else if (players[current_player].shouldHit()) {
            players[current_player].addCard(deck.deal());
        } else {
            nextPlayer();
        }
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

void Game::genPlayers() {
    for (int i = 0; i < floor((num_players - 2) / 2.0f); i++) {
        players.push_back(Player(player_positions[i+1], hand_positions[i+1], hand_rots[i+1], 0.2f, 17));
    }
    players.push_back(Player(player_positions[0], hand_positions[0], hand_rots[0], 0.2f, 0));
    for (int i = 0; i < ceil((num_players - 2) / 2.0f); i++) {
        players.push_back(Player(player_positions[players.size()], hand_positions[players.size()], hand_rots[players.size()], 0.2f, 17));
    }
    players.push_back(Player(player_positions[hand_positions.size() - 1],
        hand_positions[hand_positions.size() - 1], hand_rots[hand_positions.size() - 1], 0.2f, 17));
}

void Game::changePlayers(int inc) {
    players.clear();
    num_players += inc;
    genPlayers();
    deck = Deck(-0.0f, 0.04f, -0.4f, 1, 0.08f);
    current_player = 0;
    cards_dealt = 0;
}
