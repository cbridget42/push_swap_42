/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wwargv01_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student-21school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 16:48:42 by cbridget          #+#    #+#             */
/*   Updated: 2022/02/17 17:26:02 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker_bonus.h"

char	*save_slist01(int argc, char **argv)
{
	char	*lines[3];
	int		i;

	i = 0;
	lines[0] = "";
	while (++i < argc)
	{
		lines[2] = ft_strjoin(argv[i], " ");
		if (!lines[2])
			return (save_slist02(lines, i));
		lines[1] = ft_strjoin(lines[0], lines[2]);
		free(lines[2]);
		if (i > 1)
			free(lines[0]);
		if (!lines[1])
			return ((void *)0);
		lines[0] = ft_strdup(lines[1]);
		free(lines[1]);
		if (!lines[0])
			return ((void *)0);
	}
	return (lines[0]);
}

char	*save_slist02(char **lines, int i)
{
	if (i > 1)
	{
		free(lines[1]);
		free(lines[0]);
	}
	return ((void *)0);
}
