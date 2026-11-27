#include "GameEnvironment.hpp"
#include "Config.hpp"
#include <iostream>

GameEnvironment::GameEnvironment(int x, int y, int width, int height) 
    : x(x), y(y), width(width), height(height) {}

int GameEnvironment::getX() const { return x; }
int GameEnvironment::getY() const { return y; }
int GameEnvironment::getWidth() const { return width; }
int GameEnvironment::getHeight() const { return height; }

void GameEnvironment::setPosition(int newX, int newY) {
    x = newX;
    y = newY;
}

void GameEnvironment::setSize(int newWidth, int newHeight) {
    width = newWidth;
    height = newHeight;
}

void GameEnvironment::collider() const {
    std::cout << "Collision check in environment";
}