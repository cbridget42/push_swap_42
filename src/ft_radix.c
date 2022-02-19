/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student-21school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 13:11:33 by cbridget          #+#    #+#             */
/*   Updated: 2022/02/19 12:54:57 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

unsigned int	findbyte(unsigned int value, int nb)
{
	unsigned int	m;

	m = 0xff;
	m <<= (nb * 8);
	return ((value & m) >> (nb * 8));
}

void	ft_radix(int *array1, int *array2, int size)
{
	int				i;
	int				j;
	unsigned int	sbytes[256];

	i = 0;
	while (i < 4)
	{
		full_sbytes(sbytes, array1, i, size);
		j = -1;
		if (i != 3)
		{
			while (++j < size)
				array2[sbytes[findbyte(array1[j], i)]++] = array1[j];
		}
		else
			last_pass(sbytes, array1, array2, size);
		j = -1;
		while (++j < size)
			array1[j] = array2[j];
		i++;
	}
}

void	last_pass(unsigned int *sbytes, int *array1, int *array2, int size)
{
	int	tmp;
	int	j;

	j = -1;
	tmp = sbytes[128];
	while (++j < size)
	{
		if (findbyte(array1[j], 3) >= 128)
		{
			array2[sbytes[findbyte(array1[j], 3)] - tmp] = array1[j];
			sbytes[findbyte(array1[j], 3)]++;
		}
		else
		{
			array2[sbytes[findbyte(array1[j], 3)] + (size - tmp)] = array1[j];
			sbytes[findbyte(array1[j], 3)]++;
		}
	}
}

void	full_sbytes(unsigned int *sbytes, int *array1, int i, int size)
{
	int	j;
	int	bias;
	int	tmp;

	bias = 0;
	j = 0;
	while (j < 256)
		sbytes[j++] = 0;
	j = -1;
	while (++j < size)
		sbytes[findbyte(array1[j], i)]++;
	j = 0;
	while (j < 256)
	{
		tmp = sbytes[j];
		sbytes[j++] = bias;
		bias += tmp;
	}
}
