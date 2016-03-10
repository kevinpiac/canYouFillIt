/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 15:45:49 by kpiacent          #+#    #+#             */
/*   Updated: 2016/03/10 18:03:09 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		check_buf(char *buf, int size)
{
	int		nb_sharp;
	int		i;
	int		index;

	index = (size == 21) ? (0) : (1);
	i = 0;
	nb_sharp = 0;
	while (buf[i])
	{
		if (buf[i] == '.' && (i + index) % 5 != 0)
			i++;
		else if (buf[i] == '#' && (i + index) % 5 != 0)
		{
			i++;
			nb_sharp++;
		}
		else if (buf[i] == '\n' && (i + index) % 5 == 0)
			i++;
		else
			return (-1);
	}
	if (nb_sharp != 4)
		return (-1);
	return (1);
}
