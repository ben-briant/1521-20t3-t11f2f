#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void) {
    char *home_dir = getenv("HOME");
    if (home_dir == NULL) {
        perror("");
        exit(1);
    }

    // add space for '/' and '\0'
    int size = strlen(home_dir) + strlen(".diary") + 1 + 1;
    char file_name[size];

    snprintf(file_name, size, "%s/%s", home_dir, ".diary");

    FILE *f = fopen(file_name, "r");
    int ch;
    while ((ch = fgetc(f)) != EOF) {
        fputc(ch, stdout);
    }
}