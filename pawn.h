#pragma once
#include "bitboard.h"
#include "board.h"

extern inline bitboard_t pawn_north(bitboard_t bitboard, size_t steps);
extern inline bitboard_t pawn_south(bitboard_t bitboard, size_t steps);
extern inline bitboard_t pawn_north_east(bitboard_t bitboard);
extern inline bitboard_t pawn_north_west(bitboard_t bitboard);
extern inline bitboard_t pawn_south_east(bitboard_t bitboard);
extern inline bitboard_t pawn_south_west(bitboard_t bitboard);

bitboard_t mask_pawn_attacks(position_e pos, color_e color);

void init_pawn_masks(bitboard_t pawn_masks[2][64]);
