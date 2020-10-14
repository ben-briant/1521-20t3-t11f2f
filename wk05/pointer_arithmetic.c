// Simple C program demonstrating arithmetic with pointers

#include <stdio.h>

int main (void) {
    int i = 0;
    int *p = &i;

    printf("p     == %p\n", p);
    printf("p + 1 == %p\n", p + 1);

    // How can we use this to access the elements of an array?

    int nums[5] = {1, 2, 3, 4, 5};
    i = 0;
    while (i < 5) {
        // "nums" is a pointer to the start of the array
        int *base_addr = nums;

        // When we add "i" to "base_addr", it will increment
        // the address by i * sizeof(int).
        // Effectively, we are saying:
        // curr_addr = base_addr + (i * 4)
        int *curr_addr = base_addr + i;
        printf("array[%d] == %d\n", i, *curr_addr);
        // This has the effect of getting us the i'th int
        // in the array.

        i++;
    }

    // So, we can do a similar thing in MIPS...
}
