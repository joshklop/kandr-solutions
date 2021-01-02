#include <stdio.h>


#define MAX 52 /* Upper and lowercase English alphabet */


int main() {
    int c, count[MAX];

    for (int i = 0; i < MAX; ++i) count[i] = 0;

    while ((c = getchar()) != EOF) {
        if (c >= 'A' && c <= 'Z') ++count[c-'A'];
        else if (c >= 'a' && c <= 'z') ++count[c-'a'+26];
    }

    printf("HISTOGRAM\n");
    for (int i = 0; i < MAX; ++i) {
        if (i <= 25) printf("%c ", i + 'A');
        else printf("%c ", i + 'a' - 26);
        for (int j = 0; j < count[i]; ++j) {
            if (count[i] > 0) printf("X");
        }
        printf("\n");
    }
}
