// Copyright 2017 Andy Taylor

#ifndef PLAYING_H_INCLUDED
#define PLAYING_H_INCLUDED

#include "framework/Renderer.h"
#include "gamestates/GameState.h"
#include "objects/Card.h"
#include "objects/Table.h"
#include "objects/Deck.h"
#include "objects/Button.h"
#include "ui/ImageOverlay.h"
#include "objects/Player.h"
#include "framework/Game.h"

#include <iostream>

typedef void (*callback_function)(void);

class Playing : public GameState {
 private:
    Renderer colRenderer;
    Renderer Tex2DRenderer;
    Renderer texRenderer;

    Game game;
    Card cam;   // TODO
    Table table;

    int tick = 0;

    std::vector<Button> buttons;
    ImageOverlay crosshair;

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

    void checkMouse();
    void handleEvents();

    void hit();
};

#endif
