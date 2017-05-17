# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/22 18:35:41 by ilarbi            #+#    #+#              #
#    Updated: 2017/05/17 18:47:17 by ilarbi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS= -c -Wall -Wextra -Werror
INC=utils/utils.h  
SRC= ft_parse.c \
	 ft_convert.c \
	 ft_printf.c
OBJ= ft_parse.o \
	 ft_convert.o \
	 ft_printf.o
GARBAGE= $(addprefix libft/,  ft_atoistr.o   \
		 ft_init.o   \
		 ft_strjoin_free.o   \
		 ft_itoa.o   \
		 ft_lstmap.o   \
		 ft_lstadd.o   \
		 ft_lstdel.o   \
		 ft_lstiter.o   \
		 ft_lstdelone.o   \
		 ft_lstnew.o   \
		 ft_strsplit.o   \
		 ft_strtrim.o   \
		 ft_strjoin.o   \
		 ft_strsub.o   \
		 ft_strmapi.o   \
		 ft_strmap.o   \
		 ft_striteri.o   \
		 ft_striter.o   \
		 ft_putnbr_fd.o   \
		 ft_putendl_fd.o   \
		 ft_putstr_fd.o   \
		 ft_putchar_fd.o   \
		 ft_putendl.o   \
		 ft_isdigit.o   \
		 ft_isalpha.o   \
		 ft_isalnum.o   \
		 ft_tolower.o   \
		 ft_toupper.o   \
		 ft_strlen.o   \
		 ft_strcmp.o   \
		 ft_isprint.o   \
		 ft_memset.o   \
		 ft_memcpy.o   \
		 ft_memccpy.o   \
		 ft_memchr.o   \
		 ft_memcmp.o   \
		 ft_memmove.o   \
		 ft_memalloc.o   \
		 ft_memdel.o   \
		 ft_putnbr.o   \
		 ft_putchar.o   \
		 ft_putstr.o   \
		 ft_atoi.o   \
		 ft_isascii.o   \
		 ft_strncmp.o   \
		 ft_strdup.o   \
		 ft_strcpy.o   \
		 ft_strncpy.o   \
		 ft_strcat.o   \
		 ft_strncat.o   \
		 ft_strlcat.o   \
		 ft_strstr.o   \
		 ft_strnstr.o   \
		 ft_strchr.o   \
		 ft_strrchr.o   \
		 ft_bzero.o   \
		 ft_strnew.o   \
		 ft_strdel.o   \
		 ft_strclr.o   \
		 ft_strequ.o   \
		 ft_strnequ.o   \
		 ft_isspace.o   \
		 ft_swap.o) \
		 $(addprefix utils/, ft_isflag.o  ft_iswidth.o  ft_islen.o  ft_istype.o  ft_checkforflags.o  ft_checkforwidth.o  ft_checkforlen.o ft_printformat.o)
SUBDIR=libft utils
.PHONY: $(SUBDIR) all
NAME= libftprintf.a
LIB= libft/libft.a utils/ft_printf.a

all: $(NAME) 
$(NAME): $(OBJ) $(GARBAGE)
	ar rc $(NAME) $^	
$(OBJ): | $(SUBDIR) $(INC)
	gcc $(CFLAGS) -I $(INC) $(SRC)
$(SUBDIR): 
	$(MAKE) -C $@
utils: libft
clean: 
	rm -f $(OBJ)
	rm -f $(GARBAGE)
fclean: clean
	rm -rf $(LIB) $(NAME)
re: fclean all
