#include "king.h"

extern inline bitboard_t king_north(bitboard_t bitboard)
{
	return (bitboard_t)((bitboard >> 8));
}

extern inline bitboard_t king_south(bitboard_t bitboard)
{
	return (bitboard_t)(bitboard << 8);
}

extern inline bitboard_t king_west(bitboard_t bitboard)
{
	return (bitboard_t)(bitboard >> 1) & (~files[H_FILE]);
}

extern inline bitboard_t king_east(bitboard_t bitboard)
{
	return (bitboard_t)(bitboard << 1) & (~files[A_FILE]);
}

extern inline bitboard_t king_north_west(bitboard_t bitboard)
{
	return (bitboard_t)((bitboard >> 9) & (~files[H_FILE]));
}

extern inline bitboard_t king_north_east(bitboard_t bitboard)
{
	return (bitboard_t)((bitboard >> 7) & (~(files[A_FILE])));
}

extern inline bitboard_t king_south_west(bitboard_t bitboard)
{
	return (bitboard_t)((bitboard << 7) & (~files[H_FILE]));
}

extern inline bitboard_t king_south_east(bitboard_t bitboard)
{
	return (bitboard_t)((bitboard << 9) & (~files[A_FILE]));
}

bitboard_t mask_king_attacks(position_e pos)
{
	bitboard_t knight_bb, move_bb;
	knight_bb = 0;
	move_bb = 0;
	set_position(&knight_bb, pos);

	move_bb = 0
		| king_north(knight_bb)
		| king_south(knight_bb)
		| king_west(knight_bb)
		| king_east(knight_bb)
		| king_north_west(knight_bb)
		| king_north_east(knight_bb)
		| king_south_west(knight_bb)
		| king_south_east(knight_bb);
		
	return move_bb;
}

void init_king_masks(bitboard_t king_masks[64])
{
	for (position_e pos = a8; pos < no_sq; pos++) {
		king_masks[pos] = mask_king_attacks(pos);
	}
}