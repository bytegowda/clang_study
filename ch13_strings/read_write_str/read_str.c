/*
 *  scanf   : only takes the string without whitespace.
 *            If whitespace is detected, the scanf stops reading
 *
 *  getline : ssize_t getline(char** line, size_t *n, FILE* stream); 
 *            where char *line; ssize_t n; stream could fp or stdin
 *            returns no of chars read if success else returns -1.
 *
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_LEN     64

void check_next_line_char(char *str) {
    int i=0;
    while(str[i] != '\0') {
        if(str[i] == '\n') {
            str[i] = '\0';
        }
        i++;
    }
}

int main() {
    char str[STR_LEN] = {0};
    char *pstr = NULL;
    char *pcpy = NULL;
    size_t n=0;
    ssize_t nread=0;
    int len = 0;

    printf("Enter the string\n");
    //scanf("[*\n]%s", str);
    nread = getline(&pstr, &n, stdin);
    if(nread == -1) {
        printf("getline read failed\n");
        exit(EXIT_FAILURE);
    }

    pstr[nread-1] = '\0';

    printf("The String Entered : %s\n", pstr);
    pcpy = malloc(strlen(pstr)*sizeof(char));
    if(pcpy == NULL) {
        printf("Failed to allocate memory\n");
        exit(EXIT_FAILURE);
    }

    //memcpy(pcpy, pstr, strlen(pstr));
    strncpy(pcpy, pstr, strlen(pstr));

    check_next_line_char(pstr);
    printf("The String After check : %s\n", pstr);

    printf("\npcpy = %s\n", pcpy);

    free(pstr);
    free(pcpy);

    return 0;
}
