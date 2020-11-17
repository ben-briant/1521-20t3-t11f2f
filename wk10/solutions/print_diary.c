#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void) {
    char *home = getenv("HOME");
    if (home == NULL) {
        home = ".";
    }

    int path_len = strlen(home) + strlen(".diary") + 2;
    char diary_path[path_len];

    snprintf(diary_path, path_len, "%s/%s", home, ".diary");

    FILE *f = fopen(diary_path, "r");
    if (f == NULL) {
        fprintf(stderr, "No diary exists in home directory\n");
        return 1;
    }

    int ch;
    while ((ch = fgetc(f)) != EOF) {
        putchar(ch);
    }

    fclose(f);
}
