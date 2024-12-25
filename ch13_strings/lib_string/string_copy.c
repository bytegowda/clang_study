/*
 *
 *  char *strcpy(char *dst, const char *src);
 *          - copies string pointed to by src to the array dst.
 *          - copies the string upto null character  '\0'
 *          - returns the pointer to dst, src remains unmodified.
 *
 *  char *strncpy(char *dst, const char* src, size_t n);
 *          - copies n bytes of characters from string pointed to by src to char array dst
 *
 *  size_t strlen(const char* str);
 *          - returns the length of the string of type size_t not including the Null character '\0'
 *          - size_t is typedef of unsigned integer,
 *          - which means if char str[8]="abcefg"; then strlen(str)=7 but sizeof(str)=8
 *
*/

#include <stdio.h>
#include <string.h>

#define SIZEOF_CUS(arr)     ((char*)(&arr+1) - (char*)&arr)

char* strncpy_cus(char *dst, const char *src, size_t n) {
    int i=0;
    if( (src == NULL) || n <=0) {
        return NULL;
    }

    for(i < n; *src != '\0'; i++, dst++, src++) {
        //dst[i] = *src[i];
        *dst = *src;
    }

    return dst;
}

#if LIB

int main() {
    char str1[16] = {0};
    char *str2 = "hello";
    char str3[8] = {0};
    char *str4 = "abcdefghijklmnopqrst";

    //copy str2 to str1 using strcpy
    strcpy(str1, str2);

    printf("str1 = %s\n", str1);

    //strcpy(str1, str4);  - will cause undefined behaviour since str1 size is 16 but str4 is longer
    //same is the cause if strcpy(str3, str4) - causes undefined behaviour

    strncpy(str3, str4, sizeof(str3)-1);
    str3[sizeof(str3)-1] = '\0';

    printf("str3 = %s\n", str3);

    strncpy(str1, str4, sizeof(str1)-1);
    str1[sizeof(str1)-1] = '\0';

    printf("After copying str4 to str1:\n\t str1=%s\n", str1);

    printf("strlen(str1)=%u and sizeof(str1)=%u\n", strlen(str1), sizeof(str1));
    printf("strlen(\"abc\")=%u and sizoef(\"abc\")=%u\n", strlen("abc"), sizeof("abc"));

    return 0;
}
#else
int main() {
    char str1[16] = {0};
    char *str2 = "hello";
    char str3[8] = {0};
    char *str4 = "abcdefghijklmnopqrst";

    //copy str2 to str1 using strcpy
    //strcpy(str1, str2);

    strncpy_cus(str1, str2, sizeof(str1)-1);
    str1[sizeof(str1)-1] = '\0';
    printf("str1 = %s\n", str1);

    //strcpy(str1, str4);  - will cause undefined behaviour since str1 size is 16 but str4 is longer
    //same is the cause if strcpy(str3, str4) - causes undefined behaviour

    strncpy_cus(str3, str4, sizeof(str3)-1);
    str3[sizeof(str3)-1] = '\0';

    printf("str3 = %s\n", str3);

    strncpy_cus(str1, str4, sizeof(str1)-1);
    str1[sizeof(str1)-1] = '\0';

    printf("After copying str4 to str1:\n\t str1=%s\n", str1);

    printf("strlen(str1)=%u and sizeof(str1)=%u\n", strlen(str1), sizeof(str1));
    printf("strlen(\"abc\")=%u and sizoef(\"abc\")=%u\n", strlen("abc"), sizeof("abc"));

    printf("SIZEOF_CUS(str1)=%u \t SIZEOF_CUS(\"abc\")=%u \t SIZEOF_CUS(\"abcdef\")=%u\n",
                                                    SIZEOF_CUS(str1), SIZEOF_CUS("abc"), SIZEOF_CUS("abcdef"));


    int arr1[20] = {0};
    char arr2[20] = {0};
    unsigned char arr3[20] = {0};
    unsigned int arr4[20] = {0};
    long int arr5[20] = {0};
    unsigned long int arr6[20] = {0};
    double arr7[20] = {0};

    printf("sizeof int array=%u\n", SIZEOF_CUS(arr1));
    printf("sizeof char array=%u\n", SIZEOF_CUS(arr2));
    printf("sizeof unsigned char array=%u\n", SIZEOF_CUS(arr3));
    printf("sizeof unsigned int array=%u\n", SIZEOF_CUS(arr4));
    printf("sizeof long int array=%u\n", SIZEOF_CUS(arr5));
    printf("sizeof unsigned long int array=%u\n", SIZEOF_CUS(arr6));
    printf("sizeof double array=%u\n", SIZEOF_CUS(arr7));

    return 0;
}
#endif
