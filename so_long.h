/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:09:32 by lboudjel          #+#    #+#             */
/*   Updated: 2023/10/14 15:09:50 by lboudjel         ###   ########.fr       */
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
	void	*img_steps;
	void	*img_plant;
	void	*anim_tea;
	int		steps;
	char	*win_steps;
	int		bonus_tea;
	int		bonus_exit;
	int		bonus_nmi;
	int		x;
	int		y;
	int		width;
	int		height;
}			t_jeu;

//					parsing					//

//map_checker
void		nbr_of_line(char *av1, t_jeu *jeu);
int			create_map(char *av1, t_jeu *jeu, int i);
int			check_letter(t_jeu *jeu);
int			check_valid_name(char *av1);
int			check_map(t_jeu *jeu);

//handle_error
int			error_letter(t_jeu *jeu);
int			wall_up_down(t_jeu *jeu);
int			line_size(t_jeu *jeu);
int			check_empty(t_jeu *jeu);
int			content_line(t_jeu *jeu, int i);

//free
int			free_map(char **carte);
void		free_all(t_jeu *jeu);

//flood_fill
int			flood_fill(int x, int y, t_jeu *jeu);
void		change_ennemi_and_exit_to_wall(t_jeu *jeu);
int			flood_fill_checker(t_jeu *jeu);

//					mlx					//

//new windows
int			xpm_to_img(t_jeu *jeu);
int			xpm_to_img_two(t_jeu *jeu);
void		img_to_window(t_jeu *jeu, int i, int j);
void		print_img(t_jeu *jeu, int i, int j);
void		print_moves(t_jeu *jeu);

//utils
char		*ft_itoa(int nb);
int			ft_countlen(long int n);
void		loop_hook(t_jeu *jeu);

//movement
void		go_right(t_jeu *jeu);
void		go_down(t_jeu *jeu);
void		go_up(t_jeu *jeu);
void		go_left(t_jeu *jeu);
int			ft_move(int keysym, t_jeu *jeu);

//leaving
int			destroy(t_jeu *jeu);
void		destroy_two(t_jeu *jeu);
int			exit_and_leave(t_jeu *jeu);

//copy
char		**copy_map(char **map);
char		*copy(const char *src);

//					bonus					//

//bonus collectible
int			animation_loop(t_jeu *jeu);
void		anim_coin(t_jeu *jeu, int i, int j);
void		tea_one(t_jeu *jeu, int i, int j);
void		tea_two(t_jeu *jeu, int i, int j);
void		tea_three(t_jeu *jeu, int i, int j);
void		tea_four(t_jeu *jeu, int i, int j);
void		tea_five(t_jeu *jeu, int i, int j);
void		ft_reset(t_jeu *jeu);

//bonus ennemi
void		anim_nmi(t_jeu *jeu, int i, int j);
void		ft_reset_nmi(t_jeu *jeu);
void		don_left(t_jeu *jeu, int i, int j);
void		don_right(t_jeu *jeu, int i, int j);

//bonus exit
void		frame_sink(t_jeu *jeu, int i, int j);
void		anim_exit(t_jeu *jeu);
void		ft_reset_sink(t_jeu *jeu);
void		sink_one(t_jeu *jeu, int i, int j);
void		sink_two(t_jeu *jeu, int i, int j);
void		sink_three(t_jeu *jeu, int i, int j);
void		sink_four(t_jeu *jeu, int i, int j);
void		sink_five(t_jeu *jeu, int i, int j);

#endif