NAME = libftprintf.a

FILES = ft_printf.c \
		ft_print_number.c \
		print_unint.c \
		address_printer.c \
		hex_printer.c \
		ft_itoa.c

FtoO = $(FILES:.c=.o)

CC		=	cc
RM		=	rm -f
CFLAGS	=	-Wall -Wextra -Werror

all:	$(NAME)

$(NAME):	$(FtoO)
		ar rcs $(NAME) $(FtoO)

%.o: %.c
	$(CC) $(CFLAGS) -c $?

clean:
	$(RM) $(FtoO)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean