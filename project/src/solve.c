/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 16:25:00 by kpiacent          #+#    #+#             */
/*   Updated: 2016/03/15 16:58:20 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		solve(unsigned int *tab, unsigned int i, int retry)
{
	int		res;

	while (tab[i])
	{
		res = solve_set(tab, i, retry);
		if (!res && i == 1)
		{
			tab[0]++;
			move_resetall(tab);
			i++;
		}
		else if (res)
		{
			move_topleft(&tab[i + 1]);
			retry = 0;
			i++;
		}
		else
		{
			retry = 1;
			i--;
		}
	}
	return (1);
}

int		solve_set(unsigned int *tab, unsigned int i, int retry)
{
	unsigned int	x;
	unsigned int	y;

	x = pos_getborder(tab[i], "bottom");
	y = pos_getborder(tab[i], "right");
	if (y >= tab[0] || x >= tab[0])
		return (0);
	while (!pos_isfree(tab, tab[i], i) || retry)
	{
		retry = 0;
		if (y + 1 < tab[0])
			move(&tab[i], "right");
		else if (y + 1 >= tab[0] && x + 1 <= tab[0])
			move_nxtl(&tab[i]);
		x = pos_getborder(tab[i], "bottom");
		y = pos_getborder(tab[i], "right");
		if (y >= tab[0] || x >= tab[0])
			return (0);
	}
	return (1);
}
