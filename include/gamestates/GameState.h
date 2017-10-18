// Copyright 2017 Andy Taylor

#ifndef GAME_STATE_H_INCLUDED
#define GAME_STATE_H_INCLUDED

#include <SDL2/SDL.h>
#include <iostream>

#include "framework/Display.h"

class GameState {
 public:
    virtual void cleanup() = 0;
    
    virtual void handleEvents() = 0;
    virtual void update() = 0;
    virtual void render() = 0;
    
 protected:
    GameState() {}
};

#endif
