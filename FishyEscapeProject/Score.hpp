#ifndef SCORE_HPP
#define SCORE_HPP

#include <string>
#include "Config.hpp"

class Score {
private:
    int point;
    int x, y;

public:
    Score(int x = 10, int y = 10);
    void addPoints(int points = 0);
    int& getPoint();
    void displayScore() const;
    void setPosition(int newX, int newY);
};

#endif