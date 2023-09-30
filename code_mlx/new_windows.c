/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_windows.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:23:24 by lboudjel          #+#    #+#             */
/*   Updated: 2023/09/27 18:16:42 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	xpm_to_img(t_jeu *jeu)
{
	static int	width;
	static int	height;

	width = 64;
	height = 64;
	jeu->img_coin = mlx_xpm_file_to_image(jeu->mlx_ptr, "tea.xpm", &width,
			&height);
	jeu->img_wall = mlx_xpm_file_to_image(jeu->mlx_ptr, "./xpm/plant.xpm", &width,
			&height);
	jeu->img_exit = mlx_xpm_file_to_image(jeu->mlx_ptr, "door.xpm", &width,
			&height);
	jeu->img_floor = mlx_xpm_file_to_image(jeu->mlx_ptr, "floor.xpm", &width,
			&height);
	jeu->img_right = mlx_xpm_file_to_image(jeu->mlx_ptr, "perso_right.xpm", &width,
			&height);
	jeu->img_left = mlx_xpm_file_to_image(jeu->mlx_ptr, "perso2.xpm", &width,
			&height);
	jeu->img_perso = mlx_xpm_file_to_image(jeu->mlx_ptr, "persof.xpm", &width,
			&height);
	jeu->img_nmi = mlx_xpm_file_to_image(jeu->mlx_ptr, "don.xpm", &width,
			&height);
	jeu->pied = mlx_xpm_file_to_image(jeu->mlx_ptr, "doubl.xpm", &width,
			&height);
	// jeu->end = mlx_xpm_file_to_image(jeu->mlx_ptr, "oikawa.xpm", &width,
	// 		&height);
	// jeu->end_two = mlx_xpm_file_to_image(jeu->mlx_ptr, "haikyu.xpm", &width,
	// 		&height);
}

void	img_to_window(t_jeu *jeu)
{
	int	i;
	int	j;

	i = 0;
	while (jeu->map_p[i])
	{
		j = 0;
		while (jeu->map_p[i][j])
		{
			if (jeu->map_p[i][j] == 'C')
				mlx_put_image_to_window(jeu->mlx_ptr, jeu->win_ptr, jeu->img_coin, j
					* 64, i * 64);
			if (jeu->map_p[i][j] == '1')
				mlx_put_image_to_window(jeu->mlx_ptr, jeu->win_ptr, jeu->img_wall, j
					* 64, i * 64);
			if (jeu->map_p[i][j] == 'E')
				mlx_put_image_to_window(jeu->mlx_ptr, jeu->win_ptr, jeu->img_exit, j
					* 64, i * 64);
			if (jeu->map_p[i][j] == '0')
				mlx_put_image_to_window(jeu->mlx_ptr, jeu->win_ptr, jeu->img_floor,
					j * 64, i * 64);
			if (jeu->map_p[i][j] == 'P')
				mlx_put_image_to_window(jeu->mlx_ptr, jeu->win_ptr, jeu->img_perso,
					j * 64, i * 64);
			if (jeu->map_p[i][j] == 'D')
				mlx_put_image_to_window(jeu->mlx_ptr, jeu->win_ptr, jeu->img_nmi,
					j * 64, i * 64);
			mlx_put_image_to_window(jeu->mlx_ptr, jeu->win_ptr, jeu->pied,
					0, 0);
			j++;
		}
		i++;
	}
}

int    disconnect(t_jeu *jeu)
{
    mlx_destroy_image(jeu->mlx_ptr, jeu->img_wall);
    mlx_destroy_image(jeu->mlx_ptr, jeu->img_floor);
    mlx_destroy_image(jeu->mlx_ptr, jeu->img_exit);
    mlx_destroy_image(jeu->mlx_ptr, jeu->img_perso);
    mlx_destroy_image(jeu->mlx_ptr, jeu->img_coin);
	mlx_destroy_image(jeu->mlx_ptr, jeu->img_nmi);
    mlx_destroy_window(jeu->mlx_ptr, jeu->win_ptr);
	// toute les nouvelle image a destroy
    mlx_destroy_display(jeu->mlx_ptr);
	free(jeu->mlx_ptr);
   exit(0);
}

int	exit_and_leave(t_jeu *jeu)
{
		free_all(jeu);
		disconnect(jeu);
		exit(EXIT_SUCCESS);
}

static int	count_lenn(long int n)
{	
	int	len;

	len = 0;
	if (n < 0)
	{
		len++;
		n = n * -1;
	}
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int nb)
{
	long int	n;
	int			len;
	char		*str;

	n = nb;
	len = count_lenn(n);
	str = malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	len = len -1;
	if (n == 0)
		str[0] = '0';
	else if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	while (n != 0)
	{
		str[len--] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}

void	print_moves(t_jeu *jeu)
{
	jeu->win_steps = ft_itoa(jeu->steps);
	if (!jeu->win_steps)
		return ;
	mlx_string_put(jeu->mlx_ptr, jeu->win_ptr, 78, 30, 0xbc7241,
		jeu->win_steps);
	free(jeu->win_steps);
	jeu->steps++;
	jeu->win_steps = ft_itoa(jeu->steps);
	mlx_string_put(jeu->mlx_ptr, jeu->win_ptr, 78, 30, 0xFFFFFF,
		jeu->win_steps);
	free(jeu->win_steps);
}

// int	end_frame(int keysym, t_jeu *jeu)
// {
// 	printf("ok");
// 	mlx_put_image_to_window(jeu->mlx_ptr, jeu->win_ptr, jeu->end, 0, 0);
// 	printf("123");

// 	if (keysym == 46)
// 	{
// 		mlx_destroy_image(jeu->mlx_ptr, jeu->end);
// 		mlx_put_image_to_window(jeu->mlx_ptr, jeu->win_ptr, jeu->end_two, 0, 0);
// 		printf("salut");
// 	}
// 	if(keysym == XK_l)
// 	{
// 		printf("ok");

// 		free_all(jeu);
// 		disconnect(jeu);
// 		exit(EXIT_SUCCESS);
// 	}
// 	return (0);
// }