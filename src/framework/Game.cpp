// Copyright 2017 Andy Taylor

#include "framework/Game.h"
#include <iostream>

Game::Game(int _num_players, int _turn_delay)
: deck(-0.0f, 0.04f, -0.4f, 1, 0.08f)
, turn_delay(_turn_delay)
, num_players(_num_players) {
    genPlayers();
    deck.shuffle();
}

void Game::update(int tick) {
    deck.update();

    if (tick % turn_delay == 0 && roundStarted) {
        if (cards_dealt < num_players * 2) {
            players[current_player].addCard(deck.deal());
            nextPlayer();
            cards_dealt++;
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

        if (cards_dealt >= num_players * 2) {
            cards_dealt = 0;
            roundStarted = false;

            Player& human = getHumanPlayer();
            Player& dealer = players[num_players-1];

            if (dealer.getHandValue() == human.getHandValue() || (dealer.getHandValue() > 21 && human.getHandValue() > 21)) {
                human.money += pot;
            } else if (dealer.getHandValue() > 21 || human.getHandValue() > dealer.getHandValue()) {
                human.money += 2*pot;
            }
            std::cout << "Current balance " << human.money << std::endl;

            pot = 0;

            for (int i = 0; i < players.size(); i++) {
                players[i].clearHand();
            }
        }
    }
}

void Game::genPlayers() {
    for (int i = 0; i < fmin(num_players-2, 2); i++) {
        players.push_back(Player(player_positions[i+1], hand_positions[i+1], hand_rots[i+1], 0.2f, 17));
    }
    players.push_back(Player(player_positions[0], hand_positions[0], hand_rots[0], 0.2f, 0));
    for (int i = 0; i < fmin(num_players-4, 2); i++) {
        players.push_back(Player(player_positions[players.size()], hand_positions[players.size()], hand_rots[players.size()], 0.2f, 17));
    }
    players.push_back(Player(player_positions[hand_positions.size() - 1],
        hand_positions[hand_positions.size() - 1], hand_rots[hand_positions.size() - 1], 0.2f, 17));
}

void Game::changeNumPlayers(int inc) {
    players.clear();
    num_players += inc;
    num_players = fmax(fmin(num_players, 6), 2);
    // num_players = 5;
    genPlayers();
    deck = Deck(-0.0f, 0.04f, -0.4f, 1, 0.08f);
    deck.shuffle();
    current_player = 0;
    cards_dealt = 0;
}

void Game::changePlaystyle(int player) {
    if (player >= num_players || players[player].isHuman()) return;

    if (players[player].playstyle < 21) {
        players[player].playstyle++;
    } else {
        players[player].playstyle = 15;
    }

    if (player == num_players-1) {
        std::cout << "Dealer";
    } else {
        std::cout << "Player " << player;
    }

    std::cout << " will now stand at " << players[player].playstyle << std::endl;
}

void Game::placeBet() {
    if (roundStarted) return;
    Player& human = getHumanPlayer();

    if (human.money > 20) {
        human.money -= 20;
        pot += 20;
    }

    std::cout << "Pot: " << pot << std::endl;
    std::cout << "Balance: " << human.money << std::endl;
}

Player& Game::getHumanPlayer() {
    for (int i = 0; i < players.size(); i++) {
        if (players[i].isHuman()) {
            return players[i];
        }
    }
    return players[0];
}
