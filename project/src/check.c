/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 15:45:49 by kpiacent          #+#    #+#             */
/*   Updated: 2016/03/15 17:19:49 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static unsigned int		*create_tref(void)
{
	unsigned int	*t_ref;

	if (!(t_ref = (unsigned int *)ft_memalloc(sizeof(unsigned int) * 19)))
		return (NULL);
	t_ref[0] = 69664;
	t_ref[1] = 69921;
	t_ref[2] = 66066;
	t_ref[3] = 34607378;
	t_ref[4] = 1056816;
	t_ref[5] = 1056801;
	t_ref[6] = 66064;
	t_ref[7] = 1052946;
	t_ref[8] = 69649;
	t_ref[9] = 69906;
	t_ref[10] = 1052961;
	t_ref[11] = 17830176;
	t_ref[12] = 16912401;
	t_ref[13] = 17899553;
	t_ref[14] = 66051;
	t_ref[15] = 1052960;
	t_ref[16] = 17830162;
	t_ref[17] = 17830177;
	t_ref[18] = 66065;
	return (t_ref);
}

int						check_tab(unsigned int *tab)
{
	int				i;
	int				j;
	int				sharp;
	unsigned int	*t_ref;

	t_ref = create_tref();
	j = 1;
	sharp = 0;
	while (tab[j] != 0)
	{
		i = 0;
		while (i < 19)
		{
			if (tab[j] == t_ref[i++])
			{
				sharp++;
				break ;
			}
		}
		j++;
	}
	if (sharp == j - 1)
		return (1);
	ft_putstr("error\n");
	return (-1);
}

int						check_buf(char *buff, int size)
{
	size_t			i;
	size_t			flag;
	int				nbsharp;

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
