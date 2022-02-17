/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student-21school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 14:40:09 by cbridget          #+#    #+#             */
/*   Updated: 2022/02/17 17:33:57 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker_bonus.h"

struct s_stcks	*rrotate_ab(struct s_stcks *stck, char mod, int act)
{
	if (!stck || !stck->back)
		return (stck);
	if (act)
	{
		if (!mod)
			write(1, "rra\n", 4);
		else
			write(1, "rrb\n", 4);
	}
	return (stck->back);
}

int	rrr(struct s_stcks **stck_a, struct s_stcks **stck_b, int act)
{
	if (!*stck_a || !(*stck_a)->back)
		return (1);
	if (!*stck_b || !(*stck_b)->back)
		return (1);
	*stck_a = (*stck_a)->back;
	*stck_b = (*stck_b)->back;
	if (act)
		write(1, "rrr\n", 4);
	return (0);
}

void	ss(struct s_stcks *stck_a, struct s_stcks *stck_b, int mod)
{
	swap_ab(stck_a, 0, 0);
	swap_ab(stck_b, 1, 0);
	if (mod)
		write(1, "ss\n", 3);
}
