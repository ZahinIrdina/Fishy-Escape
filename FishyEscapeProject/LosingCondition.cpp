#include "LosingCondition.hpp"
#include "Config.hpp"
#include <graphics.h>
#include <iostream>
#include <windows.h>     
#include <mmsystem.h>

#pragma comment(lib, "winmm.lib")

using namespace std;

LosingCondition::LosingCondition(const PlayerCat& player) : player(player) {}

bool LosingCondition::check() const {
    return !player.isAlive();
}

void LosingCondition::displayLoss() const {
    setcolor(RED);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 5);
    PlaySound(TEXT("lose.wav"), NULL, SND_FILENAME | SND_ASYNC);
    
    readimagefile("loss_screen.bmp", 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);  // Show background first

    setcolor(RED);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 5);
    outtextxy(200, 200, "GAME OVER!");

    swapbuffers();

    delay(3000);
}
