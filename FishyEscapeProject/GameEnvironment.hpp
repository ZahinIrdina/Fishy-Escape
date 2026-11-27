#ifndef GAMEENVIRONMENT_HPP
#define GAMEENVIRONMENT_HPP

#include "Config.hpp"

class GameEnvironment {
protected:
    int x, y;
    int width, height;

public:
    GameEnvironment(int x = 0, int y = 0, int width = 0, int height = 0);
    virtual void collider() const;
    virtual ~GameEnvironment() {}
    
    // Accessors
    int getX() const;
    int getY() const;
    int getWidth() const;
    int getHeight() const;
    
    // Mutators
    void setPosition(int newX, int newY);
    void setSize(int newWidth, int newHeight);
};

#endif
