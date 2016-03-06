/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 14:37:50 by kpiacent          #+#    #+#             */
/*   Updated: 2016/03/06 16:31:01 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "libft.h"

/*
**    MOVE.C / FUNCTIONS TO MOVE
*/

void	move_down(unsigned int *t);
void	move_up(unsigned int *t);
void	move_left(unsigned int *t);
void	move_right(unsigned int *t);
void	move_topleft(unsigned int *t);

/*
**    POS.C / FUNCTIONS TO CHECK POSITIONS
*/

int		pos_cmp(unsigned int t1, unsigned int t2);
int		pos_isfree(unsigned int *tab, unsigned int index, size_t size);

/*
**    DEBUG.C
*/

void	debug_coordinates(unsigned int t);

/*
**    PRINT.C
*/

void	print_result(unsigned int *t, size_t nbr);

#endif
