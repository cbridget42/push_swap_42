/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_MMM.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student-21school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 16:29:30 by cbridget          #+#    #+#             */
/*   Updated: 2022/02/02 12:27:10 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	search_MMM(struct s_stcks *stck_a, int *mmm)
{
	int	*array;
	int	size;
	int	i;

//	mmm = NULL;
	
	size = length_stck(stck_a);
	i = 0;
	array = malloc(sizeof(int) * size);
	if (!array)
		return (1);
	while (i < size)
	{
		array[i] = stck_a->value;
		stck_a = stck_a->next;
		i++;
	}
	
	
	i = 0;
	while (i < size)
	{
		printf(" %d", array[i]);
		i++;
	}
	printf("\n");
	
	if (check_sort(array, size))
	{
		free(array);
		return (55);
	}
	ft_qsort(array, 0, size - 1);

	i = 0;
	while (i < size)
	{
		printf(" %d", array[i]);
		i++;
	}

	printf("\nres=%d\n", length_stck(stck_a));

	mmm[0] = 0;
	return (mmm[0]);
}

void	ft_qsort(int *array, int min, int max)
{
	int	i;
	int	tmp;

	tmp = min;
	i = min + 1;
	ft_swap(array, min, (min + max) / 2);
	while (i <= max)
	{
		if (array[i] < array[min])
			ft_swap(array, i, ++tmp);
		i++;
	}
	ft_swap(array, min, tmp);
	if (min < tmp - 1)
		ft_qsort(array, min, tmp - 1);
	if (tmp + 1 < max)
		ft_qsort(array, tmp + 1, max);
}

void	ft_swap(int *array, int i, int j)
{
	int	tmp;

	tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
}

int	check_sort(int *array, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (array[i] > array[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	length_stck(struct s_stcks *stck)
{
	struct s_stcks	*tmp;
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
