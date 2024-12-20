/*
 * Character Arrays vs Character Pointers
 *    char date[] = "June 14";  //Character Array
 *    char *pdate = "June 14"; //Character Pointer
 * 
 *    date[] can be modified because it is an array. But *pdate cannot be modified because it is a pointer pointing to string literal.
 *    Like any other pointer, pdate = date; and it now points to date[] character array
 *
*/


#include <stdio.h>

void print_str(char *str) {
	int i=0;
	if(str != NULL) {
		while(str[i] != '\0') {
			printf("%c", str[i]);
			i++;
		}
	}
	printf("\n");
}

int str_len(char *str) {
	int i=0;
	if(str != NULL) {
		while(str[i] != '\0') {
			i++;
		}
	}

	return i;
}

int main() {
	char var[] = "string variable";	//editable string
	char *lit = "string literal";	//non editable
	int len = 0;

	printf("Printing string variable\n");
	print_str(var);

	printf("\nPrinting string literal\n");
	print_str(lit);

	len = str_len(var);
	var[len/2] = 'A';
	printf("print modified string variable of len = %d\n", len);
	print_str(var);

	lit = var;	//Now lit is pointing to a character array that can be editible.

	printf("\nprinting modified string literal pointer\n");
	print_str(lit);

	lit[(len+1)/2] = 'B';
	printf("\nprinting edited string literal pointer\n");
	print_str(lit);

	return 0;
}
