#include "GameController.hpp"
#include "Player.hpp"
#include "PlayerCat.hpp"
#include "ZombieCat.hpp"
#include "Config.hpp"

GameController::GameController(PlayerCat* player, ZombieCat* zombie, int& score, int winScore, LosingCondition* loseCond)
    : player(player), zombie(zombie), winCond(winScore), loseCond(loseCond), score(score) {
    }
    
bool GameController::update(int board[BOARD_SIZE][BOARD_SIZE]) {
    if (player->checkZombieCollision(board) == PlayerCat::CollisionType::ZOMBIE) {
        player->dieCondition();
        if (loseCond) {  // Check if pointer is valid
            loseCond->displayLoss();
            return false;
        }
    }

    zombie->insertToBoard(board);
    player->insertToBoard(board);

    if (loseCond && loseCond->check()) {
        loseCond->displayLoss();
        return false;
    }

    if (winCond.check(score)) {
        winCond.displayWin();
        return false;
    }

    return true;
}
