#include "splash_screen.h"

#include <iostream>

SplashScreen::SplashScreen() {}

bool SplashScreen::update() {
    std::cout << "Updating SplashScreen...\n";
    return true;
}

void SplashScreen::render() {
    // Render stuff.
    std::cout << "Rendering SplashScreen...\n";
}