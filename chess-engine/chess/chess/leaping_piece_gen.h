#pragma once
#include "bitboard.h"
#include "position.h"
#include "board.h"

// TODO:
// finish generations of all leaping pieces attacks.
// learn hashing shit
// start the implementation of the move generations.  
/*
* represents the attcks sets for each leaping piece.
*/
typedef struct leaping_pieces_attacks_t {
	bitboard_t pwn_attcks[2][64];
	bitboard_t knight_attacks[64];
	bitboard_t king_attacks[64];
} leaping_pieces_attacks_t;

/*
*  returns pawn attack given its color and position on board
*/
bitboard_t get_pawn_attack(position_e pos, color_e color);

/*
*  returns a knight attack given its position on board.
*/

/*
*  returns a king attack given its position on board.
* 
*  A king can move one square horizontally, vertically, 
*  and diagonally"
*  
*  in order to generate all of the king's attacks for each position we should use the following bit-tricks:
*  1.) step up: shl 8
*  2.) step down: shr 8
*  3.) step right: shr 1
*  4.) step left: shl 1
*  
*  In addition we need to check for the edge of the board.
*  In case that the king is at the edge of the board( 0ne of the 4) we wont be able to move in the direction of that edge.
*  we can check that by masking 
*/

/*
*  inits the attack sets for each leaping piece and square using the 'get_*_attack' methods.
*/
void init_attacks(leaping_pieces_attacks_t* attack_sets);

bitboard_t gen_knight_attacks(const bitboard_t occupancy_bitboard, const position_e pos);

bitboard_t gen_pawn_attacks(const bitboard_t occupancy_bitboard, const position_e pos);

bitboard_t gen_king_attacks(const bitboard_t occupancy_bitboard, const position_e pos);