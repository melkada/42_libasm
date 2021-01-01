NAME = libasm.a
HEADER = srcs/libasm.h

CC = gcc
CFLAGS = -Wall -Werror -Wextra
NASM = nasm
NASMFLAGS = -f elf64

SRCS = ./srcs/ft_strlen.s\
       ./srcs/ft_strcpy.s

OBJS = $(SRCS:.s=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)
%.o:		%.s
			$(NASM) $(NASMFLAGS) $< -o $@
clean:
		rm -rf $(OBJS)
fclean:
		rm -rf $(NAME) a.out
re:		fclean all

.PHONY:		all clean fclean re