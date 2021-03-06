// Copyright 2017 Andy Taylor
#include "framework/Display.h"

namespace Display {
    SDL_Window* window;
    bool open = true;

    bool init() {
        if (!initSDL())
            return false;

        initGL();

        return true;
    }

    void clear() {
        glClearColor(0.41, 0.41, 0.41, 1.0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void update() {
        SDL_GL_SwapWindow(window);
    }

    bool isOpen() {
        return open;
    }

    void close() {
        open = false;
        SDL_DestroyWindow(window);
        SDL_Quit();
    }

    bool initSDL() {
        if (SDL_Init(SDL_INIT_VIDEO) < 0)
            return false;

        window = SDL_CreateWindow("Blackjack",
                                  SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                  WIDTH, HEIGHT,
                                  SDL_WINDOW_OPENGL);
        SDL_SetRelativeMouseMode(SDL_TRUE);
        // SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);

        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,
                            SDL_GL_CONTEXT_PROFILE_CORE);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
        SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
        SDL_GL_CreateContext(window);

        return true;
    }

    void initGL() {
        glewExperimental = GL_TRUE;
        glewInit();
        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LESS);

        // glEnable(GL_CULL_FACE);
        // glCullFace(GL_BACK);

        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    }
}   // namespace Display


