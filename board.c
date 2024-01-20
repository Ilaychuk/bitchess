#pragma once
#include "board.h"

const wchar_t wchess_bb_fmt[] = L"\n\n"
L"  +---+---+---+---+---+---+---+---+\n"
L"8 | %c | %c | %c | %c | %c | %c | %c | %c |\n"
L"  +---+---+---+---+---+---+---+---+\n"
L"7 | %c | %c | %c | %c | %c | %c | %c | %c |\n"
L"  +---+---+---+---+---+---+---+---+\n"
L"6 | %c | %c | %c | %c | %c | %c | %c | %c |\n"
L"  +---+---+---+---+---+---+---+---+\n"
L"5 | %c | %c | %c | %c | %c | %c | %c | %c |\n"
L"  +---+---+---+---+---+---+---+---+\n"
L"4 | %c | %c | %c | %c | %c | %c | %c | %c |\n"
L"  +---+---+---+---+---+---+---+---+\n"
L"3 | %c | %c | %c | %c | %c | %c | %c | %c |\n"
L"  +---+---+---+---+---+---+---+---+\n"
L"2 | %c | %c | %c | %c | %c | %c | %c | %c |\n"
L"  +---+---+---+---+---+---+---+---+\n"
L"1 | %c | %c | %c | %c | %c | %c | %c | %c |\n"
L"  +---+---+---+---+---+---+---+---+\n"
L"    a   b   c   d   e   f   g   h"
L"\n\n";


extern const board_t opening_positions = {

	[WHITE] = {

		  [PAWN] = 0b0000000011111111000000000000000000000000000000000000000000000000,
		  [ROOK] = 0b1000000100000000000000000000000000000000000000000000000000000000,
		  [BISHOP] = 0b0010010000000000000000000000000000000000000000000000000000000000,
		  [KNIGHT] = 0b0001000000000000000000000000000000000000000000000000000000000000,
		  [QUEEN] = 0b0000100000000000000000000000000000000000000000000000000000000000,
		  [KING] = 0b0001000000000000000000000000000000000000000000000000000000000000
	},

	[BLACK] = {

		 [PAWN] = 0b0000000000000000000000000000000000000000000000001111111100000000,
		 [ROOK] = 0b0000000000000000000000000000000000000000000000000000000010000001,
		 [BISHOP] = 0b0000000000000000000000000000000000000000000000000000000000100100,
		 [KNIGHT] = 0b0000000000000000000000000000000000000000000000000000000001000010,
		 [QUEEN] = 0b0000000000000000000000000000000000000000000000000000000000001000,
		 [KING] = 0b0000000000000000000000000000000000000000000000000000000000010000,
	}
};

extern const symbol_t symbols[6] = {
   [PAWN] = 'P',
   [ROOK] = 'R',
   [BISHOP] = 'B',
   [KNIGHT] = 'N',
   [QUEEN] = 'Q',
   [KING] = 'K',
};

/*
♜♞♝♛♚♝♞♜
♟♟♟♟♟♟♟♟
♙♙♙♙♙♙♙♙
♖♘♗♕♔♗♘♖
*/
extern const wchar_t fancy_symbols[2][6] = {

	[WHITE] = {
	   [PAWN] = '♟',
	   [ROOK] = '♜',
	   [BISHOP] = '♝',
	   [KNIGHT] = '♞',
	   [QUEEN] = '♛',
	   [KING] = '♚',
	},

	[BLACK] = {
		[PAWN] = '♙',
		[ROOK] = '♖',
		[BISHOP] = '♗',
		[KNIGHT] = '♘',
		[QUEEN] = '♕',
		[KING] = '♔'
    }

};

/*
*  returns the right symbol of the piece.
*/
symbol_t get_symbol(piece_e piece, color_e color)
{
	return (color == WHITE) ? symbols[piece] : chr_tolower(symbols[piece]);
}

void clear_board(board_t* board)
{
	memset(board, 0, sizeof(board_t));
}

void init_board(board_t* board)
{
	memcpy(board, opening_positions, sizeof(board_t));
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

void stringify_board(const wchar_t* stringified_board, size_t size, board_t* board)
{
	wchar_t unicode_pieces[64];
	memset(unicode_pieces, ' ', sizeof(unicode_pieces));
	for (color_e color = WHITE; color < NUM_COLORS; color++) {

		for (piece_e piece = PAWN; piece < NUM_PIECES; piece++) 	
		{
			bitboard_t bitboard = board[color][piece];
			wchar_t unicode_piece = fancy_symbols[color][piece];

			while (bitboard) {
				position_e pos = get_first_bit(bitboard);
				assert(pos >= a8 && pos < no_sq);

				unicode_pieces[pos] = unicode_piece;
				clear_bit(&bitboard, pos);

			}
		}
	}

	swprintf(
		stringified_board,
		size,
		wchess_bb_fmt,
		unicode_pieces[a8], unicode_pieces[b8], unicode_pieces[c8], unicode_pieces[d8], unicode_pieces[e8], unicode_pieces[f8], unicode_pieces[g8], unicode_pieces[h8],
		unicode_pieces[a7], unicode_pieces[b7], unicode_pieces[c7], unicode_pieces[d7], unicode_pieces[e7], unicode_pieces[f7], unicode_pieces[g7], unicode_pieces[h7],
		unicode_pieces[a6], unicode_pieces[b6], unicode_pieces[c6], unicode_pieces[d6], unicode_pieces[e6], unicode_pieces[f6], unicode_pieces[g6], unicode_pieces[h6],
		unicode_pieces[a5], unicode_pieces[b5], unicode_pieces[c5], unicode_pieces[d5], unicode_pieces[e5], unicode_pieces[f5], unicode_pieces[g5], unicode_pieces[h5],
		unicode_pieces[a4], unicode_pieces[b4], unicode_pieces[c4], unicode_pieces[d4], unicode_pieces[e4], unicode_pieces[f4], unicode_pieces[g4], unicode_pieces[h4],
		unicode_pieces[a3], unicode_pieces[b3], unicode_pieces[c3], unicode_pieces[d3], unicode_pieces[e3], unicode_pieces[f3], unicode_pieces[g3], unicode_pieces[h3],
		unicode_pieces[a2], unicode_pieces[b2], unicode_pieces[c2], unicode_pieces[d2], unicode_pieces[e2], unicode_pieces[f2], unicode_pieces[g2], unicode_pieces[h2],
		unicode_pieces[a1], unicode_pieces[b1], unicode_pieces[c1], unicode_pieces[d1], unicode_pieces[e1], unicode_pieces[f1], unicode_pieces[g1], unicode_pieces[h1]
	);
}