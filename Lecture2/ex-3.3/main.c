#include <stdio.h>

long power(int x, int y);
void multiswap(int* x, int* y, int* z);

int main () {
    printf("%lu\n", power(2, 3));

    int x = 2;
    int y = 3;
    int z = 4;
    multiswap(&x, &y, &z);
    printf("%i\n", x);
    printf("%i\n", y);
    printf("%i\n", z);
    return 0;
}

// Fast modular exponentiation algorithm
long power(int x, int y) {
    int res = 1;
    while (y > 0) {
        if (y & 1) res = res*x;
  
        y = y >> 1;
        x = x * x;
    }
    return res;
}

void multiswap(int* x, int* y, int* z) {
    int tmp = *x;
    *x = *y;
    *y = *z;
    *z = tmp;
}