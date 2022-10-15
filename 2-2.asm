;数据段中的定义数据
;section .data
;string db "?????????????????"          ;; string used for comparison, e.g., "ABC abc"
;slength equ $-string
;cmpstr db 'ABC'
;cmpslength equ $-cmpstr 
;****begin your code here****
;输出结果存放在eax寄存器中

sub eax,eax
mov ecx,slength
mov edx, string
dec edx

mov esi,string
mov

;如果一样eax++
;****end your code here****
;后续程序输出eax中的数值，不需要实现
;call print_eax
;jmp quit