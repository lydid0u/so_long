/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_windows.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:23:24 by lboudjel          #+#    #+#             */
/*   Updated: 2023/09/27 18:16:42 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// int	destroy(t_jeu *jeu)
// {
// 	mlx_destroy_window(jeu->mlx_ptr, jeu->win_ptr);
// 	mlx_destroy_display(jeu->mlx_ptr);
// 	free(jeu->mlx_ptr);
// 	exit(0);
// 	return (0);
// }

int i = 0;

int	count_move(int keysym) // keysym = nom de touche
{
	if (keysym == 65361 || keysym == 65363 || keysym == 65364 || keysym == 65362 || keysym == 97 || keysym == 119 || keysym == 115 || keysym == 100)
	{
		i++;
		ft_printf("Move : %d %d\n", i, keysym);
	}
	return (0);
}

void	xpm_to_img(t_jeu *jeu)
{
	static int	width;
	static int	height;

	width = 64;
	height = 64;
	jeu->img_coin = mlx_xpm_file_to_image(jeu->mlx_ptr, "viande.xpm", &width,
			&height);
	jeu->img_wall = mlx_xpm_file_to_image(jeu->mlx_ptr, "arbre.xpm", &width,
			&height);
	jeu->img_exit = mlx_xpm_file_to_image(jeu->mlx_ptr, "door.xpm", &width,
			&height);
	jeu->img_floor = mlx_xpm_file_to_image(jeu->mlx_ptr, "floor.xpm", &width,
			&height);
	jeu->img_perso = mlx_xpm_file_to_image(jeu->mlx_ptr, "perso.xpm", &width,
			&height);
}

void	img_to_window(t_jeu *jeu)
{
	int	i;
	int	j;

	i = 0;
	while (jeu->map_p[i])
	{
		j = 0;
		while (jeu->map_p[i][j])
		{
			if (jeu->map_p[i][j] == 'C')
				mlx_put_image_to_window(jeu->mlx_ptr, jeu->win_ptr, jeu->img_coin, j
					* 64, i * 64);
			if (jeu->map_p[i][j] == '1')
				mlx_put_image_to_window(jeu->mlx_ptr, jeu->win_ptr, jeu->img_wall, j
					* 64, i * 64);
			if (jeu->map_p[i][j] == 'E')
				mlx_put_image_to_window(jeu->mlx_ptr, jeu->win_ptr, jeu->img_exit, j
					* 64, i * 64);
			if (jeu->map_p[i][j] == '0')
				mlx_put_image_to_window(jeu->mlx_ptr, jeu->win_ptr, jeu->img_floor,
					j * 64, i * 64);
			if (jeu->map_p[i][j] == 'P')
				mlx_put_image_to_window(jeu->mlx_ptr, jeu->win_ptr, jeu->img_perso,
					j * 64, i * 64);
			j++;
		}
		i++;
	}
}

int    disconnect(t_jeu *jeu)
{
    mlx_destroy_image(jeu->mlx_ptr, jeu->img_wall);
    mlx_destroy_image(jeu->mlx_ptr, jeu->img_floor);
    mlx_destroy_image(jeu->mlx_ptr, jeu->img_exit);
    mlx_destroy_image(jeu->mlx_ptr, jeu->img_perso);
    mlx_destroy_image(jeu->mlx_ptr, jeu->img_coin);
    mlx_destroy_window(jeu->mlx_ptr, jeu->win_ptr);
    mlx_destroy_display(jeu->mlx_ptr);
	free(jeu->mlx_ptr);
    exit(0);
}

int	ft_move(int keysym, t_jeu *jeu)
{
	if (keysym == 65307)
	{
		free_all(jeu);
		disconnect(jeu);
		exit(EXIT_SUCCESS);
	}
	if (keysym == 65363 || keysym == 100)
	{
		go_right(jeu);
	}
	if (keysym == 65361 || keysym == 97)
		go_left(jeu);
	if (keysym == 65362 || keysym == 119)
		go_up(jeu);
	if (keysym == 65364 || keysym == 115)
		go_down(jeu);
	printf("%d\n", jeu->coin);	
	ft_printf("number of steps : %d\n", jeu->steps);

	return (0);
}

// <- = 65361
// -> = 65363
// en bas : 65364
// en haut : 65362

// a : 97
// s : 115
// d : 100
// w : 119

void	go_right(t_jeu *jeu)
{
	jeu->steps++;
	if (jeu->map_p[jeu->x][jeu->y + 1] == 'E' && jeu->coin == 0)
	{
		free_all(jeu);
		disconnect(jeu);
		exit(EXIT_SUCCESS);
	}
	printf("go right :%d %d \n", jeu->x, jeu->y);
	if (jeu->map_p[jeu->x][jeu->y + 1] == '1' || jeu->map_p[jeu->x][jeu->y + 1] == 'E')
		return ;
	if (jeu->map_p[jeu->x][jeu->y + 1] == 'C')
	{
		jeu->coin--;
		jeu->map_p[jeu->x][jeu->y + 1] = '0';
	}
	mlx_put_image_to_window(jeu->mlx_ptr, jeu->win_ptr, jeu->img_floor, jeu->y * 64, jeu->x * 64);
	jeu->y = jeu->y + 1;
	mlx_put_image_to_window(jeu->mlx_ptr, jeu->win_ptr, jeu->img_perso, jeu->y * 64, jeu->x * 64);
}

void	go_left(t_jeu *jeu)
{
	jeu->steps++;
	if (jeu->map_p[jeu->x][jeu->y - 1] == 'E' && jeu->coin == 0)
	{
		free_all(jeu);
		disconnect(jeu);
		exit(EXIT_SUCCESS);
	}
	if (jeu->map_p[jeu->x][jeu->y - 1] == '1' || jeu->map_p[jeu->x][jeu->y - 1] == 'E')
		return ;
	if (jeu->map_p[jeu->x][jeu->y - 1] == 'C')
	{
		jeu->coin--;
		jeu->map_p[jeu->x][jeu->y - 1] = '0';
	}
	mlx_put_image_to_window(jeu->mlx_ptr, jeu->win_ptr, jeu->img_floor, jeu->y * 64, jeu->x * 64);
	jeu->y = jeu->y - 1;
	mlx_put_image_to_window(jeu->mlx_ptr, jeu->win_ptr, jeu->img_perso, jeu->y * 64, jeu->x * 64);
}

void	go_up(t_jeu *jeu)
{
	jeu->steps++;
	if (jeu->map_p[jeu->x - 1][jeu->y] == 'E' && jeu->coin == 0)
	{
		free_all(jeu);
		disconnect(jeu);
		exit(EXIT_SUCCESS);
	}
	if (jeu->map_p[jeu->x - 1][jeu->y] == '1' || jeu->map_p[jeu->x - 1][jeu->y] == 'E')
		return ;
	if (jeu->map_p[jeu->x - 1][jeu->y] == 'C')
	{
		jeu->coin--;
		jeu->map_p[jeu->x - 1][jeu->y] = '0';
	}
	mlx_put_image_to_window(jeu->mlx_ptr, jeu->win_ptr, jeu->img_floor, jeu->y * 64, jeu->x * 64);
	jeu->x = jeu->x - 1;
	mlx_put_image_to_window(jeu->mlx_ptr, jeu->win_ptr, jeu->img_perso, jeu->y * 64, jeu->x * 64);
}

void	go_down(t_jeu *jeu)
{
	jeu->steps++;
	if (jeu->map_p[jeu->x + 1][jeu->y] == 'E' && jeu->coin == 0)
	{
		free_all(jeu);
		disconnect(jeu);
		exit(EXIT_SUCCESS);
	}
	if (jeu->map_p[jeu->x + 1][jeu->y] == '1' || jeu->map_p[jeu->x + 1][jeu->y] == 'E')
		return ;
	if (jeu->map_p[jeu->x + 1][jeu->y] == 'C')
	{
		jeu->coin--;
		jeu->map_p[jeu->x + 1][jeu->y] = '0';
	}
	mlx_put_image_to_window(jeu->mlx_ptr, jeu->win_ptr, jeu->img_floor, jeu->y * 64, jeu->x * 64);
	jeu->x = jeu->x + 1;
	mlx_put_image_to_window(jeu->mlx_ptr, jeu->win_ptr, jeu->img_perso, jeu->y * 64, jeu->x * 64);
}

int	exit_and_leave(t_jeu *jeu)
{
		free_all(jeu);
		disconnect(jeu);
		exit(EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	static t_jeu	jeu = {0};

	if (argc == 2)
	{
		if (!(check_valid_name(argv[1])))
			return (0);
		if (!(create_map(argv[1], &jeu)))
			return (0);
		if (!(check_empty(&jeu)))
			return (0);
		jeu.map_p = copy_map(jeu.map);
		if (!(check_map(&jeu)))
			return (0);
		jeu.map_f = copy_map(jeu.map);
		flood_fill(jeu.x, jeu.y, &jeu);
		if (!(check_flood(&jeu)))
			return (0);
		jeu.mlx_ptr = mlx_init();
		if (!jeu.mlx_ptr)
			return (1);
		jeu.win_ptr = mlx_new_window(jeu.mlx_ptr, jeu.len * 64, jeu.nbr_ligne * 64, "mugiwara :D");
		if (!jeu.win_ptr)
			return (free(jeu.mlx_ptr), 1);
		xpm_to_img(&jeu);
		img_to_window(&jeu);
		
		mlx_hook(jeu.win_ptr, KeyRelease, KeyReleaseMask, &count_move, &jeu);
		
		mlx_key_hook(jeu.win_ptr, &ft_move, &jeu);
		printf("DASDSA AS %d\n", jeu.y);
		mlx_hook(jeu.win_ptr, DestroyNotify, StructureNotifyMask, &exit_and_leave, &jeu);
				
		mlx_loop(jeu.mlx_ptr);
		return (0);
	}
}
