NAME	= libft.a
SRC		= ft_atoi.c ft_calloc.c ft_isalpha.c ft_isdigit.c ft_memchr.c  ft_memcpy.c  ft_memset.c  ft_strchr.c  ft_strjoin.c ft_strlcpy.c ft_strncmp.c ft_strrchr.c ft_substr.c ft_bzero.c   ft_isalnum.c ft_isascii.c ft_isprint.c ft_memcmp.c ft_memmove.c ft_strdup.c ft_strlcat.c ft_strlen.c ft_strnstr.c ft_strtrim.c ft_toupper.c ft_tolower.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
OBJC	= ${SRC:.c=.o}
FLAGS	= -Wall -Werror -Wextra
CC		= gcc ${FLAGS}
RM		= rm -f

.o:.c
	${CC} -c ${<} -o ${<:.c=.o}

${NAME}: ${OBJC}
	ar rc ${NAME} ${OBJC}
	ranlib ${NAME}

all: ${NAME}

clean:
	${RM} ${OBJC}

fclean: clean
	${RM} ${NAME}

re: fclean all

