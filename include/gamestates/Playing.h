// Copyright 2017 Andy Taylor

#ifndef PLAYING_H_INCLUDED
#define PLAYING_H_INCLUDED

#include "framework/Renderer.h"
#include "gamestates/GameState.h"
#include "objects/Card.h"
#include "objects/Table.h"

class Playing : public GameState {
 private:
    Renderer simpleRenderer;
    Card myCard;
    Card cam;   // TODO
    Table table;
    
    bool moving_right = false;
    bool moving_left = false;
    bool moving_forward = false;
    bool moving_backward = false;
    bool moving_up = false;
    bool moving_down = false;
    
 public:
    Playing();
    
    void init();
    void cleanup();
    
    void update();
    void render();
    
    void handleEvents();
};

#endif
