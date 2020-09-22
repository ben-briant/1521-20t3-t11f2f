#include <stdio.h>

int main(void) {
    int n[4] = { 42, 23, 11, 7 };
    int *p;

    p = &n[0];
    printf("%p\n", p); // prints 0x7fff00000000
    printf("%lu\n", sizeof (int)); // prints 4

    // what do these statements print ?
    n[0]++;
    printf("%d\n", *p); // prints 43 (p points to the first element of the array, which is now 43. Therefore, dereferencing p will get 43.)
    p++;
    printf("%p\n", p);  // prints 0x7fff00000004 (when we increment a pointer, the value of the pointer increases by the size of the
                        // thing it is pointing to. Since p is a pointer to an int, and sizeof(int) == 4, when we increment p, it will increase by 4.
    printf("%d\n", *p); // prints 23 (p has been incremented, meaning it will be pointing to the next int in the array, so dereferencing it will get 23.)

    return 0;
}
