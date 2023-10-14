/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   handle_error.c									 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: lboudjel <lboudjel@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/09/24 14:45:55 by lboudjel		  #+#	#+#			 */
/*   Updated: 2023/10/02 16:39:52 by lboudjel		 ###   ########.fr	   */
/*																			*/
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
	if (jeu->len > 31)
		return (ft_printf("Error\nLine is too long !"), 0);
	return (1);
}

int	wall_up_down(t_jeu *jeu)
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
			return (1);
		i++;
	}
	ft_printf("Error\nEmpty map !\n");
	free_map(jeu->map);
	return (0);
}

int	content_line(t_jeu *jeu, int i)
{
	int	j;
	int	longueur;

	longueur = ft_strlen(jeu->map_p[i]);
	while (i < jeu->nbr_ligne - 1)
	{
		j = 0;
		while (jeu->map_p[i][j] && j < longueur - 1)
		{
			if (jeu->map_p[i][0] != '1' || jeu->map_p[i][longueur - 1] != '1')
				return (ft_printf("Error\nEnds must contain '1' only!\n"), 0);
			else if (jeu->map_p[i][j] != '0' && jeu->map_p[i][j] != '1'
					&& jeu->map_p[i][j] != 'C' && jeu->map_p[i][j] != 'P'
					&& jeu->map_p[i][j] != 'E' && jeu->map_p[i][j] != 'D')
				return (ft_printf("Error\nIncompatible character!\n"), 0);
			if (jeu->map_p[i][j] == 'P')
			{
				jeu->x = i;
				jeu->y = j;
			}
			j++;
		}
		i++;
	}
	return (1);
}
