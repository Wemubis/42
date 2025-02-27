# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wemubis_ <wemubis_@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/25 18:05:58 by wemubis_          #+#    #+#              #
#    Updated: 2022/07/28 20:27:32 by wemubis_         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
AR = ar
INCL = includes/ft.h
CCFLAGS = -Wall -Wextra -Werror -I $(INCL)
SRC = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c
NAME = libft.a
OBJ = $(SRC:%.c=%.o)


all : $(NAME)

$(NAME) : $(OBJ)
	$(AR) rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o : %.c
	$(CC) -o $@ -c $< $(CCFLAGS)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
