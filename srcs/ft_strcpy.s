section .text

global ft_strcpy

; rdi = dest & rsi = src

ft_strcpy:
	mov rax, 0

ft_strcpy_engine:
	mov	dl, byte [rsi + rax]
	mov	byte [rdi + rax], dl
	cmp	dl, 0
	jz	ft_strcpy_end
	inc	rax
	jmp	ft_strcpy_engine

ft_strcpy_end:
	mov	rax, rdi
	ret
