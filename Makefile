NAME    = so_long

CC              = clang

CFLAGS  = -Wall -Wextra -Werror -g3

RM              = rm -f

PRINTF        = ft_printf

FT_PRINTF    = ft_printf/libftprintf.a

SRC     = ./srcs/solong.c ./srcs/map_checker.c ./srcs/map_checker2.c flood_fill.c main.c ./code_mlx/new_windows.c ./GNL/get_next_line.c ./GNL/get_next_line_utils.c

OBJ    = ${SRC:.c=.o}

all : ${NAME}

${NAME} : ${OBJ}
	${MAKE} -C ${PRINTF}
	${CC} ${OBJ} ./minilibx-linux/libmlx.a ./minilibx-linux/libmlx_Linux.a -lX11 -lXext -L -lX11 -o ${NAME} ${FT_PRINTF}

clean :
	${RM} ${OBJ}

fclean : clean
	${RM} ${NAME}

re : fclean all

.PHONY : all clean fclean re
