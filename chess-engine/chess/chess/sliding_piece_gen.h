#pragma once
#include "bitboard.h"
#include "bitboard.h"
#include "position.h"
#include "hash.h"

/*
*  maps position on board to a bitboard that contains all the possible blockers for bishops.
*/
extern const int bishop_occupancy_bits[64];

/*
*  magic numbers for bishop.
*/
extern const bitboard_t bishop_magics[64];

/*
*
*/
extern bitboard_t bishop_attacks[64][512];

/*
*
*/
extern bitboard_t bishop_masks[64];

/*
*  maps position on board to a bitboard that contains all the possible blockers for rook.
*/
extern const int rook_occupancy_bits[64];

/*
*  magic numbers for rook.
*/
extern const bitboard_t rook_magics[64];

/*
*  rooks attacks
*/
bitboard_t rook_attacks[64][4096];

/*
*  rooks masks
*/
bitboard_t rook_masks[64];



bitboard_t gen_rook_attacks(const bitboard_t full_bitboard, const position_e pos);

bitboard_t gen_bishop_attacks(const bitboard_t full_bitboard, const position_e pos);

bitboard_t gen_queen_attacks(const bitboard_t full_bitboard, const position_e pos);