/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_windows.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:23:24 by lboudjel          #+#    #+#             */
/*   Updated: 2023/10/07 12:32:35 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	xpm_to_img(t_jeu *jeu)
{
	jeu->width = 64;
	jeu->height = 64;
	jeu->img_coin = mlx_xpm_file_to_image(jeu->mlx_ptr, "./xpm/tea01.xpm",
			&jeu->width, &jeu->height);
		if(!jeu->img_coin)
			return(exit_and_leave(jeu), ft_printf("Error\nImage incorrect !", 0));
	jeu->img_wall = mlx_xpm_file_to_image(jeu->mlx_ptr, "./xpm/plant.xpm",
			&jeu->width, &jeu->height);
		if(!jeu->img_wall)
			return(exit_and_leave(jeu), ft_printf("Error\nImage incorrect !", 0));
	jeu->img_exit = mlx_xpm_file_to_image(jeu->mlx_ptr, "./xpm/door.xpm",
			&jeu->width, &jeu->height);
		if(!jeu->img_exit)
			return(exit_and_leave(jeu), ft_printf("Error\nImage incorrect !", 0));
	jeu->img_floor = mlx_xpm_file_to_image(jeu->mlx_ptr, "./xpm/floor.xpm",
			&jeu->width, &jeu->height);
		if(!jeu->img_floor)
			return(exit_and_leave(jeu), ft_printf("Error\nImage incorrect !", 0));	
	jeu->img_right = mlx_xpm_file_to_image(jeu->mlx_ptr, "./xpm/right.xpm",
			&jeu->width, &jeu->height);
		if(!jeu->img_right)
			return(exit_and_leave(jeu), ft_printf("Error\nImage incorrect !", 0));
	jeu->img_left = mlx_xpm_file_to_image(jeu->mlx_ptr, "./xpm/left.xpm",
			&jeu->width, &jeu->height);
		if(!jeu->img_left)
			return(exit_and_leave(jeu), ft_printf("Error\nImage incorrect !", 0));
	jeu->img_perso = mlx_xpm_file_to_image(jeu->mlx_ptr, "./xpm/perso.xpm",
			&jeu->width, &jeu->height);
		if(!jeu->img_perso)
			return(exit_and_leave(jeu), ft_printf("Error\nImage incorrect !", 0));
	jeu->img_nmi = mlx_xpm_file_to_image(jeu->mlx_ptr, "./xpm/don.xpm",
			&jeu->width, &jeu->height);
		if(!jeu->img_nmi)
			return(exit_and_leave(jeu), ft_printf("Error\nImage incorrect !", 0));
	jeu->pied = mlx_xpm_file_to_image(jeu->mlx_ptr, "./xpm/doubl.xpm",
			&jeu->width, &jeu->height);
		if(!jeu->pied)
			return(exit_and_leave(jeu), ft_printf("Error\nImage incorrect !", 0));
	return (1);
}

void	img_to_window(t_jeu *jeu, int i, int j)
{
	xpm_to_img(jeu);
	while (jeu->map_p[i])
	{
		j = 0;
		while (jeu->map_p[i][j])
		{
			print_img(jeu, i, j);
			j++;
		}
		i++;
	}
}

void	print_img(t_jeu *jeu, int i, int j)
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
		mlx_put_image_to_window(jeu->mlx_ptr, jeu->win_ptr, jeu->img_floor, j
			* 64, i * 64);
	if (jeu->map_p[i][j] == 'P')
		mlx_put_image_to_window(jeu->mlx_ptr, jeu->win_ptr, jeu->img_perso, j
			* 64, i * 64);
	if (jeu->map_p[i][j] == 'D')
		mlx_put_image_to_window(jeu->mlx_ptr, jeu->win_ptr, jeu->img_nmi, j
			* 64, i * 64);
	mlx_put_image_to_window(jeu->mlx_ptr, jeu->win_ptr, jeu->pied, 0, 0);
}

void	print_moves(t_jeu *jeu)
{
	jeu->win_steps = ft_itoa(jeu->steps);
	if (!jeu->win_steps)
		return ;
	mlx_string_put(jeu->mlx_ptr, jeu->win_ptr, 78, 30, 0xbc7241,
		jeu->win_steps);
	free(jeu->win_steps);
	jeu->steps++;
	ft_printf("number of steps : %d\n", jeu->steps);
	jeu->win_steps = ft_itoa(jeu->steps);
	mlx_string_put(jeu->mlx_ptr, jeu->win_ptr, 78, 30, 0xFFFFFF,
		jeu->win_steps);
	free(jeu->win_steps);
}

void	loop_hook(t_jeu *jeu)
{
	img_to_window(jeu, 0, 0);
	mlx_key_hook(jeu->win_ptr, ft_move, jeu);
	mlx_hook(jeu->win_ptr, DestroyNotify, StructureNotifyMask, exit_and_leave,
		jeu);
	mlx_loop(jeu->mlx_ptr);
}
