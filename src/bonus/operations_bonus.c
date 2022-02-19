/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student-21school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 15:14:05 by cbridget          #+#    #+#             */
/*   Updated: 2022/02/18 20:04:36 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker_bonus.h"

struct s_stcks	*push_ab(struct s_stcks **stck_1, struct s_stcks *stck_2,
						char mod, int act)
{
	struct s_stcks	*tmp;
	int				size_2;

	tmp = stck_2;
	size_2 = length_stck(stck_2);
	if (size_2 == 0)
		return (stck_2);
	*stck_1 = addtop(*stck_1, stck_2->value);
	if (!*stck_1)
		return (clean_stck(stck_2));
	if (size_2 == 1)
	{
		free(stck_2);
		stck_2 = (void *)0;
	}
	else
	{
		stck_2->back->next = stck_2->next;
		stck_2->next->back = stck_2->back;
		stck_2 = stck_2->next;
		free(tmp);
	}
	push_ab2(mod, act);
	return (stck_2);
}

void	push_ab2(char mod, int act)
{
	if (act)
	{
		if (!mod)
			write(1, "pa\n", 3);
		else
			write(1, "pb\n", 3);
	}
}

struct s_stcks	*rotate_ab(struct s_stcks *stck, char mod, int act)
{
	if (!stck || !stck->next)
		return (stck);
	if (act)
	{
		if (!mod)
			write(1, "ra\n", 3);
		else
			write(1, "rb\n", 3);
	}
	return (stck->next);
}

int	rr(struct s_stcks **stck_a, struct s_stcks **stck_b, int act)
{
	if (*stck_a && (*stck_a)->back)
		*stck_a = (*stck_a)->next;
	if (*stck_b && (*stck_b)->back)
		*stck_b = (*stck_b)->next;
	if (act)
		write(1, "rr\n", 3);
	return (0);
}

void	swap_ab(struct s_stcks *stck, int mod, int act)
{
	int	tmp;

	tmp = length_stck(stck);
	if (tmp < 2)
		return ;
	tmp = stck->value;
	stck->value = stck->next->value;
	stck->next->value = tmp;
	if (act)
	{
		if (!mod)
			write(1, "sa\n", 3);
		else
			write(1, "sb\n", 3);
	}
}
