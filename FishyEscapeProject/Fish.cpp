// Fish.cpp
#include "Fish.hpp"
#include "GameController.hpp"
#include "Config.hpp"
#include <graphics.h>
#include <cstdlib>
#include <ctime>
#include <algorithm> 

Fish::Fish(int x, int y, int size, int color, int respawnTimer) 
    : GameEnvironment(x, y, size*2, size*2), isEaten(false), color(color), 
      size(size), respawnTimer(0) { 
    std::srand(static_cast<unsigned>(time(nullptr)));
}

void Fish::respawn(int maxX, int maxY, int catX, int catY, const std::vector<Wall>& walls) {
    if (respawnTimer < RESPAWN_WAIT) {
        respawnTimer++;
        return;
    }
    
    int distanceSquared;
    bool collidesWithWall;
    const int minDistanceFromWall = size * 2;  // Increased minimum distance
    
    int attempts = 0;
    const int maxAttempts = 100;  // Prevent infinite loops
    
    do {
        // Generate new position with proper margins
        x = rand() % (maxX - size * 4) + size * 2;
        y = rand() % (maxY - size * 4) + size * 2;
        
        // Check distance from cat
        int dx = x - catX;
        int dy = y - catY;
        distanceSquared = dx * dx + dy * dy; 
        
        // Check collision with walls
        collidesWithWall = false;
        for (const auto& wall : walls) {
            if (wall.isColliding(x, y, size * 2)) {
                collidesWithWall = true;
                break;
            }
        }
        
        attempts++;
        if (attempts >= maxAttempts) break;  // Safety net
    } while ((distanceSquared < (size * size) || collidesWithWall) && attempts < maxAttempts);

    isEaten = false;
    respawnTimer = 0;
}

bool Fish::getStatus() const { 
    return !isEaten; 
}

void Fish::gotEaten() { 
    isEaten = true;
}

void Fish::draw() {
    if (!isEaten) {
        setcolor(color);
        setfillstyle(SOLID_FILL, color);
        fillellipse(x, y, size, size/2); // Fish body (oval)
        
        // Fish tail (triangle)
        int tail[6] = {x+size, y, x+size*2, y-size/2, x+size*2, y+size/2};
        fillpoly(3, tail);
    }
}