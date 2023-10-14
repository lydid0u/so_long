/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   free.c									 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: lboudjel <lboudjel@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/09/24 15:05:12 by lboudjel		  #+#	#+#			 */
/*   Updated: 2023/10/06 12:21:05 by lboudjel		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../so_long.h"

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

void	free_all(t_jeu *jeu)
{
	free_map(jeu->map);
	free_map(jeu->map_p);
	free_map(jeu->map_f);
}
