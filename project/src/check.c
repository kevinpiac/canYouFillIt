/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 15:45:49 by kpiacent          #+#    #+#             */
/*   Updated: 2016/03/15 11:48:31 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "t_ref.h"

static const unsigned int t_ref[19] = {3665, 565565};

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

int		check_tet(unsigned int t)
{
	int		i;

	i = 0;
	while (i < 19)
	{
		if (pos_cmp(t, t_ref[i]) == t)
			return (1);
		i++;
	}
	return (-1);
}
