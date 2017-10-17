// Copyright 2017 Andy Taylor

#ifndef CARD_H_INCLUDED
#define CARD_H_INCLUDED

#include "objects/Object.h"

class Card : public Object {
 public:
    Card(float _x, float _y, float _z);
    
    void render();
    void update();
    void cleanup();
};

#endif
