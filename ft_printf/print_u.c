/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzinabi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 17:15:47 by adzinabi          #+#    #+#             */
/*   Updated: 2023/05/12 17:15:49 by adzinabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_u(va_list args)
{
	size_t	n;

	n = va_arg(args, size_t);
	ft_putnbr_positive(n);
	return (count_len_u(n));
}
