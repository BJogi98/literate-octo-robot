ORG 00H

MOV R2, #0AH
MOV R0, @29H
MOV R1, @2EH

LBL:MOV A, @R0
MOV @R1, A
DEC R0
DEC R1
DJNZ R2,LBL

END