#include "rook.h"

extern const int rook_occupancy_bits[64] = {
	12, 11, 11, 11, 11, 11, 11, 12,
	11, 10, 10, 10, 10, 10, 10, 11,
	11, 10, 10, 10, 10, 10, 10, 11,
	11, 10, 10, 10, 10, 10, 10, 11,
	11, 10, 10, 10, 10, 10, 10, 11,
	11, 10, 10, 10, 10, 10, 10, 11,
	11, 10, 10, 10, 10, 10, 10, 11,
	12, 11, 11, 11, 11, 11, 11, 12
};

extern const bitboard_t rook_magics[64] = {
	0x8a80104000800020ULL,
	0x140002000100040ULL,
	0x2801880a0017001ULL,
	0x100081001000420ULL,
	0x200020010080420ULL,
	0x3001c0002010008ULL,
	0x8480008002000100ULL,
	0x2080088004402900ULL,
	0x800098204000ULL,
	0x2024401000200040ULL,
	0x100802000801000ULL,
	0x120800800801000ULL,
	0x208808088000400ULL,
	0x2802200800400ULL,
	0x2200800100020080ULL,
	0x801000060821100ULL,
	0x80044006422000ULL,
	0x100808020004000ULL,
	0x12108a0010204200ULL,
	0x140848010000802ULL,
	0x481828014002800ULL,
	0x8094004002004100ULL,
	0x4010040010010802ULL,
	0x20008806104ULL,
	0x100400080208000ULL,
	0x2040002120081000ULL,
	0x21200680100081ULL,
	0x20100080080080ULL,
	0x2000a00200410ULL,
	0x20080800400ULL,
	0x80088400100102ULL,
	0x80004600042881ULL,
	0x4040008040800020ULL,
	0x440003000200801ULL,
	0x4200011004500ULL,
	0x188020010100100ULL,
	0x14800401802800ULL,
	0x2080040080800200ULL,
	0x124080204001001ULL,
	0x200046502000484ULL,
	0x480400080088020ULL,
	0x1000422010034000ULL,
	0x30200100110040ULL,
	0x100021010009ULL,
	0x2002080100110004ULL,
	0x202008004008002ULL,
	0x20020004010100ULL,
	0x2048440040820001ULL,
	0x101002200408200ULL,
	0x40802000401080ULL,
	0x4008142004410100ULL,
	0x2060820c0120200ULL,
	0x1001004080100ULL,
	0x20c020080040080ULL,
	0x2935610830022400ULL,
	0x44440041009200ULL,
	0x280001040802101ULL,
	0x2100190040002085ULL,
	0x80c0084100102001ULL,
	0x4024081001000421ULL,
	0x20030a0244872ULL,
	0x12001008414402ULL,
	0x2006104900a0804ULL,
	0x1004081002402ULL
};

bitboard_t mask_rook_attacks(position_e pos)
{
	bitboard_t move_bb = 0;
	cordinate_t cord = { 0 };

	pos_to_cordinate(pos, &cord);
	int r, f;

	int tr = cord.row;
	int tf = cord.col;

	for (r = tr + 1; r <= 6; r++) { 
		move_bb |= ((uint64)1 << (r * 8 + tf));
	}

	for (r = tr - 1; r >= 1; r--) { 
		move_bb |= ((uint64)1 << (r * 8 + tf));
	}

	for (f = tf + 1; f <= 6; f++) { 
		move_bb |= ((uint64)1 << (tr * 8 + f));
	}

	for (f = tf - 1; f >= 1; f--) { 
		move_bb |= ((uint64)1 << (tr * 8 + f));
	}

	return move_bb;
}

bitboard_t rook_attacks_over_blockers(position_e pos, bitboard_t blockers)
{
	bitboard_t move_bb = 0;
	cordinate_t cord;
	pos_to_cordinate(pos, &cord);
	int r, f;

	int tr = cord.row;
	int tf = cord.col;

	for (r = tr + 1; r <= 7; r++) {
		move_bb |= ((uint64)1 << (r * 8 + tf));

		if (((uint64)1 << (r * 8 + tf)) & blockers) {
			break;
		}
	}

	for (r = tr - 1; r >= 0; r--) {
		move_bb |= ((uint64)1 << (r * 8 + tf));

		if (((uint64)1 << (r * 8 + tf)) & blockers) {
			break;
		}
	}

	for (f = tf + 1; f <= 7; f++) {
		move_bb |= ((uint64)1 << (tr * 8 + f));
		if (((uint64)1 << (tr * 8 + f)) & blockers) {
			break;
		}
	}

	for (f = tf - 1; f >= 0; f--) {
		move_bb |= ((uint64)1 << (tr * 8 + f));
		if (((uint64)1 << (tr * 8 + f)) & blockers) {
			break;
		}
	}

	return move_bb;
}

void init_rook_masks(bitboard_t rook_masks[])
{
	for (position_e pos = a8; pos < no_sq; pos++) {
		rook_masks[pos] = mask_rook_attacks(pos);
	}
}

void init_rook_attacks(bitboard_t rook_masks[], bitboard_t rook_attacks[64][power_set(12)])
{
	for (position_e pos = a8; pos < no_sq; pos++) {

		bitboard_t assertion_mask = 0;
		bitboard_t mask = rook_masks[pos];

		size_t mask_bitcnt = popcnt(mask);
		size_t permutations_count = power_set(popcnt(mask));

		for (size_t i = 0; i < permutations_count; i++) {

			permutation_t p = get_occupancy_permutation(i, mask, mask_bitcnt);

			uint32 magic_index = (p * rook_magics[pos]) >> (64 - rook_occupancy_bits[pos]);
			rook_attacks[pos][magic_index] = rook_attacks_over_blockers(pos, p);
			assertion_mask |= p;

		}

		// Assert that the union of all permutations is the mask
		assert(assertion_mask == mask);
	}
}

bitboard_t get_rook_attacks(position_e pos, bitboard_t rook_masks[], bitboard_t occupancy, bitboard_t rook_attacks[][power_set(12)])
{
	occupancy &= rook_masks[pos];
	occupancy *= rook_magics[pos];
	occupancy >>= (64 - rook_occupancy_bits[pos]);

	return rook_attacks[pos][occupancy];
}