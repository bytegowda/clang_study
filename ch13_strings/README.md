# Study and Practice Strings.

## Progress:
	1. String Literals and operation using return "0123456789ABCDEF"[digit]
	2. Don't ever pass character in place of string because character is an Interger but string is a pointer.
		printf("\n"); - valid because printf takes pointer as first argument.
		printf('\n'); - Invalid, because it is passing a character.
	3. Character Arrays vs Character Pointers
		char date[] = "June 14";  //Character Array
		char *pdate = "June 14"; //Character Pointer

		date[] can be modified because it is an array. But *pdate cannot be modified because it is a pointer pointing to string literal.
		like any other pointer, pdate = date; and it now points to date[] character array

## Status: In Progress
