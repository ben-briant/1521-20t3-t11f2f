// Program which will reverse the bits in an unsigned integer
// Written by T11 f2f

#include <stdio.h>
#include <assert.h>

uint32_t reverseBits(uint32_t original) {
    // start our value to be returned as 0, so all the bits inside it are 0.
    // As we look through the bits of the original value, we will set
    // the corresponding bit in the reversed value
    uint32_t reversed = 0;

    // Use 'bit' to keep track of which bit we are looking at in the original value.
    for (int bit = 0; bit < 32; bit++) {
        // Create masks for the original and reversed values.
        // Since 1u (1, but unsigned) only has the last bit as 1, when we shift it left by 'bit',
        // we are selecting the bit in position 'bit' (i.e if bit == 6, we are selecting the 6th bit)
        // 1u             = 00000000000000000000000000000001
        // 1u << 6        = 00000000000000000000000001000000
        // Now, when we shift 1u left by '31 - bit', this will be the mirror of 1u << 6.
        // 1u << (31 - 6) = 00000010000000000000000000000000
        uint32_t originalMask = 1u << bit;
        uint32_t reversedMask = 1u << (31 - bit);
        // With this setup done, we can now check if the bit at the
        // current position in original is 1 or 0, using originalMask.
        // Recall that  0 & 0 == 0, and 1 & 0 == 0. Therefore, 0 'and' anything will be 0.
        // Also recall, 0 & 1 == 0, and 1 & 1 == 1. Therefore, 1 'and' anything will be the original value.
        // So, since originalMask only has the current bit set to 1, with all others being 0,
        // When we do a bitwise & with orignal, the result will be a value with the bits being all 0,
        // except for the bit which was 1 in originalMask, which will retain its original value.
        // Using this, we can check if that bit was 1 or 0. If the bit was 0, original & originalMask will be 0 (and therefore considered 'false' by C),
        // But if the bit was 1, then original & originalMask will be non-zero (and therefore considered 'true' by C).
        // If the bit was 1, then we want to set the corresponding bit in 'reversed', which we do inside the if statement. If not, we continue, leaving it as 0.
        if (original & originalMask) {
            // Recall that  0 | 0 == 0, and 1 | 0 == 1. Therefore, 0 'or' anything will be the original value.
            // Also recall, 0 | 1 == 1, and 1 | 1 == 1. Therefore, 0 'or' anything will be the 1.
            // This means that, if we do reversed | reversedMask, all bits in reversed will
            // be left unchanged, except for the bit in reversedMask which is 1.
            // This bit will always become 1.
            // So, since reversedMask is a mirror of originalMask, we will be adding the bits to reversed
            // in the opposite order they appear in original, thus reversing it.
            reversed = reversed | reversedMask;
        }
    }

    return ret;
}

// testing
int main(void) {
    uint32_t w1 = 0x01234567;
    // 0000 => 0000 = 0
    // 0001 => 1000 = 8
    // 0010 => 0100 = 4
    // 0011 => 1100 = C
    // 0100 => 0010 = 2
    // 0101 => 1010 = A
    // 0110 => 0110 = 6
    // 0111 => 1110 = E
    assert(reverseBits(w1) == 0xE6A2C480);
    puts("All tests passed!");
    return 0;
}
