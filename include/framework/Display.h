// Copyright 2017 Andy Taylor
#ifndef DISPLAY_H_INCLUDED
#define DISPLAY_H_INCLUDED

#include <GL/glew.h>
#include <SDL2/SDL.h>

#include <iostream>

namespace Display {
    const uint WIDTH = 1280;
    const uint HEIGHT = 720;
    
    bool init();
    bool initSDL();
    void initGL();
    void clear();
    void update();
    bool isOpen();
    void close();
}   // namespace Display

#endif /* DISPLAY_H_INCLUDED */
