/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 16:25:00 by kpiacent          #+#    #+#             */
/*   Updated: 2016/03/12 18:39:18 by kpiacent         ###   ########.fr       */
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

int		solve(unsigned int *tab, unsigned int i)
{
	int		res;
//	printf("-----------------------------  i-> %d\n", i);


	if (tab[i] == 0)
		return (1);
	res = solve_set(tab, i);
	if (!res && i == 1)
	{
		tab[0]++;
//		printf("INCREASE --> %d\n", tab[0]);
		tab[23] = 1;
		move_resetall(tab);
		return (solve(tab, i));
	}
	if (res)
	{
//		printf("FORWAAAARD\n");
		return (solve(tab, i + 1));
	}
//	printf("BACKKK\n");
	return (solve(tab, i - 1));
}

int			solve_set(unsigned int *tab, unsigned int i)
{
	int				x;
	int				y;
	int				max_sq;
	int				flag;
	unsigned int	tetcp;

	flag = 0;
	max_sq = tab[0];
	tetcp = tab[i];
	if (ft_bitgetoctal(tab[i], 3) != 0 || tab[23] == 0)
	{
//		//printf("IS FREE AND DIFF 0\n");
		flag = 1;
	}
	if (tab[23] == 1)
		tab[23] = 0;
	while (!pos_isfree(tab, tetcp, i) || flag)
	{
		//printf("NOT FREE\n");
		flag = 0;
		x = solve_getmaxbottom(tetcp);
		y = solve_getmaxright(tetcp);
		if (y + 1 < max_sq)
			move_right(&tetcp);
		else if (y + 1 >= max_sq && x + 1 <= max_sq)
			move_nxtl(&tetcp);
		else
			return (0);
	}
	if (solve_getmaxbottom(tetcp) >= max_sq || solve_getmaxright(tetcp) >= max_sq)
	{
		//printf("TOO BIG\n");
		return (0);
	}
	tab[i] = tetcp;
	//printf("OK PLACED\n");
	return (1);
}
