#include <stdio.h>
#include <stdlib.h>

#define LEN	64

int main() {
	int a[LEN]={0};
	int n=0;

	printf("Enter the array length and array\n");
	scanf("%d", &n);

	if(n>LEN) {
		printf("Enter the array length less than %d\n", LEN);
		exit(EXIT_FAILURE);
	}

	for(int i=0; i<n; i++) {
		scanf("%d", &a[i]);
	}

	printf("Array : \n");
	for(int i=0; i<n; i++)
		printf("%d\t", a[i]);
	printf("\n");

	printf("Reversed Array : \n");
	for(int i=n-1; i>=0; i--)
		printf("%d\t", a[i]);
	printf("\n");

	printf("sizeof a = %d\n", sizeof(a)/sizeof(a[0]));

	return 0;
}
