/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 16:25:00 by kpiacent          #+#    #+#             */
/*   Updated: 2016/03/07 10:50:22 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

size_t		solve_getsqsize(unsigned int *t, unsigned int nbr)
{
	int				i;
	unsigned int	n;
	unsigned int	y;
	unsigned int	x;

	n = 0;
	while (n < nbr)
	{
		i = 7;
		x = 0;
		y = 0;
		while (i > 0)
		{
			if (ft_bitgetfour(t[n], i) > x)
				x = ft_bitgetfour(t[n], i);

			if (ft_bitgetfour(t[n], i - 1) > y)
				y = ft_bitgetfour(t[n], i - 1);
			i--;
		}
		n++;
	}
	if (x > y)
		return (x);
	return (y);
}
