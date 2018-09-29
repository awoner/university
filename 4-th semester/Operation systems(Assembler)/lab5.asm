	; Лабораторна робота 5. «Системне програмування»  
	; Виконав:   Артамонов Олексій Юрійович, ТВ-61, 10.04.2018
	; Команди пересилання
	; Заповнення поля String  умістом	Simvol
Data segment 
String db "APNMOETKON $"  
	;0Dh – символ повернення каретки (Carriage Return),
	;0Ah - символ переведення рядка
CR_LF	db 0dh,0ah, '$'
Data ends
Code segment
Assume cs:Code,ds:Data
First:
mov ax, Data
mov ds, ax
mov ah, 40h			; Підготовка  і 
mov bx, 1			; виведення 
mov cx, 12			; вихідного рядка String
lea   dx, String		; засобами DOS
;mov dx, offset String
int    21h			
mov ah, 9h			; Виведення на екран
mov dx, offset CR_LF		; переведення курсора на  
int 21h				; наступний рядок
				; Розміщення символу  у позиції рядка 
	
;APNMOEKTON
mov al, string 
mov ah, string[si+7] 
mov string[si], ah 
mov string[si+7] , al
;KPNMOEATON
mov al, string[si+1] 
mov ah, string[si+4] 
mov string[si+1], ah 
mov string[si+4] , al
;KONMPEATON
mov al, string[si+2] 
mov ah, string[si+3] 
mov string[si+2], ah 
mov string[si+3] , al
;KOMNPEATON
mov al, string[si+3] 
mov ah, string[si+4] 
mov string[si+3], ah 
mov string[si+4] , al
;KOMPNEATON
mov al, string[si+4] 
mov ah, string[si+8] 
mov string[si+4], ah 
mov string[si+8] , al
;KOMPOEATNN
mov al, string[si+5] 
mov ah, string[si+8] 
mov string[si+5], ah 
mov string[si+8] , al
;KOMPONATEN
mov al, string[si+6] 
mov ah, string[si+8] 
mov string[si+6], ah 
mov string[si+8] , al
;KOMPONETAN
mov al, string[si+7] 
mov ah, string[si+9] 
mov string[si+7], ah 
mov string[si+9] , al
;KOMPONENTA

mov ah, 40h			; Підготовка        
mov bx, 1			; і виведення
mov cx, 10			; результуючого рядка 
lea   dx, String		; засобами DOS
int   21h			
mov ah, 4ch			; Повернення              
int   21h			; у середовище DOS
Code ends			
end First
