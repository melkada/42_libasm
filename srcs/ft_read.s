section .text

extern __errno_location

global ft_read

ft_read:
	mov	rax, 0x0
	syscall
	cmp rax, 0
	jl ft_read_err
	ret

ft_read_err:
	neg rax
	mov rdx, rax
	call __errno_location
	mov [rax], rdx
	mov rax, -1
	ret