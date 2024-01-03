#pragma once
#include "position.h"

/*
*  represents a move on the board
*/
typedef struct {
	position_t src;
	position_t dst;
	byte promotion;
} move_t;




