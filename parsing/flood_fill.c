/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 15:16:08 by lboudjel          #+#    #+#             */
/*   Updated: 2023/10/07 12:04:18 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	flood_fill(int x, int y, t_jeu *jeu)
{
	if (jeu->map_f[x][y] == '1' || jeu->map_f[x][y] == 'V')
		return (0);
	jeu->map_f[x][y] = 'V';
	if (flood_fill(x - 1, y, jeu) || flood_fill(x + 1, y, jeu) || flood_fill(x,
			y - 1, jeu) || flood_fill(x, y + 1, jeu))
		return (1);
	return (0);
}

int	flood_fill_stuck(int x, int y, t_jeu *jeu)
{
	if (jeu->map_fd[x][y] == '1' || jeu->map_fd[x][y] == 'S' ||
		jeu->map_fd[x][y] == 'E' || jeu->map_fd[x][y] == 'D')
		return (0);
	if (jeu->map_fd[x][y] == 'C')
		return (1);
	jeu->map_fd[x][y] = 'S';
	if (flood_fill_stuck(x - 1, y, jeu) || flood_fill_stuck(x + 1, y, jeu)
		|| flood_fill_stuck(x, y - 1, jeu) || flood_fill_stuck(x, y + 1, jeu))
		return (1);
	return (0);
}

int	check_flood(t_jeu *jeu, int i)
{
	int	j;
	int	len;

	len = ft_strlen(jeu->map_f[i]);
	while (jeu->map_f[i] && i < jeu->nbr_ligne)
	{
		j = 0;
		while (jeu->map_f[i][j] && j < len - 1)
		{
			if (jeu->map_f[i][0] != '1' || jeu->map_f[i][len - 1] != '1')
			{
				free_all(jeu);
				return (ft_printf("Error\nSomething is innacessible !\n"), 0);
			}
			else if (jeu->map_f[i][j] != 'V' && jeu->map_f[i][j] != '1')
			{
				free_all(jeu);
				return (ft_printf("Error\nSomething is innacessible !\n"), 0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_flood_nmi(t_jeu *jeu, int i)
{
	int	j;
	int	len;
	int s = 0;

	len = ft_strlen(jeu->map_fd[i]);
	while (jeu->map_fd[i] && i < jeu->nbr_ligne)
	{
			while (jeu->map_fd[s])
	{
		printf("test : %s\n", jeu->map_fd[s]);
		s++;
	}
		j = 0;
		while (jeu->map_fd[i][j] && j < len - 1)
		{
			// if (jeu->map_fd[i][0] != '1' || jeu->map_fd[i][len - 1] != '1')
			// {
			// 	free_all(jeu);
			// 	return (ft_printf("Error\nSomething is innacessible !\n"), 0);
			// }
			if (jeu->map_fd[i][j] != 'S' && jeu->map_fd[i][j] != '1' && jeu->map_fd[i][j] == 'C')
			{
				free_all(jeu);
				return (ft_printf("Error\nSomething is innacessible !\n"), 0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

// int	flood(t_jeu *jeu)
// {
// 	int	i;

// 	i = 0;
// 	flood_fill(jeu->x, jeu->y, jeu);
// 	if (!(check_flood(jeu, 0)))
// 		return (0);
// 	while (jeu->map_f[i])
// 	{
// 		printf("test : %s\n", jeu->map_f[i]);
// 		i++;
// 	}
// 	i = 0;
// 	if (!flood_fill_stuck(jeu->x, jeu->y, jeu))
// 	{
// 		while (jeu->map_f[i])
// 		{
// 			printf("%s\n", jeu->map_f[i]);
// 			i++;
// 		}
// 		free_all(jeu);
// 		ft_printf("Error\nA collectible is innacessible !");
// 		return (0);
// 	}
// 	return (1);
// }
