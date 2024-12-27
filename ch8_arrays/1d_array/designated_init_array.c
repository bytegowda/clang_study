/*
 *	Designated Initialization of Arrays
 *
 *
 *
*/

#include <stdio.h>

#define	LEN		10

int main() {
	int a[LEN] = {[2] = 9, [3] = 12, [5] = 11, [9] = 22, [8] = 34};
	int b[LEN] = {0, 1, 2, [4] = 55, 3, 6, 8, [8] = 223, 21}; //because [4] = 55 is assigned after index 2, compiler assume [3] = 0

	for(int i=0; i<LEN; i++)
		printf("a[%d] = %d\n", i, a[i]);


	printf("\n\n");
	for(int i=0; i<LEN; i++)
		printf("b[%d] = %d\n", i, b[i]);

	printf("\n\nsizeof a = %d, sizeof b = %d\n", sizeof(a)/sizeof(a[0]), sizeof(b)/sizeof(b[0]));

	return 0;
}
