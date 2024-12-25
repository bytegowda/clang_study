/*
 * getchar() - int getchar(void)
 *
 *             takes a character input from stdin and return the character equivalent in integer
 *
*/

#include <stdio.h>

#define STR_LEN     1024

int get_str_line(char str[]) {
    int i=0;
    int n=0;

    while((n = getchar()) != '\n' && (i <= STR_LEN)) {
        str[i] = n;
        i++;
    }
    printf("i = %d\n", i);
    str[i] = '\0';
    return i;
}

int main() {
    char str[STR_LEN+1] = {0};
    int len = 0;

    printf("Enter the string\n");
    len = get_str_line(str);

    printf("str = %s, strlen = %d\n", str, len);

    return 0;
}
