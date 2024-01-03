#include "board.h"
int main(){
	board_t b = { {(uint64)1 ,(uint64)2 ,(uint64)3 ,(uint64)4 ,(uint64)5 ,(uint64)6 }, {(uint64)22 , (uint64)33 ,(uint64)4000 ,(uint64)222 ,(uint64)256} };
	str_board_t str = { {0}, {0}};
	fill_str_board(&b, &str);
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			char a = str[i][j];
			printf("%c", a);
		}
	}
}