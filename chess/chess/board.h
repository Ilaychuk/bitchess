#pragma once
#include "bitboard.h"
#include "position.h"

/*
*  represents the color of the board.
*/
typedef enum {
	WHITE = 0,
	BLACK,
	NUM_COLORS
} color_t;

/*
*  represents a piece.
*/
typedef enum {
	PAWN = 0,
	ROOK,
	KNIGHT,
	BISHOP,
	QUEEN,
	KING,
	NUM_PIECES
} piece_t;

/*
*  represents a symbol.
*/
typedef char symbol_t;

/*
*  represents a stringified schess board.
*/
typedef symbol_t str_board_t[8][8];


/*
*  represents a full board with all bitboards.
*/
typedef bitboard_t board_t[NUM_COLORS][NUM_PIECES];

/*
*  returns the right symbol of the piece.
*/

/*
*  returns the bitboard representation of a given color.
*/
bitboard_t get_color_bitboard(board_t* board, color_t color);

/*
*  returns the b bitboard the full board
*/
bitboard_t get_full_bitboard(board_t* board);

/*
*  gets the board and clears it.
*/
void clear_board(board_t* board);

/*
*  returns the stringified version of the board
*/
void fill_str_piece(bitboard_t board, str_board_t* str_board, piece_t piece, color_t color);

void fill_str_board(board_t board, str_board_t* str_board);

/*
*  prints the full board.
*/
