#pragma once
#include "bits.h"
#include "position.h"

#include <assert.h>
#include <stdbool.h>

/*
*  Represents a bitboard.
* 
*  A chess board is an 8 * 8 board (64 squares). 
*  By that we can use a 64b integer to represent a location of a piece on the board.
*/
typedef uint64 bitboard_t;

/*
*  represents a permutation (subset) of the given mask.
*/
typedef uint64 permutation_t;

/*
*  square to file.
*/

/*
*  represents the bitmasks for a specific file(coloumn).
*  for ex, A_FILE = 0x808080... which in binary is: 10000000 10000000 10000000...
   these are the bits in the first file(coloumn) of the board.
*/
typedef enum file_e {
	A_FILE,
	B_FILE,
	C_FILE,
	D_FILE,
	E_FILE,
	F_FILE,
	G_FILE,
	H_FILE
} file_e;

extern const bitboard_t files[8];

/*
*  Represents bitmasks for specific rank(row).
*  for ex RANK1 = 0xff00000000000000 is in binary: 1111111100000....
*  which is exactly the first row of the board.
*/
typedef enum rank_e {
		RANK1,
		RANK2,
		RANK3,
		RANK4,
		RANK5,
		RANK6,
		RANK7,
		RANK8
} rank_e;

extern const bitboard_t ranks[8];

/*
*  represents the corners of the board.
*/
typedef enum corner_e {
	A8, 
	H8,
	A1,
	H1,
} corner_e;

extern const bitboard_t corners[8];

/*
*  represents a direction on a board.
* 
*  lest say that we have a king on d4, that kiong can go a step in every direction as marked.
*	 8 | |#| |#|_|#|_|#|
*    7 |#|_|#|_|#|_|#|_|
*    6 |_|#|_|#|_|#|_|#|
*    5 |#|_|1|1|1|_|#|_|
*    4 |_|#|1|K|1|#|_|#|
*    3 |#|_|1|1|1|_|#|_|
*    2 |_|#|_|#|_|#|_|#|
*    1 |#|_|#|_|#|_|#|_|
*       a b c d e f g h
* 
*  we can represnts its possible steps as a compass rose.
*  this can be useful for to determine which pieces are blockers on that direction.
*/
typedef enum direction_e {
	NORTH,
	SOUTH,
	EAST,
	WEST,
	NORTH_EAST,
	NORTH_WEST,
	SOUTH_EAST,
	SOUTH_WEST,
	DIRECTIONS_NUM,
	NOT_ON_BOUNDRY
} direction_e;
/*
*  returns the size of the powerset given.
*/
#define power_set(n) (permutation_t)((uint64)1 << n)

/*
*  this function gets a bitboard and a direction and checks if there are any bits on the booundries of the board in the given direction.
*/
bool boundry_check(bitboard_t bitboard, direction_e dir);

/*
*  Returns the direction of the boundry that the bit is set in. if the bit is not on the boundries, the function returns 'NOT_ON_BOUNDRY'
*/
direction_e boundries_lookup(bitboard_t bitboard);

/*
*  returns the number of squares from a position within a direction.
*/

/*
*  places a piece on bitboard
*/
extern inline void set_position(bitboard_t* bitboard, enum position_e pos);

/*
*  returns a permutation of the mask given
*/
permutation_t get_occupancy_permutation(size_t idx, bitboard_t mask, size_t mask_bitcnt);

/*
* returns a stringified buffer of the bitboard.
*/
void stringify_bitboard(bitboard_t bitboard, char* str_buffer, size_t size);

/*
*  prints a bitboard.
*/
void print_bitboard(bitboard_t bitboard);