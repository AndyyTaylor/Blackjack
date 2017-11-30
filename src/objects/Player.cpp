// Copyright 2017 Andy Taylor

#include "objects/Player.h"

Player::Player(glm::vec3 _player_pos, glm::vec3 _hand_pos, glm::vec3 _hand_rot, float _hw, int _playstyle)
: Object(_player_pos.x, _player_pos.y, _player_pos.z, TEXTURE)
, hand_pos(_hand_pos)
, hand_rot(_hand_rot)
, hand_width(_hw)
, playstyle(_playstyle) {
    if (isHuman()) money = 1000;
}

void Player::render() {
}

void Player::update() {
}

void Player::addCard(Card* c, bool flip) {
    if (flip) c->flipped = true;
    cards.push_back(c);

    glm::vec3 card_rot = hand_rot;

    for (int i = 0; i < cards.size(); i++) {
        cards[i]->glide(hand_pos - glm::vec3(hand_width/2.0f + cos(glm::radians(hand_rot.y)) * (1.0f*hand_width/cards.size()*i), -0.00001f*i,
        -sin(glm::radians(hand_rot.y)) * (1.0f*hand_width/cards.size()*i))
                       , card_rot, 100);
    }
}

void Player::clearHand() {
    for (int i = 0; i < cards.size(); i++) {
        cards[i]->hidden = true;
    }
    cards.clear();
}

void Player::cleanup() {
}

void Player::setupUVs() {
}

int Player::getHandValue() {
    int total = 0;
    int aces = 0;
    for (int i = 0; i < cards.size(); i++) {
        if (cards[i]->getValue() == 0) {
            aces += 1;
        } else {
            total += cards[i]->getValue();
        }
    }

    for (int i = 0; i < aces; i++) {
        if (total <= 10 - aces) {
            total += 11;
        } else {
            total += 1;
        }
    }

    return total;
}

bool Player::isHuman() {
    return playstyle == 0;
}

bool Player::shouldHit() {
    for (int i = 0; i < cards.size(); i++) {
        if (cards[i]->glide_tick <= 0 && cards[i]->flipped) {
            cards[i]->flipped = false;
            glm::vec3 rots = cards[i]->rotation;
            rots.z += 180;
            cards[i]->glide(cards[i]->position, rots, 50);
        }
    }
    return getHandValue() < playstyle;
}
