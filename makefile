
SRC		= sources/*.c getnextline/*.c
BNS_SRC	= bonus_sources/*.c

OBJS	= ${SRC:.c=.o}
BNS_OBJ	= ${BNS_OBJ:.c=.o}

CC		= gcc
CFLAGS	= -Werror -Wall- Wextra -g #-03 -fsamitize=address
RM		= rm -rf
NAME	= pipex
LIBS	= libft/libft.a

all:		${NAME}

${NAME}:	${OBJS}
					make -C libft
					${CC} ${CFLAGS} ${OBJS} ${LIBS} -o ${NAME}

clean:
					${RM} ${OBJS}

fclean:		clean
					make -C libft fclean
					${RM} ${NAME}

re:			fclean all

bonus:
					make -C libft
					${CC} ${CFLAGS} ${BNS_OBJ} ${LIBS} -o ${NAME}

.PHONY: clean all fclean re