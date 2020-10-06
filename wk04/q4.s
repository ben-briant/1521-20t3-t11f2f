# MIPS program to determine if a number is "medium"

main:
    # Your code here!
    la $a0, prompt
    li $v0, 4
    syscall

    li $v0, 5
    syscall

    move $t0, $v0       # x in $t0

    la $a0, small_big

    ble $t0, 100, end
    bge $t0, 1000, end

    la $a0, medium

end:
    li $v0, 4
    syscall

    jr $ra

    .data
prompt:
    .asciiz "Enter a number: "    
medium:
    .asciiz "medium\n"
small_big:
    .asciiz "small/big\n"