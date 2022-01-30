/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wwargv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:08:37 by cbridget          #+#    #+#             */
/*   Updated: 2022/01/30 14:39:45 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	save_slist(int argc, char **argv, struct slist **stckA)
{
	char	**nums;
	int		err;

	err = 0;
	if (argc < 2)
		return (1);
	else if (argc == 2)
	{
		nums = ft_split(argv[1], ' ');
		if (!nums)
			return (1);
	}
	else
		nums = &(argv[1]);
	err = check_nums(nums);
	if (!err)
		err = create_strct(nums, stckA);
	if (argc == 2)
		clear_nums(nums);
	return (err);
}

int	check_nums(char **nums)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (nums[i])
	{
		while (nums[i][j] == ' ' || nums[i][j] == '\t' || nums[i][j] == '\n'
		|| nums[i][j] == '\v' || nums[i][j] == '\f' || nums[i][j] == '\r')
			j++;
		if (nums[i][j] == '-' || nums[i][j] == '+')
			j++;
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
		i++;
	}
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
