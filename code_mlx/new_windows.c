/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_windows.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:23:24 by lboudjel          #+#    #+#             */
/*   Updated: 2023/09/25 21:11:20 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// int	destroy(t_mlx *mlx)
// {
// 	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
// 	mlx_destroy_display(mlx->mlx_ptr);
// 	free(mlx->mlx_ptr);
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

void	xpm_to_img(t_mlx *mlx)
{
	int	width;
	int	height;

	width = 64;
	height = 64;
	mlx->coin = mlx_xpm_file_to_image(mlx->mlx_ptr, "viande.xpm", &width,
			&height);
	mlx->wall = mlx_xpm_file_to_image(mlx->mlx_ptr, "arbre.xpm", &width,
			&height);
	mlx->exit = mlx_xpm_file_to_image(mlx->mlx_ptr, "door.xpm", &width,
			&height);
	mlx->floor = mlx_xpm_file_to_image(mlx->mlx_ptr, "floor.xpm", &width,
			&height);
	mlx->perso = mlx_xpm_file_to_image(mlx->mlx_ptr, "perso.xpm", &width,
			&height);
}

void	img_to_window(t_mlx *mlx, t_jeu *jeu)
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
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->coin, j
					* 64, i * 64);
			if (jeu->map_p[i][j] == '1')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->wall, j
					* 64, i * 64);
			if (jeu->map_p[i][j] == 'E')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->exit, j
					* 64, i * 64);
			if (jeu->map_p[i][j] == '0')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->floor,
					j * 64, i * 64);
			if (jeu->map_p[i][j] == 'P')
			{
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->perso,
					j * 64, i * 64);
				mlx->i = i;
				mlx->j = j;
			}
			j++;
		}
		i++;
	}
}

int    disconnect(t_mlx *mlx)
{
    mlx_destroy_image(mlx->mlx_ptr, mlx->wall);
    mlx_destroy_image(mlx->mlx_ptr, mlx->floor);
    mlx_destroy_image(mlx->mlx_ptr, mlx->exit);
    mlx_destroy_image(mlx->mlx_ptr, mlx->perso);
    mlx_destroy_image(mlx->mlx_ptr, mlx->coin);
    mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
    mlx_destroy_display(mlx->mlx_ptr);
    exit(0);
}

int	move(int keysym, t_mlx *mlx, t_jeu *jeu)
{
	if (keysym == 65307)
		disconnect(mlx);
	if (keysym == 65363 || keysym == 100)
	{

		go_right(mlx, jeu);
	}
	// if (keysym == 65361 || keysym == 97)
	// 	go_left;
	// if (keysym == 65362 || keysym == 119)
	// 	go_up
	// if (keysym == 65362 || keysym == 115)
	// 	go_down
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

void	go_right(t_mlx *mlx, t_jeu *jeu)
{
	(void) jeu;
	printf("%d %d ", mlx->i, mlx->j);

	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->perso, mlx->i + 64 , mlx->j);
	mlx->i = mlx->i * 64;
}

int	main(int argc, char **argv)
{
	static t_mlx	mlx = {0};
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
		free_map(jeu.map);
		free_map(jeu.map_f);
		mlx.mlx_ptr = mlx_init();
		if (!mlx.mlx_ptr)
			return (1);
		mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, jeu.len * 64, jeu.nbr_ligne * 64, "mugiwara :()");
		if (!mlx.win_ptr)
			return (free(mlx.mlx_ptr), 1);
	
		xpm_to_img(&mlx);
		img_to_window(&mlx, &jeu);
		mlx.j = mlx.j * 64;
		mlx_hook(mlx.win_ptr, KeyRelease, KeyReleaseMask, &count_move, &mlx);
		
		mlx_key_hook(mlx.win_ptr, &move, &mlx);
		mlx_hook(mlx.win_ptr, DestroyNotify, StructureNotifyMask, &disconnect, &mlx);			
		mlx_loop(mlx.mlx_ptr);
		return (0);
	}
}
