/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:46:59 by lboudjel          #+#    #+#             */
/*   Updated: 2023/10/14 15:08:08 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_countlen(long int n)
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
	len = ft_countlen(n);
	str = malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	len = len - 1;
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

void	loop_hook(t_jeu *jeu)
{
	img_to_window(jeu, 0, 0);
	mlx_key_hook(jeu->win_ptr, ft_move, jeu);
	mlx_hook(jeu->win_ptr, DestroyNotify, StructureNotifyMask, exit_and_leave,
		jeu);
	mlx_loop(jeu->mlx_ptr);
}

// int	destroy(t_jeu *jeu)
// {
// 	if (jeu->img_coin)
// 		mlx_destroy_image(jeu->mlx_ptr, jeu->img_coin);
// 	if (jeu->img_wall)
// 		mlx_destroy_image(jeu->mlx_ptr, jeu->img_wall);
// 	if (jeu->img_exit)
// 		mlx_destroy_image(jeu->mlx_ptr, jeu->img_exit);
// 	if (jeu->img_floor)
// 		mlx_destroy_image(jeu->mlx_ptr, jeu->img_floor);
// 	if (jeu->img_right)
// 		mlx_destroy_image(jeu->mlx_ptr, jeu->img_right);
// 	if (jeu->img_left)
// 		mlx_destroy_image(jeu->mlx_ptr, jeu->img_left);
// 	if (jeu->img_perso)
// 		mlx_destroy_image(jeu->mlx_ptr, jeu->img_perso);
// 	if (jeu->img_nmi)
// 		mlx_destroy_image(jeu->mlx_ptr, jeu->img_nmi);
// 	if (jeu->img_plant)
// 		mlx_destroy_image(jeu->mlx_ptr, jeu->img_plant);
// 	if (jeu->img_lamp)
// 		mlx_destroy_image(jeu->mlx_ptr, jeu->img_lamp);
// 	if (jeu->img_steps)
// 		mlx_destroy_image(jeu->mlx_ptr, jeu->img_steps);
// 	if (jeu->mlx_ptr)
// 	{
// 		mlx_loop_end(jeu->mlx_ptr);
// 		mlx_destroy_window(jeu->mlx_ptr, jeu->win_ptr);
// 		mlx_destroy_display(jeu->mlx_ptr);
// 		free(jeu->mlx_ptr);
// 	}
// 	// destroy_two(jeu);
// 	exit(0);
// }

// // void	destroy_two(t_jeu *jeu)
// // {
// // 	if (jeu->mlx_ptr)
// // 	{
// // 		mlx_loop_end(jeu->mlx_ptr);
// // 		mlx_destroy_window(jeu->mlx_ptr, jeu->win_ptr);
// // 		mlx_destroy_display(jeu->mlx_ptr);
// // 		free(jeu->mlx_ptr);
// // 	}
// // }
