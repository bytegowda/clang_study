#include <stdio.h>


int main() {
#if 1	//using "" to join two or more lines. Also better formatting with printing.
	printf("This is a paragraph to print the string"
			"in but type the string literal in continuation"
			"using the backslash (\\) key\n");
#else	//using \ to join two or more lines
	printf("This is a paragraph to print the string \
in but type the string literal in continuation \
using the backslash key\n");

#endif
	return 0;
}
