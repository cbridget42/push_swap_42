/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liblsts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 13:23:35 by cbridget          #+#    #+#             */
/*   Updated: 2022/01/30 15:22:57 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

struct slist	*newlst(int value)
{
	struct slist	*newlst;

	newlst = malloc(sizeof(struct slist) * 1);
	if (!newlst)
		return ((void *)0);
	newlst->value = value;
	newlst->next = (void *)0;
	newlst->back = (void *)0;
	return (newlst);
}

struct slist	*addback(struct slist *stck, int value)
{
	struct slist	*newback;

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

struct slist	*clean_stck(struct slist *stck)
{
	struct slist	*tmp;
	struct slist	*del;

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
