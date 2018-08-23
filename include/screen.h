#ifndef SCREEN_H
#define SCREEN_H

class Screen {
    private:
    protected:
        Screen();
    public:
        virtual bool update() = 0;
        virtual void render() = 0;
};

#endif