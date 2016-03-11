/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 16:25:00 by kpiacent          #+#    #+#             */
/*   Updated: 2016/03/11 16:29:33 by kpiacent         ###   ########.fr       */
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
	return ((x > y)? x : y);
}

void	solve(unsigned int i, unsigned int *tab)
{
	if (tab[i] == 0)
		return ;
	if (i == 0 || solve_set(tab, i))
		return (solve(i + 1, tab));
	else
		return (solve(i - 1, tab));
}

#include <stdio.h>

int			solve_set(unsigned int *tab, int i)
{
	size_t		min_sq;
	size_t		x;
	size_t		y;

	x = 0;
	y = 0;
	min_sq = 5;

	while (x < min_sq)
	{
		y = 0;
		move_toleft(&tab[i]);
		while (y < min_sq)
		{
			if (pos_isfree(tab, i, i))
				return (1);
			move_right(&tab[i]);
			y++;
		}
		x++;
	}
	return (0);
}










