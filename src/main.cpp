// Copyright 2017 Andy taylor
#include <iostream>

#include "framework/Display.h"

#include "gamestates/Playing.h"

std::string PROJECT_PATH;  // NOLINT
int main(int argc, char** argv) {
    std::string s(argv[0]);
    PROJECT_PATH = s.substr(0, s.length()-5);

    if (!Display::init())
        return -1;

    Playing state;
    while (Display::isOpen()) {
        Display::clear();
        state.handleEvents();
        state.update();
        state.render();
        // Display::update();  - I did a bullshit :(
    }

    std::cout << "Exiting..." << std::endl;
    return 0;
}

/*
g++ -I include src/objects/Button.cpp src/objects/Card.cpp src/objects/Deck.cpp src/objects/Object.cpp src/objects/Player.cpp src/objects/Table.cpp src/gamestates/Playing.cpp src/framework/Display.cpp src/framework/Game.cpp src/framework/Matrix.cpp src/framework/Renderer.cpp src/framework/Tex_Atlas.cpp src/ui/ImageOverlay.cpp /usr/local/Cellar/sdl2_image/2.0.1_2/lib/libSDL2_image.a /usr/local/Cellar/sdl2/2.0.5/lib/libSDL2.a /usr/local/Cellar/glew/2.0.0/lib/libGLEW.a /usr/local/Cellar/libpng/1.6.29/lib/libpng16.a -liconv -lobjc -framework Opengl -framework CoreAudio -framework AudioToolbox -framework CoreVideo -framework ForceFeedback -framework Cocoa -framework Carbon -framework IOKit -framework AppKit -framework CoreFoundation -framework CoreGraphics -framework CoreServices -framework Foundation -std=c++11 src/main.cpp -o main
*/
