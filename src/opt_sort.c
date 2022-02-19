/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student-21school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 11:43:09 by cbridget          #+#    #+#             */
/*   Updated: 2022/02/19 12:54:49 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	choose_find(struct s_stcks *stck_a, struct s_stcks *stck_b)
{
	int				bs[3];
	int				i;
	struct s_stcks	*new_stck_a;
	struct s_stcks	*new_stck_b;

	i = -1;
	bs[0] = 0;
	bs[1] = 0;
	while (++i < 2)
	{
		if (choose_find_01(&new_stck_a, &new_stck_b, stck_a, stck_b))
			return (-1);
		if (choose_find2(&new_stck_a, &new_stck_b, bs, i))
			return (-1);
		bs[i] += rrightpositiona(&new_stck_a, 0);
		clean_stck(new_stck_a);
	}
	if (bs[0] > bs[1])
		return (0);
	else
		return (1);
}

int	choose_find_01(struct s_stcks **new_stck_a, struct s_stcks **new_stck_b,
					struct s_stcks *stck_a, struct s_stcks *stck_b)
{
	*new_stck_a = creat_ns(stck_a);
	if (!*new_stck_a)
		return (1);
	*new_stck_b = creat_ns(stck_b);
	if (!*new_stck_b)
	{
		clean_stck(*new_stck_a);
		return (1);
	}
	return (0);
}

int	choose_find2(struct s_stcks **new_stck_a, struct s_stcks **new_stck_b,
				int *bs, int i)
{
	int	size_b;
	int	size_a;
	int	min;

	size_b = length_stck(*new_stck_b);
	size_a = length_stck(*new_stck_a);
	while (*new_stck_b)
	{
		count_moves(*new_stck_a, *new_stck_b, size_b, size_a);
		if (i)
			bs[2] = findmin(*new_stck_b, &min);
		else
			bs[2] = findmin_last(*new_stck_b, &min);
		if (bs[2])
			bs[i] += double_rot(new_stck_b, new_stck_a, min, 0);
		else
		{
			bs[i] += rot_b(new_stck_b, min, size_b--, 0);
			bs[i] += rot_a(new_stck_a, new_stck_b, size_a++, 0);
		}
		*new_stck_b = push_ab(new_stck_a, *new_stck_b, 0, 0);
		if (!*new_stck_a)
			return (1);
	}
	return (0);
}

struct s_stcks	*creat_ns(struct s_stcks *stck)
{
	struct s_stcks	*res;
	struct s_stcks	*tmp;

	tmp = stck;
	if (!stck)
		return (stck);
	res = newlst(stck->value);
	if (!res)
		return (res);
	if (tmp->next)
		tmp = tmp->next;
	while (tmp != stck)
	{
		res = addback(res, tmp->value);
		if (!res)
			return (res);
		tmp = tmp->next;
	}
	return (res);
}
