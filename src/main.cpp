#include <cstdlib>
#include <iostream>
#include "SDL.h"
#include "SDL_image.h"

#include "snaky.h"

const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 768;

int main(void) {
    std::cout << "Hello world" << std::endl;
    Snaky* game = new Snaky(SCREEN_WIDTH, SCREEN_HEIGHT);

    game->launch();

    return 0;
}
