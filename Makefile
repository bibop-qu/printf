#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/06 15:15:27 by basle-qu          #+#    #+#              #
#    Updated: 2015/03/31 15:39:02 by basle-qu         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

SRCS = ft_atoi.c \
ft_bzero.c \
ft_isalnum.c \
ft_isalpha.c \
ft_isascii.c \
ft_isdigit.c \
ft_isprint.c \
ft_itoa.c \
ft_memalloc.c \
ft_memcpy.c \
ft_memccpy.c \
ft_memchr.c \
ft_memcmp.c \
ft_memdel.c \
ft_memmove.c \
ft_memset.c \
ft_putchar.c \
ft_putchar_fd.c \
ft_putendl.c \
ft_putendl_fd.c \
ft_putnbr.c \
ft_putnbr_fd.c \
ft_putstr.c \
ft_putstr_fd.c \
ft_strcat.c \
ft_strchr.c \
ft_strclr.c \
ft_strcmp.c \
ft_strcpy.c \
ft_strdel.c \
ft_strdup.c \
ft_strequ.c \
ft_striter.c \
ft_striteri.c \
ft_strjoin.c \
ft_strlen.c \
ft_strmap.c \
ft_strmapi.c \
ft_strncat.c \
ft_strncmp.c \
ft_strncpy.c \
ft_strnequ.c \
ft_strnew.c \
ft_strnstr.c \
ft_strrchr.c \
ft_strstr.c \
ft_strsub.c \
ft_strtrim.c \
ft_tolower.c \
ft_toupper.c \
ft_strlcat.c \
ft_strsplit.c \
ft_putaddr.c \
ft_putstring.c \
ft_putlnbr.c \
ft_base.c \
ft_putulnbr.c \
ft_printf.c \
flags.c \
option.c \
modifier.c \
special.c \

OBJ = $(SRCS:.c=.o)
NAME = libftprintf.a
CFLAG = -Wall -Wextra -Werror

.PHONY: all test clean fclean re

all: $(NAME)

$(NAME):
	@gcc -c $(CFLAG) $(SRCS)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean $(NAME)
