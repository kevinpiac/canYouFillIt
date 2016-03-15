/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 10:03:23 by kpiacent          #+#    #+#             */
/*   Updated: 2016/03/15 15:22:07 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

int				read_file(char *file, unsigned int *tab)
{
	int		fd;
	int		ret;
	int		size;
	char	buf[22];

	size = 20;
	if ((fd = open(file, O_RDONLY)) != -1)
	{
		while ((ret = read(fd, buf, size)))
		{
			buf[ret] = '\0';
			if (check_buf(buf, ret) != size || ret != size)
			{
				ft_putstr("error\n");
				return (-1);
			}
			read_addtotab(read_buftoint(buf), tab);
			size = 21;
		}
		return (1);
	}
	return (-1);
}

/*
** Considering that the unsigned int *tab wad bzeroed before.
*/

void	read_addtotab(unsigned int t, unsigned int *tab)
{
	tab++;
	while (*tab != 0)
		tab++;
	*tab = t;
}

unsigned int	read_buftoint(char *buf)
{
	int				x;
	int				y;
	int				i;
	unsigned int	t;

	x = 0;
	y = 0;
	i = 7;
	*buf == '\n' ? buf++ : buf;
	while (*buf)
	{
		if (*buf == '#')
		{
			ft_bitsetfour(&t, x, i);
			ft_bitsetfour(&t, y, i - 1);
			i -= 2;
		}
		y++;
		if (*buf == '\n')
		{
			x++;
			y = 0;
		}
		buf++;
	}
	return (t);
}
