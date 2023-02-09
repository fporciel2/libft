# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fporciel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/08 17:28:18 by fporciel          #+#    #+#              #
#    Updated: 2023/02/09 15:29:23 by fporciel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -c
SOURCES = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_toloer.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c libft.h
OBJECTS = $(SOURCES: .c = .o)
PREFIX = ./libft

$(NAME): $(OBJECTS)
	ar rcs $@ $ˆ

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $<

install:
	mkdir -p $(PREFIX)/lib
	mkdir -p $(PREFIX)/include
	install libft.a $(PREFIX)/lib
	install libft.h $(PREFIX)/include

clean:
	rm -f $(OBJECTS)
	rm -rf $(PREFIX)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, install, clean, fclean, re
