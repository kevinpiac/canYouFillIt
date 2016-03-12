/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 16:25:00 by kpiacent          #+#    #+#             */
/*   Updated: 2016/03/12 12:01:23 by kpiacent         ###   ########.fr       */
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
#include <stdio.h>

void	solve(unsigned int i, unsigned int *tab)
{
	if (tab[i] == 0)
		return ;
	if (i == 0 || solve_set(tab, i))
		return (solve(i + 1, tab));
	else if (!solve_set(tab, i) && i == 1)
	{
		tab[0]++;
		move_resetall(tab);
		printf("POS IS FREE ? -> %d\n", pos_isfree(tab, tab[i], i));
		if (pos_isfree(tab, tab[i], i))
		{
			return (solve(i + 1, tab));
		}
		return (solve(i, tab));
	}
	else
		return (solve(i - 1, tab));
}


int			solve_set(unsigned int *tab, unsigned int i)
{
	int		x;
	int		y;
	int		max_sq;
	unsigned int	tetcp;

	y = solve_getmaxright(tab[i]);
	x = solve_getmaxbottom(tab[i]);
	max_sq = tab[0];

	while (x < max_sq)
	{
		while (y + 1 < max_sq)
		{
			tetcp = tab[i];
			move_right(&tetcp);
			if (pos_isfree(tab, tetcp, i))
			{
				move_right(&tab[i]);
				print_result(tab);
				ft_putchar('\n');
				return (1);
			}
			y++;
		}
		tetcp = tab[i];
		move_nxtl(&tetcp);
		if (pos_isfree(tab, tetcp, i) && x + 1 < max_sq)
		{
			move_nxtl(&tab[i]);
			print_result(tab);
			ft_putchar('\n');
			return (1);
		}
		x++;
		y = 0;
	}
	return (0);
}
