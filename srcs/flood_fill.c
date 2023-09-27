/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 15:16:08 by lboudjel          #+#    #+#             */
/*   Updated: 2023/09/24 16:43:09 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*copy(const char *src)
{
	char	*new;
	int		i;
	int		size;

	size = 0;
	while (src[size])
		size++;
	if (!(new = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = 0;
	while (src[i] && src[i] != '\n')
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	**copy_map(char **map)
{
	char	**dst;
	int		i;

	i = 0;
	while (map[i])
		i++;
	dst = (char **)malloc(sizeof(char *) * (i + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (map[i])
	{
		dst[i] = copy(map[i]);
		if (dst[i] == NULL)
		{
			while (i >= 0)
				free(dst[i--]);
			return (NULL);
		}
		i++;
	}
	dst[i] = NULL;
	return (dst);
}

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

int	check_flood(t_jeu *jeu)
{
	int	i;
	int	j;
	int	len;

	i = 0;
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
