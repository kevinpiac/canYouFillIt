/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 15:45:49 by kpiacent          #+#    #+#             */
/*   Updated: 2016/03/15 15:22:04 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "t_ref.h"

int		check_tab(unsigned int *tab)
{
	int	i;
	int	j;
	int	sharp;

	j = 1;
	sharp = 0;
	while (tab[j] != 0)
	{
		i = 0;
		while (i < 19)
		{
			if (tab[j] == t_ref[i])
			{
				sharp++;
				break ;
			}
			i++;
		}
		j++;
	}
	return ((sharp == j - 1) ? 1 : -1);
}

int	check_buf(char *buff, int size)
{
	size_t	i;
	size_t	flag;
	int	nbsharp;

	i = 0;
	nbsharp = 0;
	flag = (size == 20) ? 1 : 0;
	while (buff[i])
	{
		if (buff[i] == '#' && nbsharp < 4)
		{
			nbsharp++;
			i++;
		}
		else if (((buff[i] == '.' && (i + flag) % 5 != 0)
					|| ((i + flag) % 5 == 0 && buff[i] == '\n'))
				&& nbsharp < 5)
			i++;
		else
			return (-1);
	}
	if (nbsharp != 4)
		return (-1);
	return ((i == ft_strlen(buff)) ? i : -1);
}
