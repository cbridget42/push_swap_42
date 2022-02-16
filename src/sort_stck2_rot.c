/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stck2_rot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student-21school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 15:25:44 by cbridget          #+#    #+#             */
/*   Updated: 2022/02/13 17:01:25 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	rot_a(struct s_stcks **stck_a, struct s_stcks **stck_b, int size_a, int act)
{
	int				i;
	struct s_stcks	*tmp;

	tmp = *stck_a;
	i = 0;
	while (i < size_a)
	{
		if (tmp->value > (*stck_b)->value && tmp->back->value
			< (*stck_b)->value)
			break ;
		tmp = tmp->next;
		i++;
	}
	return (rot_a2(stck_a, size_a, i, act));
}

int	rot_a2(struct s_stcks **stck_a, int size_a, int i, int act)
{
	char	mod;
	int		j;

	mod = set_mod(size_a, &i);
	j = 0;
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

char	set_mod(int size, int *i)
{
	char	mod;

	mod = 1;
	if (size % 2)
	{
		if (*i <= size / 2)
			mod = 0;
		else
			*i = size - *i;
	}
	else
	{
		if (*i < size / 2)
			mod = 0;
		else
			*i = size - *i;
	}
	return (mod);
}

int	rot_b(struct s_stcks **stck_b, int i, int size_b, int act)
{
	char	mod;
	int		j;

	j = 0;
	mod = set_mod(size_b, &i);
	while (j < i)
	{
		if (mod)
			*stck_b = rrotate_ab(*stck_b, 1, act);
		else
			*stck_b = rotate_ab(*stck_b, 1, act);
		j++;
	}
	return (i);
}
