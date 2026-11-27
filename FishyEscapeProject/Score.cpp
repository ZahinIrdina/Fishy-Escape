#include "Score.hpp"
#include "Config.hpp"
#include <graphics.h>
#include <string>
#include <cstdio>
#include <stdio.h>

Score::Score(int x, int y) : point(0), x(x), y(y) {}

void Score::addPoints(int points) {
    point += points;
}

int& Score::getPoint() { 
    return point; 
}

void Score::displayScore() const {
    char buffer[50];
    sprintf(buffer, "Score: %d", point);
    outtextxy(x, y, buffer);
}

void Score::setPosition(int newX, int newY) {
    x = newX;
    y = newY;
}
