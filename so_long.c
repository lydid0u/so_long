/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 16:24:27 by lboudjel          #+#    #+#             */
/*   Updated: 2023/09/24 17:03:26 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int on_keypress(int keysym, t_jeu *jeu) // keysym = nom de touche
{
	(void)jeu;
	ft_printf("Pressed key: %d\n", keysym);
	return (0);
}

int	main(int argc, char **argv)
{
	static t_jeu	jeu = {0};

	if (argc == 2)
	{
		if (!(check_valid_name(argv[1])))
			return (0);
		if (!(create_map(argv[1], &jeu)))
			return (0);
		if (!(check_empty(&jeu)))
			return (0);
		jeu.map_p = copy_map(jeu.map);
		if (!(check_map(&jeu)))
			return (0);
		jeu.map_f = copy_map(jeu.map);
		flood_fill(jeu.x, jeu.y, &jeu);
		if (!(check_flood(&jeu)))
			return (0);
		jeu.mlx_ptr = mlx_init();
		if (!jeu.mlx_ptr)
			return (1);
		jeu.win_ptr = mlx_new_window(jeu.mlx_ptr, jeu.len * 64, jeu.nbr_ligne * 64, "Tea party <3");
		if (!jeu.win_ptr)
			return (free(jeu.mlx_ptr), 1);
		xpm_to_img(&jeu);
		img_to_window(&jeu);
		mlx_key_hook(jeu.win_ptr, &ft_move, &jeu);
		mlx_hook(jeu.win_ptr, DestroyNotify, StructureNotifyMask, &exit_and_leave, &jeu);
		mlx_loop(jeu.mlx_ptr);
		return (0);
	}
}
