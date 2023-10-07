/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:04:50 by lboudjel          #+#    #+#             */
/*   Updated: 2023/10/07 12:12:18 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./ft_printf/ft_printf.h"
# include "./get_next_line/get_next_line.h"
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
	char	**map_fd;
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
	void	*img_lamp;
	void	*img_plant;
	void	*anim_tea;
	void	*end;
	void	*end_two;
	void	*pied;
	int		steps;
	char	*win_steps;
	int		bonus_tea;
	int		watah;
	int		bonus_nmi;
	int		x;
	int		y;
	int		width;
	int		height;
}			t_jeu;

// parsing

int			create_map(char *av1, t_jeu *jeu, int i);
void		nbr_of_line(char *av1, t_jeu *jeu);
int			mur_haut_bas(t_jeu *jeu);
int			contenu_ligne(t_jeu *jeu, int i);
int			check_letter(t_jeu *jeu);
int			error_letter(t_jeu *jeu);
int			check_valid_name(char *av1);
int			free_map(char **carte);
int			check_map(t_jeu *jeu);
void		free_all(t_jeu *jeu);
int			flood_fill(int x, int y, t_jeu *jeu);
char		**copy_map(char **map);
char		*copy(const char *src);
int			check_flood(t_jeu *jeu, int i);
int			check_empty(t_jeu *jeu);

// mlx

int		xpm_to_img(t_jeu *jeu);
void		img_to_window(t_jeu *jeu, int i, int j);
int			disconnect(t_jeu *jeu);
int			ft_move(int keysym, t_jeu *jeu);
void		go_right(t_jeu *jeu);
void		go_down(t_jeu *jeu);
void		go_up(t_jeu *jeu);
void		go_left(t_jeu *jeu);
int			count_move(int keysym);
int			exit_and_leave(t_jeu *jeu);
void		print_moves(t_jeu *jeu);
void		moveEnemies(t_jeu *jeu);
int			end_frame(int keysym, t_jeu *jeu);
char		*ft_itoa(int nb);
int			ft_countlen(long int n);
void		anim_coin(t_jeu *jeu, int i, int j);
void		tea_one(t_jeu *jeu, int i, int j);
void		tea_two(t_jeu *jeu, int i, int j);
void		tea_three(t_jeu *jeu, int i, int j);
void		tea_four(t_jeu *jeu, int i, int j);
void		tea_five(t_jeu *jeu, int i, int j);
void		ft_reset(t_jeu *jeu);
void		print_img(t_jeu *jeu, int i, int j);
void		loop_hook(t_jeu *jeu);
int			flood_fill_stuck(int x, int y, t_jeu *jeu);
int			flood(t_jeu *jeu);
int			check_flood_nmi(t_jeu *jeu, int i);
int			animation_loop(t_jeu *jeu);
void	anim_watah(t_jeu *jeu, int i, int j);
void	anim_nmi(t_jeu *jeu, int i, int j);
void		ft_reset_watah(t_jeu *jeu);
void		ft_reset_nmi(t_jeu *jeu);
int			animation_loop_watah(t_jeu *jeu);
int			animation_loop_nmi(t_jeu *jeu);
void	don_left(t_jeu *jeu, int i, int j);
void	don_right(t_jeu *jeu, int i, int j);


#endif