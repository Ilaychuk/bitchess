#pragma once
#include <stdio.h>
#define byte unsigned char
#define uint32 unsigned int
#define uint64 unsigned long long 

/*
*  gets a number and an index and checks if bit is set at that index.
*/
#define bit_test(num, index) (num & ((uint64)1 << (index)))

/*
*  gets a number and returns it's lsb.
*/
#define get_lsb(num) (byte)(num & (uint64)1)

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
*  prints a number and formats it in binary representation
*/
void print_bits(uint64 num);
