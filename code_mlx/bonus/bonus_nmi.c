/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_nmi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:50:01 by lboudjel          #+#    #+#             */
/*   Updated: 2023/10/14 14:50:20 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	anim_nmi(t_jeu *jeu, int i, int j)
{
	ft_reset_nmi(jeu);
	while (jeu->map_p[i])
	{
		j = 0;
		while (jeu->map_p[i][j])
		{
			if (jeu->map_p[i][j] == 'D')
			{
				mlx_destroy_image(jeu->mlx_ptr, jeu->img_nmi);
				if (jeu->bonus_nmi >= 0 && jeu->bonus_nmi < 50)
					don_left(jeu, i, j);
				else if (jeu->bonus_nmi >= 50 && jeu->bonus_nmi < 100)
					don_right(jeu, i, j);
			}
			j++;
		}
		i++;
	}
	jeu->bonus_nmi++;
}

void	ft_reset_nmi(t_jeu *jeu)
{
	if (jeu->bonus_nmi == 100)
		jeu->bonus_nmi = 0;
}
