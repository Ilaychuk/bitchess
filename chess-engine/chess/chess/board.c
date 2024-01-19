#pragma once
#include "board.h"

/*
*  represents the symbols for each piece.
*/
const symbol_t symbols[] = {
   [PAWN] = 'P',
   [ROOK] = 'R',
   [BISHOP] = 'B',
   [KNIGHT] = 'N',
   [QUEEN] = 'Q',
   [KING] = 'K',
};

/*
*  returns the right symbol of the piece.
*/
symbol_t get_symbol(piece_e piece, color_e color)
{
	return 'p';
}

void clear_board(board_t* board)
{
	memset(board, 0, sizeof(board_t));
}

inline void place_piece(color_e color, piece_e piece, position_e pos, board_t* board)
{
	bitboard_t curr_bb = board[color][piece];
	set_position(& curr_bb, pos);
	
	*board[color][piece] = curr_bb;
}

bitboard_t get_color_bitboard(board_t* board, color_e color)
{
	bitboard_t full_bitboard = 0;
	for (piece_e piece = PAWN; piece < NUM_PIECES; piece++) {
		full_bitboard |= *(board[color][piece]);
	}

	return full_bitboard;
}

bitboard_t get_full_bitboard(board_t* board)
{
	bitboard_t full_bitboard = 0;
	for (color_e color = WHITE; color < NUM_COLORS; color++) {
		full_bitboard |= get_color_bitboard(board, color);
	}

	return full_bitboard;
}
