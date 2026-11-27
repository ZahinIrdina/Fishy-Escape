// Config.hpp
#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <graphics.h>

// Game Board Configuration
const int BOARD_SIZE = 60;        // 60x60 game grid
const int PIXEL_SIZE = 12;        // Each grid cell is 12x12 pixels
const int SCREEN_WIDTH = BOARD_SIZE * PIXEL_SIZE;  // 720 pixels
const int SCREEN_HEIGHT = BOARD_SIZE * PIXEL_SIZE; // 720 pixels

// Game Element Identifiers
const int WALL_TILE = 4;
const int ZOMBIE_BODY = 5;
const int ZOMBIE_HIGHLIGHT = 6;
const int RESPAWN_WAIT = 30;

// Player Starting Positions
const int PLAYER_START_ROW = 30;
const int PLAYER_START_COL = 30;
const int ZOMBIE_START_ROW = 10;
const int ZOMBIE_START_COL = 10;

// Fish Configuration
const int FISH_SIZE = 10;
const int FISH_COLOR = LIGHTBLUE;

// UI Configuration
const int SCORE_X = 10;
const int SCORE_Y = 10;
const int START_BTN_WIDTH = 100;
const int START_BTN_HEIGHT = 40;

#endif