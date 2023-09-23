/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzinabi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 23:05:25 by adzinabi          #+#    #+#             */
/*   Updated: 2023/07/13 23:05:26 by adzinabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strclen(char *str, char c)
{
	int	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len] && str[len] != c)
		len++;
	return (len);
}
