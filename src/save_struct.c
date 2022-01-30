/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 13:05:25 by cbridget          #+#    #+#             */
/*   Updated: 2022/01/30 14:32:27y cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	create_strct(char **nums, struct slist **stckA)
{
	int	val;
	int	overflow;

	overflow = 0;
	while (*nums)
	{
		val = ft_atoiS(*nums, &overflow);
		if (overflow)
		{
			clean_stck(*stckA);
			return (put_error(3));
		}
		if (!(*stckA))
			*stckA = newlst(val);
		else
			*stckA = addback(*stckA, val);
		nums++;
	}
	return (0);
}

int	ft_atoiS(const char *str, int *overflow)
{
	size_t			i;
	int				sign;
	unsigned int	result;

	result = 0;
	sign = 1;
	i = skipp(str, &sign);
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i ++;
		if (result > 2147483650)
			break ;
	}
	if (result > 2147483647 && sign == 1)
		*overflow = 1;
	if (result > 2147483648 && sign == -1)
		*overflow = 1;
	return ((int)result * sign);
}

int	skipp(const char *str, int *sign)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i ++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			*sign = -1;
		i ++;
	}
	return (i);
}
