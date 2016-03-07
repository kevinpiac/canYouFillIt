/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 10:03:23 by kpiacent          #+#    #+#             */
/*   Updated: 2016/03/07 17:46:06 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

void	read_file(char *file, unsigned int *tab)
{
	int		fd;
	int		ret;
	char	buf[22];

	if ((fd = open(file, O_RDONLY)) != -1)
	{
		while ((ret = read(fd, buf, 21)))
		{
			buf[ret] = '\0';
			if (check_buf(buf) == -1)
			{
				ft_putstr_fd("error\n", 0);
				return ;
			}
			(void)tab;

		}
		//print_error
	}
	//check_buf;
}















