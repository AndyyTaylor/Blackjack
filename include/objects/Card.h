// Copyright 2017 Andy Taylor

#ifndef CARD_H_INCLUDED
#define CARD_H_INCLUDED

#include "objects/Object.h"

class Card : public Object {
 private:
    glm::vec3 dpos;
    glm::vec3 drot;

    SUIT suit;

 public:
    Card(float _x, float _y, float _z, SUIT _suit, FACE _face);

    int glide_tick = 0;

    bool hidden = false;
    bool flipped = false;
    FACE face;

    void render();
    void update();
    void cleanup();

    void setupUVs();
    void glide(glm::vec3 new_pos, glm::vec3 new_rot, int ticks);

    int getValue();
};

#endif
