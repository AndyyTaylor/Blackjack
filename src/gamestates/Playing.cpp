// Copyright 2017 Andy Taylor
#include <GL/glew.h>
#include <GLUT/glut.h>

#include "gamestates/Playing.h"

Playing::Playing()
: GameState()
, simpleRenderer("data/shaders/vert.glsl", "data/shaders/frag.glsl")
, myCard(1, 1, 1) {
    
}

void Playing::init() {
    
}

void Playing::cleanup() {}

void Playing::update() {
    std::cout << "Playing State" << std::endl;
    
    simpleRenderer.activate();
    
    /*GLuint k;
    glGenBuffers(1, &k);
    GLfloat vertices[] = {
         0.0f,  0.5f,
         0.5f, -0.5f,
        -0.5f, -0.5f
    };
    glBindBuffer(GL_ARRAY_BUFFER, k);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);*/
    
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

void Playing::render() {}

void Playing::handleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT || (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)) {
            Display::close();
        }
    }
}

