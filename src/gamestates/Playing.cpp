// Copyright 2017 Andy Taylor
#include <GL/glew.h>
#include <GLUT/glut.h>

#include "gamestates/Playing.h"

void Playing::init() {
}

void Playing::cleanup() {}

void Playing::update() {
    std::cout << "Playing State" << std::endl;
    
    glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
        glColor3f(1.0f, 0.0f, 0.0f);  // Red
        glVertex2f(-0.5f, -0.5f);     // x, y
        glVertex2f(0.5f, -0.5f);
        glVertex2f(0.5f,  0.5f);
        glVertex2f(-0.5f,  0.5f);
    glEnd();
    
    // glFlush();
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

