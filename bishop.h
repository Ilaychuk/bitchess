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

bitboard_t mask_bishop_attacks(position_e pos);

bitboard_t bishop_attacks_over_blockers(position_e pos, bitboard_t blockers);

void init_bishop_masks(bitboard_t bishop_masks[]);

void init_bishop_attacks(bitboard_t bishop_masks[], bitboard_t bishop_attacks[64][power_set(9)]);

bitboard_t get_bishop_attacks(position_e pos, bitboard_t bishop_masks[], bitboard_t occupancy, bitboard_t bishop_attacks[][power_set(9)]);