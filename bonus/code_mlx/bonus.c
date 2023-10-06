/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:42:57 by lboudjel          #+#    #+#             */
/*   Updated: 2023/10/03 15:43:12 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	anim_coin(t_jeu *jeu, int i, int j)
{
	ft_reset(jeu);
	while (jeu->map_p[i])
	{
		j = 0;
		while (jeu->map_p[i][j])
		{
			if (jeu->map_p[i][j] == 'C')
			{
				mlx_destroy_image(jeu->mlx_ptr, jeu->img_coin);
				if (jeu->bonus_tea == 0)
					tea_one(jeu, i, j);
				else if (jeu->bonus_tea == 1)
					tea_two(jeu, i, j);
				else if (jeu->bonus_tea == 2)
					tea_three(jeu, i, j);
				else if (jeu->bonus_tea == 3)
					tea_four(jeu, i, j);
				else if (jeu->bonus_tea == 4)
					tea_five(jeu, i, j);
			}
			j++;
		}
		i++;
	}
	jeu->bonus_tea++;
}

void	ft_reset(t_jeu *jeu)
{
	if (jeu->bonus_tea >= 4)
		jeu->bonus_tea = 0;
}
