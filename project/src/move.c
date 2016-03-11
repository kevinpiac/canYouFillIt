/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 14:31:15 by kpiacent          #+#    #+#             */
/*   Updated: 2016/03/11 19:18:51 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	move_right(unsigned int *t)
{
	int		i;

	i = 6;
	while (i >= 0)
	{
		ft_bitsetfour(t, ft_bitgetfour(*t, i) + 1, i);
		i -= 2;
	}
}

void	move_left(unsigned int *t)
{
	int		i;

	i = 6;
	while (i >= 0)
	{
		ft_bitsetfour(t, ft_bitgetfour(*t, i) - 1, i);
		i -= 2;
	}
}

void	move_down(unsigned int *t)
{
	int		i;

	i = 7;
	while (i > 0)
	{
		ft_bitsetfour(t, ft_bitgetfour(*t, i) + 1, i);
		i -= 2;
	}
}

void	move_up(unsigned int *t)
{
	int		i;

	i = 7;
	while (i > 0)
	{
		ft_bitsetfour(t, ft_bitgetfour(*t, i) - 1, i);
		i -= 2;
	}
}

void	move_nxtl(unsigned int *t)
{
	unsigned int	tmp;

	tmp = *t;
	while (ft_bitgetfour(tmp, 6))
	{
		move_left(&tmp);
		move_left(t);
	}
	move_down(t);
}

void	move_topleft(unsigned int *t)
{
	unsigned int tmp;

	tmp = *t;
	while (ft_bitgetfour(tmp, 6))
	{
		move_left(&tmp);
		move_left(t);
	}
	while (ft_bitgetfour(tmp, 7))
	{
		move_up(&tmp);
		move_up(t);
	}
}


