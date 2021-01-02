section .text

extern ft_strlen
extern ft_strcpy
extern malloc

global ft_strdup

ft_strdup:
	mov	rsi, rdi
	push	rsi
	call	ft_strlen
	inc	rax
	mov	rdi, rax
	call	malloc
	cmp	rax, 0
	je	ft_strdup_end
	mov	rdi, rax
	pop	rsi
	call	ft_strcpy

ft_strdup_end:
	ret
