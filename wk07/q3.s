# Recursive maximum of array function

# Register usage:
#   - `a' is in $a0
#   - `length' is in $a1
#   - `first_element` is in $s0 - because its value
#     is needed before and after the function call
#   - `max_so_far is in $t0`

max:
    addi $sp, $sp, -8   # create stack frame
    sw $ra, 0($sp)      # save return address (because when we jal
                        # inside this function, it will be overwritten)
    sw $s0, 4($sp)      # Save $s0 (so that we can restore its original
                        # value before we return)

    lw $s0, ($a0)         # Load the first value in the array into $s0

    bne $a1, 1, not_empty # If length is not equal to 1, go to "else" branch
    
    move $v0, $s0       # If length == 1, then return first_element (by storing it in $v0)
    j return

not_empty:
    # Prepare arguments for function call
    addi $a0, $a0, 4    # Get the address of a[1] - by adding 4 bytes to the address of the start of the array
    addi $a1, $a1, -1   # length - 1
    jal max

    # Now, returned value is in $v0
    move $t0, $v0
    ble $s0, $t0, return
    move $t0, $s0

return:
    move $v0, $t0       # Move `max_so_far` into $v0, so it is returned
    lw $s0, 4($sp)      # Restore values, and shrink stack before returning
    lw $ra, 0($sp)
    addi $sp, $sp, 8

    jr $ra

# some test code which calls max
main:
    addi $sp, $sp, -4  # create stack frame
    sw   $ra, 0($sp)   # save return address

    la   $a0, array
    li   $a1, 10
    jal   max    #

    move  $a0, $v0     # printf ("%d")
    li    $v0, 1
    syscall

    li   $a0, '\n'     # printf("%c", '\n');
    li   $v0, 11
    syscall

                       # clean up stack frame
    lw   $ra, 0($sp)   # restore $ra
    addi $sp, $sp, 4   # restore sp

    li  $v0, 0         # return 0
    jr  $ra


.data
array:
    .word 1 2 3 4 5 6 4 3 2 1
