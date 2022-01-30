/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_MMM.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 16:29:30 by cbridget          #+#    #+#             */
/*   Updated: 2022/01/30 17:24:03 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	search_MMM(struct slist *stckA, int *mmm)
{
	int	*A;
	int	size;
	int	i;

	mmm = NULL;
	
	size = length_stck(stckA);
	i = 0;
	A = malloc(sizeof(int) * size);
	if (!A)
		return (1);
	while (i < size)
	{
		A[i] = stckA->value;
		stckA = stckA->next;
		i++;
	}
	if (check_sort(A, size))
	{
		free(A);
		return (55);
	}
	ft_qsort(A, 0, size);
	printf("res=%d\n", length_stck(stckA));
	return (0);
}

void	ft_qsort(int *A, int min, int max)
{
	int	mid;
	int	i;

	i = min;
	mid = (min + max) / 2;
	ft_swap(A, min, mid);
	while (i < max)
	{
		if (A[i] < A[mid])
			ft_swap()
	}
}

int	check_sort(int *A, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (A[i] > A[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	length_stck(struct slist *stck)
{
	struct slist	*tmp;
	int				result;

	result = 1;
	tmp = stck;
	if (tmp->next)
		tmp = tmp->next;
	while (tmp != stck)
	{
		tmp = tmp->next;
		result++;
	}
	return (result);
}
