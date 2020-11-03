#include <stdio.h>

int main (int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *f = fopen(argv[1], "r");
    if (f == NULL) {
        fprintf(stderr, "%s: could not open %s\n", argv[0], argv[1]);
        return 1;
    }

    int ch;
    while ((ch = fgetc(f)) != EOF) {
        putchar(ch);
        if (ch == '\n') break;
    }

    fclose(f);
}
