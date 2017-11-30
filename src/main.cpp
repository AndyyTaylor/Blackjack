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
