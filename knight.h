#pragma once
#include "bitboard.h"

extern inline bitboard_t knight_north_north_east(bitboard_t bitboard);
extern inline bitboard_t knight_north_east_east(bitboard_t bitboard);
extern inline bitboard_t knight_south_east_east(bitboard_t bitboard);
extern inline bitboard_t knight_south_south_east(bitboard_t bitboard);
extern inline bitboard_t knight_north_north_west(bitboard_t bitboard);
extern inline bitboard_t knight_north_west_west(bitboard_t bitboard);
extern inline bitboard_t knight_south_west_west(bitboard_t bitboard);
extern inline bitboard_t knight_south_south_west(bitboard_t bitboard);

bitboard_t mask_knight_attacks(position_e pos);

void init_knight_masks(bitboard_t knight_attacks[64]);

