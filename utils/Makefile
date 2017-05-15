# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/14 19:21:35 by ilarbi            #+#    #+#              #
#    Updated: 2017/05/14 23:14:26 by ilarbi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS= -c -Wall -Wextra -Werror
NAME= ft_printf.a
SRC= ft_isflag.c \
	 ft_iswidth.c \
	 ft_islen.c \
	 ft_istype.c \
	 ft_checkforflags.c \
	 ft_checkforwidth.c \
	 ft_checkforlen.c \
	 ft_printformat.c
OBJ= ft_isflag.o \
	 ft_iswidth.o \
	 ft_islen.o \
	 ft_istype.o \
	 ft_checkforflags.o \
	 ft_checkforwidth.o \
	 ft_checkforlen.o \
	 ft_printformat.o

all: $(NAME)
$(NAME): $(OBJ)
	ar rc $(NAME) $^
$(OBJ):
	gcc $(CFLAGS) $^ $(SRC)
clean:
	rm -f $(OBJ)
fclean: clean
	rm -rf $(NAME)
re: fclean all
