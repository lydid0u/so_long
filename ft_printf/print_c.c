/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzinabi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 17:15:15 by adzinabi          #+#    #+#             */
/*   Updated: 2023/05/12 17:15:15 by adzinabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
on donne a va_arg un int qu'on cast ensuite en char, pour les char etendu
qui n'ont pas de place dans un char
*/

int	print_c(va_list args)
{
	char	c;

	c = (char)va_arg(args, int);
	ft_putchar(c);
	return (1);
}
