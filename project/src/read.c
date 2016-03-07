/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 10:03:23 by kpiacent          #+#    #+#             */
/*   Updated: 2016/03/07 15:54:43 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	read_file(char *file, unsigned int *tab)
{
	int		fd;
	int		ret;
	char	buf[20];

	if ((fd = open(file, O_RDONLY)) != -1)
	{
		while ((ret = read(fd, buf, 20)))
		{
			check_buf(buf);
			(void)tab;
		}
		//print_error
	}
	//check_buf;
}















