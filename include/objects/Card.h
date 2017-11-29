// Copyright 2017 Andy Taylor

#ifndef CARD_H_INCLUDED
#define CARD_H_INCLUDED

#include "objects/Object.h"

class Card : public Object {
 private:
    glm::vec3 dpos;
    glm::vec3 drot;
    int glide_tick = 0;

    SUIT suit;
    FACE face;

 public:
    Card(float _x, float _y, float _z, SUIT _suit, FACE _face);

    bool hidden = false;

    void render();
    void update();
    void cleanup();

    void setupUVs();
    void glide(glm::vec3 new_pos, glm::vec3 new_rot, int ticks);

    int getValue();
};

#endif
