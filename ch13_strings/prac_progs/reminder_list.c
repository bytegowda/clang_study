//Under construction

#include <stdio.h>
#include <string.h>

#define MAX_REMIND  60
#define MSG_LEN 50

int read_line(char str[], int n);

int main() {
    char reminders[MAX_REMIND][MSG_LEN+3] = {0};
    char day_str[3] = {0}, msg_str[MSG_LEN+1] = {0};
    int day, i, j, num_remind=0;

    for(;;) {
        if(num_remind == MAX_REMIND) {
            printf("--- No Space Left ---\n");
            break;
        }

        printf("Enter the Day and Reminder: \n");
        scanf("%2d", &day);
        if(day == 0)
            break;

        sprintf(day_str, "%2d", day);
        read_line(msg_str, MSG_LEN);

    }

    return 0;
}

int read_line(char str[], int n) {
    int i=0;
    int ch=0;

    while((i < n) && (ch = getchar()) != '\n') {
        str[i] = ch;
        i++;
    }

    str[i] = '\0';
    return i;
}
