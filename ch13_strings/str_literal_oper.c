#include <stdio.h>

typedef unsigned int uint8;

char digit_to_hexchar(uint8 digit) {
	if(digit <= 15) {
		return "0123456789ABCDEF"[digit];
	}
}

int main() {
	uint8 i=0;
	for(i=0; i<16; i++) {
		printf("digit : %02d ---> hex : 0x%c\n", i, digit_to_hexchar(i));
	}

	return 0;
}
