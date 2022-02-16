/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stck2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student-21school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 16:35:06 by cbridget          #+#    #+#             */
/*   Updated: 2022/02/15 11:25:00 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	pushallback(struct s_stcks **stck_a, struct s_stcks **stck_b)
{
	int	sizes[3];

	sizes[0] = length_stck(*stck_a);
	sizes[1] = length_stck(*stck_b);
	sizes[2] = choose_find(*stck_a, *stck_b);
	if (sizes[2] == -1)
	{
		clean_stck(*stck_b);
		return (1);
	}
	while (*stck_b)
	{
		count_moves(*stck_a, *stck_b, sizes[1], sizes[0]);
		pushallback_logic(stck_a, stck_b, sizes);
		*stck_b = push_ab(stck_a, *stck_b, 0, 1);
		if (!*stck_a)
			return (1);
		sizes[1] -= 1;
		sizes[0] += 1;
	}
	return (0);
}

void	pushallback_logic(struct s_stcks **stck_a, struct s_stcks **stck_b,
						int *sizes)
{
	int	min;
	int	flg;

	if (!sizes[2])
		flg = findmin(*stck_b, &min);
	else
		flg = findmin_last(*stck_b, &min);
	if (flg)
		double_rot(stck_b, stck_a, min, 1);
	else
	{
		rot_b(stck_b, min, sizes[1], 1);
		rot_a(stck_a, stck_b, sizes[0], 1);
	}
}

void	count_moves(struct s_stcks *stck_a, struct s_stcks *stck_b,
					int size_b, int size_a)
{
	int	i;
	int	mvdr[4];
	int	m_dr;

	i = 0;
	while (i < size_b)
	{
		count_moves_logic(stck_b, size_b, i);
		mvdr[0] = i;
		mvdr[2] = size_b - i;
		stck_b->move += cma(stck_a, stck_b->value, size_a, mvdr);
		stck_b->flag = 0;
		m_dr = cm_rr(mvdr);
		if (m_dr < stck_b->move)
		{
			stck_b->move = m_dr;
			stck_b->flag = 1;
		}
		stck_b = stck_b->next;
		i++;
	}
}

void	count_moves_logic(struct s_stcks *stck_b, int size_b, int i)
{
	if (size_b % 2)
	{
		if (i <= size_b / 2)
			stck_b->move = i;
		else
			stck_b->move = size_b - i;
	}
	else
	{
		if (i < size_b / 2)
			stck_b->move = i;
		else
			stck_b->move = size_b - i;
	}
}

int	cm_rr(int *mvdr)
{
	int	min1;
	int	min2;

	if (mvdr[0] > mvdr[1])
		min1 = mvdr[0];
	else
		min1 = mvdr[1];
	if (mvdr[2] > mvdr[3])
		min2 = mvdr[2];
	else
		min2 = mvdr[3];
	if (min1 < min2)
		return (min1);
	else
		return (min2);
}
