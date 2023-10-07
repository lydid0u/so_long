#include "../so_long.h"

void	anim_watah(t_jeu *jeu, int i, int j)
{
	ft_reset_watah(jeu);
	while (jeu->map_p[i])
	{
		j = 0;

		while (jeu->map_p[i][j])
		{
			if (jeu->map_p[i][j] == 'E')
			{
				mlx_destroy_image(jeu->mlx_ptr, jeu->img_exit);
				if (jeu->watah >= 0 && jeu->watah < 100)
					tea_one(jeu, i, j);
				else if (jeu->watah >= 100 && jeu->watah < 200)
					tea_two(jeu, i, j);
				else if (jeu->watah >= 200 && jeu->watah < 300)					
					tea_three(jeu, i, j);
                else if (jeu->watah >= 300 && jeu->watah < 400)	
					tea_four(jeu, i, j);
			}
			j++;
		}
		i++;
	}
	jeu->watah++;
}

void	ft_reset_watah(t_jeu *jeu)
{
	if (jeu->watah == 400)
		jeu->watah = 0;
}

int	animation_loop_watah(t_jeu *jeu)
{
	anim_watah(jeu, 0, 0); 
	return (0); 
}