#ifndef STARTBUTTON_HPP
#define STARTBUTTON_HPP

#include <graphics.h>
#include "Config.hpp"

class StartButton {
    int x, y, width, height;
    bool clicked;

public:
    StartButton(int _x, int _y, int _w, int _h);
    void draw();
    bool isClicked(int mx, int my);
    bool waitForClick();  
};

#endif
