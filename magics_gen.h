#pragma once
#include "bitboard.h"
extern const bitboard_t pawn_magics[64];
extern const bitboard_t knight_magics[64];
extern const bitboard_t king_magics[64];

extern const bitboard_t rook_magics[64];
extern const bitboard_t bishop_magics[64];
extern const bitboard_t queen_magics[64];



void gen_pawn_magics();