/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 10:03:23 by kpiacent          #+#    #+#             */
/*   Updated: 2016/03/15 17:55:51 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int				read_fill(int fd, unsigned int *tab)
{
	int				ret;
	int				size;
	char			buf[22];
	unsigned int	t;

	size = 20;
	while ((ret = read(fd, buf, size)))
	{
		buf[ret] = '\0';
		if (check_buf(buf, ret) != size || ret != size)
			return (-1);
		read_buftoint(buf, &t);
		read_addtotab(t, tab);
		size = 21;
	}
	return (1);
}

int				read_file(char *file, unsigned int *tab)
{
	int				fd;

	if ((fd = open(file, O_RDONLY)) != -1)
	{
		if (read_fill(fd, tab) == -1 || close(fd) == -1)
			ft_putstr("error\n");
		else
			return (1);
	}
	return (-1);
}

void			read_addtotab(unsigned int t, unsigned int *tab)
{
	tab++;
	while (*tab != 0)
		tab++;
	*tab = t;
}

void			read_buftoint(char *buf, unsigned int *t)
{
	int				x;
	int				y;
	int				i;

	x = 0;
	y = 0;
	i = 7;
	*buf == '\n' ? buf++ : buf;
	while (*buf)
	{
		if (*buf == '#')
		{
			ft_bitsetfour(t, x, i);
			ft_bitsetfour(t, y, i - 1);
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
}
