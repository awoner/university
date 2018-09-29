.model small

Outputnum Macro 
    	local @plus
    	local @dvsn
    	local @vivod
   	push cx
    	mov cx, ax
    	cmp ax, 0
  	jns @plus
  	mov ah, 02h ;Symbol output function
  	mov dl, '-'
  	int 21h
  	neg cx
    	mov ax, cx
   	@plus: 
		xor cx, cx
    		mov bx, 10
   	@dvsn:
		xor dx, dx
    		div bx
    		push dx
    		inc cx
    		cmp ax, 0
    		jne @dvsn
     	 	mov ah, 02h
   	@vivod:
	 	pop dx
    		add dl, 30h
    		int 21h
  	loop @vivod  
    		mov dl, ' '
    		int 21h
    		pop cx
endm  

Endline Macro
    	push ax
    	push dx
    	mov ah, 02h
    	mov dl, 0Dh
    	int 21h
    	mov dl, 0Ah
    	int 21h
    	pop dx
    	pop ax
endm

Processarray Macro arr, size
	local @loop1
    	local @loop2
   	local @outputElem
   	mov cx, size
    	mov si, 0
	mov bx, size
    	@loop1:
		mov bx, cx
        	push cx
        	mov cx, size
        	@loop2:
        		mov ax, arr[si]
        		adc si, 2
        		cmp cx, bx
        		jne @outputElem
        		mov bx, 2
        		imul bx
        		@outputElem:
			push bx
        		Outputnum
			pop bx
        	loop @loop2
    		pop cx    
		;pop bx
    		Endline
    	loop @loop1
endm

Endpr macro 
    	mov ax, 4c00h
    	int 21h
endm

.stack 100h
.data
	dimension dw 5
    	arr dw 25 dup(1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25)

.code
main:
	mov ax, @data
	mov ds, ax

	Processarray arr, dimension 
    	Endpr
end main