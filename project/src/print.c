/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 15:49:06 by kpiacent          #+#    #+#             */
/*   Updated: 2016/03/11 11:52:06 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_result(unsigned int *t)
{
	int				index;
	unsigned int	x;
	unsigned int	y;

	x = 0;
	while (x != (t[0] >> 24))
	{
		y = 0;
		while (y != (t[0] >> 24))
		{
			index = pos_getindex(t, x, y);
			if (index > 0)
			{
				ft_putchar('A' + (index - 1));
				index = 0;
			}
			else
				ft_putchar('.');
			y++;
		}
		ft_putchar('\n');
		x++;
	}
}

