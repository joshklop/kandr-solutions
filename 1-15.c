#include <stdio.h>

double celsius(int fahr);

int main() {
    for (int fahr = 0; fahr <= 300; fahr += 20) {
        printf("%3d\t%6.1f\n", fahr, celsius(fahr));
    }
    return 0;
}

double celsius(int fahr) {
    return (5.0/9.0) * (fahr - 32.0);
}
