#pragma once
#include "bitboard.h"
#define MAX_PERM_SIZE 1 << 10
typedef bitboard_t rook_attack_t[64][MAX_PERM_SIZE];
/*
*  maps position on board to a bitboard that contains all the possible blockers for rook.
*/
extern const int rook_occupancy_bits[64];

/*
*  magic numbers for rook.
*/
extern const bitboard_t rook_magics[64];

/*
*  rooks attacks
*/
bitboard_t rook_attacks_t[64][4096];

/*
*  rooks masks
*/
bitboard_t rook_masks[64];

bitboard_t get_rook_mask(position_e pos);
