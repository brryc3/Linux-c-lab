#include <stdio.h>

int main(void) {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    if (num >= 0)
        printf("Positive\n");
    else
        printf("Non-positive\n");

    return 0;
}
