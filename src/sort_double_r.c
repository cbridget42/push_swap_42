/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_double_r.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student-21school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 13:40:44 by cbridget          #+#    #+#             */
/*   Updated: 2022/02/19 12:54:33 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	double_rot(struct s_stcks **stck_b, struct s_stcks **stck_a,
				int pos, int act)
{
	int				mvdr[4];
	int				j;
	int				size_b;
	struct s_stcks	*tmp;

	j = -1;
	tmp = *stck_b;
	size_b = length_stck(*stck_b);
	mvdr[0] = pos;
	mvdr[2] = size_b - pos;
	while (++j < pos)
		tmp = tmp->next;
	cma(*stck_a, tmp->value, length_stck(*stck_a), mvdr);
	j = cm_rr(mvdr);
	if (mvdr[0] + mvdr[1] < mvdr[2] + mvdr[3])
		double_rot1(stck_a, stck_b, mvdr, act);
	else
		double_rot2(stck_a, stck_b, mvdr, act);
	return (j);
}

void	double_rot2(struct s_stcks **stck_a, struct s_stcks **stck_b,
					int *mvdr, int act)
{
	while (mvdr[2] && mvdr[3])
	{
		rrr(stck_a, stck_b, act);
		mvdr[2]--;
		mvdr[3]--;
	}
	while (mvdr[2])
	{
		*stck_b = rrotate_ab(*stck_b, 1, act);
		mvdr[2]--;
	}
	while (mvdr[3])
	{
		*stck_a = rrotate_ab(*stck_a, 0, act);
		mvdr[3]--;
	}
}

void	double_rot1(struct s_stcks **stck_a, struct s_stcks **stck_b,
					int *mvdr, int act)
{
	while (mvdr[0] && mvdr[1])
	{
		rr(stck_a, stck_b, act);
		mvdr[0]--;
		mvdr[1]--;
	}
	while (mvdr[0])
	{
		*stck_b = rotate_ab(*stck_b, 1, act);
		mvdr[0]--;
	}
	while (mvdr[1])
	{
		*stck_a = rotate_ab(*stck_a, 0, act);
		mvdr[1]--;
	}
}
