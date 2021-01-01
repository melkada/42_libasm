section .text

global ft_strlen

ft_strlen:
	push	rcx
	mov	rcx, 0

ft_strlen_engine:
	cmp	[rdi + rcx], byte 0
	jz	ft_strlen_end
	inc	rcx
	jmp	ft_strlen_engine

ft_strlen_end:
	mov	rax, rcx
	pop	rcx
	ret
