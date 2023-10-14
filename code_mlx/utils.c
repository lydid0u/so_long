/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:46:59 by lboudjel          #+#    #+#             */
/*   Updated: 2023/10/14 16:19:15 by lboudjel         ###   ########.fr       */
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

void	find_pos_exit(t_jeu *jeu, int i, int j)
{
	jeu->exit++;
	jeu->map_p[i][j] = '0';
	jeu->exit_x = i;
	jeu->exit_y = j;
}
