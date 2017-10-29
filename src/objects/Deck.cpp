// Copyright 2017 Andy Taylor

#include "objects/Deck.h"

Deck::Deck(float _x, float _y, float _z, int num_decks, int _deck_height)
: x(_x)
, y(_y)
, z(_z)
, deck_height(_deck_height) {
    genCards(num_decks);
}

void Deck::genCards(int num_decks) {
    cards.clear();
    
    for (int deck_num = 0; deck_num < num_decks; deck_num++) {
        for (int sint = CLUB; sint != BACK; sint++) {
            SUIT suit = static_cast<SUIT>(sint);
            
            for (int fint = ACE; fint != KING+1; fint++) {
                FACE face = static_cast<FACE>(fint);
                
                cards.push_back(Card(x - (deck_height/2.0f) + (deck_height/(52.0f*num_decks))*cards.size(), y + 0.0001f*cards.size(), z, suit, face));
            }
        }
    }
    
    std::cout << cards.size() << std::endl;
}

void Deck::render(const glm::mat4 &p, const glm::mat4 &v, const Renderer &texRenderer) {
    texRenderer.activate();
    
    glm::mat4 m;
    for (int i = 0; i < cards.size(); i++) {
        m = Maths::createModelMatrix(cards[i]);
        texRenderer.loadMVP(p * v * m);
        cards[i].render();
    }
}

void Deck::update() {
    tick++;
    
    
    if ((tick / 3) > tipped) {
        int ind = tipped-1;
        if (tipped >= cards.size() + 1) ind = 52 - (ind - 52);
        if (tipped >= cards.size() * 2 + 2) { tipped = 0; tick = 0; }
        cards[ind].glide(cards[ind].position
                     , glm::vec3(0, 0, tipped >= cards.size() + 1 ? 180 : 0)
                     , 15);
        tipped += 1;
        
        std::cout << ind << std::endl;
    }
    
    for (int i = 0; i < cards.size(); i++) {
        cards[i].update();
    }
}
