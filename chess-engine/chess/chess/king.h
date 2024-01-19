#pragma once
#include "bitboard.h"

extern inline bitboard_t north(bitboard_t bitboard);
extern inline bitboard_t south(bitboard_t bitboard);
extern inline bitboard_t west(bitboard_t bitboard);
extern inline bitboard_t east(bitboard_t bitboard);
extern inline bitboard_t north_west(bitboard_t bitboard);
extern inline bitboard_t north_east(bitboard_t bitboard);
extern inline bitboard_t south_west(bitboard_t bitboard);
extern inline bitboard_t south_east(bitboard_t bitboard);

bitboard_t get_king_move(position_e pos);