/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 16:44:12 by lboudjel          #+#    #+#             */
/*   Updated: 2023/10/07 13:09:30 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_move(int keysym, t_jeu *jeu)
{
	if (keysym == 65307)
	{
		free_all(jeu);
		disconnect(jeu);
		exit(EXIT_SUCCESS);
	}
	if (keysym == 65363 || keysym == 100)
		go_right(jeu);
	if (keysym == 65361 || keysym == 97)
		go_left(jeu);
	if (keysym == 65362 || keysym == 119)
		go_up(jeu);
	if (keysym == 65364 || keysym == 115)
		go_down(jeu);
	// mlx_loop_hook(jeu->mlx_ptr, animation_loop, jeu);
	mlx_loop_hook(jeu->mlx_ptr, animation_loop_nmi, jeu);
	return (0);
}

void	go_right(t_jeu *jeu)
{
	if ((jeu->map_p[jeu->x][jeu->y + 1] == 'E' && jeu->coin == 0)
		|| jeu->map_p[jeu->x][jeu->y + 1] == 'D')
	{
		if (jeu->map_p[jeu->x][jeu->y + 1] == 'D')
			ft_printf("Don Paolo ruined your tea party :(\n");
		if (jeu->map_p[jeu->x][jeu->y + 1] == 'E' && jeu->coin == 0)
			ft_printf("Yay congrats!! It's now time to do the dishes :)\n");
		free_all(jeu);
		disconnect(jeu);
		exit(EXIT_SUCCESS);
	}
	if (jeu->map_p[jeu->x][jeu->y + 1] == '1' || jeu->map_p[jeu->x][jeu->y
		+ 1] == 'E')
		return ;
	if (jeu->map_p[jeu->x][jeu->y + 1] == 'C')
	{
		jeu->coin--;
		jeu->map_p[jeu->x][jeu->y + 1] = '0';
	}
	print_moves(jeu);
	mlx_put_image_to_window(jeu->mlx_ptr, jeu->win_ptr, jeu->img_floor, jeu->y
		* 64, jeu->x * 64);
	jeu->y = jeu->y + 1;
	mlx_put_image_to_window(jeu->mlx_ptr, jeu->win_ptr, jeu->img_right, jeu->y
		* 64, jeu->x * 64);
}

void	go_left(t_jeu *jeu)
{
	if ((jeu->map_p[jeu->x][jeu->y - 1] == 'E' && jeu->coin == 0)
		|| jeu->map_p[jeu->x][jeu->y - 1] == 'D')
	{
		if (jeu->map_p[jeu->x][jeu->y - 1] == 'D')
			ft_printf("Don Paolo ruined your tea party :(\n");
		if (jeu->map_p[jeu->x][jeu->y - 1] == 'E' && jeu->coin == 0)
			ft_printf("Yay congrats!! It's now time to do the dishes :)\n");
		free_all(jeu);
		disconnect(jeu);
		exit(EXIT_SUCCESS);
	}
	if (jeu->map_p[jeu->x][jeu->y - 1] == '1' || jeu->map_p[jeu->x][jeu->y
		- 1] == 'E')
		return ;
	if (jeu->map_p[jeu->x][jeu->y - 1] == 'C')
	{
		jeu->coin--;
		jeu->map_p[jeu->x][jeu->y - 1] = '0';
	}
	print_moves(jeu);
	mlx_put_image_to_window(jeu->mlx_ptr, jeu->win_ptr, jeu->img_floor, jeu->y
		* 64, jeu->x * 64);
	jeu->y = jeu->y - 1;
	mlx_put_image_to_window(jeu->mlx_ptr, jeu->win_ptr, jeu->img_left, jeu->y
		* 64, jeu->x * 64);
}

void	go_up(t_jeu *jeu)
{
	if ((jeu->map_p[jeu->x - 1][jeu->y] == 'E' && jeu->coin == 0)
		|| jeu->map_p[jeu->x - 1][jeu->y] == 'D')
	{
		if (jeu->map_p[jeu->x - 1][jeu->y] == 'D')
			ft_printf("Don Paolo ruined your tea party :(\n");
		if (jeu->map_p[jeu->x - 1][jeu->y] == 'E' && jeu->coin == 0)
			ft_printf("Yay congrats!! It's now time to do the dishes :)\n");
		free_all(jeu);
		disconnect(jeu);
		exit(EXIT_SUCCESS);
	}
	if (jeu->map_p[jeu->x - 1][jeu->y] == '1' || jeu->map_p[jeu->x
		- 1][jeu->y] == 'E')
		return ;
	if (jeu->map_p[jeu->x - 1][jeu->y] == 'C')
	{
		jeu->coin--;
		jeu->map_p[jeu->x - 1][jeu->y] = '0';
	}
	print_moves(jeu);
	mlx_put_image_to_window(jeu->mlx_ptr, jeu->win_ptr, jeu->img_floor, jeu->y
		* 64, jeu->x * 64);
	jeu->x = jeu->x - 1;
	mlx_put_image_to_window(jeu->mlx_ptr, jeu->win_ptr, jeu->img_perso, jeu->y
		* 64, jeu->x * 64);
}

void	go_down(t_jeu *jeu)
{
	if ((jeu->map_p[jeu->x + 1][jeu->y] == 'E' && jeu->coin == 0)
		|| jeu->map_p[jeu->x + 1][jeu->y] == 'D')
	{
		if (jeu->map_p[jeu->x + 1][jeu->y] == 'D')
			ft_printf("Don Paolo ruined your tea party :(\n");
		if (jeu->map_p[jeu->x + 1][jeu->y] == 'E' && jeu->coin == 0)
			ft_printf("Yay congrats!! It's now time to do the dishes :)\n");
		free_all(jeu);
		disconnect(jeu);
		exit(EXIT_SUCCESS);
	}
	if (jeu->map_p[jeu->x + 1][jeu->y] == '1' || jeu->map_p[jeu->x
		+ 1][jeu->y] == 'E')
		return ;
	if (jeu->map_p[jeu->x + 1][jeu->y] == 'C')
	{
		jeu->coin--;
		jeu->map_p[jeu->x + 1][jeu->y] = '0';
	}
	print_moves(jeu);
	mlx_put_image_to_window(jeu->mlx_ptr, jeu->win_ptr, jeu->img_floor, jeu->y
		* 64, jeu->x * 64);
	jeu->x = jeu->x + 1;
	mlx_put_image_to_window(jeu->mlx_ptr, jeu->win_ptr, jeu->img_perso, jeu->y
		* 64, jeu->x * 64);
}
