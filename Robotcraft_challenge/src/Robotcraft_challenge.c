/*
 ============================================================================
 Name        : Robotcraft_challenge.c
 Author      : Vladislav Holets
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdlib.h>
#include <time.h>

#include "Game/game.h"

int main(){

	srand(time(NULL));
	struct Game* game= initGameRobot();
	while(1){
		displayGame(game);
		readMoveRobot(game);

	}
}
