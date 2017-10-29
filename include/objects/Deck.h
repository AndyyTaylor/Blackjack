// Copyright 2017 Andy Taylor

#ifndef DECK_H_INCLUDED
#define DECK_H_INCLUDED

#include "framework/Matrix.h"
#include "framework/Renderer.h"
#include "objects/Card.h"
#include <iostream>

class Deck {
 private:
    float x, y, z;
    int deck_height;
    int tick = 0;
    int tipped = 0;
    
    void genCards(int num_decks);
    
 public:
    Deck(float _x, float _y, float _z, int num_decks, int _deck_height);
    std::vector<Card> cards;
    
    void update();
    void render(const glm::mat4& p, const glm::mat4& v, const Renderer& texRenderer);
};

#endif
