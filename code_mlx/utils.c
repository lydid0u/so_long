/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:33:35 by lboudjel          #+#    #+#             */
/*   Updated: 2023/10/07 12:16:53 by lboudjel         ###   ########.fr       */
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

int	disconnect(t_jeu *jeu)
{
	mlx_destroy_image(jeu->mlx_ptr, jeu->img_wall);
	mlx_destroy_image(jeu->mlx_ptr, jeu->img_floor);
	mlx_destroy_image(jeu->mlx_ptr, jeu->img_right);
	mlx_destroy_image(jeu->mlx_ptr, jeu->img_left);
	mlx_destroy_image(jeu->mlx_ptr, jeu->img_exit);
	mlx_destroy_image(jeu->mlx_ptr, jeu->img_perso);
	mlx_destroy_image(jeu->mlx_ptr, jeu->img_coin);
	mlx_destroy_image(jeu->mlx_ptr, jeu->img_nmi);
	mlx_destroy_image(jeu->mlx_ptr, jeu->pied);
	mlx_loop_end(jeu->mlx_ptr);
	mlx_destroy_window(jeu->mlx_ptr, jeu->win_ptr);
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
