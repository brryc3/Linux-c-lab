#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_MAXLEN 50
#define FILE_NAME   "contacts.txt"

struct Person {
    char name[NAME_MAXLEN];
    int  age;
};

void usage(const char *prog) {
    printf("Usage:\n");
    printf("  %s add <name> <age>\n", prog);
    printf("  %s view\n", prog);
}

int add_contact(const char *name, int age) {
    FILE *f = fopen(FILE_NAME, "a");
    if (!f) { perror("fopen"); return 1; }
    // store as: Name,Age\n
    fprintf(f, "%s,%d\n", name, age);
    fclose(f);
    printf("Added: %s, %d\n", name, age);
    return 0;
}

int view_contacts(void) {
    FILE *f = fopen(FILE_NAME, "r");
    if (!f) {
        puts("No contacts yet.");
        return 0;
    }
    char line[256];
    int count = 0;
    while (fgets(line, sizeof line, f)) {
        // parse "name,age"
        char *comma = strchr(line, ',');
        if (!comma) continue;
        *comma = '\0';
        char *name = line;
        int age = atoi(comma + 1);
        printf("%-20s | %d\n", name, age);
        count++;
    }
    fclose(f);
    if (count == 0) puts("No contacts found.");
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2) { usage(argv[0]); return 1; }

    if (strcmp(argv[1], "add") == 0) {
        if (argc != 4) { usage(argv[0]); return 1; }
        const char *name = argv[2];
        int age = atoi(argv[3]);
        if (age <= 0) { puts("Age must be a positive integer."); return 1; }
        return add_contact(name, age);
    } else if (strcmp(argv[1], "view") == 0) {
        return view_contacts();
    } else {
        usage(argv[0]);
        return 1;
    }
}
