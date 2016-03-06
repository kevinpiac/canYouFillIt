/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 14:46:50 by kpiacent          #+#    #+#             */
/*   Updated: 2016/03/06 15:17:43 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		pos_cmp(unsigned int t1, unsigned int t2 )
{
	return (t1 & t2);
}

int		pos_isfree(unsigned int *tab, unsigned int index, size_t size)
{
	size_t		i;

	i = 0;
	while (i < size)
	{
		ft_bitprint(pos_cmp(tab[index], tab[i]));
		if (i != index && pos_cmp(tab[index], tab[i]))
			return (0);
		i++;
	}
	return (1);
}
