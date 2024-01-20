#pragma once
#include "bitboard.h"
#define MAX_PERM_SIZE 1 << 10
/*
*  maps position on board to a bitboard that contains all the possible blockers for rook.
*/

extern const int rook_occupancy_bits[64];

/*
*  magic numbers for rook.
*/
extern const bitboard_t rook_magics[64];

bitboard_t mask_rook_attacks(position_e pos);

bitboard_t rook_attacks_over_blockers(position_e pos, bitboard_t blockers);

void init_rook_masks(bitboard_t rook_masks[]);

void init_rook_attacks(bitboard_t rook_masks[], bitboard_t rook_attacks[64][power_set(12)]);

bitboard_t get_rook_attacks(position_e pos, bitboard_t rook_masks[], bitboard_t occupancy, bitboard_t rook_attacks[][power_set(12)]);