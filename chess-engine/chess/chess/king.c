#include "king.h"

extern inline bitboard_t north(bitboard_t bitboard)
{
	return (bitboard_t)((bitboard >> 8));
}

extern inline bitboard_t south(bitboard_t bitboard)
{
	return (bitboard_t)(bitboard << 8);
}

extern inline bitboard_t west(bitboard_t bitboard)
{
	return (bitboard_t)(bitboard >> 1) & (~files[HFILE]);
}

extern inline bitboard_t east(bitboard_t bitboard)
{
	return (bitboard_t)(bitboard << 1) & (~files[AFILE]);
}

extern inline bitboard_t north_west(bitboard_t bitboard)
{
	return (bitboard_t)((bitboard >> 9) & (~files[HFILE]));
}

extern inline bitboard_t north_east(bitboard_t bitboard)
{
	return (bitboard_t)((bitboard >> 7) & (~(files[AFILE])));
}

extern inline bitboard_t south_west(bitboard_t bitboard)
{
	return (bitboard_t)((bitboard << 7) & (~files[HFILE]));
}

extern inline bitboard_t south_east(bitboard_t bitboard)
{
	return (bitboard_t)((bitboard << 9) & (~files[AFILE]));
}

bitboard_t get_king_move(position_e pos)
{
	bitboard_t knight_bb, move_bb;
	knight_bb = 0;
	move_bb = 0;
	set_position(&knight_bb, pos);

	move_bb = 0
		| north(knight_bb)
		| south(knight_bb)
		| west(knight_bb)
		| east(knight_bb)
		| north_west(knight_bb)
		| north_east(knight_bb)
		| south_west(knight_bb)
		| south_east(knight_bb);
		
	return move_bb;
}