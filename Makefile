NAME = libasm.a

CC = clang
CFLAGS = -Wall -Werror -Wextra
NASM = nasm
NASMFLAGS = -f elf64

SRCS = ./srcs/ft_strlen.s\
       ./srcs/ft_strcpy.s\
       ./srcs/ft_strcmp.s\
       ./srcs/ft_strdup.s\
       ./srcs/ft_write.s\
	./srcs/ft_read.s

OBJS = $(SRCS:.s=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			@ar rcs $(NAME) $(OBJS)
			@echo "----- Finished -----"

%.o:		%.s
			@$(NASM) $(NASMFLAGS) $< -o $@

tests:		$(NAME)
			@$(CC) $(CFLAGS) test.c $(NAME)
			@./a.out

clean:
		@rm -rf $(OBJS) $(TEST_OBJS)

fclean:		clean
		@rm -rf $(NAME) a.out

re:		fclean all

.PHONY:		all clean fclean re tests
