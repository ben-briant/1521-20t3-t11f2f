#include <stdio.h>

int main (int argc, char *argv[]) {

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *f = fopen(argv[1], "r");
    if (f == NULL) {
        fprintf(stderr, "Unable to open file %s\n", argv[1]);
        perror("");
        return 1;
    }

    int ch;
    while ((ch = fgetc(f)) != EOF) {
        fputc(ch, stdout);
        if (ch == '\n') {
            break;
        }
    }
}
