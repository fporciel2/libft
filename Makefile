# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fporciel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/09 17:20:25 by fporciel          #+#    #+#              #
#    Updated: 2023/02/09 17:21:08 by fporciel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re
.DEFAULT_GOAL := $(NAME)
NAME := libft.a
SRCS := $(wildcard *.c)
HEADERS := $(wildcard *.h)
OBJS := $(patsubst %.c,%.o,$(SRCS))
CC := gcc
CFLAGS := -Wall -Wextra -Werror -c

$(NAME): $(OBJS) $(HEADERS)
	ar rcs $@ $^

all: $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) $^

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

