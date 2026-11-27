#ifndef GAMECONTROLLER_HPP
#define GAMECONTROLLER_HPP

#include "PlayerCat.hpp"
#include "ZombieCat.hpp"
#include "WinningCondition.hpp"
#include "LosingCondition.hpp"
#include "Config.hpp"

class GameController {
    PlayerCat* player;
    ZombieCat* zombie;
    WinningCondition winCond;
    LosingCondition *loseCond;
    int& score;

public:
    GameController(PlayerCat* _player, ZombieCat* _zombie, int& _score, int winScore = 10, LosingCondition* _loseCond = nullptr);
    bool update(int board[BOARD_SIZE][BOARD_SIZE]);  
};

#endif
