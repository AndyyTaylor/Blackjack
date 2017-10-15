// Copyright 2017 Andy Taylor

#ifndef PLAYING_H_INCLUDED
#define PLAYING_H_INCLUDED

#include "gamestates/GameState.h"

class Playing : public GameState {
 public:
    void init();
    void cleanup();
    
    void update();
    void render();
    
    void handleEvents();
};

#endif
