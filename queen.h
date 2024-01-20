#pragma once
#include "rook.h"
#include "bishop.h"

bitboard_t get_queen_attacks(
	position_e pos, 
	bitboard_t rook_masks[],
	bitboard_t rook_attacks[][power_set(12)], 
	bitboard_t bishop_masks[], 
	bitboard_t bishop_attacks[][power_set(9)], 
	bitboard_t occupancy);