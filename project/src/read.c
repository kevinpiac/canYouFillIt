/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 10:03:23 by kpiacent          #+#    #+#             */
/*   Updated: 2016/03/10 18:45:14 by kpiacent         ###   ########.fr       */
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
			if (check_buf(buf, ret) == -1)
			{
				ft_putstr_fd("error\n", 0);
				return (-1);
			}
			(void)tab;
			ft_putnbr(read_buftoint(buf));
			ft_putstr("\n");
			ft_bitprint(read_buftoint(buf));

			size = 21;
		}
		return (1);
	}
	return (-1);
}

unsigned int	read_buftoint(char *buf)
{
	int				x;
	int				y;
	int				i;
	unsigned int	t;

	t = 0;
	x = 0;
	y = 0;
	i = 7;
	while (*buf)
	{
		if (*buf == '#')
		{
			ft_bitsetfour(&t, x, i);
			ft_bitsetfour(&t, y, i - 1);
			i -= 2;
		}
		if (*buf == '\n')
		{
			x++;
			y = 0;
		}
		else
			y++;
		buf++;
	}
	return (t);
}
