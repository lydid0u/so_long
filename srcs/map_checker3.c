/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 15:05:12 by lboudjel          #+#    #+#             */
/*   Updated: 2023/09/27 15:11:15 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_letter(t_jeu *jeu)
{
	int	i;
	int	j;

	i = 0;
	while (jeu->map_p[i])
	{
		j = 0;
		while (jeu->map_p[i][j])
		{
			if (jeu->map_p[i][j] == 'C')
				jeu->coin++;
			else if (jeu->map_p[i][j] == 'P')
				jeu->perso++;
			else if (jeu->map_p[i][j] == 'D')
				jeu->nmi++;
			else if (jeu->map_p[i][j] == 'E')
				jeu->exit++;
			j++;
		}
		i++;
	}
	if (!(error_letter(jeu)))
		return (0);
	return (1);
}

void	free_all(t_jeu *jeu)
{
	free_map(jeu->map);
	free_map(jeu->map_p);
	free_map(jeu->map_f);
}
