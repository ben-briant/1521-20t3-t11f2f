# Simpler approach to size.s

main:
    la $a0, prompt
    li $v0, 4
    syscall

    li $v0, 5
    syscall

    move $t0, $v0

    la $a0, small_big_str
    ble $t0, 100, end
    bge $t0, 1000, end

    la $a0, med_str
    j end

end:
    li $v0, 4
    syscall
    li $a0, '\n'
    li $v0, 11
    jr $ra
    
.data
    prompt: .asciiz "Enter a number: "
    med_str: .asciiz "medium\n"
    small_big_str: .asciiz "small/big\n"
