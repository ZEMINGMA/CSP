;���ݶ��еĶ�������
;section .data
;string db "?????????????????"          ;; string used for comparison, e.g., "ABC abc"
;slength equ $-string
;cmpstr db 'ABC'
;cmpslength equ $-cmpstr 
;****begin your code here****
;�����������eax�Ĵ�����

sub eax,eax
mov ecx,slength
mov edx,string
mov edi,cmpstr
dec edx

read:      ;stringָ�����ζ�ȡ
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
;���һ��eax++
;****end your code here****
;�����������eax�е���ֵ������Ҫʵ��
;call print_eax
;jmp quit