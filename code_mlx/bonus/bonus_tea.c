/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_tea.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:50:52 by lboudjel          #+#    #+#             */
/*   Updated: 2023/10/14 14:52:21 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

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
				if (jeu->bonus_tea >= 0 && jeu->bonus_tea < 5)
					tea_one(jeu, i, j);
				else if (jeu->bonus_tea >= 5 && jeu->bonus_tea < 10)
					tea_two(jeu, i, j);
				else if (jeu->bonus_tea >= 10 && jeu->bonus_tea < 15)
					tea_three(jeu, i, j);
				else if (jeu->bonus_tea >= 15 && jeu->bonus_tea < 20)
					tea_four(jeu, i, j);
				else if (jeu->bonus_tea >= 20 && jeu->bonus_tea < 25)
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
	if (jeu->bonus_tea == 25)
		jeu->bonus_tea = 0;
}

int	animation_loop(t_jeu *jeu)
{
	anim_exit(jeu);
	anim_nmi(jeu, 0, 0);
	anim_coin(jeu, 0, 0);
	return (0);
}

// else if (jeu->bonus_tea >= 25 && jeu->bonus_tea < 6)
// 	tea_four(jeu, i, j);
// else if (jeu->bonus_tea >= 6 && jeu->bonus_tea < 7)
// 	tea_three(jeu, i, j);
// else if (jeu->bonus_tea >= 7 && jeu->bonus_tea < 8)					
// 	tea_two(jeu, i, j);
// else if (jeu->bonus_tea >= 8 && jeu->bonus_tea < 9)	
// 	tea_one(jeu, i, j);