# MIPS program to print a triangle of asterisks

main:
    li $t0, 1               # i in $t0

loop0:
    bgt $t0, 10, end0
    li $t1, 0               # j in $t1

loop1:
    bge $t1, $t0, end1
    li $a0, '*'
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