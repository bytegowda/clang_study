/*
 *
 *	strcat
 *
 *
 *
*/

#include <stdio.h>

char *my_strcat(char *s1, const char *s2) {
	char *p = s1;

	//step 1
	while(*p)
		p++;

	//step2
/*	while(*s2) {
		*p = *s2;
		s2++;
		p++;
	}

	*p = '\0';
*/
	//condense the step 2
	/*why this works? *p++ = *s2++
	 *	1. s2 is first deferenced to *s2
	 *	2. p is also first deferenced to *p
	 *	3. Now, *s2 is a character and is copied to *p, since if you ignore ++ operator it is simplified to an assignment *p = *s2
	 *	4. After copying the character from *s2 to *p, both s2 and p are incremented with post increment ++
	 *	5. The loop is terminated once *s2 points to '\0' and this is assigned to *p. Now since the numeric value is 0, while(0) terminates.
	*/
	while(*p++ = *s2++)
		;

	return s1;
}

size_t read_line(char str[]) {
	int n=0;
	int i=0;
	while( ((n=getchar()) != '\n') && i<64) {
		*str = n;
		str++;
		i++;
	}
	*str = '\0';
	return i;
}

int main() {
	char str[64] = {0};
	char s1[64] = {0};

	read_line(str);
	my_strcat(s1, str);

	printf("s1=%s\n", s1);

	return 0;
}
