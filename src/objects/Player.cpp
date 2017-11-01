// Copyright 2017 Andy Taylor

#include "objects/Player.h"

Player::Player(float _x, float _y, float _z, float _hx, float _hy, float _hz, float _hw)
: Object(_x, _y, _z, TEXTURE)
, hand_pos(_hx, _hy, _hz)
, hand_width(_hw) {
    
}

void Player::render() {
    
}

void Player::update() {
    
}

void Player::addCard(Card* c) {
    cards.push_back(c);

    for (int i = 0; i < cards.size(); i++) {
        cards[i]->glide(hand_pos - glm::vec3(hand_width/2.0f + (1.0f*hand_width/cards.size()*i), -0.00001f*i, 0)
                       , glm::vec3(0, 0, 360), 100);
    }
}

void Player::clearHand() {
    cards.clear();
}

void Player::cleanup() {
    
}

void Player::setupUVs() {
    
}
