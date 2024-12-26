#include <stdio.h>
#include <stdlib.h>

#define STR_LEN     1024

void count_case(char *str) {
    int up=0, low=0, spc=0;

    for(; *str!='\0'; str++) {
        if( (*str >= 'A') && (*str <= 'Z')) {
            up++;
        }
        else if( (*str >= 'a') && (*str <= 'z')) {
            low++;
        }
        else {
            spc++;
        }
    }

    printf("up=%d, low=%d, spc=%d\n", up, low, spc);
}

void convert_str_case(char *str) {
    int diff = 'a' - 'A';

    for(; *str!='\0'; str++) {
        if( (*str >= 'A') && (*str <= 'Z')) {
            //printf("%c\n", (*str)+diff);
            *str = (*str)+diff;
        }
        else if( (*str >= 'a') && (*str <= 'z')) {
            //printf("%c\n", (*str)-diff);
            *str = (*str)-diff;
        }
        else {
            continue;
        }
    }
}


int main() {
    char *str = NULL;
    size_t n = 0;
    ssize_t nread=0;

    if((nread = getline(&str, &n, stdin)) == -1) {
        printf("getline failed, exit\n");
        exit(EXIT_FAILURE);
    }

    str[nread-1] = '\0';
    count_case(str);

    convert_str_case(str);
    printf("str = %s\n", str);

    return 0;
}
