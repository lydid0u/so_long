/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sink.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:52:42 by lboudjel          #+#    #+#             */
/*   Updated: 2023/10/14 15:20:11 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	sink_one(t_jeu *jeu, int i, int j)
{
	jeu->img_exit = mlx_xpm_file_to_image(jeu->mlx_ptr, "./xpm/door.xpm",
			&jeu->width, &jeu->height);
	mlx_put_image_to_window(jeu->mlx_ptr, jeu->win_ptr, jeu->img_exit, j * 64, i
		* 64);
}

void	sink_two(t_jeu *jeu, int i, int j)
{
	jeu->img_exit = mlx_xpm_file_to_image(jeu->mlx_ptr, "./xpm/sink2.xpm",
			&jeu->width, &jeu->height);
	mlx_put_image_to_window(jeu->mlx_ptr, jeu->win_ptr, jeu->img_exit, j * 64, i
		* 64);
}

void	sink_three(t_jeu *jeu, int i, int j)
{
	jeu->img_exit = mlx_xpm_file_to_image(jeu->mlx_ptr, "./xpm/sink3.xpm",
			&jeu->width, &jeu->height);
	mlx_put_image_to_window(jeu->mlx_ptr, jeu->win_ptr, jeu->img_exit, j * 64, i
		* 64);
}

void	sink_four(t_jeu *jeu, int i, int j)
{
	jeu->img_exit = mlx_xpm_file_to_image(jeu->mlx_ptr, "./xpm/sink4.xpm",
			&jeu->width, &jeu->height);
	mlx_put_image_to_window(jeu->mlx_ptr, jeu->win_ptr, jeu->img_exit, j * 64, i
		* 64);
}

void	sink_five(t_jeu *jeu, int i, int j)
{
	jeu->img_exit = mlx_xpm_file_to_image(jeu->mlx_ptr, "./xpm/sink5.xpm",
			&jeu->width, &jeu->height);
	mlx_put_image_to_window(jeu->mlx_ptr, jeu->win_ptr, jeu->img_exit, j * 64, i
		* 64);
}
