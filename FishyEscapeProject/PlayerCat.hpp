// PlayerCat.hpp
#ifndef PLAYERCAT_HPP
#define PLAYERCAT_HPP

#include "Player.hpp"
#include "Config.hpp"


class PlayerCat : public Player {
private:
    static const int height = 5;
    static const int width = 7;
    int sprite[height][width];
    bool movementLock = false;

public:
    enum class CollisionType {
    NONE,
    WALL,
    ZOMBIE,
}; 

    PlayerCat(int row = 30, int col = 30);
    
    void clearFromBoard(int boar[BOARD_SIZE][BOARD_SIZE]) override ;
    void insertToBoard(int board[BOARD_SIZE][BOARD_SIZE]) override ;
    CollisionType checkCollision(const int board[BOARD_SIZE][BOARD_SIZE]) const;
    CollisionType checkZombieCollision(const int board[BOARD_SIZE][BOARD_SIZE]) const;
   
    bool canMove(int dRow, int dCol, const int board[BOARD_SIZE][BOARD_SIZE]);
    void moveInstantly(int dRow, int dCol, int board[BOARD_SIZE][BOARD_SIZE]);
    void draw() const;

    int getWidth() const { return width * PIXEL_SIZE; }  
    int getHeight() const { return height * PIXEL_SIZE; }
};

#endif