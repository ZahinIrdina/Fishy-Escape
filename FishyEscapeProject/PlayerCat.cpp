#include "PlayerCat.hpp"
#include "LosingCondition.hpp"
#include "Config.hpp"

PlayerCat::PlayerCat(int row, int col) : Player(row, col) {
    int temp[height][width] = {
        {3,0,0,0,3,0,3},
        {0,2,0,0,3,3,3},
        {0,0,2,3,2,3,0},
        {0,0,2,2,2,0,0},
        {0,0,1,0,1,0,0}
    };
    for (int i = 0; i < height; ++i)
        for (int j = 0; j < width; ++j)
            sprite[i][j] = temp[i][j];
}

void PlayerCat::clearFromBoard(int board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            if (positionRow + i < 60 && positionCol + j < 60)
                board[positionRow + i][positionCol + j] = 0;
}

void PlayerCat::insertToBoard(int board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            if (sprite[i][j] != 0 && positionRow + i < 60 && positionCol + j < 60)
                board[positionRow + i][positionCol + j] = sprite[i][j];
}


bool PlayerCat::canMove(int dRow, int dCol, const int board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (sprite[i][j] != 0) {
                int newRow = positionRow + i + dRow;
                int newCol = positionCol + j + dCol;
                
                // Boundary check
                if (newRow < 0 || newRow >= 60 || newCol < 0 || newCol >= 60)
                    return false;
                    
                if (board[newRow][newCol] == 4 || 
                    board[newRow][newCol] == 5 || 
                    board[newRow][newCol] == 6) {
                    return false;
                }
            }
        }
    }
    return true;
}

void PlayerCat::draw() const {}

PlayerCat::CollisionType PlayerCat::checkCollision(const int board[BOARD_SIZE][BOARD_SIZE]) const {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (sprite[i][j] != 0) {
                int newRow = positionRow + i;
                int newCol = positionCol + j;
                
                if (newRow < 0 || newRow >= 60 || newCol < 0 || newCol >= 60)
                    continue;
                    
                if (board[newRow][newCol] == 4) return CollisionType::WALL;
                if (board[newRow][newCol] == 5 || board[newRow][newCol] == 6) {
                    return CollisionType::ZOMBIE;
                }
            }
        }
    }
    return CollisionType::NONE;
}

PlayerCat::CollisionType PlayerCat::checkZombieCollision(const int board[BOARD_SIZE][BOARD_SIZE]) const {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (sprite[i][j] != 0) {
                int newRow = positionRow + i;
                int newCol = positionCol + j;
                
                if (newRow < 0 || newRow >= 60 || newCol < 0 || newCol >= 60)
                    continue;
                    
                if (board[newRow][newCol] == 5 || board[newRow][newCol] == 6) {
                    return CollisionType::ZOMBIE;
                }
            }
        }
    }
    return CollisionType::NONE;
}

void PlayerCat::moveInstantly(int dRow, int dCol, int board[BOARD_SIZE][BOARD_SIZE]) {
    if (movementLock) return;
    
    movementLock = true;
    
    // Immediate position update
    if (canMove(dRow, dCol, board)) {
        clearFromBoard(board);
        positionRow += dRow;
        positionCol += dCol;
        insertToBoard(board);
    }
    
    movementLock = false;
}

