#pragma once
#include <assert.h>
#include <string.h>

#include "utils.h"
#include "bitboard.h"
#include "position.h"
/*
*  represents the color of the board.
*/
typedef enum {
	WHITE = 0,
	BLACK,
	NUM_COLORS
} color_e;

/*
*  represents a piece.
*/
typedef enum {
	PAWN = 0,
	ROOK,
	BISHOP,
	KNIGHT,
	QUEEN,
	KING,
	NUM_PIECES
} piece_e;

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
*  Game opening pieces.
*/
extern const board_t opening_positions;

/*
*  Pieces symbols
*/
extern const symbol_t symbols[6];

/*
*  places a piece on a board
*/
extern inline void place_piece(color_e color, piece_e piece, position_e pos, board_t* board);

/*
*  returns the bitboard representation of a given color.
*/
bitboard_t get_color_bitboard(board_t* board, color_e color);

/*
*  returns the b bitboard the full board
*/
bitboard_t get_full_bitboard(board_t* board);

/*
*  gets the board and clears it.
*/
void clear_board(board_t* board);

void init_board(board_t* board);

void stringify_board(const wchar_t* stringified_board, size_t size, board_t* board);