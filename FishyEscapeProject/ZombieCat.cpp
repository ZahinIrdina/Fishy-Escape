#include "ZombieCat.hpp"
#include "Config.hpp"
#include <graphics.h>
#include <cstdlib> 
#include <ctime>   

ZombieCat::ZombieCat(int row, int col) : Player(row, col) {
    int temp[height][width] = {
        {6,0,0,0,6,0,6},  
        {0,5,0,0,6,6,6},  
        {0,0,5,6,5,6,0},
        {0,0,5,5,5,0,0},
        {0,0,7,0,7,0,0} 
    };
    for (int i = 0; i < height; ++i)
        for (int j = 0; j < width; ++j)
            sprite[i][j] = temp[i][j];
}

void ZombieCat::changeDirection() {
    int randomDir = rand() % 4; 
    switch (randomDir) {
        case 0: // Move Up
            directionRow = -1; directionCol = 0;
            break;
        case 1: // Move Down
            directionRow = 1; directionCol = 0;
            break;
        case 2: // Move Left
            directionRow = 0; directionCol = -1;
            break;
        case 3: // Move Right
            directionRow = 0; directionCol = 1;
            break;
    }
}

void ZombieCat::randomWalk(int board[BOARD_SIZE][BOARD_SIZE]) {
    clearFromBoard(board);

    if (!canMove(directionRow, directionCol, board)) {
        // If it will collide, find a new, valid direction
        do {
            changeDirection();
        } while (!canMove(directionRow, directionCol, board)); // Keep trying until we find a direction that isn't blocked
    }

    positionRow += directionRow;
    positionCol += directionCol;

    insertToBoard(board);
}

void ZombieCat::insertToBoard(int board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            if (sprite[i][j] != 0 && positionRow + i < 60 && positionCol + j < 60)
                board[positionRow + i][positionCol + j] = sprite[i][j];
}

void ZombieCat::move(int dRow, int dCol, int board[BOARD_SIZE][BOARD_SIZE]) {
    if (canMove(dRow, dCol, board)) {
        clearFromBoard(board);
        positionRow += dRow;
        positionCol += dCol;
        insertToBoard(board);
    }
}

float ZombieCat::length() const {
    return height * size; 
}

float ZombieCat::speed() const {
    return speedVal;
}

bool ZombieCat::collision(int nextRow, int nextCol, const int board[BOARD_SIZE][BOARD_SIZE]){
    return board[nextRow][nextCol] == 4;
}

void ZombieCat::clearFromBoard(int board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            if (positionRow + i >= 0 && positionRow + i < 60 && positionCol + j >= 0 && positionCol + j < 60)
                board[positionRow + i][positionCol + j] = 0;
}

bool ZombieCat::canMove(int dRow, int dCol, const int board[BOARD_SIZE][BOARD_SIZE]) const {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (sprite[i][j] != 0) {
                int newRow = positionRow + i + dRow;
                int newCol = positionCol + j + dCol;
                
                if (newRow < 0 || newRow >= 60 || newCol < 0 || newCol >= 60)
                    return false;
                    
                // Check only for walls. Player collision is handled by GameController.
                if (board[newRow][newCol] == 4) // Wall
                    return false;
            }
        }
    }
    return true;
}
