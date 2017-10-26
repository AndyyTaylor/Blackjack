// Copyright 2017 Andy Taylor
#include <GL/glew.h>
#include <GLUT/glut.h>

#include "gamestates/Playing.h"
#include "framework/Matrix.h"

Playing::Playing()
: GameState()
, colRenderer("data/shaders/col/vert.glsl", "data/shaders/col/frag.glsl")
, texRenderer("data/shaders/tex/vert.glsl", "data/shaders/tex/frag.glsl")
, myCard(2, 0, 0, colRenderer.getProgramID())
, cam(0, 1, 5, colRenderer.getProgramID())
, table(0, -0.0001f, 0, colRenderer.getProgramID()) {
    
}

void Playing::cleanup() {}

void Playing::update() {
    float speed = 0.1f;
    if (moving_forward) {
        cam.position.x -= cos(glm::radians(cam.rotation.y + 90)) * speed;
        cam.position.z -= sin(glm::radians(cam.rotation.y + 90)) * speed;
    }
    if (moving_backward) {
        cam.position.x += cos(glm::radians(cam.rotation.y + 90)) * speed;
        cam.position.z += sin(glm::radians(cam.rotation.y + 90)) * speed;
    }
    if (moving_left) {
        cam.position.x -= cos(glm::radians(cam.rotation.y)) * speed;
        cam.position.z -= sin(glm::radians(cam.rotation.y)) * speed;
    }
    if (moving_right) {
        cam.position.x += cos(glm::radians(cam.rotation.y)) * speed;
        cam.position.z += sin(glm::radians(cam.rotation.y)) * speed;
    }
    if (moving_up) {
        cam.position.y += speed;
    }
    if (moving_down) {
        cam.position.y -= speed;
    }
    
    if (false && fabs(fabs(myCard.position.x) - 2) < 0.01f) {
        myCard.glide(glm::vec3(-myCard.position.x, 0, 0)
                     , glm::vec3(0, myCard.rotation.y + (180*5 * (myCard.position.x/fabs(myCard.position.x)))
                     , 0), 70);
    }
    myCard.update();
}

void Playing::render() {
    glm::mat4 v = Maths::createViewMatrix(cam);
    glm::mat4 p = Maths::createProjMatrix();
    glm::mat4 m;
    
    colRenderer.activate();
    m = Maths::createModelMatrix(table);
    colRenderer.loadMVP(p * v * m);
    table.render();
    
    texRenderer.activate();
    m = Maths::createModelMatrix(myCard);
    texRenderer.loadMVP(p * v * m);
    myCard.render();
}

void Playing::handleEvents() {
    SDL_Event event;
    
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT || (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)) {
            Display::close();
        } else if (event.type == SDL_KEYDOWN) {
            if (event.key.keysym.sym == SDLK_COMMA) {
                moving_forward = true;
            } else if (event.key.keysym.sym == SDLK_o) {
                moving_backward = true;
            } else if (event.key.keysym.sym == SDLK_a) {
                moving_left = true;
            } else if (event.key.keysym.sym == SDLK_e) {
                moving_right = true;
            } else if (event.key.keysym.sym == SDLK_LSHIFT) {
                moving_down = true;
            } else if (event.key.keysym.sym == SDLK_SPACE) {
                moving_up = true;
            }
        }  else if (event.type == SDL_KEYUP) {
            if (event.key.keysym.sym == SDLK_COMMA) {
                moving_forward = false;
            } else if (event.key.keysym.sym == SDLK_o) {
                moving_backward = false;
            } else if (event.key.keysym.sym == SDLK_a) {
                moving_left = false;
            } else if (event.key.keysym.sym == SDLK_e) {
                moving_right = false;
            } else if (event.key.keysym.sym == SDLK_LSHIFT) {
                moving_down = false;
            } else if (event.key.keysym.sym == SDLK_SPACE) {
                moving_up = false;
            }
        } else if (event.type == SDL_MOUSEMOTION) {
            cam.rotation.y += event.motion.xrel/3;  // MOUSE_SENSITIVITY
            cam.rotation.x += event.motion.yrel/3;
        }
    }
}

