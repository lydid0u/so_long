/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzinabi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 17:15:20 by adzinabi          #+#    #+#             */
/*   Updated: 2023/05/12 17:15:23 by adzinabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_d_i(va_list args)
{
	long long int	n;

	n = va_arg(args, int);
	ft_putnbr(n);
	return (count_len(n));
}
