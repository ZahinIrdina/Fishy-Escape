//PT2 PROJECT : FISHY ESCAPE
// This is a simple game where a player controls a cat to collect fish while avoiding zombie cats.
// The game features a grid-based board, walls, and a scoring system.
// The player can move the cat using WASD keys, and the game ends when the player collects enough fish or collides with a zombie cat.

//PREPARED BY :
// ANATASYA HUMAIRA (A20EC0261)
// ZAHIN IRDINA BINTI MOHD ZABIDY (A24CS0216)
// SYAZMIN NADIA BINTI AHMAD LUTHFI (A24CS0300)
// NUR FATIN NABILA BINTI ZAINUDIN (A24CS0163)

#include <graphics.h>
#include <conio.h>
#include <vector>
#include <time.h>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <windows.h>     
#include <mmsystem.h>
#include "GameEnvironment.hpp"
#include "ZombieCat.hpp"
#include "PlayerCat.hpp"
#include "wall.hpp"
#include "StartButton.hpp"
#include "GameController.hpp"
#include "WinningCondition.hpp"
#include "LosingCondition.hpp"
#include "Fish.hpp"
#include "Score.hpp"
#include "Config.hpp"
#pragma comment(lib, "winmm.lib")

using namespace std;

int board[BOARD_SIZE][BOARD_SIZE];

void initBoard() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = 0;
        }
    }

    for (int i = 0; i < BOARD_SIZE; i++) {
        board[i][0] = WALL_TILE;
        board[i][BOARD_SIZE - 1] = WALL_TILE;
        board[0][i] = WALL_TILE;
        board[BOARD_SIZE - 1][i] = WALL_TILE;
    }
}

void drawBoard() {
    for (int r = 0; r < BOARD_SIZE; r++) {
        for (int c = 0; c < BOARD_SIZE; c++) {
            switch (board[r][c]) {
                case WALL_TILE:
                    setfillstyle(SOLID_FILL, CYAN);
                    bar(c * PIXEL_SIZE, r * PIXEL_SIZE,
                        (c + 1) * PIXEL_SIZE - 1, (r + 1) * PIXEL_SIZE - 1);
                    break;
                case 1: setfillstyle(SOLID_FILL, LIGHTRED); break;
                case 2: setfillstyle(SOLID_FILL, WHITE); break;
                case 3: setfillstyle(SOLID_FILL, YELLOW); break;
                case 7: setfillstyle(SOLID_FILL, LIGHTGREEN); break;
                case 5: setfillstyle(SOLID_FILL, LIGHTMAGENTA); break;
                case 6: setfillstyle(SOLID_FILL, MAGENTA); break;
                default: continue;
            }

            if (board[r][c] >= 1 && board[r][c] <= 7 && board[r][c] != WALL_TILE) {
                bar(c * PIXEL_SIZE, r * PIXEL_SIZE,
                    (c + 1) * PIXEL_SIZE - 1, (r + 1) * PIXEL_SIZE - 1);
            }
        }
    }
}

int main() {
    srand(time(0));
    initwindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Fishy Escape");

    PlaySound(TEXT("start.wav"), NULL, SND_FILENAME | SND_ASYNC);

    //Show Start Background
    readimagefile("start_screen.bmp", 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

    initBoard();

    StartButton startBtn(SCREEN_WIDTH / 2 - 50, SCREEN_HEIGHT / 2 - 20, 100, 40);
    startBtn.waitForClick();

    //Switch to Gameplay Background
    readimagefile("gameplay_background.bmp", 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

    vector<Wall> walls = {
        Wall(100, 250, 500, 30, BLUE),
        Wall(0, 0, 500, 30, BLUE),
        Wall(500, 500, 500, 30, BLUE)
    };

    for (const auto& wall : walls) {
        wall.draw();
        int startX = wall.getX() / PIXEL_SIZE;
        int startY = wall.getY() / PIXEL_SIZE;
        int endX = (wall.getX() + wall.getWidth()) / PIXEL_SIZE;
        int endY = (wall.getY() + wall.getHeight()) / PIXEL_SIZE;

        for (int y = startY; y <= endY; y++) {
            for (int x = startX; x <= endX; x++) {
                if (x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE) {
                    board[y][x] = WALL_TILE;
                }
            }
        }
    }

    ZombieCat zcat(10, 10);
    PlayerCat pcat(30, 30);
    LosingCondition loseCond(pcat);
    WinningCondition winCond(10);
    Score scoreDisplay(10, 10);
    int& scoreRef = scoreDisplay.getPoint();
    GameController gameCtrl(&pcat, &zcat, scoreRef, 10, &loseCond);
    Fish fish(200, 200, 10, LIGHTBLUE);
    gameCtrl.update(board);

    int page = 0;

    while (true) {
        setactivepage(page);
        cleardevice();

        //Draw gameplay background every frame
        readimagefile("gameplay_background.bmp", 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

        //Controls
        if (kbhit()) {
            char key = getch();
            if (key == 27) break; // ESC to quit

            switch (tolower(key)) {
                case 'w': pcat.moveInstantly(-1, 0, board); break;
                case 's': pcat.moveInstantly(1, 0, board); break;
                case 'a': pcat.moveInstantly(0, -1, board); break;
                case 'd': pcat.moveInstantly(0, 1, board); break;
            }
        }

        zcat.randomWalk(board);

        int catX = (pcat.getCol() * PIXEL_SIZE) + (pcat.getWidth() * PIXEL_SIZE) / 2;
        int catY = (pcat.getRow() * PIXEL_SIZE) + (pcat.getHeight() * PIXEL_SIZE) / 2;

        if (!gameCtrl.update(board)) {
            // Game over or win — show appropriate screen
            cleardevice();
            PlaySound(TEXT("start.wav"), NULL, SND_FILENAME | SND_ASYNC);
            if (scoreRef >= 10) {
                PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
                readimagefile("win_screen.bmp", 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
                winCond.displayWin();  // Still shows "YOU WIN!"
            } else {
                PlaySound(TEXT("lose.wav"), NULL, SND_FILENAME | SND_ASYNC);
                readimagefile("loss_screen.bmp", 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
                loseCond.displayLoss();  // Still shows "GAME OVER"
            }
            break;
        }

        drawBoard();
        scoreDisplay.displayScore();

        if (fish.getStatus()) {
            fish.draw();

            int playerCenterX = pcat.getCol() * PIXEL_SIZE + (pcat.getWidth()) / 2;
            int playerCenterY = pcat.getRow() * PIXEL_SIZE + (pcat.getHeight()) / 2;
            int fishCenterX = fish.getX();
            int fishCenterY = fish.getY();
            int dx = fishCenterX - playerCenterX;
            int dy = fishCenterY - playerCenterY;
            int distanceSquared = dx * dx + dy * dy;
            int collisionDistance = (pcat.getWidth() / 2) + (fish.getWidth() / 2);
            int collisionDistanceSquared = collisionDistance * collisionDistance;

            if (distanceSquared < collisionDistanceSquared) {
                fish.gotEaten();
                PlaySound(TEXT("eat.wav"), NULL, SND_FILENAME | SND_ASYNC);
                scoreDisplay.addPoints(1);
            }

        } else {
            static int respawnTimer = 0;
            fish.respawn(SCREEN_WIDTH, SCREEN_HEIGHT, catX, catY, walls);
            respawnTimer = 0;
        }

        setvisualpage(page);
        page = 1 - page;

        delay(100);
    }

    closegraph();
    return 0;
}
