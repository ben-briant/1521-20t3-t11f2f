
main:
    li $t0, 0           # i in $t0

loop:
    bge $t0, 10, end_loop 

    mul $t1, $t0, 4     # Offset in $t1
    la $t2, numbers     # Array address in $t2
    add $t3, $t1, $t2   # &numbers[i] in $t3

    lw $t4, ($t3)       # Load numbers[i] into $t4

    bge $t4, 0, end_if  # If numbers[i] >= 0, skip if

    # Now inside if statement, so add 42 and store
    addi $t4, $t4, 42   # Add 42 to numbers[i]
    sw $t4, ($t3)       # Store the new value back in the array

end_if:
    addi $t0, $t0, 1    # i++

end_loop:
    jr $ra

    .data
numbers:
    .word 0, 1, 2, -3, 4, -5, 6, -7, 8, 9
