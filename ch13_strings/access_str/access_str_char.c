#include <stdio.h>

#define STR_LEN     1024

#if 0   //Array index increment.
int get_space_count(const char *str) {
    int i=0;
    int count=0;
    if(str != NULL) {
        for(i=0; str[i] != '\0'; i++) {
            if(str[i] == ' ')
                count++;
        }
    }

    return count;
}

#else   //pointer arithmetic increment
int get_space_count(const char *str) {
    int count=0;
    if(str != NULL) {
        for(; *str != '\0'; str++) {
            if(*str == ' ')
                count++;
        }
    }

    return count;
}
#endif

int get_str_line(char str[]) {
    int i=0;
    int n=0;

    while((n = getchar()) != '\n' && (i < STR_LEN)) {
        str[i] = n;
        i++;
    }

    str[i] = '\0';
    return i;
}

int main() {
    char str[STR_LEN] = {0};
    int space_count = 0;
    int len = 0;

    printf("Enter the string\n");
    len = get_str_line(str);

    printf("String : %s, len = %d\n", str, len);

    space_count = get_space_count(str);
    printf("No of Space in str = %d\n", space_count);

    return 0;
}
