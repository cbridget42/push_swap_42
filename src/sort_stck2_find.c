/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stck2_find.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student-21school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 14:58:57 by cbridget          #+#    #+#             */
/*   Updated: 2022/02/19 12:52:01 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	findmin(struct s_stcks *stck, int *i)
{
	struct s_stcks	*tmp;
	int				min;

	tmp = stck;
	min = tmp->move;
	if (!stck)
		return (0);
	if (tmp->next)
		tmp = tmp->next;
	while (tmp != stck)
	{
		if (min > tmp->move)
			min = tmp->move;
		tmp = tmp->next;
	}
	return (findmin2(stck, min, i));
}

int	findmin2(struct s_stcks *stck, int min, int *i)
{
	int	res;

	res = 0;
	while (stck)
	{
		if (stck->move == min)
			break ;
		stck = stck->next;
		res++;
	}
	*i = res;
	return (stck->flag);
}

int	findmin_last(struct s_stcks *stck, int *i)
{
	struct s_stcks	*tmp;
	int				j;

	if (!stck)
		return (0);
	if (stck->next)
	{
		j = stck->flag;
		tmp = stck->next;
	}
	else
	{
		*i = 0;
		return (stck->flag);
	}
	return (findmin_last2(stck, tmp, &j, i));
}

int	findmin_last2(struct s_stcks *stck, struct s_stcks *tmp, int *j, int *i)
{
	int	res;
	int	d;
	int	min;

	d = 0;
	res = 1;
	min = stck->move;
	while (tmp != stck)
	{
		if (min >= tmp->move)
		{
			d = res;
			*j = tmp->flag;
			min = tmp->move;
		}
		tmp = tmp->next;
		res++;
	}
	*i = d;
	return (*j);
}
