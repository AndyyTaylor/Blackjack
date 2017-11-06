// Copyright 2017 Andy Taylor

#include "objects/Player.h"

Player::Player(glm::vec3 _player_pos, glm::vec3 _hand_pos, float _hw)
: Object(_player_pos.x, _player_pos.y, _player_pos.z, TEXTURE)
, hand_pos(_hand_pos)
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
