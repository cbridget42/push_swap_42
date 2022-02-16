/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student-21school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 14:49:00 by cbridget          #+#    #+#             */
/*   Updated: 2022/02/13 14:29:32 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	sort_stck(struct s_stcks **stck_a, int *mmm)
{
	struct s_stcks	*stck_b;

	stck_b = (void *)0;
	if (length_stck(*stck_a) == 2)
		return (sort2(stck_a));
	if (pushalltob(stck_a, &stck_b, mmm))
		return (1);
	if (check_sort(*stck_a))
		sort3(stck_a);
	if (pushallback(stck_a, &stck_b))
		return (1);
	rrightpositiona(stck_a, 1);
	return (0);
}

int	sort2(struct s_stcks **stck_a)
{
	if ((*stck_a)->value > (*stck_a)->next->value)
		swap_ab(*stck_a, 0);
	return (0);
}

void	sort3(struct s_stcks **stck_a)
{
	if (((*stck_a)->next->value < (*stck_a)->value && (*stck_a)->next->value
			< (*stck_a)->back->value) || ((*stck_a)->next->value
			> (*stck_a)->value && (*stck_a)->next->value
			> (*stck_a)->back->value))
	{
		if ((*stck_a)->value > (*stck_a)->back->value)
			return ;
	}
	swap_ab(*stck_a, 0);
}

int	pushalltob(struct s_stcks **stck_a, struct s_stcks **stck_b, int *mmm)
{
	int	size_a;
	int	i;

	i = -1;
	size_a = length_stck(*stck_a);
	while (++i < size_a && size_a > 3)
	{
		if ((*stck_a)->value == mmm[0] || (*stck_a)->value == mmm[1]
			|| (*stck_a)->value == mmm[2])
			(*stck_a) = rotate_ab(*stck_a, 0, 1);
		else
		{
			if (pushalltob2(stck_a, stck_b, mmm, size_a))
				return (1);
		}
	}
	return (0);
}

int	pushalltob2(struct s_stcks **stck_a, struct s_stcks **stck_b,
				int *mmm, int size_a)
{
	if ((*stck_a)->value < mmm[1])
	{
		(*stck_a) = push_ab(stck_b, *stck_a, 1, 1);
		if (!*stck_a)
			return (1);
	}
	else
	{
		(*stck_a) = push_ab(stck_b, *stck_a, 1, 1);
		if (!*stck_a)
			return (1);
		if (size_a > 5)
			(*stck_b) = rotate_ab(*stck_b, 1, 1);
	}
	return (0);
}
