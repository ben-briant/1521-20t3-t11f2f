    .data
string:
    .asciiz "Hello!\n"
finished:
    .asciiz "Back from function!\n"

    .text
main:
    addi $sp, $sp, -4   # Because we are calling another function, we need to save $ra
    sw $ra, ($sp)       # So that it can be restored after being overwritten by the jal.

    jal hello

    li $v0, 4
    la $a0, finished
    syscall

    lw $ra, ($sp)
    addi $sp, $sp, 4

    jr $ra

hello:
    la $a0, string
    li $v0, 4
    syscall

    jr $ra
