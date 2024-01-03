#pragma once
#include "board.h"
#include "position.h"

#include <string.h>

/*
*  represents the symbols for each piece.
*/
const symbol_t symbols[] = {
	/* SYM_PAWN */ 'P',
	/* SYM_ROOK */ 'R',
	/* SYM_BISHOP */ 'B',
	/* SYM_KNIGHT */ 'N',
	/* SYM_QUEEN */ 'Q',
	/* SYM_KING */ 'K',

};

/*
*  returns the right symbol of the piece.
*/
symbol_t get_symbol(piece_t piece, color_t color)
{
	return 'p';
}

void clear_board(board_t* board)
{
	memset(board, 0, sizeof(board_t));
}

bitboard_t get_color_bitboard(board_t* board, color_t color)
{
	bitboard_t full_bitboard = 0;
	for (piece_t piece = PAWN; piece < NUM_PIECES; piece++) {
		full_bitboard |= *(board[color][piece]);
	}

	return full_bitboard;
}

bitboard_t get_full_bitboard(board_t* board)
{
	bitboard_t full_bitboard = 0;
	for (color_t color = WHITE; color < NUM_COLORS; color++) {
		full_bitboard |= get_color_bitboard(board, color);
	}

	return full_bitboard;
}

void fill_str_piece(bitboard_t board, str_board_t* str_board, piece_t piece, color_t color)
{
	position_t p = 0;
	while (board) {

		if (board & 1) {
			cordinate_t cord = idx_to_cord(p);
			*str_board[cord.y][cord.y] = get_symbol(piece, color);
		}
		board >>= 1;
		
	}
}

void fill_str_board(board_t board, str_board_t* str_board)
{
	for (color_t color = WHITE; color < NUM_COLORS; color++) {

		for (piece_t piece = PAWN; piece < NUM_PIECES; piece++) {
			bitboard_t curr_board = board[color][piece];
			fill_str_piece(curr_board, str_board, piece, color);
		}
	}
}
