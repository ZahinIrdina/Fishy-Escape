#ifndef PLAYER_H
#define PLAYER_H

#include <graphics.h>
#include <conio.h>
#include "Config.hpp"

class Player {
protected:  
    int positionRow;
    int positionCol;
    int directionRow;
    int directionCol;
    float speedVal = 8.0f;
    int size;
    int color;
    bool alive;

public:
    Player(int row = 0, int col = 0, float speed = 1.0f, int size = 1);

    // Accessors
    int getRow() const { return positionRow; }
    int getCol() const { return positionCol; }
    bool isAlive() const { return alive; }

    // Movement methods
    virtual void move(int dRow, int dCol, int board[BOARD_SIZE][BOARD_SIZE]);
    virtual void clearFromBoard(int board[BOARD_SIZE][BOARD_SIZE]) = 0;
    virtual void insertToBoard(int board[BOARD_SIZE][BOARD_SIZE]) = 0;
    
    // Collision detection
    virtual bool canMove(int dRow, int dCol, const int board[BOARD_SIZE][BOARD_SIZE]) const;

    bool dieCondition() { alive = false;
    return alive; }
};

#endif