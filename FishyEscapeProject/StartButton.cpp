#include "StartButton.hpp"
#include "Config.hpp"

StartButton::StartButton(int _x, int _y, int _w, int _h)
    : x(_x), y(_y), width(_w), height(_h), clicked(false) {}

void StartButton::draw() {
    setfillstyle(SOLID_FILL, LIGHTGREEN);
    bar(x, y, x + width, y + height);
    setbkcolor(BLACK);
    setcolor(WHITE);
    outtextxy(x + 10, y + 10, "START");
}

bool StartButton::isClicked(int mx, int my) {
    return mx >= x && mx <= x + width && my >= y && my <= y + height;
}

bool StartButton::waitForClick() {
    draw();
    while (!clicked) {
        if (ismouseclick(WM_LBUTTONDOWN)) {
            int mx, my;
            getmouseclick(WM_LBUTTONDOWN, mx, my);
            if (isClicked(mx, my)) {
                clicked = true;
                return true;
            }
        }
    }
    return false;
}
