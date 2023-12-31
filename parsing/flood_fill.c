/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   flood_fill.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: lboudjel <lboudjel@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/09/24 15:16:08 by lboudjel		  #+#	#+#			 */
/*   Updated: 2023/10/07 12:04:18 by lboudjel		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../so_long.h"

void	change_ennemi_and_exit_to_wall(t_jeu *jeu)
{
	int	i;
	int	j;

	i = 0;
	while (jeu->map_f[i])
	{
		j = 0;
		while (jeu->map_f[i][j])
		{
			if (jeu->map_f[i][j] == 'D')
				jeu->map_f[i][j] = '1';
			j++;
		}
		i++;
	}
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

int	flood_fill_checker(t_jeu *jeu)
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
			if (jeu->map_f[i][j] != 'V' && jeu->map_f[i][j] != '1')
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
