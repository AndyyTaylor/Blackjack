// Copyright 2017 Andy Taylor
#include <GL/glew.h>
#include <GLUT/glut.h>

#include "gamestates/Playing.h"
#include "framework/Matrix.h"

Playing::Playing()
: GameState()
, colRenderer("data/shaders/col/vert.glsl", "data/shaders/col/frag.glsl")
, Tex2DRenderer("data/shaders/2d/vert.glsl", "data/shaders/2d/frag.glsl")
, texRenderer("data/shaders/tex/vert.glsl", "data/shaders/tex/frag.glsl")
, myCard(1.5f, 0, 0, CLUB, NINE)
, cam(0, 1, 5, CLUB, ACE)
, table(0, -0.001f, 0)
, deck(-0.3f, 0.04f, -0.0f, 1, 0.08f)
, crosshair(0.2, 0.2, 0.1, "data/images/crosshair.png")
, player(0, 0, 3, 0.15f, 0, 0.8f, 0.2f) {
    buttons.push_back(Button(-0.3f, 0, 0.8f, 76, "data/images/hit.png", "data/images/hit hover.png"));
    buttons.push_back(Button(0.3f, 0, 0.8f, 77, "data/images/stand.png", "data/images/stand hover.png"));
}

void Playing::cleanup() {}

void Playing::update() {
    float speed = 0.03f;
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
    
    if (fabs(fabs(myCard.position.x) - 1.5) < 0.01f) {
        myCard.glide(glm::vec3(-myCard.position.x, 0, 0)
                     , glm::vec3(0, myCard.rotation.y + (180*5 * (myCard.position.x/fabs(myCard.position.x)))
                     , 0), 100);
    }
    myCard.update();
    
    deck.update();
    
    for (int i = 0; i < buttons.size(); i++) {
        buttons[i].update();
    }
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
    
    texRenderer.activate();
    for (int i = 0; i < buttons.size(); i++) {
        m = Maths::createModelMatrix(buttons[i]);
        texRenderer.loadMVP(p * v * m);
        buttons[i].render();
    }
    
    deck.render(p, v, texRenderer);
    
    Tex2DRenderer.activate();
    m = Maths::createModelMatrix(crosshair);
    crosshair.render();
    
    checkMouse();
}

void Playing::checkMouse() {
    Display::update();
    glFlush();
    glFinish();

    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    unsigned char data[4];
    glReadPixels(Display::WIDTH/2, Display::HEIGHT/2, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, data);
    
    int id = static_cast<int>(data[0]);
    for (int i = 0; i < buttons.size(); i++) {
        buttons[i].setHover(false);
        if (id == buttons[i].id) {
            buttons[i].setHover(true);
        }
    }
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
            } else if (event.key.keysym.sym == SDLK_PERIOD) {
                int id = -1;
                for (int i = 0; i < buttons.size(); i++) {
                    if (buttons[i].hover) {
                        id = buttons[i].id;
                        break;
                    }
                }
                
                if (id == 76) {
                    player.addCard(deck.deal());
                } else {
                    player.clearHand();
                    deck.shuffle();
                }
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
            cam.rotation.y += event.motion.xrel/5.0f;  // MOUSE_SENSITIVITY
            cam.rotation.x += event.motion.yrel/5.0f;
        }
    }
}

