#include "../so_long.h"

void	anim_nmi(t_jeu *jeu, int i, int j)
{
	ft_reset_nmi(jeu);
	while (jeu->map_p[i])
	{
		j = 0;

		while (jeu->map_p[i][j])
		{
			if (jeu->map_p[i][j] == 'D')
			{
				mlx_destroy_image(jeu->mlx_ptr, jeu->img_nmi);
				if (jeu->bonus_nmi >= 0 && jeu->bonus_nmi < 50)
					don_left(jeu, i, j);
				else if (jeu->bonus_nmi >= 50 && jeu->bonus_nmi < 100)
					don_right(jeu, i, j);
			}
			j++;
		}
		i++;
	}
	jeu->bonus_nmi++;
}

void	ft_reset_nmi(t_jeu *jeu)
{
	if (jeu->bonus_nmi == 100)
		jeu->bonus_nmi = 0;
}

int	animation_loop_nmi(t_jeu *jeu)
{
	anim_nmi(jeu, 0, 0); 
	return (0); 
}