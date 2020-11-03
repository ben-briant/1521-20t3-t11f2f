#include <stdio.h>

int main (int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *f = fopen(argv[1], "r");
    if (f == NULL) {
        // error
    }

    int c1, c2;
    int nborts = 0;
    while ((c1 = fgetc(f)) != EOF && (c2 = fgetc(f)) != EOF) {
        int bort = c1 << 8 | c2;
        printf("bort %4d: %d\n", nborts, bort);
        nborts++;
    }

    fclose(f);
}
