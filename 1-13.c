#include <stdio.h>

#define MAX 10	/* maximum number of words */

int main() {
    int c;
    int prev = 0;
    int n = 0;
    int count[MAX];

    for (int i = 0; i < MAX; ++i) count[i] = 0;

    while ((c = getchar()) != EOF) {
        if ((prev == ' ' || prev == '\n' || prev == '\t')
                && !(c == ' ' || c == '\n' || c == '\t')) {
            ++n;
            ++count[n];
        } else if (!(c == ' ' || c == '\n' || c == '\t')) ++count[n];
        prev = c;
    }
    
    printf("Horizontal histogram\n");
    for (int i = 0; i < MAX; ++i) {
        for (int j = 0; j < count[i]; ++j) printf("|");
        if (count[i] > 0) printf("\n");
    }

    printf("Vertical histogram\n");
    /* Find the max value in the array */
    int max = 0;
    for (int i =0; i < MAX; ++i) {
        if (count[i] > max) {
            max = count[i];
        }
    }
    /* Create the histogram */
    for (int i = max; i > 0; --i) {
        for (int j = 0; j < MAX; ++j) {
            if (count[j] == i) {
                printf("_ ");
                --count[j];
            } else printf("  ");
        }
        printf("\n");
    }

    return 0;
}
