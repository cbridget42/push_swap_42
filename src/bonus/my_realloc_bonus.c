/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_realloc_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student-21school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 20:42:31 by cbridget          #+#    #+#             */
/*   Updated: 2022/02/18 20:44:03 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker_bonus.h"

char	*my_realloc(char *result, unsigned int *size)
{
	char			*tmp;

	if (!result)
	{
		tmp = (char *)malloc(sizeof(char) * (*size));
		if (!tmp)
			return ((void *)0);
		tmp[0] = -1;
	}
	else
		tmp = my_realloc_two(result, size);
	return (tmp);
}

char	*my_realloc_two(char *result, unsigned int *size)
{
	char			*tmp;
	unsigned int	i;

	i = 0;
	tmp = (char *)malloc(sizeof(char) * (*size * 2));
	if (!tmp)
	{
		free(result);
		return ((void *)0);
	}
	while (i < *size)
	{
		tmp[i] = result[i];
		i++;
	}
	*size = *size * 2;
	free(result);
	return (tmp);
}
