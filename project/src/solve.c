/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 16:25:00 by kpiacent          #+#    #+#             */
/*   Updated: 2016/03/11 20:16:05 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int			ft_sqrt(int n)
{
	int		i;

	i = 0;
	while (i * i <= n)
		i++;
	return (i - 1);
}

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

int		solve_getmaxright(unsigned int t)
{
	int					i;
	unsigned int		y;

	i = 6;
	y = ft_bitgetfour(t, i);
	while (i >= 0)
	{
		if (ft_bitgetfour(t, i) > y)
			y = ft_bitgetfour(t, i);
		i -= 2;
	}
	return (y);
}

int		solve_getmaxbottom(unsigned int t)
{
	int					i;
	unsigned int		x;

	i = 7;
	x = ft_bitgetfour(t, i);
	while (i > 0)
	{
		if (ft_bitgetfour(t, i) > x)
			x = ft_bitgetfour(t, i);
		i -= 2;
	}
	return (x);
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

int			solve_set(unsigned int *tab, unsigned int i)
{
	int		x;
	int		y;
	int		max_sq;

	y = solve_getmaxright(tab[i]);
	x = solve_getmaxbottom(tab[i]);
//	x = 0;
	max_sq = 2;
	printf("Y: %d\n", y);
	printf("X: %d\n", x);
	printf("Max sq: %d\n\n----\n", max_sq);
	while (x < max_sq - 1)
	{
		while (y < max_sq - 1)
		{
			move_right(&tab[i]);
			if (pos_isfree(tab, i))
				return (1);
			y++;
		}
		move_nxtl(&tab[i]);
		x++;
		y = 0;
	}
	return (0);
}






