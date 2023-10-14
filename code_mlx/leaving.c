/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leaving.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:03:29 by lboudjel          #+#    #+#             */
/*   Updated: 2023/10/14 15:08:08 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	exit_and_leave(t_jeu *jeu)
{
	free_all(jeu);
	destroy(jeu);
	exit(EXIT_SUCCESS);
}

int	destroy(t_jeu *jeu)
{
	if (jeu->img_wall)
		mlx_destroy_image(jeu->mlx_ptr, jeu->img_wall);
	if (jeu->img_floor)
		mlx_destroy_image(jeu->mlx_ptr, jeu->img_floor);
	if (jeu->img_right)
		mlx_destroy_image(jeu->mlx_ptr, jeu->img_right);
	if (jeu->img_left)
		mlx_destroy_image(jeu->mlx_ptr, jeu->img_left);
	if (jeu->img_exit)
		mlx_destroy_image(jeu->mlx_ptr, jeu->img_exit);
	if (jeu->img_perso)
		mlx_destroy_image(jeu->mlx_ptr, jeu->img_perso);
	if (jeu->img_coin)
		mlx_destroy_image(jeu->mlx_ptr, jeu->img_coin);
	if (jeu->img_nmi)
		mlx_destroy_image(jeu->mlx_ptr, jeu->img_nmi);
	if (jeu->img_steps)
		mlx_destroy_image(jeu->mlx_ptr, jeu->img_steps);
	if (jeu->img_lamp)
		mlx_destroy_image(jeu->mlx_ptr, jeu->img_lamp);
	destroy_two(jeu);
	exit(0);
}

void	destroy_two(t_jeu *jeu)
{
	if (jeu->mlx_ptr)
	{
		mlx_loop_end(jeu->mlx_ptr);
		mlx_destroy_window(jeu->mlx_ptr, jeu->win_ptr);
		mlx_destroy_display(jeu->mlx_ptr);
		free(jeu->mlx_ptr);
	}
}
