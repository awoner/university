; Лабораторна робота 4 «Системне програмування»
; Виконав Артамонов О.Ю. гр.ТВ-61 Дата 24.04.2018
; Арифметичні команди
; Обчислення формули y = (2*c - d + 23)/(a/4 - 1)

Data segment 	
a dw 8 	      	
d dw 3	      	
c dw 11	      	
y dw ?	

remainder dw ?      
error_msg db "Error! Division by zero."
endl	db 0dh,0ah,'$'

Data ends    	

Code segment
Assume cs:Code, ds:Data

Main:
MOV ax, Data
mov ds,ax
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
mov ax,c 	
mov cx,2
imul cx 	
sbb ax,d 	
adc ax,23 	

mov bx,ax	
mov y,bx
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
mov ax,a
mov cx,4
cwd
idiv cx 	
sbb ax,1	

cmp ax,0
je @err
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
mov bx,ax
mov ax,y
cwd
idiv bx	 	
mov y,ax	
mov remainder,dx
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
push ax
cmp ax,0
jns @plus	
mov dl, '-'
mov ah, 02h 
int 21h
pop ax
neg ax
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
@plus:	xor cx, cx
	mov bx, 10

@dvsn:	xor dx, dx
	div bx
	push dx
	inc cx
	test ax, ax
	jnz short @dvsn 
	mov ah, 02h

@print: pop dx
	add dl, 30h 
	int 21h
	loop @print
	jmp @end

@err:	mov dx, offset error_msg
	mov ah, 09h
	int 21h

@end:	mov ax, 4c00h
	int 21h
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
Code ends
end Main

;tasm /la /zi lab6.asm
;tlink /x /v lab6.obj