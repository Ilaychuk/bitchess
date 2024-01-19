#include "knight.h"

inline bitboard_t north_north_east(bitboard_t bitboard)
{ 
	return  (bitboard_t)((bitboard << 17) & ((bitboard_t)(~files[AFILE])));
}

inline bitboard_t north_east_east(bitboard_t bitboard) 
{ 
	return (bitboard_t)((bitboard << 10) & ((bitboard_t)(~(files[AFILE] | files[BFILE]))));
}

inline bitboard_t south_east_east(bitboard_t bitboard) 
{ 
	return (bitboard_t)((bitboard >> 6) & ((bitboard_t)(~(files[AFILE] | files[BFILE]))));
}

inline bitboard_t south_south_east(bitboard_t bitboard) 
{
	return  (bitboard_t)((bitboard >> 15) & ((bitboard_t)(~files[AFILE])));
}

inline bitboard_t north_north_west(bitboard_t bitboard) 
{ 
	return  (bitboard_t)((bitboard << 15) & ((bitboard_t)(~files[HFILE])));
}

inline bitboard_t north_west_west(bitboard_t bitboard) 
{
	return (bitboard_t)((bitboard << 6) & ((bitboard_t)(~(files[GFILE] | files[HFILE]))));
}

inline bitboard_t south_west_west(bitboard_t bitboard)
{ 
	return (bitboard_t)((bitboard >> 10) & ((bitboard_t)(~(files[GFILE] | files[HFILE]))));
}

inline bitboard_t south_south_west(bitboard_t bitboard) 
{ 
	return  (bitboard_t)((bitboard >> 17) & ((bitboard_t)(~files[HFILE])));
}

bitboard_t get_knight_move(position_e pos)
{
	bitboard_t knight_bb, move_bb;
	knight_bb = 0;
	move_bb = 0;
	set_position(&knight_bb, pos);

	move_bb = 0
		| north_north_east(knight_bb)
		| north_east_east(knight_bb)
		| south_east_east(knight_bb)
		| south_south_east(knight_bb)
		| north_north_west(knight_bb)
		| north_west_west(knight_bb)
		| south_west_west(knight_bb)
		| south_south_west(knight_bb);

	return move_bb;
}