section .text

global	ft_strcmp

; rdi = char *s1 | rsi = char *s2

ft_strcmp:
	mov	rax, 0

ft_strcmp_engine:
	mov	dl, byte [rsi + rax]
	mov	cl, byte [rdi + rax]
	cmp	byte dl, 0
	jz	ft_strcmp_end
	cmp	dl, cl
	jne	ft_strcmp_end
	inc	rax
	jmp	ft_strcmp_engine

ft_strcmp_end:
	sub	cl, dl
	movsx	rax, cl
	ret
