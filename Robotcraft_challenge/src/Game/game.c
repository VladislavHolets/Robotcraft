/*
 * game.c
 *
 *  Created on: Jul 5, 2019
 *      Author: curab
 */

#include "game.h"
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

void displayGame(struct Game * game) {
	system("CLS");
	printf("\n");
	if (game->matrix[game->current->y][game->current->x] != FREE) {
		setPositionToFREE(game);
	}
	for (int8_t i = 0; i < SIZE; ++i) {
		for (int8_t j = 0; j < SIZE; ++j) {
			printf("|");
			if (game->current->y == i && game->current->x == j) {
				printf("#");
			} else {
				switch (game->matrix[i][j]) {
				case FREE: {
					printf("_");
					break;
				}
				case NOLL: {
					printf("O");
					break;
				}
				case CROSS: {
					printf("X");
					break;
				}
				}
			}
			printf("|");

		}
		printf("\n");
	}
}
void readMoveRobot(struct Game * game) {
	uint8_t number;
	fflush(stdout);
	fflush(stdin);
	number = getch();
	//printf("%d", number);
	fflush(stdout);
	if (game->matrix[game->current->y][game->current->x] != FREE) {
		setPositionToFREE(game);
	}
	if (number == LEFT) {
		if (game->current->x
				>= 1&& game->matrix[game->current->y][game->current->x-1]==FREE) {
			game->current->x--;
			//printf("[%d][%d]\n", game->current_i, game->current_j);
		}
	} else if (number == RIGHT) {
		if (game->current->x
				< (SIZE - 1)&& game->matrix[game->current->y][game->current->x+1]==FREE) {
			game->current->x++;
			//printf("[%d][%d]\n", game->current_i, game->current_j);
		}
	} else if (number == UP) {
		if (game->current->y
				>= 1&& game->matrix[game->current->y-1][game->current->x]==FREE) {
			game->current->y--;
			//printf("[%d][%d]\n", game->current_i, game->current_j);
		}
	} else if (number == DOWN) {
		if (game->current->y
				< (SIZE - 1)&& game->matrix[game->current->y+1][game->current->x]==FREE) {
			game->current->y++;
			//printf("[%d][%d]\n", game->current_i, game->current_j);
		}
	} else if (number == EXIT) {
		exit(0);
	}
}
struct Game * initGameRobot() {
	struct Game * instance = malloc(sizeof(struct Game));
	instance->current = malloc(sizeof(struct Position));
	for (int8_t i = 0; i < SIZE; ++i) {
		for (int8_t j = 0; j < SIZE; ++j) {
			instance->matrix[i][j] = ((rand() % 13) != 4) ? FREE : CROSS;
			//this is generation of wall you can change 13 to
			//any higher value to decrease the amount of them or
			//to any lower to increase it
		}
		instance->current->y = SIZE / 2;
		instance->current->x = SIZE / 2;
	}
	return instance;
}
void setPositionToFREE(struct Game * game) {
	for (int8_t i = 0; i < SIZE; ++i) {
		for (int8_t j = 0; j < SIZE; ++j) {
			if (game->matrix[i][j] == FREE) {
				game->current->y = i;
				game->current->x = j;
			}
		}
	}
}
uint8_t isFree(struct Game* game) {
	for (int8_t i = 0; i < SIZE; ++i) {
		for (int8_t j = 0; j < SIZE; ++j) {
			if (game->matrix[i][j] == FREE) {
				return 1;
			}
		}
	}
	return 0;
}
