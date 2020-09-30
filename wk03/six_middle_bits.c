#include <stdio.h>
#include <stdint.h>
#include <assert.h>

uint32_t six_middle_bits(uint32_t n) {
    // TODO: Return the middle 6 bits of n
    // 00000000000000000000000000000000
    //              ^    ^
    //      from here    to here
    // Shift the bits of n to the right by 13.
    // Now, the middle six bits of n are at the bottom.
    // Then, apply the bitmask 0x3F to zero all other bits
    // except the bottom six.
    return (n >> 13) & 0x3F;
}

int main (void) {
    int num;
    // Loop until CTRL-D, printing the middle six bits of each hexadecimal number inputted.
    while (scanf("%x", &num) == 1) {
        printf("The middle 6 bits of %08X are: %02X\n", num, six_middle_bits(num));
    }
}
