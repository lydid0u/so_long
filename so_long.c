/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   so_long.c										  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: lboudjel <lboudjel@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/10/02 15:58:21 by lboudjel		  #+#	#+#			 */
/*   Updated: 2023/10/07 13:12:52 by lboudjel		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	static t_jeu	jeu = {0};

	if (argc == 2)
	{
		if (!(check_valid_name(argv[1])) || !(create_map(argv[1], &jeu, 0))
			|| !(check_empty(&jeu)))
			return (0);
		jeu.map_p = copy_map(jeu.map);
		if (!(check_map(&jeu)))
			return (0);
		jeu.map_f = copy_map(jeu.map);
		change_ennemi_and_exit_to_wall(&jeu);
		flood_fill(jeu.x, jeu.y, &jeu);
		if (!(check_flood(&jeu)))
			return (0);
		jeu.mlx_ptr = mlx_init();
		if (!jeu.mlx_ptr)
			return (1);
		jeu.win_ptr = mlx_new_window(jeu.mlx_ptr, jeu.len * 64, jeu.nbr_ligne
				* 64, "Tea party <3");
		if (!jeu.win_ptr)
			return (free(jeu.mlx_ptr), 1);
		loop_hook(&jeu);
		return (0);
	}
}
