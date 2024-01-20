#pragma once
#include <stdio.h>

#include "types.h"
#include "bitboard.h"

/*
*  gets a bit and returns tha char of that bit
*/
#define bit_to_char(bit) (char)('0' + bit)
/*
*  gets a number and an index and checks if bit is set at that index.
*/
#define bit_test(num, index) (((num & ((uint64)1) << index) == 0) ? 0 : 1)

/*
*  gets a number and returns it's number of set bits.
*/
uint64 popcnt(uint64 num);

/*
*  gets a number and set the bit at index;
*/
void set_bit(uint64* num, uint32 index);

/*
*  gets a number and clears the bit at index
*/
void clear_bit(uint64* num, uint32 index);

/*
*  gets a numbe and an index and toggles the bit at that index
*/
void toggle_bit(uint64* num, uint32 index);

/*
*  gets a number and pops it's lsb
*/
byte clear_lsb(uint32* num);

/*
*  gets a number and pops its lsb and returns the index of it.
*/
uint64 get_first_bit(uint64 num);

/*
*  prints a number and formats it in binary representation
*/
void print_bits(uint64 num);
