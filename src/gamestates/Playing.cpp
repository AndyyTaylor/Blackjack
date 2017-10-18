// Copyright 2017 Andy Taylor
#include <GL/glew.h>
#include <GLUT/glut.h>

#include "gamestates/Playing.h"
#include "framework/Matrix.h"

Playing::Playing()
: GameState()
, simpleRenderer("data/shaders/vert.glsl", "data/shaders/frag.glsl")
, myCard(1, 1, 1, simpleRenderer.getProgramID())
, cam(0, -5, 0, simpleRenderer.getProgramID()) {
    
}

void Playing::cleanup() {}

void Playing::update() {
    // myCard.position.y += 1;
}

void Playing::render() {
    simpleRenderer.activate();
    
    glm::mat4 m = Maths::createModelMatrix(myCard);
    glm::mat4 v = Maths::createViewMatrix(cam);
    glm::mat4 p = Maths::createProjMatrix();
    
    simpleRenderer.loadMVP(m, v, p);
    
    myCard.render();
}

void Playing::handleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT || (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)) {
            Display::close();
        } else if (event.type == SDL_KEYDOWN) {
            if (event.key.keysym.sym == SDLK_COMMA) {
                cam.position.y += 5;
            }
        }
    }
}

