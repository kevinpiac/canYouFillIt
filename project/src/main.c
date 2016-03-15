/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 18:54:27 by nhuber            #+#    #+#             */
/*   Updated: 2016/03/15 15:21:50 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int ac, char **av)
{
	unsigned int	*tab;
	unsigned int	bottom;
	unsigned int	right;

	if (ac > 2)
		print_usage();
	else
	{
		if (!(tab = (unsigned int *)ft_memalloc(sizeof(int) * 27)))
			return ((int)NULL);
		ft_bzero(tab, 27);
		if (read_file(av[1], tab) == -1)
			return (-1);
		move_resetall(tab);
		if (check_tab(tab) == -1)
			ft_putstr("error\n");
		else
		{
			right = pos_getborder(tab[1], "right");
			bottom = pos_getborder(tab[1], "bottom");
			tab[0] = right > bottom ? right : bottom;
			(void)solve(tab, 1, 0);
			print_result(tab);
		}
	}
	return (0);
}
