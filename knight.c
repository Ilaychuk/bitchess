#include "knight.h"

inline bitboard_t knight_north_north_east(bitboard_t bitboard)
{ 
	return  (bitboard_t)((bitboard << 17) & ((bitboard_t)(~files[A_FILE])));
}

inline bitboard_t knight_north_east_east(bitboard_t bitboard) 
{ 
	return (bitboard_t)((bitboard << 10) & ((bitboard_t)(~(files[A_FILE] | files[B_FILE]))));
}

inline bitboard_t knight_south_east_east(bitboard_t bitboard) 
{ 
	return (bitboard_t)((bitboard >> 6) & ((bitboard_t)(~(files[A_FILE] | files[B_FILE]))));
}

inline bitboard_t knight_south_south_east(bitboard_t bitboard) 
{
	return  (bitboard_t)((bitboard >> 15) & ((bitboard_t)(~files[A_FILE])));
}

inline bitboard_t knight_north_north_west(bitboard_t bitboard) 
{ 
	return  (bitboard_t)((bitboard << 15) & ((bitboard_t)(~files[H_FILE])));
}

inline bitboard_t knight_north_west_west(bitboard_t bitboard) 
{
	return (bitboard_t)((bitboard << 6) & ((bitboard_t)(~(files[G_FILE] | files[H_FILE]))));
}

inline bitboard_t knight_south_west_west(bitboard_t bitboard)
{ 
	return (bitboard_t)((bitboard >> 10) & ((bitboard_t)(~(files[G_FILE] | files[H_FILE]))));
}

inline bitboard_t knight_south_south_west(bitboard_t bitboard) 
{ 
	return  (bitboard_t)((bitboard >> 17) & ((bitboard_t)(~files[H_FILE])));
}

bitboard_t mask_knight_attacks(position_e pos)
{
	bitboard_t knight_bb, move_bb;
	knight_bb = 0;
	move_bb = 0;
	set_position(&knight_bb, pos);

	move_bb = 0
		| knight_north_north_east(knight_bb)
		| knight_north_east_east(knight_bb)
		| knight_south_east_east(knight_bb)
		| knight_south_south_east(knight_bb)
		| knight_north_north_west(knight_bb)
		| knight_north_west_west(knight_bb)
		| knight_south_west_west(knight_bb)
		| knight_south_south_west(knight_bb);

	return move_bb;
}

void init_knight_masks(bitboard_t knight_attacks[64])
{
	for (position_e pos = a8; pos < no_sq; pos++) {
		knight_attacks[pos] = mask_knight_attacks(pos);
	}
}