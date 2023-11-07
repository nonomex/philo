NAME	= philo

SRCS	= src/philo.c \
			src/utils.c \
			src/timers.c \
			src/init.c \
			src/free.c \
			src/live.c

CC 		= cc

CFLAGS	= -Wextra -Wall -Werror -pthread -g3 -fsanitize=thread

OBJS 	= $(SRCS:.c=.o)

HEADERS	= header/philo.h

all:${NAME}

%.o : %.c ${HEADERS} Makefile
	${CC} ${CFLAGS} -c $< -o $@ -I $(HEADERS)

${NAME}: ${OBJS}
	${CC} $(CFLAGS) ${OBJS} -o ${NAME}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: clean re