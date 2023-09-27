/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 16:24:27 by lboudjel          #+#    #+#             */
/*   Updated: 2023/09/24 17:03:26 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "so_long.h"

// int	main(int argc, char **argv)
// {
// 	static t_jeu	jeu = {0};

// 	if (argc == 2)
// 	{
// 		if (!(check_valid_name(argv[1])))
// 			return (0);
// 		if (!(create_map(argv[1], &jeu)))
// 			return (0);
// 		if (!(check_empty(&jeu)))
// 			return (0);
// 		jeu.map_p = copy_map(jeu.map);
// 		if (!(check_map(&jeu)))
// 			return (0);
// 		jeu.map_f = copy_map(jeu.map);
// 		flood_fill(jeu.x, jeu.y, &jeu);
// 		if (!(check_flood(&jeu)))
// 			return (0);
// 		free_all(&jeu);
// 	}
// 	return (0);
// }
