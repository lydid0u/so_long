/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 14:45:46 by lboudjel          #+#    #+#             */
/*   Updated: 2023/09/27 14:52:26 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// int	check_line(char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		if (str[i] != '0' && str[i] != '1' && str[i] != 'C' && str[i] == 'E')
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }

void	nbr_of_line(char *av1, t_jeu *jeu)
{
	int		fd;
	char	*line;

	jeu->nbr_ligne = 0;
	fd = open(av1, O_RDONLY);
	if (fd == -1)
		return ;
	line = get_next_line(fd);
	// if (!line)
	// 	return ;
	while (line)
	{
		if (line == NULL)
			break ;
		// if (check_line(line))
		// {
		// 	free(line);
		// 	close(fd);
		// 	exit(1);
		// }
		free(line);
		line = get_next_line(fd);
		// if (!line)
		// 	return ;
		jeu->nbr_ligne++;
	}
	free(line);
	close(fd);
}

int	free_map(char **carte)
{
	int	i;

	if (!carte)
		return (0);
	i = 0;
	while (carte[i])
	{
		free(carte[i]);
		i++;
	}
	free(carte);
	carte = NULL;
	return (1);
}

int	create_map(char *av1, t_jeu *jeu)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(av1, O_RDONLY);
	if (fd == -1)
		return (ft_printf("Error\nFile does not exist !\n"), 0);
	nbr_of_line(av1, jeu);
	if (jeu->nbr_ligne <= 1)
		return (ft_printf("Error\nNot enough lines !"), 0);
	jeu->map = malloc(sizeof(char *) * (jeu->nbr_ligne + 1));
	if (!jeu->map)
		return (free(jeu->map), 0);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		jeu->map[i] = copy(line);
		free(line);
		i++;
	}
	jeu->map[i] = NULL;
	return (close(fd), 1);
}

int	mur_haut_bas(t_jeu *jeu)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (jeu->map_p[0][i])
	{
		if (jeu->map_p[0][i] != '1' && jeu->map_p[0][i] != '\n')
		{
			ft_printf("Error\nUp wall should only contains 1 !");
			return (0);
		}
		i++;
	}
	while (jeu->map_p[jeu->nbr_ligne - 1][j])
	{
		if (jeu->map_p[jeu->nbr_ligne - 1][j] != '1'
			&& jeu->map_p[jeu->nbr_ligne - 1][j] != '\n')
		{
			ft_printf("Error\nDown wall should only contains 1 !");
			return (0);
		}
		j++;
	}
	return (1);
}

int	contenu_ligne(t_jeu *jeu)
{
	int	i;
	int	j;
	int	longueur;

	i = 1;
	j = 0;
	longueur = ft_strlen(jeu->map_p[i]);
	while (i < jeu->nbr_ligne - 1)
	{
		while (jeu->map_p[i][j] && j < longueur - 1)
		{
			if (jeu->map_p[i][0] != '1' || jeu->map_p[i][longueur - 1] != '1')
			{
				ft_printf("Error\nEnds must contain '1' only!\n");
				return (0);
			}
			else if (jeu->map_p[i][j] != '0' && jeu->map_p[i][j] != '1'
					&& jeu->map_p[i][j] != 'C' && jeu->map_p[i][j] != 'P'
					&& jeu->map_p[i][j] != 'E')
			{
				ft_printf("Error\nIncompatible character!\n");
				return (0);
			}
			if (jeu->map_p[i][j] == 'P')
			{
				jeu->x = i;
				jeu->y = j;
				printf("apres : %d %d \n", jeu->x, jeu->y);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}
