#include <windows.h>

#include "king.h"
#include "bishop.h"
#include "rook.h"
#include "knight.h"
#include "pawn.h"


bitboard_t knight_masks[64];
bitboard_t king_masks[64];
bitboard_t pawn_masks[2][64];
bitboard_t rook_masks[64];
bitboard_t bishop_masks[64];

bitboard_t rook_attacks[64][4096];
bitboard_t bishop_attacks[64][512];

int main()
{
	/*
	*
	*8 |R|R|R|#|_|#|_|#|
*    7 |#|_|#|_|#|_|#|_|
*    6 |_|#|_|#|_|#|_|#|
*    5 |#|_|#|_|#|_|#|_|
*    4 |_|#|_|#|_|#|_|#|
*    3 |#|_|#|_|#|_|#|_|
*    2 |_|#|_|#|_|#|_|#|
*    1 |#|_|#|_|#|_|#|_|
*       a b c d e f g h
	*/

	init_king_masks(king_masks);
	init_knight_masks(knight_masks);
	init_pawn_masks(pawn_masks);

	init_bishop_masks(bishop_attacks);
	init_bishop_attacks(bishop_attacks, bishop_attacks);

	init_rook_masks(bishop_attacks);
	init_rook_attacks(bishop_attacks, bishop_attacks);

	board_t board = { 0 };
	init_board(&board);
	wchar_t buff[3000] = { 0x20 };

	stringify_board(buff, 3000, &board);
	const HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD n_chars_written = 0;
	WriteConsoleW(output, buff, 300, &n_chars_written, 0);
}