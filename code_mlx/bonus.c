/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:42:57 by lboudjel          #+#    #+#             */
/*   Updated: 2023/10/07 13:10:00 by lboudjel         ###   ########.fr       */
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
				if (jeu->bonus_tea >= 0 && jeu->bonus_tea < 100)
					tea_one(jeu, i, j);
				else if (jeu->bonus_tea >= 100 && jeu->bonus_tea < 200)
					tea_two(jeu, i, j);
				else if (jeu->bonus_tea >= 200 && jeu->bonus_tea < 300)					
					tea_three(jeu, i, j);
                else if (jeu->bonus_tea >= 300 && jeu->bonus_tea < 400)	
					tea_four(jeu, i, j);
                else if (jeu->bonus_tea >= 400 && jeu->bonus_tea < 500)	
					tea_five(jeu, i, j);
				// else if (jeu->bonus_tea >= 500 && jeu->bonus_tea < 600)
				// 	tea_four(jeu, i, j);
				// else if (jeu->bonus_tea >= 600 && jeu->bonus_tea < 700)
				// 	tea_three(jeu, i, j);
				// else if (jeu->bonus_tea >= 700 && jeu->bonus_tea < 800)					
				// 	tea_two(jeu, i, j);
                // else if (jeu->bonus_tea >= 800 && jeu->bonus_tea < 900)	
				// 	tea_one(jeu, i, j);
			}
			j++;
		}
		i++;
	}
	jeu->bonus_tea++;
}

void	ft_reset(t_jeu *jeu)
{
	if (jeu->bonus_tea == 500)
		jeu->bonus_tea = 0;
}

int	animation_loop(t_jeu *jeu)
{
	anim_coin(jeu, 0, 0); 
	return (0); 
}