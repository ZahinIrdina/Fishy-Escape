#include <graphics.h>
#include <cmath>
#include <vector>
#include "wall.hpp"
#include "Config.hpp"

Wall::Wall(int _x, int _y, int _w, int _h, int _color)
    : x(_x), y(_y), width(_w), height(_h), color(_color) {}

void Wall::_draw(int _color) const {
    setcolor(_color);
    setfillstyle(SOLID_FILL, _color);
    bar(x, y, x + width, y + height);
}

void Wall::draw() const {
    _draw(color);
}

void Wall::undraw() const {
    _draw(BLACK);
}

int Wall::getX() const { return x; }
int Wall::getY() const { return y; }
int Wall::getWidth() const { return width; }
int Wall::getHeight() const { return height; }
int Wall::getColor() const { return color; }

void Wall::setPosition(int _x, int _y) {
    x = _x;
    y = _y;
}

void Wall::setSize(int _w, int _h) {
    width = _w;
    height = _h;
}

void Wall::setColor(int _color) {
    color = _color;
}

bool Wall::isColliding(int objX, int objY, int objSize) const {
    // Checks if circle at (objX, objY) with radius objSize intersects wall rectangle
    int closestX = std::max(x, std::min(objX, x + width));
    int closestY = std::max(y, std::min(objY, y + height));
    int dx = objX - closestX;
    int dy = objY - closestY;
    return (dx * dx + dy * dy) < (objSize * objSize);
}
