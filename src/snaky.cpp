#include "snaky.h"

#include "SDL.h"
#include <string>
#include "splash_screen.h"

#include <iostream>

Snaky::Snaky(int screen_width, int screen_height) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        fprintf(stderr, "\nUnable to initialize SDL:  %s\n", SDL_GetError());
    }

    this->_screen_width = screen_width;
    this->_screen_height = screen_height;

    this->_window = SDL_CreateWindow("Snaky", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, this->_screen_width, this->_screen_height, SDL_WINDOW_SHOWN);
    if(this->_window == NULL) {
        // Unable to create the window.
        fprintf(stderr, "\nUnable to initialize SDL:  %s\n", SDL_GetError());
    }

    this->_screen = SDL_GetWindowSurface(this->_window);

    // Add screens.
    // SplashScreen.
    this->_addScreen("SplashScreen", new SplashScreen());
}

Snaky::~Snaky() {
    // todo: Destroy all Screens.

    SDL_FreeSurface(this->_screen);
    // Destroy window.
    SDL_DestroyWindow(this->_window);

    // Quit SDL subsystems.
    SDL_Quit();
}

void Snaky::launch() {
    // Calculate delta time.
    Uint64 last = SDL_GetPerformanceCounter();
    Uint64 now = 0;
    while(this->_update()) {
        // (double)((NOW - LAST)*1000 / SDL_GetPerformanceFrequency() )
        last = now;
        now = SDL_GetPerformanceCounter();
        Uint64 delta = ((now - last) * 1000 / (double)SDL_GetPerformanceFrequency());
        Uint64 last = SDL_GetPerformanceCounter();
        std::cout << "Delta: " << delta << std::endl;
        this->_render();
    }
}

bool Snaky::_update() {
    SDL_Event event;

    while(SDL_PollEvent(&event)) {
        switch(event.type) {
            case SDL_QUIT:
                return false;
        }
    }
    return true;
}

void Snaky::_render() {
    // Render stuff.
    SDL_FillRect(this->_screen, NULL, SDL_MapRGB(this->_screen->format, 0xFF, 0xFF, 0xFF));

    SDL_UpdateWindowSurface(this->_window);
}

bool Snaky::_addScreen(std::string name, Screen *screen) {
    this->_screens[name] = screen;

    return true;
}