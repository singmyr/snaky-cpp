#ifndef SNAKY_H
#define SNAKY_H

#include <map>

struct SDL_Window;
struct SDL_Surface;

class Screen;

class Snaky {
    private:
        int _screen_width;
        int _screen_height;

        SDL_Window* _window;
        SDL_Surface* _screen;

        std::map<std::string, Screen*> _screens;

        bool _update();
        void _render();

        bool _addScreen(std::string name, Screen *screen);
    public:
        Snaky(int screen_width, int screen_height);
        ~Snaky();

        void launch();
};

#endif
