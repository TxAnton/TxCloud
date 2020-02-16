TESTPC	SEGMENT
	ASSUME CS:TESTPC, DS:TESTPC, ES:NOTHING, SS:NOTHING
	ORG 100H
	
START:	JMP BEGIN
;data
s1 db 'PS			FF',0DH,0AH,'$'
s2 db 'PC/XT		FE,FB',0DH,0AH,'$'
s3 db 'AT			FC',0DH,0AH,'$'
s4 db 'PS2-30		FA',0DH,0AH,'$'
s5 db 'PS2-50-60	FC',0DH,0AH,'$'
s6 db 'PS2-300		F8',0DH,0AH,'$'
s7 db 'PCjr			FD',0DH,0AH,'$'
s8 db 'PC Convertible F9',0DH,0AH,'$'
s8 db 'XZ',0DH,0AH,'$'




STRING DB 'Some text       ',0DH,0AH,'$'
;procedures

BEGIN:	
	mov ax,0F000:0FFFEh
	
	mov DX,offset STRING
	mov AH,09h
	int 21h
	
	xor AL,AL
	mov AH,4Ch
	int 21h
TESTPC ENDS
	END START
	