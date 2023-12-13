NAME	= minishell

SRCS	= src/main.c \
			src/utils.c \
			src/parse.c \
			src/exec.c \
			src/ft_split.c \
			src/builtin/pwd.c \
			src/builtin/cd.c \
			src/isbuilt.c \
			src/builtin/exit.c \
			src/free.c

CC 		= cc

CFLAGS	= -Wextra -Wall -Werror -g3

LINK 	= -lreadline

OBJS 	= $(SRCS:.c=.o)

HEADERS	= header/minishell.h

all:${NAME}

%.o : %.c ${HEADERS} Makefile
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS}
	${CC} $(CFLAGS) ${OBJS} -o ${NAME} $(LINK)

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean re fclean
