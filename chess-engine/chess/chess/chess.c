#include "king.h"
#include "bishop.h"
#include "rook.h"

bitboard_t setOccupancy(int index, int bitsInMask, bitboard_t attackMask)
{
	bitboard_t occupancy = 0ULL;

	for (int count = 0; count < bitsInMask; count++)
	{
		int square = get_first_bit(attackMask);

		clear_bit(&attackMask, square);

		if (index & (1 << count))
			occupancy |= (1ULL << square);
	}

	return occupancy;
}
int main(){
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

	bitboard_t a = get_rook_move(d4);
	print_bitboard(get_rook_move(d4));
	printf("\n\n");
	print_bitboard(setOccupancy(d4, popcnt(a), a));
}







