#include "Player.hpp"
#include "Config.hpp"

Player::Player(int row, int col, float speed, int size) 
    : positionRow(row), positionCol(col), speedVal(speed), size(size),
      directionRow(0), directionCol(1), alive(true) {}

void Player::move(int dRow, int dCol, int board[BOARD_SIZE][BOARD_SIZE]) {
    if (canMove(dRow, dCol, board)) {
        clearFromBoard(board);
        positionRow += dRow;
        positionCol += dCol;
        insertToBoard(board);
    }
    else {
        dieCondition();
    }
}


bool Player::canMove(int dRow, int dCol, const int board[BOARD_SIZE][BOARD_SIZE]) const {
    int newRow = positionRow + dRow;
    int newCol = positionCol + dCol;
    return (newRow >= 0 && newRow < 70 && 
            newCol >= 0 && newCol < 70 && 
            board[newRow][newCol] != 4); // 4 is wall
}



