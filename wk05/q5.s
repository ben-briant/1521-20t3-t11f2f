
main:
    li $t0, 0       # i in $t0
loop:
    bge $t0, 10, end

    li $v0, 5
    syscall

    la $t1, numbers # Start of array in $t1

    mul $t2, $t0, 4 # Offset into array in $t2
    add $t3, $t1, $t2 # &numbers[i] in $t3
    
    sw $v0, ($t3)

    addi $t0, $t0, 1
    j loop

end:
    jr $ra

    .data
numbers: .word 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
