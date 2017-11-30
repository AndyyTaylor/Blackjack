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
            if (current_player == num_players-1 && players[current_player].cards.size() == 0) {
                players[current_player].addCard(deck.deal(), true);
            } else {
                players[current_player].addCard(deck.deal());
            }
            nextPlayer();
            cards_dealt++;
        } else if (players[current_player].isHuman() || players[current_player].playstyle == -1) {
            if (stand || players[current_player].getHandValue() > 21 || players[current_player].cards.size() == 5) {
                stand = false;
                nextPlayer();
            } else if (hit) {
                players[current_player].addCard(deck.deal());
                hit = false;
            } else if (shouldSplit) {
                split();
                shouldSplit = false;
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
            current_player = players.size()-1;
            game_over_ticks++;
            std::cout << game_over_ticks << std::endl;
            if (game_over_ticks < 10) return;

            cards_dealt = 0;
            roundStarted = false;

            Player& human = getHumanPlayer();
            Player& dealer = players[num_players-1];
            if (hasSplit) {
                dealer = players[num_players-2];
            }


            if ((dealer.cards.size() == 5 && dealer.cards.size() == human.cards.size())
                || dealer.getHandValue() == human.getHandValue() || (dealer.getHandValue() > 21 && human.getHandValue() > 21)) {
                human.money += pot;
            } else if (human.getHandValue() <= 21
                && (dealer.getHandValue() > 21 || human.getHandValue() > dealer.getHandValue() || human.cards.size() == 5)) {
                human.money += 2*pot;
            }

            if (hasSplit) {
                Player& splitHand = players[players.size()-1];
                if ((dealer.cards.size() == 5 && dealer.cards.size() == splitHand.cards.size())
                    || dealer.getHandValue() == splitHand.getHandValue() || (dealer.getHandValue() > 21 && splitHand.getHandValue() > 21)) {
                    human.money += pot;
                } else if (human.getHandValue() <= 21
                    && (dealer.getHandValue() > 21 || splitHand.getHandValue() > dealer.getHandValue() || splitHand.cards.size() == 5)) {
                    human.money += 2*pot;
                } else {
                    human.money -= pot;
                }
            }

            if (deck.dealt < deck.cards.size()-20) {
                deck = Deck(-0.0f, 0.04f, -0.4f, 1, 0.08f);
                deck.shuffle();
            }

            std::cout << "Current balance " << human.money << std::endl;

            pot = 0;
            game_over_ticks = 0;

            stand = false;
            hit = false;
            hasSplit = false;
            current_player = 0;

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
    players.push_back(Player(player_positions[hand_positions.size() - 2],
        hand_positions[hand_positions.size() - 2], hand_rots[hand_positions.size() - 2], 0.2f, 17));
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
    hasSplit = false;
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

    if (human.money >= 20) {
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

void Game::split() {
    Player& human = getHumanPlayer();
    if (human.cards.size() != 2 || hasSplit || human.money < pot) return;

    if (human.cards[0]->face == human.cards[1]->face) {
        hasSplit = true;

        players.push_back(Player(player_positions[hand_positions.size() - 1],
            hand_positions[hand_positions.size() - 1], hand_rots[hand_positions.size() - 1], 0.2f, -1));

        human = getHumanPlayer();
        Player& splitHand = players[players.size()-1];
        splitHand.addCard(human.cards[1]);

        getHumanPlayer().cards.pop_back();
    }
}
