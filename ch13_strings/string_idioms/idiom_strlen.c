#include <stdio.h>


int read_line(char str[], int n) {
    int i=0;
    int ch = 0;

    while((i < n) && (ch = getchar()) != '\n') {
        str[i] = ch;
        i++;
    }

    str[i] = '\0';

    return i;
}

#if 0
size_t my_strlen(const char* str) {
    size_t i=0;
    for(; *str != '\0'; str++)
        i++;

    return i;
}

#else
/*
 * condense for loop - for(; *str != '\0'; str++)
 *   *str!='\0' to *str != 0, since numeric value of '\0' is 0 - for(; *str != 0; str++)
 *   *str!= 0 is equivalent to *str - for(; *str; str++)
 *   and from section 12.2, we can combine *str and str++ as *str++ - for(; *str++;)
*/

size_t my_strlen(const char* str) {
    size_t n=0;
    for(; *str++; )
        n++;

    return n;
}

size_t while_loop_strlen(const char* str) {
    size_t n=0;
    while(*str++) {
        n++;
    }

    return n;
}
#endif

size_t fast_strlen(const char* str) {
    const char *p = str;

    //why *str and not *str++, *str - ends before null, *str++ ends just after null
    //If *str++ is used, then str-p return +1 of the real strlen of str

    //if *str used
    //while(*str)
      //str++;

    //return str-p;
    
    //if *str++ used
    while(*str++) {
    }

    return str-p-1;

}

int main() {
    char str[64] = {0};
    int n = 0;
    size_t len=0, flen=0;

    read_line(str, 64);

    n = my_strlen(str);
    printf("str = %s\t n = %d\n", str, n);

    len = while_loop_strlen(str);
    printf("str = %s\t len = %d\n", str, len);

    flen = fast_strlen(str);
    printf("str = %s\t flen = %d\n", str, flen);

    return 0;
}
