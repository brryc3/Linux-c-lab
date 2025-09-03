#include <stdio.h>

unsigned long long fact(int n) {
    if (n <= 1) return 1ULL;
    return (unsigned long long)n * fact(n - 1);
}

int main(void) {
    int n;
    printf("Enter n: ");
    if (scanf("%d", &n) != 1) {
        printf("Invalid input\n");
        return 1;
    }
    if (n < 0) {
        printf("Factorial is not defined for negative numbers\n");
        return 1;
    }
    printf("factorial(%d) = %llu\n", n, fact(n));
    return 0;
}
