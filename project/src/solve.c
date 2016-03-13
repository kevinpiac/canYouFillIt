/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 16:25:00 by kpiacent          #+#    #+#             */
/*   Updated: 2016/03/13 11:14:37 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#include <stdio.h>

int		solve(unsigned int *tab, unsigned int i, int retry)
{
	int		res;
	//printf("-----------------------------  i-> %d\n", i);
	if (tab[i] == 0)
		return (1);
	res = solve_set(tab, i, retry);
	//printf("RES:::: %d\n", res);
	if (!res && i == 1)
	{
		tab[0]++;
		//printf("INCREASE --> %d\n", tab[0]);
		move_resetall(tab);
		return (solve(tab, i, 0));
	}
	if (res)
	{
		//printf("FORWAAAARD\n");
		move_topleft(&tab[i + 1]);
		return (solve(tab, i + 1, 0));
	}
	//printf("BACKKK\n");
	return (solve(tab, i - 1, 1));
}

int			solve_set(unsigned int *tab, unsigned int i, int retry)
{
	int				x;
	int				y;
	int				max_sq;
	unsigned int	tetcp;

	max_sq = tab[0];
	tetcp = tab[i];
	x = pos_getborder(tab[i], "bottom");
	y = pos_getborder(tab[i], "right");
	//printf("X->> %d\n", x);	//printf("Y->> %d\n", y);
	if (x >= max_sq || y >= max_sq)
		return (0);
	if (retry)
	{
		retry = 0;
		if (y + 1 < max_sq)
			move(&tab[i], "right");
		else if (y + 1 >= max_sq && x + 1 <= max_sq)
			move_nxtl(&tab[i]);
		return (solve_set(tab, i, retry));
	}
	if (pos_isfree(tab, tab[i], i))
		return (1);
	return (solve_set(tab, i, 1));
}

/*
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
	if ((pos_getborder(tab[i], "left") != 0 && pos_getborder(tab[i], "top") != 0) || tab[23] == 0)
	{
		//printf("IS FREE AND DIFF 0\n");
		flag = 1;
	}
	if (tab[23] == 1)
		tab[23] = 0;
	while (!pos_isfree(tab, tetcp, i) || flag)
	{
		//printf("NOT FREE\n");
		flag = 0;
		x = pos_getborder(tetcp, "bottom");
		y = pos_getborder(tetcp, "right");
		if (y + 1 < max_sq)
			move(&tetcp, "right");
		else if (y + 1 >= max_sq && x + 1 <= max_sq)
			move_nxtl(&tetcp);
		else
			return (0);
	}
	if (pos_getborder(tetcp, "bottom") >= max_sq || pos_getborder(tetcp, "right") >= max_sq)
	{
		//printf("TOO BIG\n");
		return (0);
	}
	tab[i] = tetcp;
	//printf("OK PLACED\n");
	return (1);
}
*/
