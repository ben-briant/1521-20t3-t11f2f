# Prints out the numbers from 24 to 42

main:
    li $t0, 24      # x in $t0
loop:
    bge $t0, 42, end
    
    move $a0, $t0
    li $v0, 1
    syscall

    li $a0, '\n'
    li $v0, 11
    syscall

    addi $t0, $t0, 3
    j loop

end:
    jr $ra
