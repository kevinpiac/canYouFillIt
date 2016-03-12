/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 14:37:50 by kpiacent          #+#    #+#             */
/*   Updated: 2016/03/12 16:42:58 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "libft.h"
# include "fcntl.h"

/*
**    MOVE.C / FUNCTIONS TO MOVE
*/

void			move_down(unsigned int *t);
void			move_up(unsigned int *t);
void			move_left(unsigned int *t);
void			move_right(unsigned int *t);
void			move_topleft(unsigned int *t);
void			move_toleft(unsigned int *t);
void			move_nxtl(unsigned int *t);
void			move_resetall(unsigned int *tab);

/*
**    POS.C / FUNCTIONS TO CHECK POSITIONS
*/

int				pos_cmp(unsigned int t1, unsigned int t2);
int				pos_isfree(unsigned int *tab, unsigned int tet, int index);
int				pos_getindex(unsigned int *t, unsigned int x, unsigned int y);

/*
**    DEBUG.C
*/

void			debug_coordinates(unsigned int t);

/*
**    PRINT.C
*/

void			print_result(unsigned int *t);

/*
**    SOLVE.C
*/

size_t			solve_getsqsize(unsigned int *t, unsigned int nbr);
int				solve_set(unsigned int *tab, unsigned int index);
void			solve_setminsq(unsigned int *tab);
int				solve(unsigned int *tab, unsigned int i);

/*
**    READ.C
*/

int				read_file(char *file, unsigned int *tab);
unsigned int	read_buftoint(char *buf);
void			read_addtotab(unsigned int t, unsigned int *tab);

/*
**    CHECK.c
*/

int				check_buf(char *buf, int size);

#endif




