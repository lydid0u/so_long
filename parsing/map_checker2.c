/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 14:45:55 by lboudjel          #+#    #+#             */
/*   Updated: 2023/09/27 15:11:15 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	error_letter(t_jeu *jeu)
{
	if (jeu->perso != 1)
		return (ft_printf("Error\nYou need 1 player !\n"), 0);
	if (jeu->exit != 1)
		return (ft_printf("Error\nYou need 1 exit !\n"), 0);
	if (jeu->coin < 1)
		return (ft_printf("Error\nYou need at least 1 coin !\n"), 0);
	if (jeu->nmi < 1)
		return (ft_printf("Error\nYou need at least 1 ennemi patrol !\n"), 0);
	if (jeu->nbr_ligne >= jeu->len)
		return (ft_printf("Error\nThe map has to be rectangle !\n"), 0);
	return (1);
}

int	check_valid_name(char *av1)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(av1) - 1;
	if (av1[len] == 'r')
		i++;
	if (av1[len - 1] == 'e')
		i++;
	if (av1[len - 2] == 'b')
		i++;
	if (av1[len - 3] == '.')
		i++;
	if (i == 4)
		return (1);
	else
		return (ft_printf("Error\nFile's name is not valid !"), 0);
}

int	line_size(t_jeu *jeu)
{
	int	i;
	int	len2;

	i = 0;
	jeu->len = ft_strlen(jeu->map_p[i]);
	while (jeu->map_p[i])
	{
		len2 = ft_strlen(jeu->map_p[i]);
		if (jeu->len != len2)
		{
			ft_printf("Error\nAll lines are not the same length !\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_empty(t_jeu *jeu)
{
	int	i;
	int	len;
	int	len2;

	i = 2;
	len = ft_strlen(jeu->map[1]);
	if (len != 0)
		return (1);
	while (jeu->map[i])
	{
		len2 = ft_strlen(jeu->map[i]);
		if (len2 != len)
		{
			return (1);
		}
		i++;
	}
	ft_printf("Error\nEmpty map !\n");
	free_map(jeu->map);
	return (0);
}

int	check_map(t_jeu *jeu)
{
	if (!(line_size(jeu)))
	{
		free_map(jeu->map);
		free_map(jeu->map_p);
		return (0);
	}
	if (!(mur_haut_bas(jeu)))
	{
		free_map(jeu->map);
		free_map(jeu->map_p);
		return (0);
	}
	if (!(contenu_ligne(jeu)))
	{
		free_map(jeu->map);
		free_map(jeu->map_p);
		return (0);
	}
	if (!(check_letter(jeu)))
	{
		free_map(jeu->map);
		free_map(jeu->map_p);
		return (0);
	}
	return (1);
}
