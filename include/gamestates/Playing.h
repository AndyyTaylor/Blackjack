// Copyright 2017 Andy Taylor

#ifndef PLAYING_H_INCLUDED
#define PLAYING_H_INCLUDED

#include "framework/Renderer.h"
#include "gamestates/GameState.h"
#include "objects/Card.h"

class Playing : public GameState {
 private:
    Renderer simpleRenderer;
    Card myCard;
    
 public:
    Playing();
    
    void init();
    void cleanup();
    
    void update();
    void render();
    
    void handleEvents();
};

#endif
