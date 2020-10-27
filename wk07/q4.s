# row in $t0, col in $t1
main:
    li $t0, 0
loop0:
    bge $t0, 6, end0

    li $t1, 0
loop1:
    bge $t1, 12, end1

    # Calculate the offset of the start of the current row:
    mul $t2, $t0, 12    # There are 12 elements in each row
    mul $t2, $t2, 1     # Each element is 1 byte large (this step isn't
                        # necessary when working with an array of chars,
                        # I'm just showing the general process)

    # Now, calculate the offset within the current row:
    mul $t3, $t1, 1     # Each element in the current row is 1 byte large
                        # (Again, not necessary, since each char is only 1 byte large.
                        # for an int array, you would multiply by 4)

    # Now, add these offsets together to get the total offset into the array:
    add $t4, $t2, $t3

    # Now, add this offset to the start address of the array:
    la $t5, flag
    add $t6, $t5, $t4

    # Load the current character into $a0 and print it:
    lb $a0, ($t6)
    li $v0, 11
    syscall

    addi $t1, $t1, 1

    j loop1

end1:
    li $a0, '\n'
    li $v0, 11
    syscall

    addi $t0, $t0, 1
    j loop0

end0:
    jr $ra

.data
flag:
    .byte '#' '#' '#' '#' '#' '.' '.' '#' '#' '#' '#' '#'
    .byte '#' '#' '#' '#' '#' '.' '.' '#' '#' '#' '#' '#'
    .byte '.' '.' '.' '.' '.' '.' '.' '.' '.' '.' '.' '.'
    .byte '.' '.' '.' '.' '.' '.' '.' '.' '.' '.' '.' '.'
    .byte '#' '#' '#' '#' '#' '.' '.' '#' '#' '#' '#' '#'
    .byte '#' '#' '#' '#' '#' '.' '.' '#' '#' '#' '#' '#'
