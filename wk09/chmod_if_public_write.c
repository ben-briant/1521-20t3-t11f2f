// remove public write from specified as command line arguments if needed

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

void chmod_if_needed(char *pathname);

int main(int argc, char *argv[]) {
    for (int arg = 1; arg < argc; arg++) {
        chmod_if_needed(argv[arg]);
    }
    return 0;
}

// chmod a file if publically-writeable

void chmod_if_needed(char *pathname) {
    // TODO: Implement this function
    // If a file is already not publicly writeable, print a message
    // Otherwise, remove the public write permission.
    struct stat s;
    stat(pathname, &s);

    if (s.st_mode & S_IWOTH) {
        // We need to remove it
        chmod(pathname, s.st_mode & ~S_IWOTH);
        printf("removing public write from %s\n", pathname);
    } else {
        printf("%s is not publicly writeable\n", pathname);
    }
}
