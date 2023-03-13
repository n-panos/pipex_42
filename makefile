
SRC			= pipex.c parse_path.c utils.c
OBJS		= ${SRC:.c=.o}
NAME		= pipex

BNS_SRC		= bonus_sources/*.c
BNS_OBJ		= ${BNS_SRC:.c=.o}
BNS_NAME	= bonus_pipex

HEADER		= pipex.h
CC			= gcc
CFLAGS		= -Werror -Wall -Wextra -g #-03 -fsamitize=address
RM			= rm -rf
LIBS		= libft/libft.a

all:		${NAME}

${NAME}:	${OBJS}
					make -C libft
					${CC} ${CFLAGS} ${OBJS} ${LIBS} -o ${NAME}

clean:
					${RM} ${OBJS}
					${RM} ${BNS_OBJ}
					${RM} outfile

fclean:		clean
					make -C libft fclean

re:			fclean all

bonus:
					make -C libft
					${CC} ${CFLAGS} ${BNS_OBJ} ${LIBS} -o ${BNS_NAME}

.PHONY: clean all fclean re