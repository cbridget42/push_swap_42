/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stck3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student-21school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 11:50:26 by cbridget          #+#    #+#             */
/*   Updated: 2022/02/15 10:32:46 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	rrightpositiona(struct s_stcks **stck_a, int act)
{
	int	i;
	int	size_a;
	int	mod;
	int	j;

	j = 0;
	size_a = length_stck(*stck_a);
	i = findmin_rrp(*stck_a);
	mod = set_mod(size_a, &i);
	while (j < i)
	{
		if (mod)
			*stck_a = rrotate_ab(*stck_a, 0, act);
		else
			*stck_a = rotate_ab(*stck_a, 0, act);
		j++;
	}
	return (i);
}

int	findmin_rrp(struct s_stcks *stck)
{
	struct s_stcks	*tmp;
	int				res;
	int				min;

	res = 0;
	tmp = stck;
	min = tmp->value;
	if (!stck)
		return (0);
	if (tmp->next)
		tmp = tmp->next;
	while (tmp != stck)
	{
		if (min > tmp->value)
			min = tmp->value;
		tmp = tmp->next;
	}
	while (min != stck->value)
	{
		res++;
		stck = stck->next;
	}
	return (res);
}
