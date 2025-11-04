ASSUME CS: CODE, DS: DATA

DATA SEGMENT
    MSG1 DB 0AH, 0DH, "Enter No.: $"
    MSG2 DB 0AH, 0DH, "Sum: $"
    NUM1 DW 0000H
    NUM2 DW 0000H
DATA ENDS

CODE SEGMENT
    PRINT MACRO MSG
        LEA DX, MSG
        MOV AH, 09H
        INT 21H
    ENDM

READ PROC
    XOR AX, AX
    PUSH AX
    L1:
        MOV AH, 01H
        INT 21H
        CMP AL, 0DH
        JE L2
        MOV AH, 00H
        SUB AL, 30H
        MOV BX, AX
        MOV DX, 000AH
        POP AX
        MUL DX
        ADD AX, BX
        PUSH AX
        JMP L1
    L2:
        POP AX
        RET
READ ENDP

DIS PROC
    PUSH DX
    XOR CX, CX
    MOV BX, 000AH
    L3:
        XOR DX, DX
        DIV BX
        ADD DX, 0030H
        PUSH DX
        INC CX
        CMP AX, 0000H
        JNZ L3
    L4:
        POP DX
        MOV AH, 02H
        INT 21H
        LOOP L4
    POP DX
    RET
DIS ENDP

ADDITION PROC
    MOV AX, NUM1
    MOV BX, NUM2
    ADD AX, BX
    CALL DIS
    RET
ADDITION ENDP

START:
    MOV AX, DATA
    MOV DS, AX
    PRINT MSG1
    CALL READ
    MOV NUM1, AX
    PRINT MSG1
    CALL READ
    MOV NUM2, AX
    PRINT MSG2
    CALL ADDITION
    MOV AH, 4CH
    INT 21H
    CODE ENDS
END START