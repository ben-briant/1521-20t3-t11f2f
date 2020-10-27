main:
    # Prologue
    addi $sp, $sp, -4
    sw $ra, ($sp)

    li $a0, 11
    li $a1, 13
    li $a2, 15
    li $a3, 17

    jal sum4

    # Epilogue
    lw $ra, ($sp)
    addi $sp, $sp, 4

    jr $ra

sum4:
    addi $sp, $sp, -20
    sw $ra, 0($sp)
    sw $s0, 4($sp)
    sw $s1, 8($sp)
    sw $s5, 12($sp)
    sw $s6, 16($sp)

    move $s5, $a2
    move $s6, $a3

    jal sum2
    move $s0, $v0

    move $a0, $s5
    move $a1, $s6
    jal sum2
    move $s1, $v0

    move $a0, $s0
    move $a1, $s1
    jal sum2

    lw $ra, 0($sp)
    lw $s0, 4($sp)
    addi $sp, $sp, 20

    jr $ra

sum2:
    addi $sp, $sp, -4
    sw $s0, ($sp)

    add $s0, $a0, $a1

    move $v0, $s0

    lw $s0, ($sp)
    addi $sp, $sp, 4

    jr $ra