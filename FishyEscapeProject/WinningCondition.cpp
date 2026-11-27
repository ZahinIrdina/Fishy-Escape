#include "WinningCondition.hpp"
#include "Config.hpp"
#include <graphics.h>
#include <windows.h>     
#include <mmsystem.h>

#pragma comment(lib, "winmm.lib")

WinningCondition::WinningCondition(int targetScore) : winScore(targetScore) {}

bool WinningCondition::check(int currentScore) {
    return currentScore >= winScore;
}

void WinningCondition::displayWin() {
    setcolor(GREEN);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 5);

    PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
    
    readimagefile("win_screen.bmp", 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);  

    setcolor(GREEN);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 5);
    outtextxy(200, 200, "YOU WIN!");

    swapbuffers();

    delay(3000);
}
