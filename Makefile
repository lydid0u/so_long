NAME    = so_long

CC              = clang

CFLAGS  = -Wall -Wextra -Werror -g3

RM              = rm -f

PRINTF        = ft_printf

FT_PRINTF    = ft_printf/libftprintf.a

SRC     = so_long.c ./parsing/map_checker.c ./parsing/map_checker2.c ./parsing/map_checker3.c ./parsing/flood_fill.c ./code_mlx/new_windows.c ./code_mlx/bonus.c ./code_mlx/movement.c ./code_mlx/utils.c ./code_mlx/copy.c ./code_mlx/tea.c ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c

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
