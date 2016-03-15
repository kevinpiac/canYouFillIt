/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 14:46:50 by kpiacent          #+#    #+#             */
/*   Updated: 2016/03/15 13:57:35 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

unsigned int	pos_cmp(unsigned int t1, unsigned int t2)
{
	return (t1 & t2);
}

int		pos_isfree(unsigned int *tab, unsigned int tet, int index)
{
	int		i;
	int		x;
	int		y;
	int		res;

	i = 7;
	while (i >= 0)
	{
		x = ft_bitgetfour(tet, i);
		y = ft_bitgetfour(tet, i - 1);
		res = pos_getindex(tab, x, y);
		if (res > 0 && res < index)
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

int		pos_getborder(unsigned int t, char *border)
{
	int					i;
	unsigned int		x;

	if (!ft_strcmp(border, "right") || !ft_strcmp(border, "left"))
		i = 6;
	else
		i = 7;
	x = ft_bitgetfour(t, i);
	if (!ft_strcmp(border, "right") || !ft_strcmp(border, "bottom"))
	{
		while (i >= 0)
		{
			if (ft_bitgetfour(t, i) > x)
				x = ft_bitgetfour(t, i);
			i -= 2;
		}
		return (x);
	}
	while (i >= 0)
	{
		if (ft_bitgetfour(t, i) < x)
			x = ft_bitgetfour(t, i);
		i -= 2;
	}
	return (x);
}
