/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 14:31:15 by kpiacent          #+#    #+#             */
/*   Updated: 2016/03/12 21:00:44 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	move(unsigned int *t, char *direction)
{
	int		i;
	int		sign;

	if (!ft_strcmp(direction, "down") || !ft_strcmp(direction, "right"))
		sign = 1;
	else
		sign = -1;
	if (!ft_strcmp(direction, "left") || !ft_strcmp(direction, "right"))
		i = 6;
	else
		i = 7;
	while (i >= 0)
	{
		ft_bitsetfour(t, ft_bitgetfour(*t, i) + sign, i);
		i -= 2;
	}
}

void	move_nxtl(unsigned int *t)
{
	unsigned int	tmp;

	tmp = *t;
	while (pos_getborder(tmp, "left"))
	{
		move(&tmp, "left");
		move(t, "left");
	}
	move(t, "down");
}

void	move_topleft(unsigned int *t)
{
	unsigned int tmp;

	tmp = *t;
	while (pos_getborder(tmp, "left"))
	{
		move(&tmp, "left");
		move(t, "left");
	}
	while (pos_getborder(tmp, "top"))
	{
		move(&tmp, "up");
		move(t, "up");
	}
}

void	move_resetall(unsigned int *tab)
{
	int		i;

	i = 1;
	while (tab[i])
	{
		move_topleft(&tab[i]);
		i++;
	}
}
