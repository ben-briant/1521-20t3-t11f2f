# MIPS program to read in a number,
# and print its square.

main:
    la $a0, prompt
    li $v0, 4
    syscall

    li $v0, 5
    syscall
    move $t0, $v0       # x in $t0

    ble $t0, 46340, multiply
    la $a0, error_msg
    li $v0, 4
    syscall
    j end

multiply:
    mul $t1, $t0, $t0   # y in $t1

    move $a0, $t1
    li $v0, 1
    syscall

    li $a0, '\n'
    li $v0, 11
    syscall

end:
    jr $ra

    .data
prompt:
    .asciiz "Enter a number: "
error_msg:
    .asciiz "square too big for 32 bits\n"