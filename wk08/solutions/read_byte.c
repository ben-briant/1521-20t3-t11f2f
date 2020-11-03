#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main (int argc, char *argv[]) {
    printf("Which byte would you like to read? ");
    int byte_num;
    scanf("%d", &byte_num);

    FILE *f = fopen(argv[1], "r");
    fseek(f, byte_num, SEEK_SET);

    int ch = fgetc(f);
    if (ch == EOF) {
        printf("File is less than %d bytes\n", byte_num);
    } else {
        printf("Byte read was: %c\n", ch);
    }

    fclose(f);
}
