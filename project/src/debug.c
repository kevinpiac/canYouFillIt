/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 15:22:11 by kpiacent          #+#    #+#             */
/*   Updated: 2016/03/06 15:47:47 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	debug_coordinates(unsigned int t)
{
	int		i;
	int		n;
	char	c;

	i = 7;
	n = 0;
	while (i >= 0)
	{
		if (i % 2)
			c = 'x';
		else
			c = 'y';
		ft_putchar(c);
		ft_putnbr(n);
		ft_putstr(": ");
		ft_putnbr(ft_bitgetfour(t, i));
		if (!(i % 2))
			ft_putchar('\n');
		else
			ft_putstr("   ----   ");
		n++;
		i--;
	}
}
