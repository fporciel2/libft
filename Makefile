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

NAME := libft.a
SRCS := $(wildcard *.c)
HEADERS := $(wildcard *.h)
OBJS := $(wildcard *.o)
CC := gcc
CFLAGS := -Wall -Wextra -Werror -c

$(NAME): $(OBJS)
	ar rcs $@ $^

all:
	$(NAME)

$(OBJS): $(SRCS) $(HEADERS)
	$(CC) $(CFLAGS) $(SRCS)
