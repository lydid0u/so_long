#include "../../so_long.h"

void	frame_sink(t_jeu *jeu, int i, int j)
{
	mlx_destroy_image(jeu->mlx_ptr, jeu->img_exit);
	if (jeu->bonus_exit >= 0 && jeu->bonus_exit < 50)
		sink_one(jeu, i, j);
	else if (jeu->bonus_exit >= 50 && jeu->bonus_exit < 100)
		sink_two(jeu, i, j);
	else if (jeu->bonus_exit >= 100 && jeu->bonus_exit < 150)
		sink_three(jeu, i, j);
	else if (jeu->bonus_exit >= 150 && jeu->bonus_exit < 200)
		sink_four(jeu, i, j);
	else if (jeu->bonus_exit >= 200 && jeu->bonus_exit < 250)
		sink_five(jeu, i, j);
}

void	anim_exit(t_jeu *jeu)
{
	int i;
	int j;

	i = 0;
	ft_reset_sink(jeu);
	while (jeu->map_p[i])
	{
		j = 0;
		while (jeu->map_p[i][j])
		{
			if (jeu->map_p[i][j] == 'E')
				frame_sink(jeu, i, j);
			j++;
		}
		i++;
	}
	jeu->bonus_exit++;
}

void	ft_reset_sink(t_jeu *jeu)
{
	if (jeu->bonus_exit == 250)
		jeu->bonus_exit = 0;
}
