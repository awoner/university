MODEL tiny;
.DATA

k db -8
db -10
dw -10
db 15
db -15
db 0feh
db 0b12h
db 01100110b
dw 10001011b
dw 13
dw '0f'
dw 0245h
dw 0101b
dw 0a32h
dw 0f45h
dw 55
dw 0c47h
dw 0afh
dd 4, 8, 0Ah, 0ffh
dw -15
db -16
dw -16
r db 127
q db -127
t1 dw -127
db 128
i db -128
i1 dw -128
w db -129
p dw -129
db 255
db -255
db 256
dw 256 
q dw -32768
rr1 df -32768
zz1 dd -32768
j dw 32767
a dw 65535
dw -65535
dd -65535
dd -2147583648
dd -2147583647
dq -2147583648
dq -2147583647
ll dw 10101000b
ff db 12, "¹", 0b12h
f1 dw 12, "¹", 0b12h
g5 db 0101b
ss dw 00000101b
xx dq 26
c1 dw 0f45h, 55, 66
a1 db -113
aa2 dw -133
ii db -159
i11 dw -159
s1 db -89
ss5 dw -89
s2 db -92
ff2 dw -92
s3 dw -231
a11 db "sigma"
a22 dw e301h
a33 db 12
a55 dw offset a11
a66 dw 13
gg dw -123
hh dw -9
end