// Copyright 2017 Andy Taylor

#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "objects/Object.h"
#include "objects/Card.h"

class Player : public Object {      // Would like to put models there eventually
 private:
    std::vector<Card*> cards;
    glm::vec3 hand_pos;
    glm::vec3 hand_rot;
    float hand_width;

 public:
    Player(glm::vec3 _player_pos, glm::vec3 _hand_pos, glm::vec3 _hand_rot, float _hw, int _playstyle);
    Player() {}

    int playstyle;
    int money;

    void render();
    void update();
    void cleanup();

    void addCard(Card* c);
    void clearHand();

    void setupUVs();

    int getHandValue();
    bool isHuman();
    bool shouldHit();
};

#endif
