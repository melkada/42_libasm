section .text

global ft_strcpy

; rdi = dest & rsi = src

ft_strcpy:
	push rcx
	mov rcx, 0

ft_strcpy_engine:
	cmp	[rsi + rcx], byte 0
	jz	ft_strcpy_end
	mov	[rdi], [rsi]
	inc	rcx
	jmp	ft_strcpy_engine

ft_strcpy_end:
	mov	rax, rdi
	pop	rcx
	ret
