#include <stdio.h>
#define MAXLINE 1000

int get_line(char line[], int maxline);

int main() {
    int len;
    char line[MAXLINE];
    char newline[MAXLINE];

    while ((len = get_line(line, MAXLINE)) > 0) {
        if (line[0] != '\n') {
            int i, j;
            /* Use len-2 to skip the null character and newline character */
            for (i = len - 2; (i >= 0) && (line[i] == ' ' || line[i] == '\t'); --i);
            for (j = 0; j <= i; ++j) newline[j] = line[j];
            newline[j++] = '\n';
            newline[j] = '\0';
            printf("%s", newline);
        }
    }
    return 0;
}

int get_line(char s[], int lim) {
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') s[i++] = c;
    s[i] = '\0';
    return i;
}
