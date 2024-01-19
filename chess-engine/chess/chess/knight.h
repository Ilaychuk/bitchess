#pragma once
#include "bitboard.h"

extern inline bitboard_t north_north_east(bitboard_t bitboard);
extern inline bitboard_t north_east_east(bitboard_t bitboard);
extern inline bitboard_t south_east_east(bitboard_t bitboard);
extern inline bitboard_t south_south_east(bitboard_t bitboard);
extern inline bitboard_t north_north_west(bitboard_t bitboard);
extern inline bitboard_t north_west_west(bitboard_t bitboard);
extern inline bitboard_t south_west_west(bitboard_t bitboard);
extern inline bitboard_t south_south_west(bitboard_t bitboard);

bitboard_t get_knight_move(position_e pos);