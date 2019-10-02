.586
.model flat,stdcall
option casemap:none
;include windows.inc
include msvcrt.inc
include kernel32.inc
includelib msvcrt.lib
includelib kernel32.lib
.data
text    db 512 dup (0)  ;вводимый текст
msg     db 'Enter text: ',0
msg2    db 'New text: ',0
.code
;макрос вывода строки на экран
outstr  macro s
    push offset s   ;передать функции адрес строки
    call crt_printf ;вывести строку
    add esp,4       ;скорректировать указатель стека
endm
_start:
    outstr msg      ;вывести приглашение ввести текст
    invoke crt_gets,offset text ;ввод текста
    lea esi,text        ;начало строки
    call replace        ;удалить точкидо первой запятой
    outstr msg2     ;вывести сообщение
    outstr text     ;вывести сообщение
    invoke crt__getch   ;ожидание нажатия любой клавиши
    invoke ExitProcess,0    ;выход
;процедура замены многоточия одной точкой
;esi - адрес строки
replace proc
    mov edi,esi ;адрес строки
lp: lodsb       ;взять очередной символ
    cmp al,' '  ;если не пробел
    jnz save    ;то сохранить
    cmp al,[esi];если не два пробела подряд
    jnz save    ;то сохранить
    inc esi     ;если два пробеда, один пропустить
save:
    stosb       ;сохранить символ
    cmp al,0    ;если это был не конец строки
    jnz lp      ;продолжить работу
    ret         ;выйти из подпрограммы
replace endp
end _start
end