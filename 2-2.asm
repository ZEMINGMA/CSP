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
mov edx, string
dec edx

mov esi,string
mov

;���һ��eax++
;****end your code here****
;�����������eax�е���ֵ������Ҫʵ��
;call print_eax
;jmp quit