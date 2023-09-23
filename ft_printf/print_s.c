/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzinabi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 17:15:42 by adzinabi          #+#    #+#             */
/*   Updated: 2023/05/12 17:15:43 by adzinabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

int	print_s(va_list args)
{
	char	*s;

	s = (char *)va_arg(args, char *);
	if (s == NULL)
		return (ft_putstr("(null)"));
	else
		ft_putstr(s);
	return (ft_strlen(s));
}
