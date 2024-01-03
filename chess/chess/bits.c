#include "bits.h"
#include "bitboard.h"


void set_bit(uint64* num, uint32 index)
{
	*num = (*num | ((uint64)1 << index));
}

void clear_bit(uint64* num, uint32 index)
{
	*num = (*num & (~((uint64)1 << index)));
}

void toggle_bit(uint64* num, uint32 index)
{
	*num = (*num ^ ((uint64)1 << index));
}

uint64 popcnt(uint64 num)
{
	uint64 count = 0;
	while (num) {
		num &= (num - 1);
		count++;
	}

	return count;
}

byte clear_lsb(uint32* num)
{
	byte lsb = get_lsb(*num);
	*num = (*num & (*num - 1));

	return lsb;
}

void print_bits(uint64 num)
{
	printf("num is: 0b");
	for (size_t i = 0; i < sizeof(bitboard_t); i++) {
		
		// prints the value as a char by adding the ascii value of '0'
		printf("%c", (char)((unsigned int)'0' + bit_test(num, i)));
	}
}