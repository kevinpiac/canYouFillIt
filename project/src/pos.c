/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 14:46:50 by kpiacent          #+#    #+#             */
/*   Updated: 2016/03/11 19:37:24 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int				pos_cmp(unsigned int t1, unsigned int t2 )
{
	return (t1 & t2);
}

int		pos_isfree(unsigned int *tab, int index)
{
	int		i;
	int		x;
	int		y;

	i = 7;
	while (i >= 0)
	{
		x = ft_bitgetfour(tab[index], i);
		y = ft_bitgetfour(tab[index], i - 1);
		if (pos_getindex(tab, x, y) > 0 && pos_getindex(tab, x, y) < index)
			return (0);
		i -= 2;
	}
	return (1);
}

int		pos_getindex(unsigned int *t, unsigned int x, unsigned int y)
{
	unsigned int	i;
	unsigned int	j;

	i = 1;
	while (t[i] != 0)
	{
		j = 0;
		while ((ft_bitgetfour(t[i], j + 1) != x ||
				ft_bitgetfour(t[i], j) != y) && j < 8)
			j += 2;
		if (j < 8)
			return (i);
		i++;
	}
	return (0);
}
