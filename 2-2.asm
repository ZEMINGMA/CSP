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
mov edx,string
mov edi,cmpstr
dec edx

read:      ;string指针依次读取
 cmp ecx,0
    je end
    
 dec ecx 
    inc edx
    mov bl,[edi]
    
    cmp [edx],bl
    je next1
    add bl,0x20
    cmp [edx],bl
    je next1  

    
    jmp read

next1:     
 cmp ecx,0
    je end
    
 dec ecx
    inc edx
    mov bl,[edi+1]
    
    
    cmp [edx],bl
    je next2
    add bl,0x20
    cmp [edx],bl
    je  next2

    jmp read

next2:
 cmp ecx,0
    je end
    
 dec ecx
    inc edx
    mov bl,[edi+2]
    
    cmp [edx],bl
    je right
    add bl,0x20
    cmp [edx],bl
    je  right
    
    jmp read
    
right:
    inc eax
    jmp read
    
end:
 add eax,2
;如果一样eax++
;****end your code here****
;后续程序输出eax中的数值，不需要实现
;call print_eax
;jmp quit