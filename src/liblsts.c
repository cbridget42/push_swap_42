/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liblsts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student-21school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 13:23:35 by cbridget          #+#    #+#             */
/*   Updated: 2022/02/02 11:38:58 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

struct s_stcks	*newlst(int value)
{
	struct s_stcks	*newlst;

	newlst = malloc(sizeof(struct s_stcks) * 1);
	if (!newlst)
		return ((void *)0);
	newlst->value = value;
	newlst->next = (void *)0;
	newlst->back = (void *)0;
	return (newlst);
}

struct s_stcks	*addback(struct s_stcks *stck, int value)
{
	struct s_stcks	*newback;

	newback = newlst(value);
	if (!newback)
		return (clean_stck(stck));
	if (!stck->next)
	{
		stck->next = newback;
		stck->back = newback;
		newback->next = stck;
		newback->back = stck;
	}
	else
	{
		stck->back->next = newback;
		newback->back = stck->back;
		stck->back = newback;
		newback->next = stck;
	}
	return (stck);
}

struct s_stcks	*clean_stck(struct s_stcks *stck)
{
	struct s_stcks	*tmp;
	struct s_stcks	*del;

	tmp = stck;
	if (tmp)
	{
		if (tmp->next)
		{
			tmp = tmp->next;
			while (tmp != stck)
			{
				del = tmp;
				tmp = tmp->next;
				free(del);
			}
		}
		free(stck);
	}
	return ((void *)0);
}
