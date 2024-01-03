#include "position.h"
#include "utils.h"

cordinate_t idx_to_cord(uint64 idx)
{
	cordinate_t cord = {
		.x = idx / 8,
		.y = idx % 8
	};

	return cord;
}