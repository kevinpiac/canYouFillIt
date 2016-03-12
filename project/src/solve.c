/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 16:25:00 by kpiacent          #+#    #+#             */
/*   Updated: 2016/03/12 16:06:19 by kpiacent         ###   ########.fr       */
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

void	solve(unsigned int *tab, unsigned int i)
{
	if (i == 0)
		return (solve(tab, i + 1));
	if (!tab[i])
		return ;
	if (solve_set(tab, i))
	{
		printf("FORWAAAARD\n");
		return (solve(tab, i + 1));

	}
	if (!solve_set(tab, i) && i == 1)
	{
		tab[0]++;
		move_topleft(&tab[1]);
		return (solve(tab, i));
	}
	else
	{
		printf("BACKKK\n");
		return (solve(tab, i - 1));

	}

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
	if (pos_isfree(tab, tab[i], i) && ft_bitgetoctal(tab[i], 3) != 0)
	{
		printf("1111111111\n");
		flag = 1;
	}
	while (!pos_isfree(tab, tetcp, i) || flag)
	{
			printf("2222222222\n");
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
		printf("33333333333\n");
		return (0);

	}
	tab[i] = tetcp;
	printf("4444444444444444\n");
	return (1);
}
