/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:04:50 by adzinabi          #+#    #+#             */
/*   Updated: 2023/09/23 18:31:01 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
#include "./ft_printf/ft_printf.h"
# include "./GNL/get_next_line.h"
# include "minilibx-linux/mlx_int.h"
# include "minilibx-linux/mlx.h"

typedef struct s_jeu
{
    char    **map;
    int     nbr_ligne;
    int     collectible;
    int     perso;
    int     exit;
    int     len;
    char    **map_flood;
    char    **map_parser;
    int     x;
    int     y;
}           t_jeu;

typedef struct s_mlx
{
    void	*mlx_ptr;
    void	*win_ptr;
    void    *perso;
    void    *collectible;
    void    *exit;
    void    *wall;
    void    *floor;
    int     largeur;
    int     hauteur;
    
}	t_mlx;

int 	creation_carte(char *av1, t_jeu *jeu);
void    nombredeligne(char *av1, t_jeu *jeu);
int 	mur_haut_bas(t_jeu *jeu);
int     contenu_ligne(t_jeu *jeu);
int 	check_letter(t_jeu *jeu);

int 	error_letter(t_jeu *jeu);
int     check_valid_name(char *av1);
int    libere_carte(char **carte);
int     check_map(t_jeu *jeu);

int    flood_fill(int x, int y, t_jeu *jeu);
char    **copy_map(char **map);
char	*copy(const char *src);
int 	check_flood(t_jeu *jeu);


#endif