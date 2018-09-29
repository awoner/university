;(a-b)/a + 1,	a > b
;25,		a = b
;(a-5)/b, 	a < b 

.MODEL small
.Stack 100h
Data segment
	a  dw  1
	b  dw  2
	x  dw  ?
	err_msg db 'Error! Division by zero.$'
Data ends

Code segment
	Assume cs:Code, ds:Data
main:	mov ax, Data
	mov ds, ax
	
	mov ax, a
	cmp ax, b
	jg @more	;ÿךשמ ZF=0 & SF=OF ב³כüרו
	jl @less	;ÿךשמ SF<>OF לוםרו

	xor ax, ax
	mov ax, 25
	mov x, ax
	jmp @otv


@more:
	xor ax, ax
	cmp a, 0
	je @err		;ÿךשמ ZF=1 המנ³גם‏÷
	mov ax, a
	sub ax, b
	cwd
	idiv a
	add ax, 1
	mov x, ax
	jmp @otv

@less:	xor ax, ax
	cmp b, 0
	je @err
	mov ax, a
	sub ax, 5
	cwd
	idiv b
	mov x, ax
	jmp @otv

@otv:	xor ax, ax
	mov ax, x
	push ax
	cmp ax, 0
	jns @plus	;ÿךשמ ZF=0 םולא÷ םףכÿ
	mov dl, '-'
	mov ah, 02h
	int 21h
	pop ax
	neg ax

@plus:	xor cx, cx
	mov bx, 10

@dvsn:	xor dx, dx
	idiv bx
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

@err:	mov dx, offset err_msg
	mov ah, 09h
	int 21h

@end:	mov ax, 4c00h
	int 21h
Code ends
end main