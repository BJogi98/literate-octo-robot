ORG 00H

MOV R2, #0AH
MOV R0, #20H
MOV R1, #40H

LBL:MOV A, @R0
MOV @R1, A
INC R0
INC R1
DJNZ R0, LBL
END