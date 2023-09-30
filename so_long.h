/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:04:50 by adzinabi          #+#    #+#             */
/*   Updated: 2023/09/27 18:14:44 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./GNL/get_next_line.h"
# include "./ft_printf/ft_printf.h"
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_jeu
{
	char	**map;
	int		nbr_ligne;
	int		coin;
	int		perso;
	int		exit;
	int		len;
	int		nmi;
	char	**map_f;
	char	**map_p;
    void	*mlx_ptr;
	void	*win_ptr;
	void	*img_perso;
	void	*img_right;
	void	*img_left;
	void	*img_coin;
	void	*img_exit;
	void	*img_wall;
	void	*img_floor;
	void	*img_nmi;
	void	*end;
	void	*end_two;
	void	*pied;
	int		steps;
	char	*win_steps;
	int		x;
	int		y;
		int		hauteur;
	int		largeur;
}			t_jeu;


int			create_map(char *av1, t_jeu *jeu);
void		nbr_of_line(char *av1, t_jeu *jeu);
int			mur_haut_bas(t_jeu *jeu);
int			contenu_ligne(t_jeu *jeu);
int			check_letter(t_jeu *jeu);

int			error_letter(t_jeu *jeu);
int			check_valid_name(char *av1);
int			free_map(char **carte);
int			check_map(t_jeu *jeu);
void		free_all(t_jeu *jeu);

int			flood_fill(int x, int y, t_jeu *jeu);
char		**copy_map(char **map);
char		*copy(const char *src);
int			check_flood(t_jeu *jeu);
int			check_empty(t_jeu *jeu);

//mlx

void		xpm_to_img(t_jeu *jeu);
void		img_to_window(t_jeu *jeu);
int			disconnect(t_jeu *jeu);
int			ft_move(int keysym, t_jeu *jeu);
void		go_right(t_jeu *jeu);
void	    go_down(t_jeu *jeu);
void	    go_up(t_jeu *jeu);
void	    go_left(t_jeu *jeu);
int			count_move(int keysym);
int	exit_and_leave(t_jeu *jeu);
void	print_moves(t_jeu *jeu);
void moveEnemies(t_jeu *jeu);
int	end_frame(int keysym, t_jeu *jeu);

#endif