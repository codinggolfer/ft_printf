NAME = libftprintf.a

FILES = ft_printf.c \

FtoO = $(FILES:.c=.o)

CC		=	cc
RM		=	rm -f
CFLAGS	=	-Wall -Wextra -Werror

LDR	=	libft
LFL	=	libft.a

all:	$(NAME)

$(NAME):	$(LDR) $(FtoO)
		ar rcs $(NAME) $(FtoO)

libft:
	@make -C $(LDR)
	@cpy $(LDR) $(LFL) .
	@mv $(LFL) $(NAME)

clean:
	$(RM) $(FtoO)
	@make -C $(LDR) fclean

fclean:
	$(RM) $(NAME)

re:	flean all

.PHONY: all clean fclean re libft