/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_mmm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student-21school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 16:29:30 by cbridget          #+#    #+#             */
/*   Updated: 2022/02/13 13:59:56 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	search_mmm(struct s_stcks *stck_a, int *mmm)
{
	int	*array1;
	int	*array2;
	int	size;
	int	i;

	size = length_stck(stck_a);
	i = 0;
	if (!check_sort(stck_a))
		return (55);
	array1 = malloc(sizeof(int) * size);
	if (!array1)
		return (1);
	array2 = malloc(sizeof(int) * size);
	if (!array2)
		return (1);
	while (i < size)
	{
		array1[i] = stck_a->value;
		stck_a = stck_a->next;
		i++;
	}
	search_mmm2(array1, array2, size, mmm);
	return (0);
}

void	search_mmm2(int *array1, int *array2, int size, int *mmm)
{
	ft_radix(array1, array2, size);
	mmm[0] = array1[0];
	mmm[1] = array1[size / 2];
	mmm[2] = array1[size - 1];
	free(array1);
	free(array2);
}

int	check_sort(struct s_stcks *stck)
{
	struct s_stcks	*tmp;

	tmp = stck;
	if (!stck)
		return (0);
	while (tmp->next && tmp->next != stck)
	{
		if (tmp->value > tmp->next->value)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	length_stck(struct s_stcks *stck)
{
	struct s_stcks	*tmp;
	int				result;

	result = 1;
	tmp = stck;
	if (!stck)
		return (0);
	if (tmp->next)
		tmp = tmp->next;
	while (tmp != stck)
	{
		tmp = tmp->next;
		result++;
	}
	return (result);
}
