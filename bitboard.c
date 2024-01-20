#include "bitboard.h"
const char chess_bb_fmt[] = "\n\n"
"  +---+---+---+---+---+---+---+---+\n"
"8 | %c | %c | %c | %c | %c | %c | %c | %c |\n"
"  +---+---+---+---+---+---+---+---+\n"
"7 | %c | %c | %c | %c | %c | %c | %c | %c |\n"
"  +---+---+---+---+---+---+---+---+\n"
"6 | %c | %c | %c | %c | %c | %c | %c | %c |\n"
"  +---+---+---+---+---+---+---+---+\n"
"5 | %c | %c | %c | %c | %c | %c | %c | %c |\n"
"  +---+---+---+---+---+---+---+---+\n"
"4 | %c | %c | %c | %c | %c | %c | %c | %c |\n"
"  +---+---+---+---+---+---+---+---+\n"
"3 | %c | %c | %c | %c | %c | %c | %c | %c |\n"
"  +---+---+---+---+---+---+---+---+\n"
"2 | %c | %c | %c | %c | %c | %c | %c | %c |\n"
"  +---+---+---+---+---+---+---+---+\n"
"1 | %c | %c | %c | %c | %c | %c | %c | %c |\n"
"  +---+---+---+---+---+---+---+---+\n"
"    a   b   c   d   e   f   g   h"
"\n\n";


extern const bitboard_t ranks[8] = {
	[RANK1] = 0xff00000000000000,
	[RANK2] = 0x00ff000000000000,
	[RANK3] = 0x0000ff0000000000,
	[RANK4] = 0x000000ff00000000,
	[RANK5] = 0x00000000ff000000,
	[RANK6] = 0x0000000000ff0000,
	[RANK7] = 0x000000000000ff00,
	[RANK8] = 0x00000000000000ff
};

extern const bitboard_t files[8] = {
	[H_FILE] = 0x8080808080808080,
	[G_FILE] = 0x4040404040404040,
	[F_FILE] = 0x2020202020202020,
	[E_FILE] = 0x1010101010101010,
	[D_FILE] = 0x0808080808080808,
	[C_FILE] = 0x0404040404040404,
	[B_FILE] = 0x0202020202020202,
	[A_FILE] = 0x0101010101010101
};

extern const bitboard_t corners[8] = {
	[A8] = (uint64)1 << 0,
	[H8] = (uint64)1 << 7,
	[A1] = (uint64)1 << 56,
	[H1] = (uint64)1 << 63
};

inline void set_position(bitboard_t* bitboard, position_e pos)
{
	assert(bit_test(*bitboard, pos) == 0);
	set_bit(bitboard, pos);
}

bool boundry_check(bitboard_t bitboard, direction_e dir)
{
	switch (dir) {
		case NORTH:
			bitboard &= ranks[RANK8];
			break;

		case SOUTH:
			bitboard &= ranks[RANK1];
			break;

		case WEST:
			bitboard &= files[H_FILE];
			break;

		case EAST:
			bitboard &= files[A_FILE];
			break;

		case NORTH_WEST:
			bitboard &= corners[A8];
			break;

		case NORTH_EAST:
			bitboard &= corners[H8];
			break;

		case SOUTH_WEST:
			bitboard &= corners[A1];
			break;

		case SOUTH_EAST:
			bitboard &= corners[H1];
			break;

		default:
			assert(false);
			break;
	}

	return (bool)(bitboard);
}

uint32 get_boundry_distance(position_e pos, direction_e dir)
{
	uint32 distance = 0;
	cordinate_t cord;
	pos_to_cordinate(pos, &cord);
	assert(cord.col <= 8 && cord.row <= 8);
	switch (dir)
	{
	case NORTH:
		distance = 8 - cord.col;
		break;

	case SOUTH:
		distance = cord.col;
		break;
	
	case EAST:
		distance = cord.col;
		break;

	case WEST:
		distance = 8 - cord.col;
		break;

	default:
		break;
	}

	return distance;
}

direction_e boundries_lookup(bitboard_t bitboard) {
	// starting from the corners, cause a corner is in fact 2 directions.
	for (direction_e dir = DIRECTIONS_NUM - 1; dir >= NORTH; dir--) {
		if (boundry_check(bitboard, dir))
			return dir;
	}

	return NOT_ON_BOUNDRY;
}

permutation_t get_occupancy_permutation(size_t idx, bitboard_t mask, size_t mask_bitcnt)
{
	permutation_t p = 0;
	size_t set_bits_size = popcnt(mask);

	for (size_t i = 0; i < set_bits_size; i++) {

		size_t bit_idx = 0;
		bit_idx = get_first_bit(mask);

		if (idx & ((uint64)1 << i)) {
			set_bit(&p, bit_idx);
		}

		clear_bit(&mask, bit_idx);
	}

	return p;
}

void stringify_bitboard(bitboard_t bitboard, char* str_buffer, size_t size)
{
	// chess_bb_fmt contains 64 * '%c' wich will be replaced with 1/0. extra 64 chars...
	assert(size > sizeof(chess_bb_fmt) - 64 * sizeof('%'));

	char bits[64] = { 0 };
	char bit = 0;

	for (position_e pos = a8; pos < no_sq; pos++) {
		bit = bit_to_char(bit_test(bitboard, pos));
		bits[pos] = bit;
	}

	sprintf_s(
		str_buffer,
		size,
		chess_bb_fmt,
		bits[a8], bits[b8], bits[c8], bits[d8], bits[e8], bits[f8], bits[g8], bits[h8],
		bits[a7], bits[b7], bits[c7], bits[d7], bits[e7], bits[f7], bits[g7], bits[h7],
		bits[a6], bits[b6], bits[c6], bits[d6], bits[e6], bits[f6], bits[g6], bits[h6],
		bits[a5], bits[b5], bits[c5], bits[d5], bits[e5], bits[f5], bits[g5], bits[h5],
		bits[a4], bits[b4], bits[c4], bits[d4], bits[e4], bits[f4], bits[g4], bits[h4],
		bits[a3], bits[b3], bits[c3], bits[d3], bits[e3], bits[f3], bits[g3], bits[h3],
		bits[a2], bits[b2], bits[c2], bits[d2], bits[e2], bits[f2], bits[g2], bits[h2],
		bits[a1], bits[b1], bits[c1], bits[d1], bits[e1], bits[f1], bits[g1], bits[h1]
	);
}

void print_bitboard(bitboard_t bitboard)
{
	char stringified_board[sizeof(chess_bb_fmt)] = { 0 };
	stringify_bitboard(bitboard, stringified_board, sizeof(stringified_board));

	printf(stringified_board);
}

