

NAME		=	libftprintf.a

SRCS		=	ft_printf.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_putnbr.c \
		ft_putunsigned.c \
		ft_puthex.c \
		ft_putptr.c

OBJS		=	$(SRCS:.c=.o)

CC		=	cc

CFLAGS		=	-Wall -Wextra -Werror

AR		=	ar

ARFLAGS		=	rcs

RM		=	rm -f

all:		$(NAME)

$(NAME):	$(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean:		clean
	$(RM) $(NAME)

re:		fclean all

.PHONY: all clean fclean re
