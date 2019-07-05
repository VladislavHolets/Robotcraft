/*
 * game.h
 *
 *  Created on: Jul 5, 2019
 *      Author: curab
 */

#ifndef GAME_H_
#define GAME_H_
#include "../Position/position.h"
#include <stdint.h>

//STATES OF THE CELLS
#define FREE 0
#define NOLL 1
#define CROSS 2
#define CURRENT 3

//CONTROLS NUMPAD
//#define THIS 53

//#define LEFT 52
//#define RIGHT 54
//#define UP 56
//#define DOWN 50

//#define EXIT 48

//CONTROLS ARROWS

#define THIS 53

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80

#define EXIT 48

//SIZE OF ARRAY
#define SIZE 20

struct Game {
	uint8_t matrix[SIZE][SIZE];
	struct Position *current;
	uint8_t player;
	uint8_t endFlag;
};

void displayGame(struct Game * game);
struct Game * initGameRobot();
void readMoveRobot(struct Game * game);
void setPositionToFREE(struct Game * game);
uint8_t isFree(struct Game* game);

#endif /* GAME_H_ */
