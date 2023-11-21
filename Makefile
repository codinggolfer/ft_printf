NAME = libftprintf.a

FILES = ft_printf.c \
		ft_printstr.c \
		ft_print_number.c \
		print_unint.c \
		address_printer.c \
		hex_printer.c

FtoO = $(FILES:.c=.o)

CC		=	cc
RM		=	rm -f
CFLAGS	=	-Wall -Wextra -Werror

LDR	=	libft
LFL	=	libft.a

all:	$(NAME)

$(NAME):	libft $(FtoO)
		ar -r $(NAME) $(FtoO)

%.o: %.c
	$(CC) $(CFLAGS) -c $?

libft:
	@make -C $(LDR)
	@cp $(LDR)/$(LFL) .
	@mv $(LFL) $(NAME)

clean:
	$(RM) $(FtoO)
	@make -C $(LDR) fclean

fclean:
	$(RM) $(NAME)

re:	flean all

.PHONY: all clean fclean re libft