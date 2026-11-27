#ifndef WINNINGCONDITION_HPP
#define WINNINGCONDITION_HPP

#include "Config.hpp"

class WinningCondition {
    int winScore;

public:
    WinningCondition(int targetScore);
    bool check(int currentScore);
    void displayWin();
};

#endif
