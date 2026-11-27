#ifndef LOSINGCONDITION_HPP
#define LOSINGCONDITION_HPP

#include "Player.hpp"
#include "PlayerCat.hpp"
#include "Config.hpp"

class LosingCondition {
    const PlayerCat& player;
public:
    LosingCondition(const PlayerCat& player);
    bool check() const;
    void displayLoss() const;
};

#endif
