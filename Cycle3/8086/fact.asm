ASSUME CS:code, DS:data
data SEGMENT
    msg1 DB 0Ah, 0Dh, "Enter no: $"
    msg2 DB 0Ah, 0Dh, "Factorial is: $"
    num1 DW 0000h
data ENDS

code SEGMENT
    print MACRO msg
    lea dx, msg
    mov ah, 09h
    int 21h
ENDM

read PROC
    xor ax, ax
    push ax
    l1:
        mov ah, 01h
        int 21h
        cmp al, 0Dh
        je l2
        mov ah, 00h
        sub al, 30h
        mov bx, ax
        mov dx, 000Ah
        pop ax
        mul dx
        add ax, bx
        push ax
        jmp l1
    l2:
        pop ax
        ret
read ENDP

display PROC
    push dx
    mov bx, 000Ah
    xor cx, cx
    l3:
        xor dx, dx
        div bx
        add dx, 0030h
        push dx
        inc cx
        cmp ax, 0000h
        jnz l3
    l4:
        pop dx
        mov ah, 02h
        int 21h
        loop l4
        pop dx
        ret
display ENDP

factorial PROC
    mov ax, 0001h
    mov cx, num1
    l5:
        mul cx
        dec cx
        jnz l5
        call display
        ret
factorial ENDP

start:
    mov ax, data
    mov ds, ax
    print msg1
    call read
    mov num1, ax
    print msg2
    call factorial
    mov ah, 4Ch
    int 21h
    code ENDS
END start
