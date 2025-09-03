#include <stdio.h>

int main(void) {
    int arr[3] = {1, 2, 3};
    int *ptr = arr;                 // points at arr[0]

    for (int i = 0; i < 3; i++) {
        printf("%d\n", *(ptr + i)); // print arr[i] via pointer
    }
    return 0;
}
