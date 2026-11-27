#ifndef ZOMBIECAT_HPP
#define ZOMBIECAT_HPP

#include "Player.hpp"
#include "Config.hpp"

class ZombieCat : public Player {
private:
    static const int height = 5;
    static const int width = 7;
    int sprite[height][width];

    void changeDirection();

public:
    ZombieCat(int row, int col);
    void move(int dRow, int dCol, int board[BOARD_SIZE][BOARD_SIZE]) override;
    void clearFromBoard(int board[BOARD_SIZE][BOARD_SIZE]) override;
    void insertToBoard(int board[BOARD_SIZE][BOARD_SIZE]) override;
    bool canMove(int dRow, int dCol, const int board[BOARD_SIZE][BOARD_SIZE]) const override;
    
    void randomWalk(int board[BOARD_SIZE][BOARD_SIZE]);

    bool collision(int nextRow, int nextCol, const int board[BOARD_SIZE][BOARD_SIZE]);
    float length() const;
    float speed() const;
};

#endif
