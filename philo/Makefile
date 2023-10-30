NAME	= philo

SRCS	= src/philo.c \
			src/utils.c \
			src/timers.c \
			src/init.c \
			src/free.c

CC 		= cc

CFLAGS	= -Wextra -Wall -Werror 

OBJS 	= $(SRCS:.c=.o)

HEADERS	= header/philo.h

all:${NAME}

%.o : %.c ${HEADERS} Makefile
	${CC} ${CFLAGS} -c $< -o $@ -I $(HEADERS)

${NAME}: ${OBJS}
	${CC} ${OBJS} -o ${NAME}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: clean re