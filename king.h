#pragma once
#include "bitboard.h"

extern inline bitboard_t king_north(bitboard_t bitboard);
extern inline bitboard_t king_south(bitboard_t bitboard);
extern inline bitboard_t king_west(bitboard_t bitboard);
extern inline bitboard_t king_east(bitboard_t bitboard);
extern inline bitboard_t king_north_west(bitboard_t bitboard);
extern inline bitboard_t king_north_east(bitboard_t bitboard);
extern inline bitboard_t king_south_west(bitboard_t bitboard);
extern inline bitboard_t king_south_east(bitboard_t bitboard);

bitboard_t mask_king_attacks(position_e pos);

void init_king_masks(bitboard_t king_masks[64]);