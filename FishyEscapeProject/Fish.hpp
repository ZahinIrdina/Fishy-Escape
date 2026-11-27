// Fish.hpp
#ifndef FISH_HPP
#define FISH_HPP
#include <graphics.h>
#include <vector>
#include "GameEnvironment.hpp"
#include "wall.hpp" 
#include "Config.hpp"

const int wall = 4;

class Fish : public GameEnvironment {
private:
    bool isEaten;
    int color;
    int size;
    int respawnTimer;  // Added this line


public:
    Fish(int x = 0, int y = 0, int size = 5, int color = LIGHTBLUE, int respawnTimer = 0);
    void respawn(int maxX, int maxY, int catX, int catY, const std::vector<Wall>& walls);  // Add walls parameter
    bool getStatus() const;
    void gotEaten();
    void draw();
    int getWidth() const { return size*2; }
    int getHeight() const { return size*2; }
};

#endif