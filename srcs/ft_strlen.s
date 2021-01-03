section .text

global ft_strlen

ft_strlen:
	mov	rax, 0

ft_strlen_engine:
	cmp	byte [rdi + rax], 0
	je	ft_strlen_end
	inc	rax
	jmp	ft_strlen_engine

ft_strlen_end:
	ret
