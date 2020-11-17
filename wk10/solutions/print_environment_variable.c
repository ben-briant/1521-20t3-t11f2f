#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {
    for (int i = 1; i < argc; i++) {
        printf("%s: %s\n", argv[i], getenv(argv[i]));
    }
}
