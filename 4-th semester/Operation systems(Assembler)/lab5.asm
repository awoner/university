	; ����������� ������ 5. ��������� ��������������  
	; �������:   ��������� ������ �������, ��-61, 10.04.2018
	; ������� �����������
	; ���������� ���� String  ������	Simvol
Data segment 
String db "APNMOETKON $"  
	;0Dh � ������ ���������� ������� (Carriage Return),
	;0Ah - ������ ����������� �����
CR_LF	db 0dh,0ah, '$'
Data ends
Code segment
Assume cs:Code,ds:Data
First:
mov ax, Data
mov ds, ax
mov ah, 40h			; ϳ��������  � 
mov bx, 1			; ��������� 
mov cx, 12			; ��������� ����� String
lea   dx, String		; �������� DOS
;mov dx, offset String
int    21h			
mov ah, 9h			; ��������� �� �����
mov dx, offset CR_LF		; ����������� ������� ��  
int 21h				; ��������� �����
				; ��������� �������  � ������� ����� 
	
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

mov ah, 40h			; ϳ��������        
mov bx, 1			; � ���������
mov cx, 10			; ������������� ����� 
lea   dx, String		; �������� DOS
int   21h			
mov ah, 4ch			; ����������              
int   21h			; � ���������� DOS
Code ends			
end First
