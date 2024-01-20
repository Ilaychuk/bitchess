#include "pawn.h"

extern inline bitboard_t pawn_north(bitboard_t bitboard, size_t stepos)
{
	return (bitboard_t)((bitboard >> 8 * stepos));
}

extern inline bitboard_t pawn_south(bitboard_t bitboard, size_t steps)
{
	return (bitboard_t)(bitboard << 8 * steps);
}

extern inline bitboard_t pawn_west(bitboard_t bitboard)
{
	return (bitboard_t)(bitboard >> 1) & (~files[H_FILE]);
}

extern inline bitboard_t pawn_east(bitboard_t bitboard)
{
	return (bitboard_t)(bitboard << 1) & (~files[A_FILE]);
}

extern inline bitboard_t pawn_north_west(bitboard_t bitboard)
{
	return (bitboard_t)((bitboard >> 9) & (~files[H_FILE]));
}

extern inline bitboard_t pawn_north_east(bitboard_t bitboard)
{
	return (bitboard_t)((bitboard >> 7) & (~(files[A_FILE])));
}

extern inline bitboard_t pawn_south_west(bitboard_t bitboard)
{
	return (bitboard_t)((bitboard << 7) & (~files[H_FILE]));
}

extern inline bitboard_t pawn_south_east(bitboard_t bitboard)
{
	return (bitboard_t)((bitboard << 9) & (~files[A_FILE]));

}

bitboard_t mask_pawn_attacks(position_e pos, color_e color)
{
    bitboard_t pawn_bb, move_bb;
    pawn_bb = 0;
    move_bb = 0;
    set_position(&pawn_bb, pos);

    if (color == WHITE) {
		move_bb = 0
			| pawn_north_east(pawn_bb)
			| pawn_north_east(pawn_bb);
    }

	if (color == BLACK) {
		move_bb = 0
			| pawn_south_east(pawn_bb)
			| pawn_south_east(pawn_bb);
	}

    return move_bb;
}


void init_pawn_masks(bitboard_t pawn_masks[2][64])
{
	for (color_e color = WHITE; color < NUM_COLORS; color++) {

		for (size_t pos = a8; pos < no_sq; pos++) {
			pawn_masks[color][pos] = mask_pawn_attacks(pos, color);
		}
	}
}