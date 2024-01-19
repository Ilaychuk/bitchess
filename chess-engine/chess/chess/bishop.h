#pragma once
#include "bitboard.h"

/*
*  maps position on board to a bitboard that contains all the possible blockers for bishops.
*/
extern const int bishop_occupancy_bits[64];

/*
*  magic numbers for bishop.
*/
extern const bitboard_t bishop_magics[64];

/*
*
*/
extern bitboard_t bishop_attacks[64][512];

/*
*
*/
extern bitboard_t bishop_masks[64];

extern inline bitboard_t get_bishop_move(position_e pos);
