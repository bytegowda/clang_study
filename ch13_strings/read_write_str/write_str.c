/*
 *
 * printf() - conversion specifier %s to print string
 *            conversion specifier %.ps to print part of the string where p - 0, 1, 2, ...
 *
*/

#include <stdio.h>

int main() {
    char *str = "Are we having a good time?";

    printf("Full String:\n\t%s\n", str);

    printf("Part of the String:\n\t%.8s\n", str);

    return 0;
}
