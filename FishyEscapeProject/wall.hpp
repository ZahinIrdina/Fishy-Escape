#ifndef WALL_H
#define WALL_H

#include "Config.hpp"

class Wall {
private:
    int x, y;
    int width, height;
    int color;

    void _draw(int _color) const;

public:
    Wall(int _x = 0, int _y = 0, int _w = 100, int _h = 30, int _color = 8);

    // Accessors
    int getX() const;
    int getY() const;
    int getWidth() const;
    int getHeight() const;
    int getColor() const;

    // Mutators
    void setPosition(int _x, int _y);
    void setSize(int _w, int _h);
    void setColor(int _color);

    // Drawing
    void draw() const;
    void undraw() const;

    // Collision detection
    bool isColliding(int objX, int objY, int objSize) const;
};

#endif