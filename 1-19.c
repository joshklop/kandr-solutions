#include <stdio.h>
#define MAXLINE 1000

int get_line(char line[], int maxline);
void reverse(char s[], int lim);

int main() {
    int len;
    char line[MAXLINE];

    while ((len = get_line(line, MAXLINE)) > 0) {
        reverse(line, len);
        printf("%s", line);
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

void copy(char to[], char from[]) {
    int i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}

void reverse(char s[], int len) {
    char temp[len];
    for (int i = 0; i < len; ++i) {
        /* Use len-2 to skip newline and null characters */
        temp[len-2 - i] = s[i];
    }
    temp[len - 1] = '\n';
    temp[len] = '\0';
    copy(s, temp);
}
