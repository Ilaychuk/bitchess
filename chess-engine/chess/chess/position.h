#pragma once
#include "bits.h"

/*
*  Represents a position on the board.
*  
*  Lets say that we take the integer 7 that represents all the black rooks locations.
*  7 in binary representation: 0b 1110000000000....0
*  If we arrange that number as an 8 * 8 matrix it would look like that:
* 
*    1 1 1 0 0 0 0 0
*    0 0 0 0 0 0 0 0
*    0 0 0 0 0 0 0 0
*    0 0 0 0 0 0 0 0
*    0 0 0 0 0 0 0 0
*    0 0 0 0 0 0 0 0
*    0 0 0 0 0 0 0 0
*    0 0 0 0 0 0 0 0
*    
*  so our chess board would look like that:
*      _______________
*    8 |R|R|R|#|_|#|_|#|
*    7 |#|_|#|_|#|_|#|_|
*    6 |_|#|_|#|_|#|_|#|
*    5 |#|_|#|_|#|_|#|_|
*    4 |_|#|_|#|_|#|_|#|
*    3 |#|_|#|_|#|_|#|_|
*    2 |_|#|_|#|_|#|_|#|
*    1 |#|_|#|_|#|_|#|_|
*       a b c d e f g h
* 
*  meaning that the first bit isnt a0 but a8, and thats why our enum starts from a8, b8, c8 and so on...
*/
typedef enum position_e {
    a8, b8, c8, d8, e8, f8, g8, h8,
    a7, b7, c7, d7, e7, f7, g7, h7,
    a6, b6, c6, d6, e6, f6, g6, h6,
    a5, b5, c5, d5, e5, f5, g5, h5,
    a4, b4, c4, d4, e4, f4, g4, h4,
    a3, b3, c3, d3, e3, f3, g3, h3,
    a2, b2, c2, d2, e2, f2, g2, h2,
    a1, b1, c1, d1, e1, f1, g1, h1, no_sq
} position_e;

typedef struct cordinate_t {
    uint32 row;
    uint32 col;
} cordinate_t;

void pos_to_cordinate(position_e pos, cordinate_t* cordinate);
/*
*  ascii positions.
*/
extern const char* squareToCoords[];
