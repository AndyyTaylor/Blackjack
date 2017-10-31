// Copyright 2017 Andy Taylor

#include "objects/Deck.h"

Deck::Deck(float _x, float _y, float _z, int num_decks, float _deck_height)
: x(_x)
, y(_y)
, z(_z)
, deck_height(_deck_height) {
    std::srand(std::time(0));
    
    genCards(num_decks);
}

void Deck::genCards(int num_decks) {
    cards.clear();
    
    for (int deck_num = 0; deck_num < num_decks; deck_num++) {
        for (int sint = CLUB; sint != BACK; sint++) {
            SUIT suit = static_cast<SUIT>(sint);
            
            for (int fint = ACE; fint != KING+1; fint++) {
                FACE face = static_cast<FACE>(fint);
                
                cards.push_back(Card(x, y + (deck_height/2.0f) - (deck_height/(52.0f*num_decks))*cards.size(), z, suit, face));
                cards[cards.size()-1].rotation.z = 180;
        // cards.push_back(Card(x - (deck_height/2.0f) + (deck_height/(52.0f*num_decks))*cards.size(), y + 0.0001f*cards.size(), z, suit, face));
            }
        }
    }
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
    
    /*if (tick == 0) shuffle();
    if ((tick / 3) > tipped) {
        int ind = tipped-1;
        if (tipped >= cards.size() + 1) ind = 52 - (ind - 52);
        if (tipped >= cards.size() * 2 + 2) { tipped = 0; tick = -40; }
        cards[ind].glide(cards[ind].position
                     , glm::vec3(0, 0, tipped >= cards.size() + 1 ? 180 : 0)
                     , 15);
        tipped += 1;
    }*/
    
    for (int i = 0; i < cards.size(); i++) {
        cards[i].update();
    }
}

void Deck::shuffle() {
    /* Durstenfeld's version of the Fisher-Yates shuffle O(n) complexity */
    dealt = 0;
    for (int i = cards.size()-1; i >= 0; i--) {
        int j = (rand() % static_cast<int>(i + 1));    // NOLINT
        
        Card temp = cards[j];
        cards[j] = cards[i];
        cards[i] = temp;
    }
    
    for (int i = 0; i < cards.size(); i++) {
        cards[i].position = glm::vec3(x, y + (deck_height/2.0f) - (1.0f*deck_height/(cards.size()))*i, z);
        cards[i].rotation.z = 180;
    }
}

void Deck::deal() {
    cards[dealt].glide(glm::vec3(0.0f, 0, 0.8f), glm::vec3(0, 180, 0), 50);
    dealt++;
}
