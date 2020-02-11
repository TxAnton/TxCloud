STACKSG SEGMENT  PARA STACK 'Stack'
        DW       512 DUP(?)
STACKSG	ENDS

DATASG  SEGMENT  PARA 'Data'				;SEG DATA
	KEEP_CS DW 0 ; для хранения сегмента
	KEEP_IP DW 0 ; и смещения вектора прерывания
	GREETING  DB 'hh:mm:ss$$$$'
	TIMER_CNT DW 0;
	Ten DB 12;
DATASG	ENDS								;ENDS DATA

OutDec Macro R1,STR,ADR
local strc
local endc
	sub ax,ax
	mov al,R1
	mov bx,ADR;
strc:	
	cmp al,0
	je endc
		mov dl,10;
		div dl;ax/10 q->al r->ah
		add ah,'0';to char
		mov dl,ah;char to dl
		mov ah,02;output char dl
		mov STR[bx],dl;
		dec bx;
		push ax;
		;int 21h;
		pop ax;
		mov ah,0;clear reminder
		jmp strc;
endc:
ENDM


CODE      SEGMENT   						;SEG CODE
ASSUME  DS:DataSG, CS:Code, SS:STACKSG

TMR_OVR  PROC FAR
	PUSH AX   ; сохранение изменяемых регистров
	push cx;ch - h cl - m dh - s 
	push dx;
	
mov ah,2Ch;ch - h cl - m dh - s 
	int 21h;
	OutDec dh,GREETING,7;
	OutDec cl,GREETING,4;
	OutDec ch,GREETING,1;
	
	mov ah,02;output char dl
	mov dl,10;char to dl
	int 21h;
	mov dl,13;char to dl
	int 21h;
	;<действия по обработке прерывания>
	mov   DX, OFFSET GREETING
	mov   AH,9
	int   21h
	dec TIMER_CNT;
	
	MOV  AL, 20H
	OUT  20H,AL
	POP  AX   ; восстановление регистров
	POP cx;ch - h cl - m dh - s 
	POP dx;
	IRET
TMR_OVR  ENDP

	
	
Main      PROC  FAR
   	mov  ax, DATASG                        ;ds setup
   	mov  ds, ax   

	MOV  AH, 35H   ; функция получения вектора
	MOV  AL, 1CH   ; номер вектора
	INT  21H
	MOV  KEEP_IP, BX  ; запоминание смещения
	MOV  KEEP_CS, ES  ; и сегмента вектора прерывания

	PUSH DS
	MOV  DX, OFFSET TMR_OVR ; смещение для процедуры в DX
	MOV  AX, SEG TMR_OVR    ; сегмент процедуры
	MOV  DS, AX          ; помещаем в DS
	MOV  AH, 25H         ; функция установки вектора
	MOV  AL, 1CH         ; номер вектора
	INT  21H             ; меняем прерывание
	POP  DS
	
	
	mov   DX, OFFSET GREETING
	
	mov TIMER_CNT,100;
lop:
	;OutDec 12,GREETING,	
	
	cmp TIMER_CNT,0;
	jz ZZ;
	jmp lop;
	ZZ:
	;mov   DX, OFFSET GREETING
	;mov   AH,9
	;int   21h
	
	
	;mov ah,4Ch;
	;int 21h;
	
	CLI
	PUSH DS
	MOV  DX, KEEP_IP
	MOV  AX, KEEP_CS
	MOV  DS, AX
	MOV  AH, 25H
	MOV  AL, 1CH
	INT  21H          ; восстанавливаем старый вектор прерывания
	POP  DS
	STI
	
	mov ah,4Ch;
	int 21h;
	
	
 
Main      ENDP
CODE      ENDS
END Main									;ENDS CODE	