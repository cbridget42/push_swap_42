/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wwargv_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student-21school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:08:37 by cbridget          #+#    #+#             */
/*   Updated: 2022/02/17 17:25:45 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker_bonus.h"

int	save_slist(int argc, char **argv, struct s_stcks **stck_a)
{
	char	**nums;
	char	*line;
	int		err;

	err = 0;
	if (argc < 2)
		return (1);
	line = save_slist01(argc, argv);
	if (!line)
		return (1);
	nums = ft_split(line, ' ');
	free(line);
	if (!nums)
		return (1);
	err = check_nums(nums);
	if (!err)
		err = create_strct(nums, stck_a);
	clear_nums(nums);
	return (err);
}

int	check_nums(char **nums)
{
	int	j;
	int	i;

	j = 0;
	i = -1;
	while (nums[++i])
	{
		if (check_nums2(nums, &i, &j))
			return (put_error(3));
		while (nums[i][j])
		{
			if (!ft_isdigit(nums[i][j]))
				return (put_error(1));
			j++;
		}
		j = i + 1;
		while (nums[j])
		{
			if (!ft_strncmp(nums[i], nums[j], 11))
				return (put_error(2));
			j++;
		}
		j = 0;
	}
	return (0);
}

int	check_nums2(char **nums, int *i, int *j)
{
	if (!nums[*i][0])
		return (1);
	while (nums[*i][*j] == ' ' || nums[*i][*j] == '\t' || nums[*i][*j] == '\n'
		|| nums[*i][*j] == '\v' || nums[*i][*j] == '\f' || nums[*i][*j] == '\r')
		(*j)++;
	if (nums[*i][*j] == '-' || nums[*i][*j] == '+')
		(*j)++;
	return (0);
}

int	put_error(int err)
{
	write(2, "Error\n", 6);
	return (err);
}

void	clear_nums(char **nums)
{
	int	i;

	i = 0;
	while (nums[i])
	{
		free(nums[i]);
		i++;
	}
	free(nums);
}
