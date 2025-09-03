#include <stdio.h>
#include <string.h>

int main(void) {
    const char *msg = "Text";
    FILE *file = fopen("output.txt", "w");
    if (!file) {
        perror("fopen");
        return 1;
    }
    fprintf(file, "%s\n", msg);
    fclose(file);
    printf("Wrote to output.txt\n");
    return 0;
}
