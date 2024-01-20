#pragma once
#include "position.h"

/*
*  represents a move on the board
*/
typedef struct {
	position_e src;
	position_e dst;
	byte promotion;
} move_t;




