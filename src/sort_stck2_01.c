/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stck2_01.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student-21school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 17:30:14 by cbridget          #+#    #+#             */
/*   Updated: 2022/02/19 12:51:38 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cma(struct s_stcks *stck_a, int val, int size_a, int *mvdr)
{
	int	i;

	i = 0;
	while (i < size_a)
	{
		if (stck_a->value > val && stck_a->back->value < val)
			break ;
		stck_a = stck_a->next;
		i++;
	}
	mvdr[1] = i;
	mvdr[3] = size_a - i;
	return (cma_logic(i, size_a));
}

int	cma_logic(int i, int size_a)
{
	if (size_a % 2)
	{
		if (i <= size_a / 2)
			return (i);
		else
			return (size_a - i);
	}
	else
	{
		if (i < size_a / 2)
			return (i);
		else
			return (size_a - i);
	}
}
