#ifndef SPLASH_SCREEN_H
#define SPLASH_SCREEN_H

#include "screen.h"

class SplashScreen : public Screen {
    private:
    protected:
    public:
        SplashScreen();

        bool update();
        void render();
};

#endif