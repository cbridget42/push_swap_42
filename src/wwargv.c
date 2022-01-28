/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wwargv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:08:37 by cbridget          #+#    #+#             */
/*   Updated: 2022/01/28 14:04:59 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	save_slist(int argc, char **argv/*, &stk*/)
{
	char	**nums;
	int		err[4];

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
	check_nums(nums, err);
//	create_strct(); do this
	if (argc == 2)
		clear_nums(nums);
	return (put_error(err));
}

int	check_nums(char **nums, int *err)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (++i < 4)
		err[i] = 0;
	i = 0;
	while (nums[i])
	{
		if (nums[i][j] == '-')
			j++;
		while (nums[i][j])
		{
			if (!ft_isdigit(nums[i][j]))
				err[0] = 1;
			j++;
		}
		j = i + 1;
		while (nums[j])
		{
			if (!ft_strncmp(nums[i], nums[j], 11))
				err[1] = 1;
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int	put_error(int *err)
{
	int	error;

	error = 0;
	if (err[0])
	{
		write(2, "Error: some arguments aren’t integers\n", 40);
		error = 2;
	}
	if (err[1])
	{
		write(2, "Error: there are duplicates\n", 28);
		error = 2;
	}
	if (err[2])
	{
		write(2, "Error: some arguments are bigger than an integer\n", 48);
		error = 2;
	}
	if (err[3])
	{
		write(2, "Error: some arguments are less than an integer\n", 46);
		error = 2;
	}
	return (error);
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
