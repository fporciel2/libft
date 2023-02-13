# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fporciel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/09 17:20:25 by fporciel          #+#    #+#              #
#    Updated: 2023/02/13 10:13:05 by fporciel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re bonus
.DEFAULT_GOAL := $(NAME)
NAME := libft.a
SRCS := $(filter-out ft_lst%.c, $(wildcard *.c))
BONUSSRCS := $(wildcard ft_lst*.c)
HEADERS := $(wildcard *.h)
OBJS := $(patsubst %.c,%.o,$(SRCS))
BONUSOBJS := $(patsubst %.c,%.o,$(BONUSSRCS))
CC := gcc
CFLAGS := -Wall -Wextra -Werror -c

$(NAME): $(OBJS) $(HEADERS)
	ar rcs $@ $^

all: $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) $^

bonus: $(BONUSOBJS)
	ar rcs $(NAME) $<

clean:
	rm -f $(OBJS) $(BONUSOBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

