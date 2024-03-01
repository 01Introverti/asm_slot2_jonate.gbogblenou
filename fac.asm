    bits 64
    global my_sous
    section .text

my_sous:
    mov string rsi
    mov c rdi
    jmp loop
loop:
    cmp rsi, 0
    jmp find_char
    
