/*
 *  char *stcat(char* dst, const char *src);
 *          - string pointed to by src is appended to string pointed to by dst at the end
 *          - returns dst
 *          - it will also add \0 at the end of the string
 *
 *  char *strncat(char* dst, const char* src, size_t n);
 *
*/

#include <stdio.h>
#include <string.h>

#define STR_LEN     16

int main() {
    char str1[8] = {0};
    char str2[8] = {0};

    strcat(str1, strcat(str2, "abcd"));
    printf("%s:%d: str1=%s\t str2=%s\n", __func__, __LINE__, str1, str2);

    //strcat(str1, str2); - causes buffer overflow
    strncat(str1, str2, sizeof(str1)-strlen(str1)-1);
    printf("%s:%d: str1=%s\t str2=%s\n", __func__, __LINE__, str1, str2);

    //strcat(str1, str2);   - causes buffer overflow
    strncat(str1, str2, sizeof(str1)-strlen(str1)-1);
    printf("%s:%d: str1=%s\t str2=%s\n", __func__, __LINE__, str1, str2);

    return 0;
}
