/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tea.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:26:20 by lboudjel          #+#    #+#             */
/*   Updated: 2023/10/03 16:10:12 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	tea_one(t_jeu *jeu, int i, int j)
{
	jeu->img_coin = mlx_xpm_file_to_image(jeu->mlx_ptr, "./xpm/tea01.xpm",
			&jeu->width, &jeu->height);
	mlx_put_image_to_window(jeu->mlx_ptr, jeu->win_ptr, jeu->img_coin, j * 64, i
		* 64);
}

void	tea_two(t_jeu *jeu, int i, int j)
{
	jeu->img_coin = mlx_xpm_file_to_image(jeu->mlx_ptr, "./xpm/tea02.xpm",
			&jeu->width, &jeu->height);
	mlx_put_image_to_window(jeu->mlx_ptr, jeu->win_ptr, jeu->img_coin, j * 64, i
		* 64);
}

void	tea_three(t_jeu *jeu, int i, int j)
{
	jeu->img_coin = mlx_xpm_file_to_image(jeu->mlx_ptr, "./xpm/tea03.xpm",
			&jeu->width, &jeu->height);
	mlx_put_image_to_window(jeu->mlx_ptr, jeu->win_ptr, jeu->img_coin, j * 64, i
		* 64);
}

void	tea_four(t_jeu *jeu, int i, int j)
{
	jeu->img_coin = mlx_xpm_file_to_image(jeu->mlx_ptr, "./xpm/tea04.xpm",
			&jeu->width, &jeu->height);
	mlx_put_image_to_window(jeu->mlx_ptr, jeu->win_ptr, jeu->img_coin, j * 64, i
		* 64);
}

void	tea_five(t_jeu *jeu, int i, int j)
{
	jeu->img_coin = mlx_xpm_file_to_image(jeu->mlx_ptr, "./xpm/tea05.xpm",
			&jeu->width, &jeu->height);
	mlx_put_image_to_window(jeu->mlx_ptr, jeu->win_ptr, jeu->img_coin, j * 64, i
		* 64);
}
