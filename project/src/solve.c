/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 16:25:00 by kpiacent          #+#    #+#             */
/*   Updated: 2016/03/13 13:21:06 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#include <stdio.h>

void		solve(unsigned int *tab, unsigned int i, int retry)
{
	int				res;

	printf("MAP: ---> %d\n", tab[0]);
	if (tab[i] == 0)
		return ;
	res = solve_set(tab, i, retry);
	if (!res && i == 1)
	{
		tab[0]++;
		move_resetall(tab);
		return (solve(tab, i, 0));
	}
	if (res)
	{
		move_topleft(&tab[i + 1]);
		return (solve(tab, i + 1, 0));
	}
	return (solve(tab, i - 1, 1));
}

int			solve_set(unsigned int *tab, unsigned int i, int retry)
{
	unsigned int	x;
	unsigned int	y;

	x = pos_getborder(tab[i], "bottom");
	y = pos_getborder(tab[i], "right");
	if (x >= tab[0] || y >= tab[0])
		return (0);
	if (retry)
	{
		if (y + 1 < tab[0])
			move(&tab[i], "right");
		else if (y + 1 >= tab[0] && x + 1 <= tab[0])
			move_nxtl(&tab[i]);
		return (solve_set(tab, i, 0));
	}
	if (pos_isfree(tab, tab[i], i))
		return (1);
	return (solve_set(tab, i, 1));
}
