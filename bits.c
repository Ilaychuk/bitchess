#include "bits.h"

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

uint64 get_first_bit(uint64 num)
{
	if (num)
		return popcnt((num & (-1 * num)) - 1);
	else
		return -1;
}

void print_bits(uint64 num)
{
	printf("num is: 0b");
	for (size_t i = 0; i < sizeof(bitboard_t); i++) {
		
		// prints the value as a char by adding the ascii value of '0'
		printf("%c", (char)((unsigned int)'0' + bit_test(num, i)));
	}
}