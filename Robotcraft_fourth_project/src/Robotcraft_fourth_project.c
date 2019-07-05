/*
 ============================================================================
 Name        : Robotcraft_fourth_project.c
 Author      : Vladislav Holets
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <conio.h>

//STATES OF THE CELLS
#define FREE 0
#define NOLL 1
#define CROSS 2
#define CURRENT 3

//CONTROLS
#define THIS 53

#define LEFT 52
#define RIGHT 54
#define UP 56
#define DOWN 50

#define EXIT 48
//SIZE OF ARRAY
#define SIZE 3

//PLAYERS
#define FIRST 0
#define SECOND 1

//END
#define NOT_END 10
struct Game {
	uint8_t matrix[SIZE][SIZE];
	int8_t current_i, current_j;
	uint8_t player;
};

void displayTurns();
void displayGame(struct Game * game);
struct Game * initGameTicTacToe();
struct Game * initGameRobot();
void readMoveRobot(struct Game * game);
void readMoveTicTacToe(struct Game * game);
void setPositionToFREE(struct Game * game);
uint8_t isEnd(struct Game *game);
void suggestTryAgain();
uint8_t isFree(struct Game* game);
uint8_t endFlag = 0;
int main(void) {
	struct Game * game;
	while (1) {
		game = initGameTicTacToe();
		while (endFlag == 0) {
			displayGame(game);
			readMoveTicTacToe(game);
		}
		free(game);
		endFlag = 0;
	}
	return EXIT_SUCCESS;
}
void displayTurns() {

}
void displayGame(struct Game * game) {
	system("CLS");
	printf("\n");
	if (game->matrix[game->current_i][game->current_j] != FREE) {
		setPositionToFREE(game);
	}
	for (int8_t i = 0; i < SIZE; ++i) {
		for (int8_t j = 0; j < SIZE; ++j) {
			printf("|");
			if (game->current_i == i && game->current_j == j) {
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
//			case CURRENT: {
//				printf("#");
//				break;
//			}
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
	//printf("%d",number);
	fflush(stdout);
	if (game->matrix[game->current_i][game->current_j] != FREE) {
		setPositionToFREE(game);
	}
//	if (number == THIS) {
//		if (game->matrix[game->current_i][game->current_j] == FREE) {
//			game->matrix[game->current_i][game->current_j] =
//					(game->player == FIRST) ? NOLL : CROSS;
//			if(game->player == FIRST){
//				game->player = SECOND;
//			}else if(game->player == SECOND){
//				game->player = FIRST;
//			}
//		}
//	} else

	if (number == LEFT) {
		if (game->current_j
				>= 1&& game->matrix[game->current_i][game->current_j-1]==FREE) {
			game->current_j--;
			//printf("[%d][%d]\n", game->current_i, game->current_j);
		}
	} else if (number == RIGHT) {
		if (game->current_j
				< (SIZE - 1)&& game->matrix[game->current_i][game->current_j+1]==FREE) {
			game->current_j++;
			//printf("[%d][%d]\n", game->current_i, game->current_j);
		}
	} else if (number == UP) {
		if (game->current_i
				>= 1&& game->matrix[game->current_i-1][game->current_j]==FREE) {
			game->current_i--;
			//printf("[%d][%d]\n", game->current_i, game->current_j);
		}
	} else if (number == DOWN) {
		if (game->current_i
				< (SIZE - 1)&& game->matrix[game->current_i+1][game->current_j]==FREE) {
			game->current_i++;
			//printf("[%d][%d]\n", game->current_i, game->current_j);
		}
	} else if (number == EXIT) {
		exit(0);
	}
//	if (isEnd(game) != NOT_END && isEnd(game) != FREE) {
//		printf("The winner is ");
//		if (isEnd(game) == NOLL)
//			printf("first player");
//		else if (isEnd(game) == CROSS)
//			printf("second player");
//		endFlag=1;
//	} else if (!isFree(game)) {
//		printf("There is no winner");
//		endFlag=1;
//	}
}
void readMoveTicTacToe(struct Game * game) {
	uint8_t number;
	fflush(stdout);
	fflush(stdin);
	number = getch();
	//printf("%d", number);
	fflush(stdout);
	if (game->matrix[game->current_i][game->current_j] != FREE) {
		setPositionToFREE(game);
	}
	if (number == THIS) {
		if (game->matrix[game->current_i][game->current_j] == FREE) {
			game->matrix[game->current_i][game->current_j] =
					(game->player == FIRST) ? NOLL : CROSS;
			if (game->player == FIRST) {
				game->player = SECOND;
			} else if (game->player == SECOND) {
				game->player = FIRST;
			}
		}
	} else

	if (number == LEFT) {
		if (game->current_j >= 1) {
			game->current_j--;
			//printf("[%d][%d]\n", game->current_i, game->current_j);
		}
	} else if (number == RIGHT) {
		if (game->current_j < (SIZE - 1)) {
			game->current_j++;
			//printf("[%d][%d]\n", game->current_i, game->current_j);
		}
	} else if (number == UP) {
		if (game->current_i >= 1) {
			game->current_i--;
			//printf("[%d][%d]\n", game->current_i, game->current_j);
		}
	} else if (number == DOWN) {
		if (game->current_i < (SIZE - 1)) {
			game->current_i++;
			//printf("[%d][%d]\n", game->current_i, game->current_j);
		}
	} else if (number == EXIT) {
		exit(0);
	}
	if (isEnd(game) != NOT_END && isEnd(game) != FREE) {
		printf("The winner is ");
		if (isEnd(game) == NOLL)
			printf("first player");
		else if (isEnd(game) == CROSS)
			printf("second player");
		getch();
		endFlag = 1;
	} else if (!isFree(game)) {
		printf("There is no winner");
		getch();
		endFlag = 1;
	}
}
struct Game * initGameTicTacToe() {
	struct Game * instance = malloc(sizeof(struct Game));
	for (int8_t i = 0; i < SIZE; ++i) {
		for (int8_t j = 0; j < SIZE; ++j) {
			instance->matrix[i][j] = FREE;
		}
		instance->current_i = SIZE / 2;
		instance->current_j = SIZE / 2;
		instance->player = FIRST;
	}
	return instance;
}
struct Game * initGameRobot() {
	struct Game * instance = malloc(sizeof(struct Game));
	for (int8_t i = 0; i < SIZE; ++i) {
		for (int8_t j = 0; j < SIZE; ++j) {
			instance->matrix[i][j] = (rand() % 2) ? FREE : CROSS;
		}
		instance->current_i = SIZE / 2;
		instance->current_j = SIZE / 2;
		instance->player = FIRST;
	}
	return instance;
}
void setPositionToFREE(struct Game * game) {
	for (int8_t i = 0; i < SIZE; ++i) {
		for (int8_t j = 0; j < SIZE; ++j) {
			if (game->matrix[i][j] == FREE) {
				game->current_i = i;
				game->current_j = j;
			}
		}
	}
}
uint8_t isEnd(struct Game *game) {
	for (int8_t i = 0; i < SIZE; ++i) {
		if (game->matrix[i][0]
				== game->matrix[i][1] && game->matrix[i][0] == game->matrix[i][2] && game->matrix[i][0] != FREE) {
			return game->matrix[i][0];
		}
	}
	for (int8_t j = 0; j < SIZE; ++j) {
		if (game->matrix[0][j]
				== game->matrix[1][j] && game->matrix[0][j] == game->matrix[2][j]&& game->matrix[0][j] != FREE) {
			return game->matrix[0][j];
		}
	}

	if (game->matrix[0][0]
			== game->matrix[1][1] && game->matrix[0][0] == game->matrix[2][2] && game->matrix[0][0] != FREE) {
		return game->matrix[0][0];
	}
	if (game->matrix[2][0]
			== game->matrix[1][1] && game->matrix[2][0] == game->matrix[0][2] && game->matrix[2][0] != FREE) {
		return game->matrix[2][0];
	}
	return NOT_END;
}

void suggestTryAgain() {

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
