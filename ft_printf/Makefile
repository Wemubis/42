NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rcs
RM = rm -f

SRCS = ft_printf.c ft_putchar.c ft_putnbr.c ft_putnbr_base.c \
	ft_putnbr_unsigned.c ft_putstr.c ft_strlen.c ft_putptr_base.c \

HEADER = ft_printf.h
OBJS =  $(patsubst %.c,%.o,$(SRCS))


.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

%.o: %.c Makefile $(HEADER)
	$(CC) $(CFLAGS) -I. -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
