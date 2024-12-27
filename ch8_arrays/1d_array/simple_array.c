#include <stdio.h>

#define ARR_LEN		16

int main() {
	int a[ARR_LEN] = {0};
	int n=0;

	for(int i=0; i<ARR_LEN; i++)
		a[i] = i;

	/*Side effect assignment of array subscripts
	 * this fails to behave in the orderly manner
	 * the code a[k] = k++; could execute in any order. a[k] could execute first or k++ could execute first
	 * int k=0;
	 * while(k<ARR_LEN)
		  a[k] = k++;

	*/

	for(int i=0; i<ARR_LEN; i++)
		printf("a[%d]=%d\n", i, a[i]);

	for(int i=0; i<ARR_LEN; i++)
		a[i] = 0;

	printf("No of arrays and Enter array elements\n");
	scanf("%d", &n);

	if(n > ARR_LEN) {
		printf("Array len exceeded beyond 16\n");
		return 1;
	}

	for(int i=0; i<n; i++)
		scanf("%d", &a[i]);

	for(int i=0; i<n; i++)
		printf("a[%d]=%d\n", i, a[i]);

	//An Array with side effects
	/*Side effect - in printf("a[%d] = %d\n", i, a[i++]);
	 *		a[i] is deferenced for a[%d] = a[i]
	 *		then i is incrementd to i++ and then a[%d] becomes a[i+1] since i was incremented.
	 *		Need to be cautious about such side effects
	*/
	int i=0;
	printf("Printing an array with side effects\n");
	while(i<n) {
		printf("a[%d] = %d\n", i, a[i]);
		i++;
	}

	return 0;
}
