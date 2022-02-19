/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student-21school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:10:36 by cbridget          #+#    #+#             */
/*   Updated: 2022/02/19 14:57:22 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker_bonus.h"

int	main(int argc, char **argv)
{
	int				err;
	struct s_stcks	*stck_a;
	struct s_stcks	*stck_b;

	stck_a = (void *)0;
	stck_b = (void *)0;
	err = save_slist(argc, argv, &stck_a);
	if (!err)
		err = ft_exec(&stck_a, &stck_b);
	if (!err)
	{
		if (!check_sort(stck_a) && !stck_b)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	clean_stck(stck_a);
	clean_stck(stck_b);
	return (err);
}

int	ft_exec(struct s_stcks **stck_a, struct s_stcks **stck_b)
{
	char			*cmd;
	int				i;
	unsigned int	size;
	int				error;

	size = 5;
	while (1)
	{
		i = -1;
		error = ft_exec_read(&cmd, &size, &i);
		if (error == 5)
			return (0);
		else if (error)
			return (error);
		cmd[++i] = '\0';
		error = ft_exec2(stck_a, stck_b, cmd);
		free(cmd);
		if (error)
			return (error);
	}
}

int	ft_exec_read(char **cmd, unsigned int *size, int *i)
{
	*cmd = my_realloc((void *)0, size);
	if (!*cmd)
		return (4);
	while (read(0, &(*cmd)[++(*i)], 1) > 0 && (*cmd)[*i] != '\n')
	{
		if ((unsigned int)(*i) == *size - 2)
		{
			*cmd = my_realloc(*cmd, size);
			if (!*cmd)
				return (4);
		}
	}
	if (*i == 0)
	{
		free(*cmd);
		return (5);
	}
	return (0);
}

int	ft_exec2(struct s_stcks **stck_a, struct s_stcks **stck_b, char *cmd)
{
	if (!ft_strncmp(cmd, "sa\n", 3))
		swap_ab(*stck_a, 0, 0);
	else if (!ft_strncmp(cmd, "sb\n", 3))
		swap_ab(*stck_b, 0, 0);
	else if (!ft_strncmp(cmd, "ss\n", 3))
		ss(*stck_a, *stck_b, 0);
	else if (!ft_strncmp(cmd, "pa\n", 3))
		*stck_b = push_ab(stck_a, *stck_b, 0, 0);
	else if (!ft_strncmp(cmd, "pb\n", 3))
		*stck_a = push_ab(stck_b, *stck_a, 0, 0);
	else if (!ft_strncmp(cmd, "ra\n", 3))
		*stck_a = rotate_ab(*stck_a, 0, 0);
	else if (!ft_strncmp(cmd, "rb\n", 3))
		*stck_b = rotate_ab(*stck_b, 0, 0);
	else if (!ft_strncmp(cmd, "rr\n", 3))
		rr(stck_a, stck_b, 0);
	else if (!ft_strncmp(cmd, "rra\n", 4))
		*stck_a = rrotate_ab(*stck_a, 0, 0);
	else if (!ft_strncmp(cmd, "rrb\n", 4))
		*stck_b = rrotate_ab(*stck_b, 0, 0);
	else if (!ft_strncmp(cmd, "rrr\n", 4))
		rrr(stck_a, stck_b, 0);
	else
		return (put_error(255));
	return (0);
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
