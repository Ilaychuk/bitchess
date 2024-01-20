#include "queen.h"

bitboard_t get_queen_attacks(
	position_e pos,
	bitboard_t rook_masks[],
	bitboard_t rook_attacks[][power_set(12)],
	bitboard_t bishop_masks[],
	bitboard_t bishop_attacks[][power_set(9)],
	bitboard_t occupancy)
{
	bitboard_t queen_attacks = 0
		| get_rook_attacks(pos, rook_masks, occupancy, rook_attacks)
		| get_bishop_attacks(pos, bishop_masks, occupancy, bishop_masks);

	return queen_attacks;
}