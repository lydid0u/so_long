/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nmi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:52:39 by lboudjel          #+#    #+#             */
/*   Updated: 2023/10/14 14:52:50 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	don_left(t_jeu *jeu, int i, int j)
{
	jeu->img_nmi = mlx_xpm_file_to_image(jeu->mlx_ptr, "./xpm/don.xpm",
			&jeu->width, &jeu->height);
	mlx_put_image_to_window(jeu->mlx_ptr, jeu->win_ptr, jeu->img_nmi, j * 64, i
		* 64);
}

void	don_right(t_jeu *jeu, int i, int j)
{
	jeu->img_nmi = mlx_xpm_file_to_image(jeu->mlx_ptr, "./xpm/don_right.xpm",
			&jeu->width, &jeu->height);
	mlx_put_image_to_window(jeu->mlx_ptr, jeu->win_ptr, jeu->img_nmi, j * 64, i
		* 64);
}
