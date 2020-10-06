# MIPS program to print the numbers 24..42 incrementing by 3

main:
    # Your code here!
    li $t0, 24      # x in $t0

loop:
    bge $t0, 42, end

    move $a0, $t0
    li $v0, 1
    syscall

    li $v0, 11
    li $a0, '\n'
    syscall

    addi $t0, $t0, 3

    j loop

end:
    jr $ra
