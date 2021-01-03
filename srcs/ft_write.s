section .text

global ft_write

; rdi = fd - rsi = buf - rdx = count

ft_write:
	mov	rax, 0x1
	syscall
	ret

ft_write_end
